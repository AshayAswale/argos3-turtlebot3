/**
 * @file <argos3/plugins/robots/turtlebot3/simulator/dynamics2d_turtlebot3_model.cpp>
 *
 * @author Carlo Pinciroli - <ilpincy@gmail.com>
 */

#include "dynamics2d_turtlebot3_model.h"
#include "turtlebot3_measures.h"

#include <argos3/plugins/simulator/physics_engines/dynamics2d/dynamics2d_gripping.h>
#include <argos3/plugins/simulator/physics_engines/dynamics2d/dynamics2d_engine.h>

namespace argos {

   /****************************************/
   /****************************************/

   static const Real TURTLEBOT3_MASS                = 0.4f;
   static const Real TURTLEBOT3_MAX_FORCE           = 1.5f;
   static const Real TURTLEBOT3_MAX_TORQUE          = 1.5f;

   enum TURTLEBOT3_WHEELS {
      TURTLEBOT3_LEFT_WHEEL = 0,
      TURTLEBOT3_RIGHT_WHEEL = 1
   };

   /****************************************/
   /****************************************/

   CDynamics2DTurtlebot3Model::CDynamics2DTurtlebot3Model(CDynamics2DEngine& c_engine,
                                                        CTurtlebot3Entity& c_entity) :
      CDynamics2DSingleBodyObjectModel(c_engine, c_entity),
      m_cTurtlebot3Entity(c_entity),
      m_cWheeledEntity(m_cTurtlebot3Entity.GetWheeledEntity()),
      m_cDiffSteering(c_engine,
                      TURTLEBOT3_MAX_FORCE,
                      TURTLEBOT3_MAX_TORQUE,
                      TURTLEBOT3_WHEEL_DISTANCE,
                      c_entity.GetConfigurationNode()),
      m_fCurrentWheelVelocity(m_cWheeledEntity.GetWheelVelocities()) {
      /* Create the body with initial position and orientation */
      cpBody* ptBody =
         cpSpaceAddBody(GetDynamics2DEngine().GetPhysicsSpace(),
                        cpBodyNew(TURTLEBOT3_MASS,
                                  cpMomentForCircle(TURTLEBOT3_MASS,
                                                    0.0f,
                                                    TURTLEBOT3_BASE_RADIUS + TURTLEBOT3_BASE_RADIUS,
                                                    cpvzero)));
      const CVector3& cPosition = GetEmbodiedEntity().GetOriginAnchor().Position;
      ptBody->p = cpv(cPosition.GetX(), cPosition.GetY());
      CRadians cXAngle, cYAngle, cZAngle;
      GetEmbodiedEntity().GetOriginAnchor().Orientation.ToEulerAngles(cZAngle, cYAngle, cXAngle);
      cpBodySetAngle(ptBody, cZAngle.GetValue());
      /* Create the body shape */
      cpShape* ptShape =
         cpSpaceAddShape(GetDynamics2DEngine().GetPhysicsSpace(),
                         cpCircleShapeNew(ptBody,
                                          TURTLEBOT3_BASE_RADIUS,
                                          cpvzero));
      ptShape->e = 0.0; // No elasticity
      ptShape->u = 0.7; // Lots of friction
      /* Constrain the actual base body to follow the diff steering control */
      m_cDiffSteering.AttachTo(ptBody);
      /* Set the body so that the default methods work as expected */
      SetBody(ptBody, TURTLEBOT3_BASE_TOP);
   }

   /****************************************/
   /****************************************/

   CDynamics2DTurtlebot3Model::~CDynamics2DTurtlebot3Model() {
      m_cDiffSteering.Detach();
   }

   /****************************************/
   /****************************************/

   void CDynamics2DTurtlebot3Model::Reset() {
      CDynamics2DSingleBodyObjectModel::Reset();
      m_cDiffSteering.Reset();
   }

   /****************************************/
   /****************************************/

   void CDynamics2DTurtlebot3Model::UpdateFromEntityStatus() {
      /* Do we want to move? */
      if((m_fCurrentWheelVelocity[TURTLEBOT3_LEFT_WHEEL] != 0.0f) ||
         (m_fCurrentWheelVelocity[TURTLEBOT3_RIGHT_WHEEL] != 0.0f)) {
         m_cDiffSteering.SetWheelVelocity(m_fCurrentWheelVelocity[TURTLEBOT3_LEFT_WHEEL],
                                          m_fCurrentWheelVelocity[TURTLEBOT3_RIGHT_WHEEL]);
      }
      else {
         /* No, we don't want to move - zero all speeds */
         m_cDiffSteering.Reset();
      }
   }

   /****************************************/
   /****************************************/

   REGISTER_STANDARD_DYNAMICS2D_OPERATIONS_ON_ENTITY(CTurtlebot3Entity, CDynamics2DTurtlebot3Model);

   /****************************************/
   /****************************************/

}
