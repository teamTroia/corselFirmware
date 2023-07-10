#include <Arduino.h>
#include <defines.h>
#include <motor.h>
#include <Serial.h>
// #include <giroscopio.h>
#include <Controle.h>
//#include <Odometria.h>
#include <Ultrassonico.h>
#include <Adafruit_NeoPixel.h>

int leitura, eixoX, 
int contAchou = 0;
void setup()
{
  Adafruit_NeoPixel pixels(numPixel, LEDCONE, NEO_GRB + NEO_KHZ800);
  pixels.begin();
  pixels.clear();
  initPKS();
  Serial.begin(9600);
  init_mpu();
  initUltrassonico();
}

void loop()
{
  eixoX = SerialConvertion();
  testeMotor(eixoX);
  int distancia = distCone();
  //getpulse(1760,1793);
  if(distancia <= 25){
    int tempoatual = millis();
    FW_PKS.writeMicroseconds(1500);
    ANG_PKS.writeMicroseconds(1500);
    while(millis()-tempoatual <= 1500){
      for(int i=0; i<NUMPIXELS; i++) {
        pixels.setPixelColor(i, pixels.Color(255, 255, 255));
        pixels.show();
      }
      Serial.print("LIGADO");
    }
    pixels.clear();
    Serial.print("DESLIGADO");
    contAchou++;
  }
  if (contAchou == 1){
    int tempoatual = millis();
    while(millis()-tempoatual <= 7000){
      FW_PKS.writeMicroseconds(1760);
      ANG_PKS.writeMicroseconds(1894);
    }
    contAchou--;
  }
}
