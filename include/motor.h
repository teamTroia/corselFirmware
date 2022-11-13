#ifndef MOTOR_H
#define MOTOR_H


#include "./defines.h"

class Motor {
private:
    void setMotorA(float vel);
    void setMotorB(float vel);
public:
    Motor();
    void stopMotors();
    void setMotor(float vel1, float vel2);
}

#endif