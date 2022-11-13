#ifndef MOTOR_H
#define MOTOR_H


#include "./defines.h"

class Motor {
private:
    
public:
    Motor();
    void enablePKS1(float vel);
    void enablePKS2(float vel);
    void stopPKS();
    void enablePKS(float vel1, float vel2);
};

#endif