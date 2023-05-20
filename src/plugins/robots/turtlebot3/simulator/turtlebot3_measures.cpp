/**
 * @file <argos3/plugins/robots/turtlebot3/simulator/turtlebot3_measures.h>
 *
 * @author Carlo Pinciroli - <ilpincy@gmail.com>
 */

#include "turtlebot3_measures.h"

/****************************************/
/****************************************/
// Measures from here:
// https://emanual.robotis.com/docs/en/platform/turtlebot3/features/

const Real TURTLEBOT3_BASE_RADIUS    = 0.08;
const Real TURTLEBOT3_BASE_ELEVATION = 0.009;
const Real TURTLEBOT3_BASE_HEIGHT    = 0.192;
const Real TURTLEBOT3_BASE_TOP       = TURTLEBOT3_BASE_ELEVATION + TURTLEBOT3_BASE_HEIGHT;

const Real TURTLEBOT3_WHEEL_RADIUS        = 0.033;
const Real TURTLEBOT3_WHEEL_DISTANCE      = 0.160;
const Real TURTLEBOT3_HALF_WHEEL_DISTANCE = TURTLEBOT3_WHEEL_DISTANCE * 0.5;

const CVector3 TURTLEBOT3_LEDS_OFFSET[3] = {
   CVector3( 0.04,  0.025, TURTLEBOT3_BASE_TOP),
   CVector3(-0.05,  0.000, TURTLEBOT3_BASE_TOP),
   CVector3( 0.04, -0.025, TURTLEBOT3_BASE_TOP)
};

const Real TURTLEBOT3_LIDAR_CENTER_ELEVATION   = -0.01;  // Lidar hight is considered in the robot height
                                                         // Hence, negative value
const Real TURTLEBOT3_LIDAR_ELEVATION          = TURTLEBOT3_BASE_TOP + TURTLEBOT3_LIDAR_CENTER_ELEVATION;
const Real TURTLEBOT3_LIDAR_SENSORS_FAN_RADIUS = TURTLEBOT3_BASE_RADIUS;
const CRadians TURTLEBOT3_LIDAR_ANGLE_SPAN(ToRadians(CDegrees(360.0)));

// Readings from here:
// https://emanual.robotis.com/docs/en/platform/turtlebot3/appendix_lds_01/
const CRange<Real> TURTLEBOT3_LIDAR_SENSORS_RING_RANGE(0.120, 3.500);

/****************************************/
/****************************************/
