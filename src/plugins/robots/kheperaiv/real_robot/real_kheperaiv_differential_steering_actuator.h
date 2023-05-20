#ifndef REAL_TURTLEBOT3_DIFFERENTIAL_STEERING_ACTUATOR_H
#define REAL_TURTLEBOT3_DIFFERENTIAL_STEERING_ACTUATOR_H

#include <argos3/plugins/robots/generic/control_interface/ci_differential_steering_actuator.h>
#include <argos3/plugins/robots/turtlebot3/real_robot/real_turtlebot3_device.h>
#include <argos3/plugins/robots/turtlebot3/real_robot/real_turtlebot3_differential_steering_device.h>

using namespace argos;

class CRealTurtlebot3DifferentialSteeringActuator :
   public CCI_DifferentialSteeringActuator,
   public CRealTurtlebot3Device {

public:

   CRealTurtlebot3DifferentialSteeringActuator(knet_dev_t* pt_dspic);
   
   virtual ~CRealTurtlebot3DifferentialSteeringActuator();

   virtual void Do(Real f_elapsed_time);
   
   virtual void SetLinearVelocity(Real f_left_velocity,
                                  Real f_right_velocity);

private:

  CRealTurtlebot3DifferentialSteeringDevice* m_pcDevice;
};

#endif
