#include "../include/motor.h"

#include "../include/defines.h"
#include "../include/imuUtils.h"

void Motor::enablePKS1(float vel) {
    if (vel > 0) {
        pwmWrite(SD1_PK1, vel);
        pwmWrite(SD2_PK1, 100);
        digitalWrite(ENB1_PK1, HIGH);
        digitalWrite(ENB2_PK1, LOW);

    } else if (vel < 0) {
        pwmWrite(SD2_PK1, vel);
        pwmWrite(SD1_PK1, 100);
        digitalWrite(ENB1_PK1, LOW);
        digitalWrite(ENB2_PK1, HIGH);

    } else {
        pwmWrite(SD2_PK1, 0);
        pwmWrite(SD1_PK1, 0);
        digitalWrite(ENB1_PK1, LOW);
        digitalWrite(ENB2_PK1, LOW);
    }
}

void enablePKS2(float vel) {
    if (vel > 0) {
        pwmWrite(SD1_PK2, vel);
        pwmWrite(SD2_PK2, 100);
        digitalWrite(ENB1_PK2, HIGH);
        digitalWrite(ENB2_PK2, LOW);

    } else if (vel < 0) {
        pwmWrite(SD2_PK2, vel);
        pwmWrite(SD1_PK2, 100);
        digitalWrite(ENB1_PK2, LOW);
        digitalWrite(ENB2_PK2, HIGH);

    } else {
        pwmWrite(SD2_PK2, 0);
        pwmWrite(SD1_PK2, 0);
        digitalWrite(ENB1_PK2, LOW);
        digitalWrite(ENB2_PK2, LOW);
    }
}

void Motor::stopPKS() {
    pwmWrite(SD1_PK1, 0);
    pwmWrite(SD2_PK1, 0);
    pwmWrite(SD1_PK2, 0);
    pwmWrite(SD2_PK2, 0);

    digitalWrite(ENB1_PK1, LOW);
    digitalWrite(ENB2_PK1, LOW);
    digitalWrite(ENB2_PK1, LOW);
    digitalWrite(ENB2_PK2, LOW);
}

Motor::Motor() {
    pinMode(SD1_PK1, PWM);  // SD Parkinson
    pinMode(SD2_PK1, PWM);
    pinMode(SD1_PK2, PWM);
    pinMode(SD2_PK2, PWM);

    pinMode(ENB1_PK1, OUTPUT);  // Enable Parkinson
    pinMode(ENB1_PK2, OUTPUT);
    pinMode(ENB2_PK1, OUTPUT);
    pinMode(ENB2_PK2, OUTPUT);

    stopPKS();
}

void Motor::enablePKS(float vel1, float vel2) {
    enablePKS1(vel1);
    enablePKS2(vel2);
}

float Motor::pid(float target, float atual) {
    float kp = 20;
    // float kd = 0;
    // float ki = 0;

    float error = target - atual;
    float output = error * kp;
    return output;
}

void Motor::motorsControl(float linear, float angular) {
    float ROBO_V[2] = {0, 0};
    Serial.print("ANGULAR: ");
    Serial.println(angular);
    angular = pid(angular, readAngularSpeed());
    angular = angular > 100 ? 100 : angular;
    float Vel_R =
        linear - angular;  // ao somar o angular com linear em cada motor
                           // conseguimos a ideia de direcao do robo
    float Vel_L = linear + angular;
    Vel_L = abs(Vel_L) < 10 ? 0 : Vel_L;
    Vel_R = abs(Vel_R) < 10 ? 0 : Vel_R;
    ROBO_V[0] = map(Vel_L, -100, 100, -65535, 65535);
    ROBO_V[1] = map(Vel_R, -100, 100, -65535, 65535);
    enablePKS(ROBO_V[1], ROBO_V[0]);
}