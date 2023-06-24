#include <Arduino.h>
#include <defines.h>
#include <motor.h>
#include <Serial.h>
#include <giroscopio.h>
#include <testemotor.h>


void setup() {
  initPKS();
  init_mpu();
  Serial.begin(9600);
}

void loop() {
  
  motorsControl(20,0);
  //Serial.println("Tá INDO");
  
}

