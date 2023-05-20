/**
 * @file <argos3/plugins/robots/turtlebot3/simulator/turtlebot3_proximity_default_sensor.h>
 *
 * @author Carlo Pinciroli - <ilpincy@gmail.com>
 */

#ifndef TURTLEBOT3_PROXIMITY_DEFAULT_SENSOR_H
#define TURTLEBOT3_PROXIMITY_DEFAULT_SENSOR_H

#include <string>
#include <map>

namespace argos {
   class CTurtlebot3ProximityDefaultSensor;
}

#include <argos3/plugins/robots/turtlebot3/control_interface/ci_turtlebot3_proximity_sensor.h>
#include <argos3/plugins/robots/generic/simulator/proximity_default_sensor.h>

namespace argos {

   class CTurtlebot3ProximityDefaultSensor : public CCI_Turtlebot3ProximitySensor,
                                            public CSimulatedSensor {

   public:

      CTurtlebot3ProximityDefaultSensor();

      virtual ~CTurtlebot3ProximityDefaultSensor();

      virtual void SetRobot(CComposableEntity& c_entity);

      virtual void Init(TConfigurationNode& t_tree);

      virtual void Update();

      virtual void Reset();

   private:

      CProximityDefaultSensor* m_pcProximityImpl;

   };

}

#endif
