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
