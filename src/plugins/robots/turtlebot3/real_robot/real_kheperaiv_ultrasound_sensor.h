#ifndef REAL_TURTLEBOT3_ULTRASOUND_SENSOR_H
#define REAL_TURTLEBOT3_ULTRASOUND_SENSOR_H

#include <argos3/plugins/robots/turtlebot3/control_interface/ci_turtlebot3_ultrasound_sensor.h>
#include <argos3/plugins/robots/turtlebot3/real_robot/real_turtlebot3_device.h>

using namespace argos;

class CRealTurtlebot3UltrasoundSensor :
   public CCI_Turtlebot3UltrasoundSensor,
   public CRealTurtlebot3Device {

public:

   CRealTurtlebot3UltrasoundSensor(knet_dev_t* pt_dspic);
   
   virtual ~CRealTurtlebot3UltrasoundSensor();

   virtual void Do(Real f_elapsed_time);

};

#endif // REAL_TURTLEBOT3_ULTRASOUND_SENSOR_H
