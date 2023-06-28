#include <Arduino.h>
#include <defines.h>
#include <motor.h>
#include <Serial.h>
#include <giroscopio.h>
#include <Controle.h>
//#include <Odometria.h>

int leitura, eixoX;
void setup(){
  pinMode(LED_BUILTIN, OUTPUT);
  initPKS();
  Serial.begin(9600, SERIAL_8N2);
  Serial.setTimeout(1000);
  init_mpu();
}

void loop(){
  if (Serial.available() > 0){
    leitura = (Serial.parseInt(SKIP_ALL, 1));
    Serial.println(leitura, DEC);
    if (leitura > 330){
      eixoX = -leitura;
    }
    else if (leitura < 300){
      eixoX = leitura;
    }
    else{
      eixoX = 0;
    }
    testeMotor(eixoX);
  }

  // getPosicao(ENCDIR,positionDir,newPosDir);
  // getPosicao(ENCESC,positionEsq,newPosEsq);
}
