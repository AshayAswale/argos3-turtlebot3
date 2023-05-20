#ifndef REAL_TURTLEBOT3_LIDAR_SENSOR_H
#define REAL_TURTLEBOT3_LIDAR_SENSOR_H

#include <argos3/plugins/robots/turtlebot3/control_interface/ci_turtlebot3_lidar_sensor.h>
#include <argos3/plugins/robots/turtlebot3/real_robot/real_turtlebot3_device.h>

using namespace argos;

class CRealTurtlebot3LIDARSensor :
   public CCI_Turtlebot3LIDARSensor,
   public CRealTurtlebot3Device {

public:

   CRealTurtlebot3LIDARSensor(knet_dev_t* pt_dspic);
   
   virtual ~CRealTurtlebot3LIDARSensor();

   virtual void Do(Real f_elapsed_time);

   virtual long GetReading(UInt32 un_idx) const;

   virtual size_t GetNumReadings() const;

   virtual void PowerOn();
   
   virtual void PowerOff();

   virtual void LaserOn();

   virtual void LaserOff();
   
private:

   /** LIDAR board handle */
   int m_nDeviceHandle;

   /** Power and Laser states */
   UInt8 m_unPowerLaserState;

};

#endif // REAL_TURTLEBOT3_LIDAR_SENSOR_H
