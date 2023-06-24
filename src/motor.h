#ifndef MOTOR_H
#define MOTOR_H

#include <defines.h>
#include <giroscopio.h>
#include <servo.h>
Servo FW_PKS, ANG_PKS;
int marge_erro = 60;

void initPKS() {
        FW_PKS.attach(fw_pks);
        ANG_PKS.attach(ang_pks);
}

void stopPKS() {
    FW_PKS.writeMicroseconds(0);
    ANG_PKS.writeMicroseconds(0);
}

void pwmWrite(float FWD, double ANG){
    FW_PKS.writeMicroseconds(FWD);
    FW_PKS.writeMicroseconds(int(ANG));
}

float pidCamera(int target, int atual) {
    int kp = 0.00035;

    int error = target - atual;
    int output = error * kp;
    return output;
}

float pidIMU(float target, float atual) {
    float kp = 60;
    
    float error = target - atual;
    float output = error * kp;
    return output;
}

void motorsControl(float linear, float angular) {
    float ROBO_V[2] = {0, 0};
    int posCone;
    if(Serial.available()){
        posCone = Serial.parseInt();
    }
    angular += pidCamera(CENTRO_CONE, posCone);
    angular = pidIMU(angular, readAngularSpeed());
    angular = angular > 100 ? 100 : angular;


    float Vel_R = -linear - angular ;
    float Vel_L = -linear + angular;

    Vel_L = abs(Vel_L) < 10 ? 0 : Vel_L;
    Vel_R = abs(Vel_R) < 10 ? 0 : Vel_R;

    ROBO_V[0] = map(Vel_L, -100, 100, 1000, 2000);
    ROBO_V[1] = map(Vel_R, -100, 100, 1000, 2000);
    
    int VEL_M = ((ROBO_V[0]+ROBO_V[1])/2);
    int VEL_A = ((ROBO_V[0]+ROBO_V[1])/1.75);

    Serial.println("Foward: ");
    Serial.println(VEL_M);
    delay(1000);
    Serial.println("Angular: ");
    Serial.println(VEL_A);
    delay(1000);
    pwmWrite(VEL_M,VEL_A);
}

#endif