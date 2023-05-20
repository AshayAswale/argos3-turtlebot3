#include "real_turtlebot3_differential_steering_device.h"
#include <argos3/core/utility/logging/argos_log.h>
#include <memory>

/****************************************/
/****************************************/

CRealTurtlebot3DifferentialSteeringDevice* CRealTurtlebot3DifferentialSteeringDevice::GetInstance() {
   static std::unique_ptr<CRealTurtlebot3DifferentialSteeringDevice> pcInstance(
      new CRealTurtlebot3DifferentialSteeringDevice());
   return pcInstance.get();
}

/****************************************/
/****************************************/

CRealTurtlebot3DifferentialSteeringDevice::CRealTurtlebot3DifferentialSteeringDevice() :
   m_fVelocityLeft(0.0),
   m_fVelocityRight(0.0) {}

/****************************************/
/****************************************/
