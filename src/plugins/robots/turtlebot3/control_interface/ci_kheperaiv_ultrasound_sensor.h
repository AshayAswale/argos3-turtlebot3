/**
 * @file <argos3/plugins/robots/turtlebot3/control_interface/ci_turtlebot3_ultrasound_sensor.h>
 *
 * @brief This file provides the definition of the Turtlebot 3 ultrasound sensor.
 *
 * This file provides the definition of the Turtlebot 3 ultrasound sensor.
 * The sensors are evenly spaced on a ring around the base of the robot.
 * The readings are normalized between 0 and 1, and are in the following
 * order (seeing the robot from TOP, the camera is the FRONT):
 * 
 *      front
 * 
 * l      0      r
 * e    1   4    i
 * f  2       3  g
 * t             h
 *               t
 * 
 *       back   
 *
 * @author Carlo Pinciroli <ilpincy@gmail.com>
 */

#ifndef CCI_TURTLEBOT3_ULTRASOUND_SENSOR_H
#define CCI_TURTLEBOT3_ULTRASOUND_SENSOR_H

namespace argos {
   class CCI_Turtlebot3UltrasoundSensor;
}

#include <argos3/core/control_interface/ci_sensor.h>
#include <argos3/core/utility/math/angles.h>

namespace argos {

   class CCI_Turtlebot3UltrasoundSensor : public CCI_Sensor {

   public:

      struct SReading {
         Real Value;
         CRadians Angle;

         SReading() :
            Value(0.0f) {}

         SReading(Real f_value,
                  const CRadians& c_angle) :
            Value(f_value),
            Angle(c_angle) {}
      };

      typedef std::vector<SReading> TReadings;

   public:

      /**
       * Class constructor
       */
      CCI_Turtlebot3UltrasoundSensor();

      /**
       * Class destructor
       */
      virtual ~CCI_Turtlebot3UltrasoundSensor() {}

      /**
       * Returns the readings of this sensor
       */
      const TReadings& GetReadings() const;

#ifdef ARGOS_WITH_LUA
      virtual void CreateLuaState(lua_State* pt_lua_state);

      virtual void ReadingsToLuaState(lua_State* pt_lua_state);
#endif

   protected:

      TReadings m_tReadings;

   };

   std::ostream& operator<<(std::ostream& c_os, const CCI_Turtlebot3UltrasoundSensor::SReading& s_reading);
   std::ostream& operator<<(std::ostream& c_os, const CCI_Turtlebot3UltrasoundSensor::TReadings& t_readings);

}

#endif
