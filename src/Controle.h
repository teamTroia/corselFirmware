#include <defines.h>
#include <motor.h>

int ang, frente;
void testeMotor(int eixoX)
{
    if (eixoX != 0)
    {
        if (eixoX > 0 && eixoX < 220)
        {
            frente = 1340;
            int cont;
            for(int cont = 14; cont >= 0; cont--){
                ang = 1156+cont;    
                FW_PKS.writeMicroseconds(frente);
                ANG_PKS.writeMicroseconds(ang);
            }
        }
        else if (eixoX > 420)
        {
            frente = 1760;
            for(int cont = 14; cont>=0; cont--){
                ang = 1894-cont;
                FW_PKS.writeMicroseconds(frente);
                ANG_PKS.writeMicroseconds(ang);
            }
        }
        else if (eixoX >= 220 && eixoX <= 420)
        {
           ang = 1500;
           for(int cont = 14; cont>=0; cont--){
                frente = 1879-cont;
                FW_PKS.writeMicroseconds(frente);
                ANG_PKS.writeMicroseconds(ang);
            }
        }
    }
    delay(400);
}

float PID(float target, float atual)
{
    float kp = 60;

    float error = target - atual;
    float output = error * kp;
    return output;
}

float pidCamera(int target, int atual)
{
    int kp = 0.00035;

    int error = target - atual;
    int output = error * kp;
    return output;
}

void align(int eixoX){
    float gyro = readAngularSpeed();
}

void getpulse(int frente, int ang){
    FW_PKS.writeMicroseconds(frente);
    ANG_PKS.writeMicroseconds(ang);
    
}