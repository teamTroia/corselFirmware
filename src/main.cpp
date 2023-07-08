#include <Arduino.h>
// #include <defines.h>
// #include <motor.h>
#include <Serial.h>
// #include <giroscopio.h>
#include <Controle.h>
//#include <Odometria.h>
#include <Ultrassonico.h>

int leitura, eixoX, contAchou;
void setup()
{
  contAchou = 0;
  pinMode(LEDCONE, OUTPUT);
  digitalWrite(LEDCONE, LOW);
  initPKS();
  Serial.begin(96
  00);
  init_mpu();
  initUltrassonico();
}

void loop()
{
  eixoX = SerialConvertion();
  testeMotor(eixoX);
  distCone();
  if(distance <= 25){
    int tempoatual = millis();
    FW_PKS.writeMicroseconds(1500);
    ANG_PKS.writeMicroseconds(1500);
    while(millis()-tempoatual <= 1000){
      digitalWrite(LEDCONE, HIGH);
      Serial.print("LIGADO");
    }
    digitalWrite(LEDCONE, LOW);
    Serial.print("DESLIGADO");
    contAchou++;
  }
  if (contAchou == 1 ){
    int tempoatual = millis();
    while(millis()-tempoatual <= 7000){
      FW_PKS.writeMicroseconds(1760);
      ANG_PKS.writeMicroseconds(1894);
    }
  }
  //getpulse(1900,1500);
}