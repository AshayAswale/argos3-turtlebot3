#
# turtlebot3 headers
#
# argos3/plugins/robots/turtlebot3/control_interface
set(ARGOS3_HEADERS_PLUGINS_ROBOTS_TURTLEBOT3_CONTROLINTERFACE
  control_interface/ci_turtlebot3_camera_sensor.h
  control_interface/ci_turtlebot3_encoder_sensor.h
  control_interface/ci_turtlebot3_ground_sensor.h
  control_interface/ci_turtlebot3_lidar_sensor.h
  control_interface/ci_turtlebot3_light_sensor.h
  control_interface/ci_turtlebot3_proximity_sensor.h
  control_interface/ci_turtlebot3_ultrasound_sensor.h)
if(BUZZ_FOUND)
  set(ARGOS3_HEADERS_PLUGINS_ROBOTS_TURTLEBOT3_CONTROLINTERFACE
    ${ARGOS3_HEADERS_PLUGINS_ROBOTS_TURTLEBOT3_CONTROLINTERFACE}
    control_interface/buzz_controller_turtlebot3.h)
endif(BUZZ_FOUND)
# argos3/plugins/robots/turtlebot3/simulator
if(ARGOS_BUILD_FOR_SIMULATOR)
  set(ARGOS3_HEADERS_PLUGINS_ROBOTS_TURTLEBOT3_SIMULATOR
    simulator/dynamics2d_turtlebot3_model.h
    simulator/turtlebot3_entity.h
    simulator/turtlebot3_light_rotzonly_sensor.h
    simulator/turtlebot3_measures.h
    simulator/turtlebot3_ground_rotzonly_sensor.h
    simulator/turtlebot3_lidar_default_sensor.h
    simulator/turtlebot3_proximity_default_sensor.h
    simulator/turtlebot3_ultrasound_default_sensor.h)
endif(ARGOS_BUILD_FOR_SIMULATOR)
# argos3/plugins/robots/turtlebot3/real_robot
if(ARGOS_BUILD_FOR STREQUAL "khiv")
  set(ARGOS3_HEADERS_PLUGINS_ROBOTS_TURTLEBOT3_REALROBOT
    real_robot/real_turtlebot3.h
    real_robot/real_turtlebot3_device.h
    real_robot/real_turtlebot3_differential_steering_device.h
    real_robot/real_turtlebot3_differential_steering_actuator.h
    #real_robot/real_turtlebot3_gripper_actuator.h
    real_robot/real_turtlebot3_leds_actuator.h
    real_robot/real_turtlebot3_battery_sensor.h
    real_robot/real_turtlebot3_camera_sensor.h
    real_robot/real_turtlebot3_encoder_sensor.h
    real_robot/real_turtlebot3_ground_sensor.h
    real_robot/real_turtlebot3_lidar_sensor.h
    real_robot/real_turtlebot3_proximity_sensor.h
    real_robot/real_turtlebot3_ultrasound_sensor.h)
endif(ARGOS_BUILD_FOR STREQUAL "khiv")

#
# turtlebot3 sources
#
set(ARGOS3_SOURCES_PLUGINS_ROBOTS_TURTLEBOT3
  ${ARGOS3_HEADERS_PLUGINS_ROBOTS_TURTLEBOT3_CONTROLINTERFACE}
  control_interface/ci_turtlebot3_camera_sensor.cpp
  control_interface/ci_turtlebot3_encoder_sensor.cpp
  control_interface/ci_turtlebot3_ground_sensor.cpp
  control_interface/ci_turtlebot3_lidar_sensor.cpp
  control_interface/ci_turtlebot3_light_sensor.cpp
  control_interface/ci_turtlebot3_proximity_sensor.cpp
  control_interface/ci_turtlebot3_ultrasound_sensor.cpp)
if(BUZZ_FOUND)
  set(ARGOS3_SOURCES_PLUGINS_ROBOTS_TURTLEBOT3
    ${ARGOS3_SOURCES_PLUGINS_ROBOTS_TURTLEBOT3}
    control_interface/buzz_controller_turtlebot3.cpp)
endif(BUZZ_FOUND)

if(ARGOS_BUILD_FOR_SIMULATOR)
  set(ARGOS3_SOURCES_PLUGINS_ROBOTS_TURTLEBOT3
    ${ARGOS3_SOURCES_PLUGINS_ROBOTS_TURTLEBOT3}
    ${ARGOS3_HEADERS_PLUGINS_ROBOTS_TURTLEBOT3_SIMULATOR}
    simulator/dynamics2d_turtlebot3_model.cpp
    simulator/turtlebot3_entity.cpp
    simulator/turtlebot3_light_rotzonly_sensor.cpp
    simulator/turtlebot3_measures.cpp
    simulator/turtlebot3_ground_rotzonly_sensor.cpp
    simulator/turtlebot3_lidar_default_sensor.cpp
    simulator/turtlebot3_proximity_default_sensor.cpp
    simulator/turtlebot3_ultrasound_default_sensor.cpp)
  # Compile the graphical visualization only if the necessary libraries have been found
  if(ARGOS_QTOPENGL_FOUND)
    include_directories(${ARGOS_QTOPENGL_INCLUDE_DIRS})
    set(ARGOS3_HEADERS_PLUGINS_ROBOTS_TURTLEBOT3_SIMULATOR
      ${ARGOS3_HEADERS_PLUGINS_ROBOTS_TURTLEBOT3_SIMULATOR}
      simulator/qtopengl_turtlebot3.h)
    set(ARGOS3_SOURCES_PLUGINS_ROBOTS_TURTLEBOT3
      ${ARGOS3_SOURCES_PLUGINS_ROBOTS_TURTLEBOT3}
      simulator/qtopengl_turtlebot3.h
      simulator/qtopengl_turtlebot3.cpp)
  endif(ARGOS_QTOPENGL_FOUND)
