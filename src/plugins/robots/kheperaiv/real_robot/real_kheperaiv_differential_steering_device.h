#ifndef REAL_TURTLEBOT3_DIFFERENTIAL_STEERING_DEVICE_H
#define REAL_TURTLEBOT3_DIFFERENTIAL_STEERING_DEVICE_H

#include <argos3/core/utility/datatypes/datatypes.h>

using namespace argos;

class CRealTurtlebot3DifferentialSteeringDevice {

public:

   static CRealTurtlebot3DifferentialSteeringDevice* GetInstance();

   ~CRealTurtlebot3DifferentialSteeringDevice() {}

   inline void SetVelocity(Real* f_velocity) {
      m_fVelocityLeft = f_velocity[0];
      m_fVelocityRight = f_velocity[1];
   }

   inline Real GetVelocityLeft() const {
      return m_fVelocityLeft;
   }

   inline Real GetVelocityRight() const {
      return m_fVelocityRight;
   }

private:

   CRealTurtlebot3DifferentialSteeringDevice();
   
private:

   static CRealTurtlebot3DifferentialSteeringDevice* m_pcInstance;
   Real m_fVelocityLeft;
   Real m_fVelocityRight;
};

#endif
