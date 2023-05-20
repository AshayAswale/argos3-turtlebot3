#include "real_turtlebot3_gripper_actuator.h"

/****************************************/
/****************************************/

CRealTurtlebot3GripperActuator::CRealTurtlebot3GripperActuator(knet_dev_t* pt_dspic) :
   CRealTurtlebot3Device(pt_dspic) {
   /* Initialize gripper */
   kgripper_init();
   /* Open sockets to gripper components */
   m_ptArm = knet_open( "Kgripper:Arm", KNET_BUS_I2C, 0, NULL);
   if(m_ptArm == NULL) {
      THROW_ARGOSEXCEPTION("Can't connect to Turtlebot 3 arm");
   }
   m_ptGripper = knet_open( "Kgripper:Gripper", KNET_BUS_I2C, 0, NULL);
   if(m_ptArm == NULL) {
      THROW_ARGOSEXCEPTION("Can't connect to Turtlebot 3 gripper");
   }
}
   
/****************************************/
/****************************************/

CRealTurtlebot3GripperActuator::~CRealTurtlebot3GripperActuator() {
}
   
/****************************************/
/****************************************/

void CRealTurtlebot3GripperActuator::Do(Real f_elapsed_time) {
}

/****************************************/
/****************************************/
