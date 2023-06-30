#include <Arduino.h>

// Colocar o baudrate desejado para leitura
int SerialConvertion()
{
    int eixoX = 0;
    if (Serial.available() > 0)
    {
        String palavra = "";
        char c = ' ';
        if (Serial.available() > 0)
        {
            c = char(Serial.read());
        }
        if (c == 'b')
        {
            int i = 0;
            while (c != '\n')
            {
                if (Serial.available() > 0)
                {
                    c = char(Serial.read());
                    i++;
                    if (i >= 2 && i < 5){
                        palavra = palavra + c;
                    }
                }
            }
            eixoX = palavra.toInt();
        }

        return eixoX;
    }
}