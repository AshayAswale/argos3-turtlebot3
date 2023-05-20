#include "real_turtlebot3_lidar_sensor.h"

/****************************************/
/****************************************/

/* Device where the LRF is connected: here USB port */
static char  TURTLEBOT3_LRF_DEVICE[]    = "/dev/ttyACM0";
static UInt8 TURTLEBOT3_POWERON_LASERON = 3;

/****************************************/
/****************************************/

CRealTurtlebot3LIDARSensor::CRealTurtlebot3LIDARSensor(knet_dev_t* pt_dspic) :
   CRealTurtlebot3Device(pt_dspic),
   m_unPowerLaserState(TURTLEBOT3_POWERON_LASERON) {
   /* Initialize LIDAR */
   m_nDeviceHandle = kb_lrf_Init(TURTLEBOT3_LRF_DEVICE);
   if(m_nDeviceHandle < 0) {
      kb_lrf_Power_Off();
      THROW_ARGOSEXCEPTION("Can't initialize LIDAR");
   }
   if(kb_lrf_GetDistances(m_nDeviceHandle) < 0) {
      kb_lrf_Close(m_nDeviceHandle);
      kb_lrf_Power_Off();
      THROW_ARGOSEXCEPTION("Can't get distance readings from LIDAR");
   }
}

/****************************************/
/****************************************/

CRealTurtlebot3LIDARSensor::~CRealTurtlebot3LIDARSensor() {
   kb_lrf_Close(m_nDeviceHandle);
   kb_lrf_Power_Off();
}

/****************************************/
/****************************************/

void CRealTurtlebot3LIDARSensor::Do(Real f_elapsed_time) {
   if(m_unPowerLaserState != TURTLEBOT3_POWERON_LASERON)
      return;
   kb_lrf_GetDistances(m_nDeviceHandle);
}

/****************************************/
/****************************************/

long CRealTurtlebot3LIDARSensor::GetReading(UInt32 un_idx) const {
   return kb_lrf_DistanceData[LRF_DATA_NB - un_idx - 1];
}

/****************************************/
/****************************************/

size_t CRealTurtlebot3LIDARSensor::GetNumReadings() const {
   return LRF_DATA_NB;
}

/****************************************/
/****************************************/

void CRealTurtlebot3LIDARSensor::PowerOn() {
   m_unPowerLaserState = m_unPowerLaserState | 0x1;
   kb_lrf_Power_On();
}

/****************************************/
/****************************************/

void CRealTurtlebot3LIDARSensor::PowerOff() {
   m_unPowerLaserState = m_unPowerLaserState & 0xFE;
   kb_lrf_Power_Off();
}

/****************************************/
/****************************************/

void CRealTurtlebot3LIDARSensor::LaserOn() {
   m_unPowerLaserState = m_unPowerLaserState | 0x2;
   kb_lrf_Laser_On(m_nDeviceHandle);
}

/****************************************/
/****************************************/

void CRealTurtlebot3LIDARSensor::LaserOff() {
   m_unPowerLaserState = m_unPowerLaserState & 0xFD;
   kb_lrf_Laser_Off(m_nDeviceHandle);
}

/****************************************/
/****************************************/
