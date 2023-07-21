/**
 * @file <argos3/plugins/robots/turtlebot3/simulator/qtopengl_turtlebot3.h>
 *
 * @author Carlo Pinciroli - <ilpincy@gmail.com>
 */

#ifndef QTOPENGL_TURTLEBOT3_H
#define QTOPENGL_TURTLEBOT3_H

namespace argos {
   class CQTOpenGLTurtlebot3;
   class CTurtlebot3Entity;
}

#ifdef __APPLE__
#include <gl.h>
#else
#include <GL/gl.h>
#endif

#include <argos3/plugins/simulator/visualizations/qt-opengl/qtopengl_obj_model.h>

namespace argos {

   class CQTOpenGLTurtlebot3 {

   public:

      CQTOpenGLTurtlebot3();

      virtual ~CQTOpenGLTurtlebot3();

      virtual void Draw(CTurtlebot3Entity& c_entity);

   private:

      CQTOpenGLObjModel m_cBodyModel;

   };

}

#endif