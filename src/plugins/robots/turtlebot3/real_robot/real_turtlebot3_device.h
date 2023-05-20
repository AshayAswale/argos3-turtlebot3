#ifndef REAL_TURTLEBOT3_DEVICE_H
#define REAL_TURTLEBOT3_DEVICE_H

#include <argos3/core/utility/datatypes/datatypes.h>
#include <turtlebot3/turtlebot3.h>

using namespace argos;

class CRealTurtlebot3Device {

public:

   CRealTurtlebot3Device(knet_dev_t* pt_dspic);
   virtual ~CRealTurtlebot3Device() {}

   virtual void Do(Real f_elapsed_time) = 0;

   inline knet_dev_t* GetDSPic() const {
      return m_ptDSPic;
   }

   inline char* GetBuffer() {
      return m_pchBuffer;
   }

private:

   knet_dev_t* m_ptDSPic;
   static char m_pchBuffer[100];
   
};

#endif // REAL_TURTLEBOT3_DEVICE_H
