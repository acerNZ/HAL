/*
   \file KinectDriver.cpp
 */

#include "KinectDriver.h"

#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/imgproc/types_c.h>

#include <boost/lexical_cast.hpp>

#include <HAL/Utils/TicToc.h>


#define MAX_DEPTH 10000

using namespace xn;
using namespace hal;

///////////////////////////////////////////////////////////////////////////////
//
KinectDriver::KinectDriver()
{
}

///////////////////////////////////////////////////////////////////////////////
//
KinectDriver::~KinectDriver()
{
}

#define CHECK_XN_RETURN(rc) { \
    if (rc != XN_STATUS_OK) { \
        XnChar strError[1024]; \
        EnumerationErrors errors; \
        errors.ToString(strError, 1024); \
        printf("%s\n", strError); \
        return false; \
    } \
}


///////////////////////////////////////////////////////////////////////////////
void KinectDriver::PrintInfo() {

    std::cout <<
    "\nKINECT\n"
    "--------------------------------\n"
    "Uses OpenNI to open all available depth cameras connected. If more than 1 camera is connected, it returns images in the\n"
    "following order:\n"
    "\t\tRGB1, RGB2, Depth1, Depth2, IR1, IR2"
    "\n\n"
    "Options:\n"
    "   -fps            <framerate> [default 30]\n"
    "   -res            <resolution> [default 'VGA']\n"
    "\n"
    "Flags:\n"
    "   -greyscale      If the driver should return images in greyscale.\n"
    "   -no-rgb         If no RGB images should be captured.\n"
    "   -no-depth       If no depth images should be taken.\n"
    "   -with-ir        If infrared images should be returned.\n"
    "   -align-depth    If the depth map should be aligned to the RGB image.\n"
    "\n"
    "Notes:\n"
    "   Infrared images cannot be captured along other images.\n"
    "   It is not possible to capture full res at 60FPS; the resolution must be QVGA.\n"
    "\n"
    "Examples:\n"
    "./Exec  -idev Kinect  -no-depth   -with-ir\n\n";
}


