/**
 * @file <argos3/plugins/robots/turtlebot3/simulator/turtlebot3_measures.h>
 *
 * @author Carlo Pinciroli - <ilpincy@gmail.com>
 */

#ifndef TURTLEBOT3_MEASURES_H
#define TURTLEBOT3_MEASURES_H

#include <argos3/core/utility/datatypes/datatypes.h>
#include <argos3/core/utility/math/vector2.h>
#include <argos3/core/utility/math/vector3.h>

using namespace argos;

extern const Real TURTLEBOT3_BASE_RADIUS;
extern const Real TURTLEBOT3_BASE_ELEVATION;
extern const Real TURTLEBOT3_BASE_HEIGHT;
extern const Real TURTLEBOT3_BASE_TOP;

extern const Real TURTLEBOT3_WHEEL_RADIUS;
extern const Real TURTLEBOT3_WHEEL_DISTANCE;
extern const Real TURTLEBOT3_HALF_WHEEL_DISTANCE;

extern const Real TURTLEBOT3_IR_SENSORS_RING_ELEVATION;
extern const Real TURTLEBOT3_IR_SENSORS_RING_RADIUS;
extern const Real TURTLEBOT3_IR_SENSORS_RING_RANGE;

extern const Real TURTLEBOT3_ULTRASOUND_SENSORS_RING_ELEVATION;
extern const Real TURTLEBOT3_ULTRASOUND_SENSORS_RING_RADIUS;
extern const CRange<Real> TURTLEBOT3_ULTRASOUND_SENSORS_RING_RANGE;

extern const CVector2 TURTLEBOT3_IR_SENSORS_GROUND_OFFSET[4];

extern const CVector3 TURTLEBOT3_LEDS_OFFSET[3];

extern const Real TURTLEBOT3_LIDAR_ELEVATION;
extern const Real TURTLEBOT3_LIDAR_SENSORS_FAN_RADIUS;
extern const CRadians TURTLEBOT3_LIDAR_ANGLE_SPAN;
extern const CRange<Real> TURTLEBOT3_LIDAR_SENSORS_RING_RANGE;

#endif