endif(ARGOS_BUILD_FOR_SIMULATOR)
if(ARGOS_BUILD_FOR STREQUAL "khiv")
  set(ARGOS3_SOURCES_PLUGINS_ROBOTS_TURTLEBOT3
    ${ARGOS3_SOURCES_PLUGINS_ROBOTS_TURTLEBOT3}
    ${ARGOS3_HEADERS_PLUGINS_ROBOTS_TURTLEBOT3_REALROBOT}
    real_robot/real_turtlebot3.cpp
    real_robot/real_turtlebot3_device.cpp
    real_robot/real_turtlebot3_differential_steering_device.cpp
    real_robot/real_turtlebot3_differential_steering_actuator.cpp
    #real_robot/real_turtlebot3_gripper_actuator.cpp
    real_robot/real_turtlebot3_leds_actuator.cpp
    real_robot/real_turtlebot3_battery_sensor.cpp
    real_robot/real_turtlebot3_camera_sensor.cpp
    real_robot/real_turtlebot3_encoder_sensor.cpp
    real_robot/real_turtlebot3_ground_sensor.cpp
    real_robot/real_turtlebot3_lidar_sensor.cpp
    real_robot/real_turtlebot3_proximity_sensor.cpp
    real_robot/real_turtlebot3_ultrasound_sensor.cpp)
endif(ARGOS_BUILD_FOR STREQUAL "khiv")

#
# Create turtlebot3 plugin
#
add_library(argos3plugin_${ARGOS_BUILD_FOR}_turtlebot3 SHARED ${ARGOS3_SOURCES_PLUGINS_ROBOTS_TURTLEBOT3})
target_link_libraries(argos3plugin_${ARGOS_BUILD_FOR}_turtlebot3
  argos3plugin_${ARGOS_BUILD_FOR}_genericrobot)
if(ARGOS_BUILD_FOR_SIMULATOR)
  target_link_libraries(argos3plugin_${ARGOS_BUILD_FOR}_turtlebot3
    argos3plugin_${ARGOS_BUILD_FOR}_dynamics2d)
  if(ARGOS_QTOPENGL_FOUND)
    target_link_libraries(argos3plugin_${ARGOS_BUILD_FOR}_turtlebot3 argos3plugin_${ARGOS_BUILD_FOR}_qtopengl)
  endif(ARGOS_QTOPENGL_FOUND)
else(ARGOS_BUILD_FOR_SIMULATOR)
  target_link_libraries(argos3plugin_${ARGOS_BUILD_FOR}_turtlebot3
    -lturtlebot3)
endif(ARGOS_BUILD_FOR_SIMULATOR)
if(BUZZ_FOUND)
  target_link_libraries(argos3plugin_${ARGOS_BUILD_FOR}_turtlebot3 argos3plugin_${ARGOS_BUILD_FOR}_buzz ${BUZZ_LIBRARY})
endif(BUZZ_FOUND)

#
# Create battery monitor
#
if(ARGOS_BUILD_FOR STREQUAL "khiv")
  add_executable(battery real_robot/battery.c)
  target_link_libraries(battery -lturtlebot3)
endif(ARGOS_BUILD_FOR STREQUAL "khiv")

#
# Installation
#
install(FILES ${ARGOS3_HEADERS_PLUGINS_ROBOTS_TURTLEBOT3_CONTROLINTERFACE} DESTINATION include/argos3/plugins/robots/turtlebot3/control_interface)

if(ARGOS_BUILD_FOR_SIMULATOR)
  install(FILES ${ARGOS3_HEADERS_PLUGINS_ROBOTS_TURTLEBOT3_SIMULATOR} DESTINATION include/argos3/plugins/robots/turtlebot3/simulator)
  install(FILES simulator/turtlebot3_texture_bottom.png simulator/turtlebot3_texture_side.png simulator/turtlebot3_texture_top.png DESTINATION include/argos3/plugins/simulator/visualizations/qt-opengl/textures)
else(ARGOS_BUILD_FOR_SIMULATOR)
  install(FILES ${ARGOS3_HEADERS_PLUGINS_ROBOTS_TURTLEBOT3_REALROBOT} DESTINATION include/argos3/plugins/robots/turtlebot3/real_robot)
  install(FILES real_robot/main.cpp DESTINATION include/argos3/plugins/robots/turtlebot3/real_robot)
endif(ARGOS_BUILD_FOR_SIMULATOR)

install(TARGETS argos3plugin_${ARGOS_BUILD_FOR}_turtlebot3
  RUNTIME DESTINATION bin
  LIBRARY DESTINATION lib/argos3
  ARCHIVE DESTINATION lib/argos3)
