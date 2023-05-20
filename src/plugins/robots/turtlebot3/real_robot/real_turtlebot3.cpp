#include "real_turtlebot3.h"
#include "real_turtlebot3_differential_steering_actuator.h"
#include "real_turtlebot3_leds_actuator.h"
#include "real_turtlebot3_battery_sensor.h"
#include "real_turtlebot3_camera_sensor.h"
#include "real_turtlebot3_encoder_sensor.h"
#include "real_turtlebot3_ground_sensor.h"
#include "real_turtlebot3_lidar_sensor.h"
#include "real_turtlebot3_proximity_sensor.h"
#include "real_turtlebot3_ultrasound_sensor.h"
#include <argos3/core/utility/logging/argos_log.h>

/****************************************/
/****************************************/

CRealTurtlebot3::CRealTurtlebot3() :
   m_ptDSPic(NULL) {
}

/****************************************/
/****************************************/

CRealTurtlebot3::~CRealTurtlebot3() {
}

/****************************************/
/****************************************/

void CRealTurtlebot3::InitRobot() {
   /* Initialize Turtlebot */
   if(kh4_init(0,NULL) != 0) {
      THROW_ARGOSEXCEPTION("Error initializing the Turtlebot 3 subsystem (kh4_init)");
   }
   /* Open robot socket and store the handle in its pointer */
   m_ptDSPic = knet_open("Turtlebot3:dsPic", KNET_BUS_I2C, 0, NULL);
   if(m_ptDSPic == NULL) {
      THROW_ARGOSEXCEPTION("Error initializing communication with Turtlebot 3 dsPic (knet_open)");
   }
   /* Make sure to start from a clean state */
   /* It's weird to call Destroy() here, but all it does is making
    * sure that at this stage the robot has everything switched off */
   Destroy();
}

/****************************************/
/****************************************/

void CRealTurtlebot3::Destroy() {
   /* Stop wheels */
   kh4_set_speed(0, 0, m_ptDSPic);
   kh4_SetMode(kh4RegIdle, m_ptDSPic );
   /* Switch LEDs off */
   kh4_SetRGBLeds(0,0,0,0,0,0,0,0,0, m_ptDSPic);
   /* Switch ultrasound sensor off */
   kh4_activate_us(0, m_ptDSPic);
}

/****************************************/
/****************************************/

#define MAKE_ACTUATOR(CLASSNAME, TAG)					\
   if(str_name == TAG) {						\
      CLASSNAME* pcAct =						\
         new CLASSNAME(GetDSPic());					\
      m_vecActuators.push_back(pcAct);					\
      LOG << "[INFO] Initialized \"" << TAG << "\" actuator " << std::endl; \
      return pcAct;							\
   }

CCI_Actuator* CRealTurtlebot3::MakeActuator(const std::string& str_name) {
   MAKE_ACTUATOR(CRealTurtlebot3DifferentialSteeringActuator,
                 "differential_steering");
   MAKE_ACTUATOR(CRealTurtlebot3LEDsActuator,
                 "leds");
   return NULL;
}

/****************************************/
/****************************************/

#define MAKE_SENSOR(CLASSNAME, TAG)					\
   if(str_name == TAG) {						\
      CLASSNAME* pcSens =						\
         new CLASSNAME(GetDSPic());					\
      m_vecSensors.push_back(pcSens);					\
      LOG << "[INFO] Initialized \"" << TAG << "\" sensor " << std::endl; \
      return pcSens;							\
   }

CCI_Sensor* CRealTurtlebot3::MakeSensor(const std::string& str_name) {
   MAKE_SENSOR(CRealTurtlebot3BatterySensor,
               "turtlebot3_battery");
   MAKE_SENSOR(CRealTurtlebot3CameraSensor,
               "camera");
   MAKE_SENSOR(CRealTurtlebot3EncoderSensor,
	       "differential_steering");
   MAKE_SENSOR(CRealTurtlebot3GroundSensor,
               "turtlebot3_ground");
   MAKE_SENSOR(CRealTurtlebot3LIDARSensor,
               "turtlebot3_lidar");
   MAKE_SENSOR(CRealTurtlebot3ProximitySensor,
               "turtlebot3_proximity");
   MAKE_SENSOR(CRealTurtlebot3UltrasoundSensor,
               "turtlebot3_ultrasound");
   return NULL;
}

/****************************************/
/****************************************/

void CRealTurtlebot3::Sense(Real f_elapsed_time) {
   for(size_t i = 0; i < m_vecSensors.size(); ++i) {
      m_vecSensors[i]->Do(f_elapsed_time);
   }
}

/****************************************/
/****************************************/

void CRealTurtlebot3::Act(Real f_elapsed_time) {
   for(size_t i = 0; i < m_vecActuators.size(); ++i) {
      m_vecActuators[i]->Do(f_elapsed_time);
   }
}

/****************************************/
/****************************************/
