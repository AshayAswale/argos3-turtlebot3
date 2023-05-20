#ifndef BUZZ_CONTROLLER_TURTLEBOT3_H
#define BUZZ_CONTROLLER_TURTLEBOT3_H

#include <buzz/argos/buzz_controller.h>
#include <argos3/plugins/robots/generic/control_interface/ci_differential_steering_actuator.h>
#include <argos3/plugins/robots/generic/control_interface/ci_leds_actuator.h>
#include <argos3/plugins/robots/turtlebot3/control_interface/ci_turtlebot3_ground_sensor.h>
#include <argos3/plugins/robots/turtlebot3/control_interface/ci_turtlebot3_proximity_sensor.h>
#include <argos3/plugins/robots/turtlebot3/control_interface/ci_turtlebot3_light_sensor.h>
#include <argos3/plugins/robots/turtlebot3/control_interface/ci_turtlebot3_ultrasound_sensor.h>
#include <argos3/plugins/robots/turtlebot3/control_interface/ci_turtlebot3_lidar_sensor.h>

using namespace argos;

class CBuzzControllerTurtlebot3 : public CBuzzController {

public:

   struct SWheelTurningParams {
      /*
       * The turning mechanism.
       * The robot can be in three different turning states.
       */
      enum ETurningMechanism
      {
         NO_TURN = 0, // go straight
         SOFT_TURN,   // both wheels are turning forwards, but at different speeds
         HARD_TURN    // wheels are turning with opposite speeds
      } TurningMechanism;
      /*
       * Angular thresholds to change turning state.
       */
      CRadians HardTurnOnAngleThreshold;
      CRadians SoftTurnOnAngleThreshold;
      CRadians NoTurnAngleThreshold;
      /* Maximum wheel speed */
      Real MaxSpeed;

      SWheelTurningParams();
      void Init(TConfigurationNode& t_tree);
   };

public:

   CBuzzControllerTurtlebot3();
   virtual ~CBuzzControllerTurtlebot3();

   virtual void Init(TConfigurationNode& t_node);

   virtual void UpdateSensors();

   void SetWheels(Real f_left_speed, Real f_right_speed);
   void SetWheelSpeedsFromVector(const CVector2& c_heading);
   void SetLEDs(const CColor& c_color);

private:

   virtual buzzvm_state RegisterFunctions();

protected:

   /* Pointer to the differential steering actuator */
   CCI_DifferentialSteeringActuator* m_pcWheels;
   /* Pointer to the LEDs actuator */
   CCI_LEDsActuator* m_pcLEDs;
   /* Pointer to the ground sensor */
   CCI_Turtlebot3GroundSensor* m_pcGround;
   /* Pointer to the proximity sensor */
   CCI_Turtlebot3ProximitySensor* m_pcProximity;
   /* Pointer to the light sensor */
   CCI_Turtlebot3LightSensor* m_pcLight;
   /* Pointer to the ultrasound sensor */
   CCI_Turtlebot3UltrasoundSensor* m_pcUltrasound;
   /* Pointer to the lidar sensor */
   CCI_Turtlebot3LIDARSensor* m_pcLIDAR;

   /* The turning parameters. */
   SWheelTurningParams m_sWheelTurningParams;

};

#endif
