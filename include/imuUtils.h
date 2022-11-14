#ifndef IMUUTILS_H
#define IMUUTILS_H

#include "./defines.h"

class IMU {
private:

public:
      IMU();
      void init_mpu();
      float readAngularSpeed();
};
#endif