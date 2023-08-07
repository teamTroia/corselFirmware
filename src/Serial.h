#include <Arduino.h>

void limparBufer(){
    unsigned char temp = Serial.available(); 

    for (int i = temp; i>=0; i--){
        Serial.read();
    };
}

// Colocar o baudrate desejado para leitura
int SerialConvertion()
{
    String palavra = " ";
    char c;
    if (Serial.available() > 0)
    {
        c = (Serial.read());
        if (c == (','))
        {
            while (c != '/')
            {
                int i = 0;
                if (Serial.available() > 0)
                {   
                    c = char(Serial.read());
                    i++;
                    if (i < 2)
                    {
                        palavra = palavra + c;
                    }
                }
            }
            int eixoX = palavra.toInt();
            return eixoX;
        }
    }
    else
    {
        return 0;
    }
}
