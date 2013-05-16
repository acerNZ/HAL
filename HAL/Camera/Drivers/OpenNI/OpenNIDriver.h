#pragma once

#include "HAL/Camera/CameraDriverInterface.h"

#pragma GCC system_header
#include <XnCppWrapper.h>


namespace hal {

class OpenNIDriver : public CameraDriverInterface
{
    public:
        OpenNIDriver(
                unsigned int            nWidth,
                unsigned int            nHeight,
                unsigned int            nFPS,
                bool                    bCaptureRGB,
                bool                    bCaptureDepth,
                bool                    bCaptureIR,
                bool                    bAlignDepth
                );

        virtual ~OpenNIDriver();

        bool Capture( pb::CameraMsg& vImages );

        std::string GetDeviceProperty(const std::string& sProperty);

        unsigned int Width( unsigned int idx = 0 );

        unsigned int Height( unsigned int idx = 0 );


    private:
        unsigned int                    m_nImgHeight;
        unsigned int                    m_nImgWidth;
        xn::Context                     m_Context;
        std::vector<double>             m_DepthBaselines;
        std::vector<double>             m_DepthFocalLengths;
        std::vector<xn::DepthGenerator> m_DepthGenerators;
        std::vector<xn::ImageGenerator> m_ImageGenerators;
        std::vector<xn::IRGenerator>    m_IRGenerators;
};

}