#include "../include/defines.h"
#include "../include/motor.h"
#include "../include/testes.h"

Motor motores = Motor();
Testes testes = Testes();

void setup() {
    Serial.begin(9600);
    testes.testeMotor();
}
void loop() {}