#ifndef MOTOR_H
#define MOTOR_H

#include "./defines.h"

class Motor {
   private:
    float pid(float target, float atual);
    void motorsControl(float linear, float angular);
    void enablePKS1(float vel);
    void enablePKS2(float vel);

   public:
    Motor();
    void stopPKS();
    void enablePKS(float vel1, float vel2);
};

#endif