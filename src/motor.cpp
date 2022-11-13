#include "../include/motor.h"

#include "../include/defines.h"

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