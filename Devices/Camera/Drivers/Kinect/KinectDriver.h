/*
   \file KinectDriver.h

 */

#ifndef _KINECT_H_
#define _KINECT_H_

#include "RPG/Devices/Camera/CameraDriverInterface.h"

#include <XnCppWrapper.h>

class KinectDriver : public CameraDriver
{
    public:
        KinectDriver();
        virtual ~KinectDriver();
        bool Capture( std::vector<cv::Mat>& vImages );
        bool Init();
    private:
        xn::Context             m_Context;
        xn::ScriptNode          m_ScriptNode;
        xn::DepthGenerator      m_DepthNode;
        xn::ImageGenerator      m_ImageNode;
        xn::DepthMetaData       m_DepthMD;
        xn::ImageMetaData       m_ImageMD;
};

#endif