#ifndef REAL_TURTLEBOT3_ENCODER_SENSOR_H
#define REAL_TURTLEBOT3_ENCODER_SENSOR_H

#include <argos3/plugins/robots/generic/control_interface/ci_differential_steering_sensor.h>
#include <argos3/plugins/robots/turtlebot3/real_robot/real_turtlebot3_device.h>
#include <argos3/plugins/robots/turtlebot3/real_robot/real_turtlebot3_differential_steering_device.h>

using namespace argos;

class CRealTurtlebot3EncoderSensor :
   public CCI_DifferentialSteeringSensor,
   public CRealTurtlebot3Device {

public:

   CRealTurtlebot3EncoderSensor(knet_dev_t* pt_dspic);
   
   virtual ~CRealTurtlebot3EncoderSensor();

   virtual void Do(Real f_elapsed_time);

private:

   int m_nEncoderLeft;
   int m_nEncoderRight;
   CRealTurtlebot3DifferentialSteeringDevice* m_pcDevice;

};

#endif // REAL_TURTLEBOT3_ENCODER_SENSOR_H
