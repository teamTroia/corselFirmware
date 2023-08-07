#include <Arduino.h>
#include <Wire.h>
#include <defines.h>
// #include <motor.h>
#include <Serial.h>
// #include <giroscopio.h>
#include <Controle.h>
// #include <Odometria.h>
#include <FastLED.h>
#include <Ultrassonico.h>

CRGB leds[NUM_LEDS];
int leitura, eixoX;

void acendeLED()
{
  for (int i = 0; i <= 3; i++)
  {
    leds[i] = CRGB::Green;
    FastLED.show();
  }
  delay(3000);
}

void apagaLED()
{
  for (int i = 0; i <= 3; i++)
  {
    leds[i] = CRGB::Black;
    FastLED.show();
  }
}

void setup()
{
  FastLED.addLeds<WS2812, 3, GRB>(leds, NUM_LEDS);
  initPKS();
  Serial.begin(9600);
  init_mpu();
  initUltrassonico();
  apagaLED();
}

void ultra(){
  int d = distCone();
  Serial.println(d);
  if (d < 50)
  {
    FW_PKS.writeMicroseconds(1500);
    ANG_PKS.writeMicroseconds(1500);
    acendeLED();
    apagaLED();
    Serial.println("SensorDistPegou");
    delay(50000);
  }
}

void loop()
{
  eixoX = SerialConvertion();
  while (eixoX == 0)
  {
    float gyro = readAngularSpeed();
    if (gyro != -0.02)
    {
      //Serial.println(gyro);
      int Angularspeed = PID(0, gyro);
      //Serial.println(Angularspeed);
      if (Angularspeed > -140 && Angularspeed < 140)
      {
        getpulse(1890, 1500 + Angularspeed); //1890 day4
        //Serial.println("Esquerda");
      }
      else
      {
        getpulse(1890, 1500); //1890 day4
      }
    }
    ultra();
  }
  testeMotor(eixoX);
  ultra();
}