#ifndef REAL_TURTLEBOT3_GRIPPER_ACTUATOR_H
#define REAL_TURTLEBOT3_GRIPPER_ACTUATOR_H

#include <argos3/plugins/robots/generic/control_interface/ci_gripper_actuator.h>
#include <argos3/plugins/robots/turtlebot3/real_robot/real_turtlebot3_device.h>

using namespace argos;

class CRealTurtlebot3GripperActuator :
   public CCI_GripperActuator,
   public CRealTurtlebot3Device {

public:

   CRealTurtlebot3GripperActuator(knet_dev_t* pt_dspic);
   
   virtual ~CRealTurtlebot3GripperActuator();

   virtual void Do(Real f_elapsed_time);
   
private:

   knet_dev_t* m_ptArm;
   knet_dev_t* m_ptGripper;

};

#endif
