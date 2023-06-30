#include <Arduino.h>

// Colocar o baudrate desejado para leitura
int SerialConvertion()
{
    int eixoX = 0;
    Serial.print("Alo");
    if (Serial.available())
    {
        String palavra = Serial.read();
        Print(palavra); //tm que estar neste modelo = b'0X/0X' algo assim
        eixoX = int.from_bytes(palavra, byteorder='little')
        Serial.print(eixoX, DEC); // precisa sair o valor enviado pela nvidia exemplo 435
    };
    return eixoX;
}