///////////////////////////////////////////////////////////////////////////////
//
bool KinectDriver::Init()
{
    bool            bGetImage   = m_pPropertyMap->GetProperty( "GetRGB", true );
    bool            bGetDepth   = m_pPropertyMap->GetProperty( "GetDepth", true );
    bool            bGetIR      = m_pPropertyMap->GetProperty( "GetIr", false );
    std::string     sRes        = m_pPropertyMap->GetProperty( "Resolution", "VGA" );
    unsigned int    nFPS        = m_pPropertyMap->GetProperty( "FPS", 30 );
    bool            bAlignDepth = m_pPropertyMap->GetProperty( "AlignDepth", false );

    m_bForceGreyscale = m_pPropertyMap->GetProperty( "ForceGreyscale", false);

    XnMapOutputMode MapMode;
    MapMode.nFPS = nFPS;

    if( sRes == "VGA" ) {
        m_nImgHeight = XN_VGA_Y_RES;
        m_nImgWidth = XN_VGA_X_RES;
        MapMode.nXRes = XN_VGA_X_RES;
        MapMode.nYRes = XN_VGA_Y_RES;
    }

    if( sRes == "QVGA" ) {
        m_nImgHeight = XN_QVGA_Y_RES;
        m_nImgWidth = XN_QVGA_X_RES;
        MapMode.nXRes = XN_QVGA_X_RES;
        MapMode.nYRes = XN_QVGA_Y_RES;
    }

    if( sRes == "QQVGA" ) {
        m_nImgHeight = XN_QQVGA_Y_RES;
        m_nImgWidth = XN_QQVGA_X_RES;
        MapMode.nXRes = XN_QQVGA_X_RES;
        MapMode.nYRes = XN_QQVGA_Y_RES;
    }

    XnStatus rc;

    rc = m_Context.Init ();
    CHECK_XN_RETURN(rc);

    if( bGetImage ) {
        // Enumerate Image Generating nodes
        NodeInfoList ImageNodeList;
        rc = m_Context.EnumerateProductionTrees( XN_NODE_TYPE_IMAGE, NULL, ImageNodeList, 0 );
        CHECK_XN_RETURN(rc);

        for(NodeInfoList::Iterator it = ImageNodeList.Begin(); it != ImageNodeList.End(); ++it) {
            // create depth generator
            NodeInfo node = *it;

            xn::ImageGenerator imageGen;

            rc = m_Context.CreateProductionTree(node, imageGen);
            CHECK_XN_RETURN(rc);

            rc = node.GetInstance(imageGen);
            CHECK_XN_RETURN(rc);

            rc = imageGen.SetMapOutputMode(MapMode);

            m_ImageGenerators.push_back(imageGen);
        }
    }


    if( bGetDepth ) {
        // Enumerate Depth Generating nodes
        NodeInfoList DepthNodeList;
        rc = m_Context.EnumerateProductionTrees( XN_NODE_TYPE_DEPTH, NULL, DepthNodeList, 0 );
        CHECK_XN_RETURN(rc);

        unsigned int count = 0;
        for(NodeInfoList::Iterator it = DepthNodeList.Begin(); it != DepthNodeList.End(); ++it) {
            // create depth generator
            NodeInfo node = *it;

            xn::DepthGenerator depthGen;

            rc = m_Context.CreateProductionTree(node, depthGen);
            CHECK_XN_RETURN(rc);

            rc = node.GetInstance(depthGen);
            CHECK_XN_RETURN(rc);

            rc = depthGen.SetMapOutputMode(MapMode);
            CHECK_XN_RETURN(rc);

            // --- ALIGN DEPTH TO RGB IF REQUESTED ---
            if( bAlignDepth ) {
                if( depthGen.IsCapabilitySupported(XN_CAPABILITY_ALTERNATIVE_VIEW_POINT) ) {
                    AlternativeViewPointCapability avpx = depthGen.GetAlternativeViewPointCap();
                    rc = avpx.SetViewPoint( m_ImageGenerators[count]  );
                    CHECK_XN_RETURN(rc);
                }
                count++;
            }


            // --- GET CAMERA PARAMS ---
            // Details can be found in XnStreamParams.h

            // focal length in mm
            XnUInt64 depth_focal_length_SXGA_mm;   //in mm
            depthGen.GetIntProperty("ZPD", depth_focal_length_SXGA_mm);

            // pixel size in mm
            XnDouble pixelSize;
            depthGen.GetRealProperty( "ZPPS", pixelSize );  // in mm

            // focal length in pixels
//            double depth_focal_length_SXGA = depth_focal_length_SXGA_mm / pixelSize;

            XnDouble dBaselineRGBDepth;
            depthGen.GetRealProperty( "DCRCDIS", dBaselineRGBDepth );

//            const int camn = m_DepthGenerators.size();
//            m_pPropertyMap->SetProperty( "Depth" +  boost::lexical_cast<std::string>(camn) + "FocalLength", depth_focal_length_SXGA / 2 );
//            m_pPropertyMap->SetProperty( "Depth" +  boost::lexical_cast<std::string>(camn) + "Baseline", dBaselineRGBDepth );

            m_DepthGenerators.push_back(depthGen);
        }
    }


    if( bGetIR ) {
        // Enumerate IR Generating nodes
        NodeInfoList IRNodeList;
        rc = m_Context.EnumerateProductionTrees( XN_NODE_TYPE_IR, NULL, IRNodeList, 0 );
        CHECK_XN_RETURN(rc);

        for(NodeInfoList::Iterator it = IRNodeList.Begin(); it != IRNodeList.End(); ++it) {
            // create depth generator
            NodeInfo node = *it;

            xn::IRGenerator irGen;

            rc = m_Context.CreateProductionTree(node, irGen);
            CHECK_XN_RETURN(rc);

            rc = node.GetInstance(irGen);
            CHECK_XN_RETURN(rc);

            rc = irGen.SetMapOutputMode(MapMode);

            m_IRGenerators.push_back(irGen);
        }
    }

//    if(m_ImageNode.IsCapabilitySupported(XN_CAPABILITY_ALTERNATIVE_VIEW_POINT))
//    {
//        //Warp RGB to match depth
//        AlternativeViewPointCapability avpx = m_ImageNode.GetAlternativeViewPointCap();
//        rc = avpx.SetViewPoint(m_DepthNode);
//        if (rc != XN_STATUS_OK) {
//            errors.ToString(strError, 1024);
//            printf("%s\n", strError);
//        }
//    }

    // --- GET CAMERA PARAMS ---
    // Details can be found in XnStreamParams.h

    /*
    max_depth = m_DepthNode.GetDeviceMaxDepth ();


    XnUInt64 shadow_value_local;
    depth.GetIntProperty ("ShadowValue", shadow_value_local);
    shadow_value = (int)shadow_value_local;

    XnUInt64 no_sample_value_local;
    depth.GetIntProperty ("NoSampleValue", no_sample_value_local);
    no_sample_value = (int)no_sample_value_local;

    // baseline from cm -> mm
    baseline = (float)(baseline_local * 10);
    */

    // --- END GETTING PARAMS ---

    rc = m_Context.StartGeneratingAll();
    CHECK_XN_RETURN(rc);

    return true;
}

