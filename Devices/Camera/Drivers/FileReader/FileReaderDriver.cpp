
#include "FileReaderDriver.h"
#include <Mvlpp/Utils.h>  // for FindFiles and PrintError
#include <boost/format.hpp>
#include "opencv/cv.h"	// for Mat structure
#include "opencv2/highgui/highgui.hpp"	// for imread()

using namespace boost;
using namespace std;

///////////////////////////////////////////////////////////////////////////////
FileReaderDriver::FileReaderDriver()
{
}

///////////////////////////////////////////////////////////////////////////////
FileReaderDriver::~FileReaderDriver()
{

}

///////////////////////////////////////////////////////////////////////////////
bool FileReaderDriver::Capture( std::vector<cv::Mat>& vImages )
{

    // allocate images if neccessary
    if( vImages.size() != m_nNumChannels ){
        vImages.resize( m_nNumChannels ); 
    }

    // TODO: this is kinda lame and insecure, change eventually
    char        imgFile[100];
    // now fetch the next set of images
    for( unsigned int ii = 0; ii < m_nNumChannels; ii++ ) {
	sprintf( imgFile, "%s", m_vFileList[ii][m_nCurrentImageIndex].c_str() );
	
	// TODO: this only reads grayscale '0'.. not sure if we need more than that tho
	vImages[ii] = cv::imread( imgFile, 0 );
//	printf("Read %s.\n", imgFile );
    }
    m_nCurrentImageIndex++;
    return true;
}


///////////////////////////////////////////////////////////////////////////////
bool FileReaderDriver::Init()
{
    assert(m_pPropertyMap);
    m_pPropertyMap->PrintPropertyMap();

    m_nNumChannels = m_pPropertyMap->GetProperty<int>( "NumChannels", 0 );
    m_vFileList.resize( m_nNumChannels );
    for( unsigned int ii = 0; ii < m_nNumChannels; ii++ ) {
        std::string sChannelName  = (format("Channel-%d")%ii).str();
        std::string sChannelRegex = m_pPropertyMap->GetProperty( sChannelName, "");

        // Now generate the list of files for each channel
        std::vector< std::string>& vFiles = m_vFileList[ii];
        if( mvl::FindFiles( sChannelRegex, vFiles ) == false ) {
        	cout << "No files found from regexp!" << endl;
            exit(1);
        }
         /*
        printf( "Channel '%s' has %d images\n", sChannelName.c_str(), vFiles.size() );
        for( unsigned int jj = 0; jj < vFiles.size(); jj++ ) {
        	printf( "file[%d] = %s\n", jj, vFiles[jj].c_str() );
        }
        */
    }

    // make sure each channel has the same number of images
    unsigned int nImages = m_vFileList[0].size();
    for( unsigned int ii = 1; ii < m_nNumChannels; ii++ ){
        if( m_vFileList[ii].size() != nImages ){
            mvl::PrintError( "ERROR: uneven number of files\n" );
            exit(1);
        }
    }
    
    m_nCurrentImageIndex = m_pPropertyMap->GetProperty<int>( "StartFrame", 0 );
    
    return true;
}
