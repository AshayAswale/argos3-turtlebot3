#ifndef REAL_TURTLEBOT3_LEDS_ACTUATOR_H
#define REAL_TURTLEBOT3_LEDS_ACTUATOR_H

#include <argos3/plugins/robots/generic/control_interface/ci_leds_actuator.h>
#include <argos3/plugins/robots/turtlebot3/real_robot/real_turtlebot3_device.h>

using namespace argos;

class CRealTurtlebot3LEDsActuator :
   public CCI_LEDsActuator,
   public CRealTurtlebot3Device {

public:

   CRealTurtlebot3LEDsActuator(knet_dev_t* pt_dspic);
   
   virtual ~CRealTurtlebot3LEDsActuator();

   virtual void Do(Real f_elapsed_time);
   
};

#endif
