#include "../include/defines.h"
#include "../include/motor.h"

void Motor::setMotorA(float vel) {
    if(vel > 0) { //Gira motor p frente
        
    } else if (vel < 0) {

    } else {

    }
}
void Motor::Motor() {
  pinMode(SD1_PK1, PWM); //SD Parkinson
  pinMode(SD2_PK1, PWM);
  pinMode(SD1_PK2, PWM);
  pinMode(SD2_PK2, PWM);
  
  pinMode(ENB1_PK1, OUTPUT); //Enable Parkinson
  pinMode(ENB1_PK2, OUTPUT);
  pinMode(ENB2_PK1, OUTPUT);
  pinMode(ENB2_PK2, OUTPUT);

  stopMotors();
}

void Motor::stopMotors() {
  pwmWrite(SD1_PK1, 0);
  pwmWrite(SD2_PK1, 0);
  pwmWrite(SD1_PK2, 0);
  pwmWrite(SD2_PK2, 0);

  digitalWrite(ENB1_PK1, LOW);
  digitalWrite(ENB2_PK1, LOW);
  digitalWrite(ENB2_PK1, LOW);
  digitalWrite(ENB2_PK2, LOW);
}

void Motor::setMotors(float vel1, float vel2) {
  setMotorA(vel1);
  setMotorB(vel2);

}


// aqui começa a outra palhaçada
#define SD1_PKS1 = PA0;
#define IN1_PKS1 = PA0;
#define SD2_PKS1 = PA0;
#define IN2_PKS1 = PA0;

#define SD1_PKS2 = PA0;
#define IN1_PKS2 = PA0;
#define SD2_PKS2 = PA0;
#define IN2_PKS2 = PA0;

#define LED_OUT = PA0;

void init_pinout(){
    pinMode(SD1_PKS1, PWM);
    pinMode(SD2_PKS1, PWM);
    pinMode(SD1_PKS2, PWM);
    pinMode(SD2_PKS2, PWM);

    pinMode(IN1_PKS1, OUTPUT);
    pinMode(IN2_PKS1, OUTPUT);
    pinMode(IN1_PKS2, OUTPUT);
    pinMode(IN2_PKS2, OUTPUT);

    pinMode(LED_OUT, OUTPUT);

    pwmWrite(SD1_PKS1, 0);
    pwmWrite(SD2_PKS1, 0);
    pwmWrite(SD1_PKS2, 0);
    pwmWrite(SD2_PKS2, 0);

    digitalWrite(IN1_PKS1, LOW);
    digitalWrite(IN2_PKS1, LOW);
    digitalWrite(IN1_PKS2, LOW);
    digitalWrite(IN2_PKS2, LOW);

    digitalWrite(LED_OUT, LOW);

}

void enablePKS1(double dutyCycle, int direction){
    if(direction == 1){
        pwmWrite(SD1_PKS1, dutyCycle);
        pwmWrite(SD2_PKS1, 100);
        digitalWrite(IN1_PKS1, HIGH);
        digitalWrite(IN2_PKS1, LOW);

    }else if(direction == -1){
        pwmWrite(SD2_PKS1, dutyCycle);
        pwmWrite(SD1_PKS1, 100);
        digitalWrite(IN1_PKS1, LOW);
        digitalWrite(IN2_PKS1, HIGH);

    }else{
        pwmWrite(SD2_PKS1, 0);
        pwmWrite(SD1_PKS1, 0);
        digitalWrite(IN1_PKS1, LOW);
        digitalWrite(IN2_PKS1, LOW);

    }
}

void enablePKS2(double dutyCycle, int direction){
    if(direction == 1){
        pwmWrite(SD1_PKS2, dutyCycle);
        pwmWrite(SD2_PKS2, 100);
        digitalWrite(IN1_PKS2, HIGH);
        digitalWrite(IN2_PKS2, LOW);

    }else if(direction == -1){
        pwmWrite(SD2_PKS2, dutyCycle);
        pwmWrite(SD1_PKS2, 100);
        digitalWrite(IN1_PKS2, LOW);
        digitalWrite(IN2_PKS2, HIGH);

    }else{
        pwmWrite(SD2_PKS2, 0);
        pwmWrite(SD1_PKS2, 0);
        digitalWrite(IN1_PKS2, LOW);
        digitalWrite(IN2_PKS2, LOW);
    }
}

void blinkLED(){
    digitalWrite(LED_OUT, HIGH);
    delay(0.5);
    digitalWrite(LED_OUT, LOW);
    delay(0.5);
    digitalWrite(LED_OUT, HIGH);
    delay(0.5);
    digitalWrite(LED_OUT, LOW);
    delay(0.5);
    digitalWrite(LED_OUT, HIGH);
    delay(0.5);
    digitalWrite(LED_OUT, LOW);
    delay(0.5);
}