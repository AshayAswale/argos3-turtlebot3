#ifndef REAL_TURTLEBOT3_BATTERY_SENSOR_H
#define REAL_TURTLEBOT3_BATTERY_SENSOR_H

#include <argos3/plugins/robots/generic/control_interface/ci_battery_sensor.h>
#include <argos3/plugins/robots/turtlebot3/real_robot/real_turtlebot3_device.h>

using namespace argos;

class CRealTurtlebot3BatterySensor :
   public CCI_BatterySensor,
   public CRealTurtlebot3Device {

public:

   CRealTurtlebot3BatterySensor(knet_dev_t* pt_dspic);
   
   virtual ~CRealTurtlebot3BatterySensor();

   virtual void Do(Real f_elapsed_time);
   
};

#endif // REAL_TURTLEBOT3_BATTERY_SENSOR_H
