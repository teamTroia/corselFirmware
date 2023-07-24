#include <Arduino.h>
#include <defines.h>
// #include <motor.h>
#include <Serial.h>
// #include <giroscopio.h>
#include <Controle.h>
//#include <Odometria.h>
#include <Ultrassonico.h>
#include <FastLED.h>

CRGB leds[NUM_LEDS];
int leitura, eixoX;

void acendeLED(){
  for (int i = 0; i <= 3; i++){
    leds[i] = CRGB::Green;
    FastLED.show();
  }
  delay(1500);
}
void apagaLED(){
  for (int i = 0; i <=  3; i++){
    leds[i] = CRGB::Black;
    FastLED.show();
  }
}

void setup(){
  FastLED.addLeds<WS2812,3,GRB>(leds,NUM_LEDS);
  apagaLED();
  initPKS();
  Serial.begin(9600);
  init_mpu();
  initUltrassonico();
}

void loop(){
  float gyro = readAngularSpeed();
  //Serial.println(gyro);
  int Angularspeed = PID(0,gyro);
  //Serial.println(Angularspeed);
  if(Angularspeed>-1){
    getpulse(1920,1500-Angularspeed);
    //Serial.println("Esquerda");
  }
  else{
    getpulse(1880,1500);
    //Serial.println("Direita");
  }


  //eixoX = SerialConvertion();
  //testeMotor(eixoX);
  //int d = distCone();
  /*if (d < 45 && d > 5)
  {
    FW_PKS.writeMicroseconds(1500);
    ANG_PKS.writeMicroseconds(1500);
    acendeLED();
    
    //int contAchou = 1;
    apagaLED();
    //if (contAchou == 1)
    //{
      FW_PKS.writeMicroseconds(1760);
      ANG_PKS.writeMicroseconds(1894);
      delay(5000);
      limparBufer();
      //contAchou--;
    //}
  }*/
}