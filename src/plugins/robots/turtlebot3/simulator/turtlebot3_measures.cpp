/**
 * @file <argos3/plugins/robots/turtlebot3/simulator/turtlebot3_measures.h>
 *
 * @author Carlo Pinciroli - <ilpincy@gmail.com>
 */

#include "turtlebot3_measures.h"

/****************************************/
/****************************************/

const Real TURTLEBOT3_BASE_RADIUS    = 0.0704;
const Real TURTLEBOT3_BASE_ELEVATION = 0.0047;
const Real TURTLEBOT3_BASE_HEIGHT    = 0.053;
const Real TURTLEBOT3_BASE_TOP       = TURTLEBOT3_BASE_ELEVATION + TURTLEBOT3_BASE_HEIGHT;

const Real TURTLEBOT3_WHEEL_RADIUS        = 0.021;
const Real TURTLEBOT3_WHEEL_DISTANCE      = 0.1054;
const Real TURTLEBOT3_HALF_WHEEL_DISTANCE = TURTLEBOT3_WHEEL_DISTANCE * 0.5;

const Real TURTLEBOT3_IR_SENSORS_RING_ELEVATION = 0.0145;
const Real TURTLEBOT3_IR_SENSORS_RING_RADIUS    = TURTLEBOT3_BASE_RADIUS;
const Real TURTLEBOT3_IR_SENSORS_RING_RANGE     = 0.12;

const Real TURTLEBOT3_ULTRASOUND_SENSORS_RING_ELEVATION = 0.0145;
const Real TURTLEBOT3_ULTRASOUND_SENSORS_RING_RADIUS    = TURTLEBOT3_BASE_RADIUS;
const CRange<Real> TURTLEBOT3_ULTRASOUND_SENSORS_RING_RANGE(0.25, 2.0);

const CVector2 TURTLEBOT3_IR_SENSORS_GROUND_OFFSET[4] = {
   CVector2(0.06140,  0.01),
   CVector2(0.02060,  0.059),
   CVector2(0.02060, -0.059),
   CVector2(0.06140, -0.01)
};

const CVector3 TURTLEBOT3_LEDS_OFFSET[3] = {
   CVector3( 0.04,  0.025, TURTLEBOT3_BASE_TOP),
   CVector3(-0.05,  0.000, TURTLEBOT3_BASE_TOP),
   CVector3( 0.04, -0.025, TURTLEBOT3_BASE_TOP)
};

const Real TURTLEBOT3_LIDAR_CENTER_ELEVATION   = 0.084;
const Real TURTLEBOT3_LIDAR_ELEVATION          = TURTLEBOT3_BASE_TOP + TURTLEBOT3_LIDAR_CENTER_ELEVATION;
const Real TURTLEBOT3_LIDAR_SENSORS_FAN_RADIUS = TURTLEBOT3_BASE_RADIUS;
const CRadians TURTLEBOT3_LIDAR_ANGLE_SPAN(ToRadians(CDegrees(210.0)));
const CRange<Real> TURTLEBOT3_LIDAR_SENSORS_RING_RANGE(0.02, 4.0);

/****************************************/
/****************************************/
