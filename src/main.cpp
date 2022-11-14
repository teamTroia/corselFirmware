#include "../include/defines.h"
#include "../include/motor.h"
#include "../include/testes.h"


Motor motores = Motor();
Testes testes = Testes();

void setup() {
    Serial.begin(9600);
    motores.init();
    // testes.testeMotor();
}
void loop() {
    motores.motorsControl(-40,0);
}