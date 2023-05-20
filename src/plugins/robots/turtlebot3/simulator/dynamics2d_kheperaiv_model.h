/**
 * @file <argos3/plugins/robots/turtlebot3/simulator/dynamics2d_turtlebot3_model.h>
 *
 * @author Carlo Pinciroli - <ilpincy@gmail.com>
 */

#ifndef DYNAMICS2D_TURTLEBOT3_MODEL_H
#define DYNAMICS2D_TURTLEBOT3_MODEL_H

namespace argos {
   class CDynamics2DDifferentialSteeringControl;
   class CDynamics2DGripper;
   class CDynamics2DGrippable;
   class CDynamics2DTurtlebot3Model;
}

#include <argos3/plugins/simulator/physics_engines/dynamics2d/dynamics2d_single_body_object_model.h>
#include <argos3/plugins/simulator/physics_engines/dynamics2d/dynamics2d_differentialsteering_control.h>
#include <argos3/plugins/robots/turtlebot3/simulator/turtlebot3_entity.h>

namespace argos {

   class CDynamics2DTurtlebot3Model : public CDynamics2DSingleBodyObjectModel {

   public:

      CDynamics2DTurtlebot3Model(CDynamics2DEngine& c_engine,
                              CTurtlebot3Entity& c_entity);
      virtual ~CDynamics2DTurtlebot3Model();

      virtual void Reset();

      virtual void UpdateFromEntityStatus();
      
   private:

      CTurtlebot3Entity& m_cTurtlebot3Entity;
      CWheeledEntity& m_cWheeledEntity;

      CDynamics2DDifferentialSteeringControl m_cDiffSteering;

      const Real* m_fCurrentWheelVelocity;

   };

}

#endif
