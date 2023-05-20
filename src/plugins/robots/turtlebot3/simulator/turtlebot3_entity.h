/**
 * @file <argos3/plugins/robots/turtlebot3/simulator/turtlebot3_entity.h>
 *
 * @author Carlo Pinciroli - <ilpincy@gmail.com>
 */

#ifndef TURTLEBOT3_ENTITY_H
#define TURTLEBOT3_ENTITY_H

namespace argos {
   class CBatteryEquippedEntity;
   class CTurtlebot3Entity;
   class CProximitySensorEquippedEntity;
}

#include <argos3/core/simulator/entity/composable_entity.h>
#include <argos3/plugins/simulator/entities/wheeled_entity.h>

namespace argos {

   class CTurtlebot3Entity : public CComposableEntity {

   public:

      ENABLE_VTABLE();

   public:

      CTurtlebot3Entity();

      CTurtlebot3Entity(const std::string& str_id,
                       const std::string& str_controller_id,
                       const CVector3& c_position = CVector3(),
                       const CQuaternion& c_orientation = CQuaternion(),
                       Real f_rab_range = 3.0f,
                       size_t un_rab_data_size = 50,
                       const std::string& str_bat_model = "");
      
      virtual void Init(TConfigurationNode& t_tree);
      virtual void Reset();
      virtual void Destroy();

      virtual void UpdateComponents();
      
      inline CControllableEntity& GetControllableEntity() {
         return *m_pcControllableEntity;
      }

      inline CEmbodiedEntity& GetEmbodiedEntity() {
         return *m_pcEmbodiedEntity;
      }

      inline CProximitySensorEquippedEntity& GetLIDARSensorEquippedEntity() {
         return *m_pcLIDARSensorEquippedEntity;
      }

      inline CWheeledEntity& GetWheeledEntity() {
         return *m_pcWheeledEntity;
      }

      inline CBatteryEquippedEntity& GetBatterySensorEquippedEntity() {
          return *m_pcBatteryEquippedEntity;
      }

      virtual std::string GetTypeDescription() const {
         return "turtlebot3";
      }

   private:

      // void SetLEDPosition();

   private:

      CControllableEntity*            m_pcControllableEntity;
      CEmbodiedEntity*                m_pcEmbodiedEntity;
      CProximitySensorEquippedEntity* m_pcLIDARSensorEquippedEntity;
      CWheeledEntity*                 m_pcWheeledEntity;
      CBatteryEquippedEntity*         m_pcBatteryEquippedEntity;
      // CGroundSensorEquippedEntity*    m_pcGroundSensorEquippedEntity;
      // CLEDEquippedEntity*             m_pcLEDEquippedEntity;
      // CLightSensorEquippedEntity*     m_pcLightSensorEquippedEntity;
      // CProximitySensorEquippedEntity* m_pcProximitySensorEquippedEntity;
      // CProximitySensorEquippedEntity* m_pcUltrasoundSensorEquippedEntity;
      // CRABEquippedEntity*             m_pcRABEquippedEntity;
   };

}

#endif
