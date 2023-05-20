#include "real_turtlebot3_battery_sensor.h"

/****************************************/
/****************************************/

CRealTurtlebot3BatterySensor::CRealTurtlebot3BatterySensor(knet_dev_t* pt_dspic) :
   CRealTurtlebot3Device(pt_dspic) {
}
   
/****************************************/
/****************************************/

CRealTurtlebot3BatterySensor::~CRealTurtlebot3BatterySensor() {
}

/****************************************/
/****************************************/

void CRealTurtlebot3BatterySensor::Do(Real f_elapsed_time) {
   kh4_battery_status(GetBuffer(), GetDSPic());
   m_sReading.AvailableCharge = GetBuffer()[3] / 100.0;
   m_sReading.TimeLeft = -1.0; // TODO
}

/****************************************/
/****************************************/
