#include <Arduino.h>
#include <defines.h>
// #include <motor.h>
#include <Serial.h>
// #include <giroscopio.h>
#include <Controle.h>
//#include <Odometria.h>
#include <Ultrassonico.h>

void setup(){
  FastLED.addLeds<WS2812,3,GRB>(leds,NUM_LEDS);
  apagaLED();
  initPKS();
  Serial.begin(9600);
  init_mpu();
  initUltrassonico();
}

void loop()
{
  eixoX = SerialConvertion();
  testeMotor(eixoX);
  //distCone();
  //getpulse(1760,1793);
}