#undef CHECK_XN_RETURN

///////////////////////////////////////////////////////////////////////////////
//
bool KinectDriver::Capture( pb::CameraMsg& vImages )
{
    XnStatus rc = XN_STATUS_OK;

    // Read a new frame
    rc = m_Context.WaitAndUpdateAll();
    const double systemTime = Tic();
    vImages.set_devicetime( systemTime );

    if (rc != XN_STATUS_OK)
    {
        printf("Read failed: %s\n", xnGetStatusString(rc));
        return false;
    }

    // prepare return images
//    const unsigned int nNumImgs = m_DepthGenerators.size() + m_ImageGenerators.size() + m_IRGenerators.size();

    for(unsigned int i=0; i<m_ImageGenerators.size(); ++i) {
        xn::ImageMetaData metaData;
        m_ImageGenerators[i].GetMetaData(metaData);
        pb::ImageMsg* pbImg = vImages.add_image();
        pbImg->set_timestamp( metaData.Timestamp() );
        pbImg->set_width( m_nImgWidth );
        pbImg->set_height( m_nImgHeight );
        pbImg->set_type(pb::ImageMsg_Type_PB_UNSIGNED_BYTE);
        if(m_bForceGreyscale) {
            static cv::Mat temp(m_nImgHeight, m_nImgWidth, CV_8UC3);
            memcpy(temp.data, metaData.RGB24Data(), metaData.DataSize() );
            cv::Mat cvImg;
            cvtColor(temp, cvImg, CV_RGB2GRAY);
            pbImg->set_data( (const char*)cvImg.data, m_nImgHeight * m_nImgWidth );
            pbImg->set_format(pb::ImageMsg_Format_PB_LUMINANCE);
        }else{
            pbImg->mutable_data()->resize( metaData.DataSize() );
            memcpy((void*)pbImg->mutable_data()->data(), metaData.RGB24Data(), metaData.DataSize() );
            pbImg->set_format(pb::ImageMsg_Format_PB_RGB);
        }
    }
    for(unsigned int i=0; i<m_DepthGenerators.size(); ++i) {
        xn::DepthMetaData metaData;
        m_DepthGenerators[i].GetMetaData(metaData);
        pb::ImageMsg* pbImg = vImages.add_image();
        pbImg->set_width( m_nImgWidth );
        pbImg->set_height( m_nImgHeight );
        pbImg->set_timestamp( metaData.Timestamp() );
        pbImg->mutable_data()->resize( metaData.DataSize() );
        memcpy((void*)pbImg->mutable_data()->data(), metaData.Data(), metaData.DataSize() );
        pbImg->set_type(pb::ImageMsg_Type_PB_UNSIGNED_SHORT);
        pbImg->set_format(pb::ImageMsg_Format_PB_LUMINANCE);
    }
    for(unsigned int i=0; i<m_IRGenerators.size(); ++i) {
        xn::IRMetaData metaData;
        m_IRGenerators[i].GetMetaData(metaData);
        pb::ImageMsg* pbImg = vImages.add_image();
        pbImg->set_width( m_nImgWidth );
        pbImg->set_height( m_nImgHeight );
        pbImg->set_timestamp( metaData.Timestamp() );
        pbImg->mutable_data()->resize( metaData.DataSize() );
        memcpy((void*)pbImg->mutable_data()->data(), metaData.Data(), metaData.DataSize() );
        pbImg->set_type(pb::ImageMsg_Type_PB_UNSIGNED_BYTE);
        pbImg->set_format(pb::ImageMsg_Format_PB_LUMINANCE);
    }

    return true;
}
