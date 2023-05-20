#ifndef REAL_TURTLEBOT3_PROXIMITY_SENSOR_H
#define REAL_TURTLEBOT3_PROXIMITY_SENSOR_H

#include <argos3/plugins/robots/turtlebot3/control_interface/ci_turtlebot3_proximity_sensor.h>
#include <argos3/plugins/robots/turtlebot3/real_robot/real_turtlebot3_device.h>

using namespace argos;

class CRealTurtlebot3ProximitySensor :
   public CCI_Turtlebot3ProximitySensor,
   public CRealTurtlebot3Device {

public:

   CRealTurtlebot3ProximitySensor(knet_dev_t* pt_dspic);
   
   virtual ~CRealTurtlebot3ProximitySensor();

   virtual void Do(Real f_elapsed_time);

};

#endif // REAL_TURTLEBOT3_PROXIMITY_SENSOR_H
