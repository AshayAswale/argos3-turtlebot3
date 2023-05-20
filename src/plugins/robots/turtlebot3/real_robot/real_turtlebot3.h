#ifndef REAL_TURTLEBOT3_H
#define REAL_TURTLEBOT3_H

#include <argos3/core/real_robot/real_robot.h>
#include <argos3/plugins/robots/turtlebot3/real_robot/real_turtlebot3_device.h>
#include <turtlebot3/turtlebot3.h>

using namespace argos;

class CRealTurtlebot3 : public CRealRobot {

public:

   CRealTurtlebot3();
   virtual ~CRealTurtlebot3();
   virtual void InitRobot();
   virtual void Destroy();
   virtual CCI_Actuator* MakeActuator(const std::string& str_name);
   virtual CCI_Sensor* MakeSensor(const std::string& str_name);
   virtual void Sense(Real f_elapsed_time);
   virtual void Act(Real f_elapsed_time);

   inline knet_dev_t* GetDSPic() const {
      return m_ptDSPic;
   }

private:

   knet_dev_t* m_ptDSPic;
   std::vector<CRealTurtlebot3Device*> m_vecActuators;
   std::vector<CRealTurtlebot3Device*> m_vecSensors;
};

#endif // REAL_TURTLEBOT3_H
