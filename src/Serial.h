#include <Arduino.h>

// Colocar o baudrate desejado para leitura
int SerialConvertion()
{
    long int leitura;
    int eixoX = 0;
    char x = ' ';
    String val = " ";
    Serial.print("Alo");
    if (Serial.available())
    {
        x = Serial.read();
        if (x == ','){
            leitura = val.toInt();
            leitura = map(leitura, 0, 1023, 0, 680);
        }
    };
    return eixoX;
}
