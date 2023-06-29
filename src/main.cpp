#include <Arduino.h>
#include <defines.h>
#include <motor.h>
#include <Serial.h>
#include <giroscopio.h>
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
 if (Serial.available()>0)
  {
    String palavra = "";
    char c = ' ';
    if (Serial.available() > 0) {
       c = char(Serial.read());
    }
    palavra += c;
    while(c != '\n'){
      if (Serial.available() > 0) {
      c = char(Serial.read());
      //Serial.println(c);
      palavra = palavra + c;
      }
    }
    int eixoX = palavra.toInt();

    //Serial.println("EixoX: ");
    //Serial.println(eixoX);
    testeMotor(eixoX);
  }
}

