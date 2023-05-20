if(ARGOS_BUILD_FOR_SIMULATOR)
  add_library(turtlebot3_diffusion MODULE turtlebot3_diffusion.h turtlebot3_diffusion.cpp)
endif(ARGOS_BUILD_FOR_SIMULATOR)
if(ARGOS_BUILD_FOR STREQUAL "tb3")
  add_executable(turtlebot3_diffusion turtlebot3_diffusion.h turtlebot3_diffusion.cpp ${CMAKE_SOURCE_DIR}/plugins/robots/turtlebot3/real_robot/main.cpp)
endif(ARGOS_BUILD_FOR STREQUAL "tb3")

target_link_libraries(turtlebot3_diffusion
  argos3core_${ARGOS_BUILD_FOR}
  argos3plugin_${ARGOS_BUILD_FOR}_turtlebot3
  argos3plugin_${ARGOS_BUILD_FOR}_genericrobot)
