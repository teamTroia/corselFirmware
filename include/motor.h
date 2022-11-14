#ifndef MOTOR_H
#define MOTOR_H

#include "./defines.h"
#include "../include/imuUtils.h"

class Motor {
   private:
    float pid(float target, float atual);
    void enablePKS1(float vel);
    void enablePKS2(float vel);
    IMU imu;
   public:
    Motor();
    void stopPKS();
    void enablePKS(float vel1, float vel2);
    void init();
    void motorsControl(float linear, float angular);
};

#endif