/**
 * @file <argos3/plugins/robots/turtlebot3/simulator/turtlebot3_ultrasound_default_sensor.h>
 *
 * @author Carlo Pinciroli - <ilpincy@gmail.com>
 */

#ifndef TURTLEBOT3_ULTRASOUND_DEFAULT_SENSOR_H
#define TURTLEBOT3_ULTRASOUND_DEFAULT_SENSOR_H

#include <string>
#include <map>

namespace argos {
   class CTurtlebot3UltrasoundDefaultSensor;
}

#include <argos3/plugins/robots/turtlebot3/control_interface/ci_turtlebot3_ultrasound_sensor.h>
#include <argos3/plugins/robots/generic/simulator/proximity_default_sensor.h>

namespace argos {

   class CTurtlebot3UltrasoundDefaultSensor : public CCI_Turtlebot3UltrasoundSensor,
                                             public CSimulatedSensor {

   public:

      CTurtlebot3UltrasoundDefaultSensor();

      virtual ~CTurtlebot3UltrasoundDefaultSensor();

      virtual void SetRobot(CComposableEntity& c_entity);

      virtual void Init(TConfigurationNode& t_tree);

      virtual void Update();

      virtual void Reset();

   private:

      CProximityDefaultSensor* m_pcUltrasoundImpl;

   };

}

#endif
