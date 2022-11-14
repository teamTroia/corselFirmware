#include <Arduino.h>
#include "../include/defines.h"
#include "../include/motor.h"
#include "../include/testes.h"
#include <string.h>


Motor motores = Motor();
bool ligado = false;

void setup() {
    Serial.begin(9600);
    motores.init();
    Serial1.begin(9600);
}

void loop() {
    String cmd = "";
    if (Serial1.available()) {
       char buff;
       buff = Serial1.read();
       Serial.print(buff);
       if (buff == 'E') {
            buff = Serial1.read();
            Serial.print(buff);
            while (Serial1.available() && buff != 'E') {
                cmd += buff;
            }
       } else {
        cmd = "";
       }
    }

    ligado = (cmd == "ON") || ligado;

    if (ligado) {
        motores.motorsControl(20,0);
    }
}