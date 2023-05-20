#include "real_turtlebot3_encoder_sensor.h"
#include <argos3/core/utility/math/general.h>

const Real TURTLEBOT3_WHEEL_DISTANCE = 0.1054;
const int  TURTLEBOT3_ENCODER_MAX = 19456; // how many ticks in a full rotation
const Real TURTLEBOT3_ENCODER_PULSE_TO_CM = KH4_PULSE_TO_MM / 10.0f;

/****************************************/
/****************************************/

CRealTurtlebot3EncoderSensor::CRealTurtlebot3EncoderSensor(knet_dev_t* pt_dspic) :
   CRealTurtlebot3Device(pt_dspic) {
   /* Set the axis length */
   m_sReading.WheelAxisLength = TURTLEBOT3_WHEEL_DISTANCE;
   /* Get initial tick values (i.e., initial wheel rotation) */
   kh4_get_position(&m_nEncoderLeft, &m_nEncoderRight, GetDSPic());
   /* Get data structure common to differential steering (for steering) */
   m_pcDevice = CRealTurtlebot3DifferentialSteeringDevice::GetInstance();
}

/****************************************/
/****************************************/

CRealTurtlebot3EncoderSensor::~CRealTurtlebot3EncoderSensor() {
}

/****************************************/
/****************************************/

void CRealTurtlebot3EncoderSensor::Do(Real f_elapsed_time) {
   /*
    * The encoder gives us the current rotation of the wheels (in ticks)
    * To know the distance covered, we consider the difference between the old rotation and the new rotation (in ticks)
    * In calculating the difference, we need to mind the fact that the sign of the velocity matters!
    * The calculated difference is then reported to modulo TURTLEBOT3_ENCODER_MAX
    * And finally converted to cm (as expected by ARGoS)
    */
   /* Get current rotation in ticks */
   int nCurLeft, nCurRight;
   int nDiffLeft, nDiffRight;
   kh4_get_position(&nCurLeft, &nCurRight, GetDSPic());
   /* Calculate difference with value */
   nDiffLeft =
      (Sign(m_pcDevice->GetVelocityLeft()) *
       (nCurLeft - m_nEncoderLeft))
      % TURTLEBOT3_ENCODER_MAX;
   nDiffRight =
      (Sign(m_pcDevice->GetVelocityRight()) *
       (nCurRight - m_nEncoderRight))
      % TURTLEBOT3_ENCODER_MAX;
   /* Save current values for future loops */
   m_nEncoderLeft = nCurLeft;
   m_nEncoderRight = nCurRight;
   /* Convert this to cm to get the final readings */
   m_sReading.CoveredDistanceLeftWheel =
      nDiffLeft * TURTLEBOT3_ENCODER_PULSE_TO_CM;
   m_sReading.CoveredDistanceRightWheel =
      nDiffRight * TURTLEBOT3_ENCODER_PULSE_TO_CM;
   m_sReading.VelocityLeftWheel =
      Sign(m_pcDevice->GetVelocityLeft()) *
      m_sReading.CoveredDistanceLeftWheel /
      f_elapsed_time;
   m_sReading.VelocityRightWheel =
      Sign(m_pcDevice->GetVelocityRight()) *
      m_sReading.CoveredDistanceRightWheel /
      f_elapsed_time;
}

/****************************************/
/****************************************/
