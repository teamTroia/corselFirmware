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
    Serial2.print("AT\r\n");
    pinMode(PC13, OUTPUT);
    digitalWrite(PC13, LOW);
    pinMode(PINO_LED, OUTPUT);
    digitalWrite(PINO_LED, LOW);
}

void blink() {
    digitalWrite(PINO_LED, HIGH);
    delay(200);
    digitalWrite(PINO_LED, LOW);
    delay(200);
    digitalWrite(PINO_LED, HIGH);
    delay(200);
    digitalWrite(PINO_LED, LOW);
    delay(200);
    digitalWrite(PINO_LED, HIGH);
    delay(200);
    digitalWrite(PINO_LED, LOW);
}


void loop() {
    char buff = ' ';
    if (Serial2.available()) {
        buff = Serial2.read();
        if (buff == 'B'){
            comandoIniciado = true;
        }
        if (comandoIniciado && buff != 'B') {
            if (buff == 'E') {
                comandoPronto = true;
            } else {
                cmd = cmd + buff;
            }
        }
    }

    if (comandoPronto) {
        if (cmd == "ON") {
            ligado = true;
            momentoLigado = millis();
        } else if (cmd == "NOC") {
            posCone = CENTRO_CONE;
        } else {
            posCone = atoi(cmd.c_str());
        }

        comandoPronto = false;
        comandoIniciado = false;
        cmd = "";
    }

    if (ligado) {
        if (momentoLigado - millis() > 5000) {
            Serial.print("POS CONE: ");
            Serial.println(posCone);
            motores.motorsControl(20,0, posCone);
        }
    }
}