/**
 * @file <argos3/plugins/robots/turtlebot3/simulator/turtlebot3_lidar_default_sensor.h>
 *
 * @author Carlo Pinciroli - <ilpincy@gmail.com>
 */

#ifndef TURTLEBOT3_LIDAR_DEFAULT_SENSOR_H
#define TURTLEBOT3_LIDAR_DEFAULT_SENSOR_H

#include <string>
#include <map>

namespace argos {
   class CTurtlebot3LIDARDefaultSensor;
}

#include <argos3/plugins/robots/turtlebot3/control_interface/ci_turtlebot3_lidar_sensor.h>
#include <argos3/plugins/robots/generic/simulator/proximity_default_sensor.h>

namespace argos {

   class CTurtlebot3LIDARDefaultSensor : public CCI_Turtlebot3LIDARSensor,
                                        public CSimulatedSensor {

   public:

      CTurtlebot3LIDARDefaultSensor();

      virtual ~CTurtlebot3LIDARDefaultSensor();

      virtual void SetRobot(CComposableEntity& c_entity);

      virtual void Init(TConfigurationNode& t_tree);

      virtual void Update();

      virtual void Reset();

      virtual void Destroy();

      virtual long GetReading(UInt32 un_idx) const;

      virtual size_t GetNumReadings() const;

      virtual void PowerOn();

      virtual void PowerOff();

      virtual void LaserOn();

      virtual void LaserOff();

   private:

      /** Readings of the LIDAR sensor */
      long int* m_pnReadings;

      /** Number of readings of the LIDAR sensor */
      size_t m_unNumReadings;

      /** Power and Laser states */
      UInt8 m_unPowerLaserState;

      /** Reference to embodied entity associated to this sensor */
      CEmbodiedEntity* m_pcEmbodiedEntity;

      /** Reference to proximity sensor equipped entity associated to this sensor */
      CProximitySensorEquippedEntity* m_pcProximityEntity;

      /** Reference to controllable entity associated to this sensor */
      CControllableEntity* m_pcControllableEntity;

      /** Flag to show rays in the simulator */
      bool m_bShowRays;

      /** Random number generator */
      CRandom::CRNG* m_pcRNG;

      /** Whether to add noise or not */
      bool m_bAddNoise;

      /** Noise range */
      CRange<Real> m_cNoiseRange;

      /** Reference to the space */
      CSpace& m_cSpace;
   };

}

#endif
