#ifndef REAL_TURTLEBOT3_GROUND_SENSOR_H
#define REAL_TURTLEBOT3_GROUND_SENSOR_H

#include <argos3/plugins/robots/turtlebot3/control_interface/ci_turtlebot3_ground_sensor.h>
#include <argos3/plugins/robots/turtlebot3/real_robot/real_turtlebot3_device.h>

using namespace argos;

class CRealTurtlebot3GroundSensor :
   public CCI_Turtlebot3GroundSensor,
   public CRealTurtlebot3Device {

public:

   CRealTurtlebot3GroundSensor(knet_dev_t* pt_dspic);
   
   virtual ~CRealTurtlebot3GroundSensor();

   virtual void Do(Real f_elapsed_time);
   
};

#endif // REAL_TURTLEBOT3_GROUND_SENSOR_H
