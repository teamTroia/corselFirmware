#include <Arduino.h>

//Colocar o baudrate desejado para leitura
void Serialinit(unsigned x){
    Serial.begin(x);
}

String getSerial()
{   
    String read;
    if (Serial.available()){
        read = Serial.readString();
    }
    return read;
}

void writeSerial(char comando) {

    if(Serial.available()){
        Serial.write(comando);
    }
}
