#include <HAL/Devices/DriverFactory.h>
#include "FileReaderDriver.h"

namespace hal
{
  class FileReaderFactory : public DriverFactory<CameraDriverInterface> 
  {
    public:
      FileReaderFactory( const std::string& driver_name, const std::vector<param_t>& default_params )
        : DriverFactory<CameraDriverInterface>( driver_name, default_params )
      {}

      // called by CameraDevice constructors
      std::shared_ptr<CameraDriverInterface> CreateDriver( const Uri& uri ) 
      {
        FileReaderDriver* pDriver = new FileReaderDriver();
        pDriver->Init( default_params_, uri );
        return std::shared_ptr<CameraDriverInterface>( pDriver );
      }
  };

  // Register this factory by creating static instance of factory
  static FileReaderFactory g_FileReaderFactory("file",  
      {
      {"startframe", "0", "First frame to capture."},
      {"loop", "false", "Play beginning once finished."},
      {"grey", "false", "Convert internally to greyscale."},
      {"buffer", "10", "Number of frames to cache in memory"},
      {"frequency", "30", "Capture frequency to emulate if needed"},
      {"name", "FileCam", "Camera name."},
      {"id", "0", "Camera id (serial number or UUID)."}
      } );

  static FileReaderFactory g_FileReaderFactoryS("files",
      {
      {"startframe", "0", "First frame to capture."},
      {"loop", "false", "Play beginning once finished."},
      {"grey", "false", "Convert internally to greyscale."},
      {"buffer", "10", "Number of frames to cache in memory"},
      {"frequency", "30", "Capture frequency to emulate if needed"},
      {"name", "FileCam", "Camera name."},
      {"id", "0", "Camera id (serial number or UUID)."}
      } );

}


