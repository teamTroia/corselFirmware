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
  //  char c = Serial.read(); // Lê o próximo caractere disponível na porta serial
  //  if (c == 'b'){
  //    while (Serial.available() > 0 && Serial.read() != 'b')
  //    {
  //      // Continua lendo até encontrar a segunda letra 'b'
  //    }
  //  }
  //  else if (isdigit(c)){
  //    String receivedString = String(c);
  //    while (Serial.available() > 0 && Serial.peek() != 'b' && isdigit(Serial.peek()))
  //    {
  //      receivedString += char(Serial.read());
  //    }

  //    leitura = receivedString.toInt();
  //    Serial.println(leitura, DEC);

    
    String receivedString = Serial.readStringUntil('b');
    String numberString = receivedString.substring(1);
    leitura = numberString.toInt();
    Serial.println(leitura, DEC);
      
    if (leitura > 330){
      eixoX = -leitura;
    }
    else if (leitura < 310){
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
