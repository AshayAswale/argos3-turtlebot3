#include "real_turtlebot3_differential_steering_actuator.h"
#include <argos3/core/utility/logging/argos_log.h>

/****************************************/
/****************************************/

static int  TURTLEBOT3_POSITIONMARGIN             = 20;
static int  TURTLEBOT3_PID_P                      = 10;
static int  TURTLEBOT3_PID_I                      = 5;
static int  TURTLEBOT3_PID_D                      = 1;
static int  TURTLEBOT3_SPEEDPROFILE_ACC_INC       = 3;
static int  TURTLEBOT3_SPEEDPROFILE_ACC_DIV       = 0;
static int  TURTLEBOT3_SPEEDPROFILE_MIN_SPEED_ACC = 20;
static int  TURTLEBOT3_SPEEDPROFILE_MIN_SPEED_DEC = 1;
static int  TURTLEBOT3_SPEEDPROFILE_MAX_SPEED     = 400;
static Real TURTLEBOT3_SPEED_CM_S_TO_PULSES       = 10.0 / KH4_SPEED_TO_MM_S;

/****************************************/
/****************************************/

CRealTurtlebot3DifferentialSteeringActuator::CRealTurtlebot3DifferentialSteeringActuator(knet_dev_t* pt_dspic) :
  CRealTurtlebot3Device(pt_dspic) {
  LOG << "[INFO] Differential Steering actuator parameters:" << std::endl;
  kh4_SetPositionMargin(TURTLEBOT3_POSITIONMARGIN, GetDSPic());
  LOG << "[INFO]   Position Margin = "
      << TURTLEBOT3_POSITIONMARGIN
      << std::endl;
  kh4_ConfigurePID(TURTLEBOT3_PID_P,
		   TURTLEBOT3_PID_I,
		   TURTLEBOT3_PID_D, GetDSPic());
  LOG << "[INFO]   PID factors = <"
      << TURTLEBOT3_PID_P << ", "
      << TURTLEBOT3_PID_I << ", "
      << TURTLEBOT3_PID_D << ">"
      << std::endl;
  kh4_SetSpeedProfile(TURTLEBOT3_SPEEDPROFILE_ACC_INC,
		      TURTLEBOT3_SPEEDPROFILE_ACC_DIV,
		      TURTLEBOT3_SPEEDPROFILE_MIN_SPEED_ACC,
		      TURTLEBOT3_SPEEDPROFILE_MIN_SPEED_DEC,
		      TURTLEBOT3_SPEEDPROFILE_MAX_SPEED,
		      GetDSPic());
  LOG << "[INFO]   Speed profile = <"
      << "acc_inc = "       << TURTLEBOT3_SPEEDPROFILE_ACC_INC << ", "
      << "acc_div = "       << TURTLEBOT3_SPEEDPROFILE_ACC_DIV << ", "
      << "min_speed_acc = " << TURTLEBOT3_SPEEDPROFILE_MIN_SPEED_ACC << ", "
      << "min_speed_dec = " << TURTLEBOT3_SPEEDPROFILE_MIN_SPEED_DEC << ", "
      << "max_speed = "     << TURTLEBOT3_SPEEDPROFILE_MAX_SPEED << ">"
      << std::endl;
  kh4_SetMode(kh4RegSpeedProfile, GetDSPic());
  /* Get data structure common to differential steering (for encoder) */
  m_pcDevice = CRealTurtlebot3DifferentialSteeringDevice::GetInstance();
}
   
/****************************************/
/****************************************/

CRealTurtlebot3DifferentialSteeringActuator::~CRealTurtlebot3DifferentialSteeringActuator() {
  kh4_set_speed(0, 0, GetDSPic());
  kh4_SetMode(kh4RegIdle, GetDSPic());
}
   
/****************************************/
/****************************************/

void CRealTurtlebot3DifferentialSteeringActuator::Do(Real f_elapsed_time) {
  kh4_set_speed(m_fCurrentVelocity[0] * TURTLEBOT3_SPEED_CM_S_TO_PULSES,
		m_fCurrentVelocity[1] * TURTLEBOT3_SPEED_CM_S_TO_PULSES,
		GetDSPic());
}

/****************************************/
/****************************************/

void CRealTurtlebot3DifferentialSteeringActuator::SetLinearVelocity(Real f_left_velocity,
                                                                   Real f_right_velocity) {
  /* The speed is passed in cm/s, but the Turtlebot expects it in mm/s  */
  m_fCurrentVelocity[0] = f_left_velocity;
  m_fCurrentVelocity[1] = f_right_velocity;
  m_pcDevice->SetVelocity(m_fCurrentVelocity);
}

/****************************************/
/****************************************/

