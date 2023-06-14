/**
 * @file <argos3/plugins/robots/turtlebot3/simulator/qtopengl_turtlebot3.cpp>
 *
 * @author Carlo Pinciroli - <ilpincy@gmail.com>
 */

#include "qtopengl_turtlebot3.h"
#include "turtlebot3_entity.h"
#include "turtlebot3_measures.h"
#include <argos3/core/utility/math/vector2.h>
#include <argos3/core/simulator/entity/embodied_entity.h>
#include <argos3/plugins/simulator/entities/led_equipped_entity.h>
#include <argos3/plugins/simulator/visualizations/qt-opengl/qtopengl_widget.h>
#include <QImage>

namespace argos {

   /****************************************/
   /****************************************/

   CQTOpenGLTurtlebot3::CQTOpenGLTurtlebot3() :
      m_cBodyModel("turtlebot3.obj") {
   }

   /****************************************/
   /****************************************/

   CQTOpenGLTurtlebot3::~CQTOpenGLTurtlebot3() {
   }

   /****************************************/
   /****************************************/

   void CQTOpenGLTurtlebot3::Draw(CTurtlebot3Entity& c_entity) {
      m_cBodyModel.Draw();
   }

   /****************************************/
   /****************************************/

   class CQTOpenGLOperationDrawTurtlebot3Normal : public CQTOpenGLOperationDrawNormal {
   public:
      void ApplyTo(CQTOpenGLWidget& c_visualization,
                   CTurtlebot3Entity& c_entity) {
         static CQTOpenGLTurtlebot3 m_cModel;
         c_visualization.DrawRays(c_entity.GetControllableEntity());
         c_visualization.DrawEntity(c_entity.GetEmbodiedEntity());
         m_cModel.Draw(c_entity);
      }
   };

   class CQTOpenGLOperationDrawTurtlebot3Selected : public CQTOpenGLOperationDrawSelected {
   public:
      void ApplyTo(CQTOpenGLWidget& c_visualization,
                   CTurtlebot3Entity& c_entity) {
         c_visualization.DrawBoundingBox(c_entity.GetEmbodiedEntity());
      }
   };

   REGISTER_QTOPENGL_ENTITY_OPERATION(CQTOpenGLOperationDrawNormal, CQTOpenGLOperationDrawTurtlebot3Normal, CTurtlebot3Entity);

   REGISTER_QTOPENGL_ENTITY_OPERATION(CQTOpenGLOperationDrawSelected, CQTOpenGLOperationDrawTurtlebot3Selected, CTurtlebot3Entity);

   /****************************************/
   /****************************************/

}
