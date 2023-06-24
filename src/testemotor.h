#include <defines.h>
#include <motor.h>


void testeMotor() {
    while (true) {

        Serial.print("Ta indo");
        FW_PKS.writeMicroseconds(2000);
        ANG_PKS.writeMicroseconds(1200);
    }
}