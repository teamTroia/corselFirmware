#include <Arduino.h>
#include "../include/defines.h"
#include "../include/motor.h"
#include "../include/testes.h"
#include <string.h>


Motor motores = Motor();
bool ligado = false;
bool comandoIniciado = false;
bool comandoPronto = false;
String cmd = "";
long int momentoLigado = 0;

int posCone = 320;

void setup() {
    Serial.begin(9600);
    motores.init();
    Serial2.begin(9600);
    pinMode(PC13, OUTPUT);
    digitalWrite(PC13, LOW);
}


void loop() {
    char buff = ' ';
    if (Serial2.available()) {
        buff = Serial2.read();
        Serial.print(buff);
        if (buff == 'B'){
            comandoIniciado = true;
        }
        if (comandoIniciado && buff != 'B') {
            if (buff == 'E') {
                Serial.println("AA0");
                comandoPronto = true;
                Serial.print(cmd);
                digitalWrite(PC13, HIGH);
            } else {
                cmd = cmd + buff;
            }
        }
    }

    if (comandoPronto) {
        if (cmd == "ON") {
            ligado = true;
            momentoLigado = millis();
        }

        comandoPronto = false;
        comandoIniciado = false;
        cmd = "";
    }

    if (ligado) {
        Serial.println("LIGOU");
        if (momentoLigado - millis() > 5000) {
            motores.motorsControl(20,0);
        }
    }
}