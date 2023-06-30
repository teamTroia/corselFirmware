#include <Arduino.h>

// Colocar o baudrate desejado para leitura
int SerialConvertion()
{
    int eixoX = 0;
    char c = ' ';
    Serial.print("Alo");
    if (Serial.available() > 0)
    {
        c = Serial.read();
        eixoX = c;//map(c, 0, 6, 0, 680);
        Serial.print(eixoX, DEC);
    };
    return eixoX;
}