#include "../include/testes.h"
#include "../include/defines.h"
#include "../include/motor.h"

Motor motor = Motor();

Testes::Testes() {

}

void Testes::testeMotor() {
    while (true) {
        motor.enablePKS(60000,60000);
        delay(5000);
        motor.enablePKS(-60000,-60000);
        delay(5000);
    }
    
}