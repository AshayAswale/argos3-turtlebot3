/**
 * @file <argos3/plugins/robots/turtlebot3/control_interface/ci_turtlebot3_camera_sensor.cpp>
 *
 * @author Carlo Pinciroli - <ilpincy@gmail.com>
 */

#include "ci_turtlebot3_camera_sensor.h"

#ifdef ARGOS_WITH_LUA
#include <argos3/core/wrappers/lua/lua_utility.h>
#endif

namespace argos {

   /****************************************/
   /****************************************/

   CCI_Turtlebot3CameraSensor::CCI_Turtlebot3CameraSensor() {}

   /****************************************/
   /****************************************/

   UInt32 CCI_Turtlebot3CameraSensor::GetWidth() const {
      return m_unWidth;
   }

   /****************************************/
   /****************************************/

   UInt32 CCI_Turtlebot3CameraSensor::GetHeight() const {
      return m_unHeight;
   }

   /****************************************/
   /****************************************/

   const CCI_Turtlebot3CameraSensor::TBlobs& CCI_Turtlebot3CameraSensor::GetBlobs() const {
      return m_tBlobs;
   }

   /****************************************/
   /****************************************/

#ifdef ARGOS_WITH_LUA
   void CCI_Turtlebot3CameraSensor::CreateLuaState(lua_State* pt_lua_state) {
      // TODO
   }
#endif

   /****************************************/
   /****************************************/

#ifdef ARGOS_WITH_LUA
   void CCI_Turtlebot3CameraSensor::ReadingsToLuaState(lua_State* pt_lua_state) {
      // TODO
   }
#endif


   /****************************************/
   /****************************************/

   std::ostream& operator<<(std::ostream& c_os,
                            const CCI_Turtlebot3CameraSensor::SBlob& s_blob) {
      c_os << "<Color=\"" << s_blob.Color << "\", "
           << "Min=" << s_blob.Min << ", "
           << "Max=" << s_blob.Max << ">";
      return c_os;
   }

   /****************************************/
   /****************************************/

   std::ostream& operator<<(std::ostream& c_os,
                            const CCI_Turtlebot3CameraSensor::TBlobs& t_blobs) {
      if(! t_blobs.empty()) {
         c_os << "{ " << t_blobs[0] << " }";
         for(UInt32 i = 1; i < t_blobs.size(); ++i) {
            c_os << "   { " << t_blobs[i] << " }";
         }
         c_os << std::endl;
      }
      return c_os;
   }

   /****************************************/
   /****************************************/

}
