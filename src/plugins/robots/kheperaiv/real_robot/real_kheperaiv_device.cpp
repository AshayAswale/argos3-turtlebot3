#include "real_turtlebot3_device.h"

/****************************************/
/****************************************/

char CRealTurtlebot3Device::m_pchBuffer[100];

/****************************************/
/****************************************/

CRealTurtlebot3Device::CRealTurtlebot3Device(knet_dev_t* pt_dspic) :
   m_ptDSPic(pt_dspic) {
}

/****************************************/
/****************************************/
