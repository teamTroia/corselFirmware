#include <Arduino.h>
// #include <defines.h>
// #include <motor.h>
#include <Serial.h>
// #include <giroscopio.h>
#include <Controle.h>
#include <Odometria.h>
int leitura, eixoX, valEixoX;
void setup()
{
  pinMode(LED_BUILTIN, OUTPUT);
  initPKS();
  Serial.begin(9600);
  init_mpu();
}

void loop()
{
  eixoX = SerialConvertion();
  testeMotor(eixoX);
}