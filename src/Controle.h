#include <defines.h>
#include <motor.h>

int ang, frente;

float PID(float target, float atual)
{
    float kp = 1800;

    float error = target - atual;
    float output = error * kp;
    return output;
}

void testeMotor(int eixoX)
{
    if (eixoX != 0)
    {
        float giro = readAngularSpeed();
        int Angularspeed = PID(0, giro);
        if (eixoX > 0 && eixoX < 280) //220
        {
            frente = 1340;
            int cont;
            for(int cont = 14; cont >= 0; cont--){
                ang = 1140+cont;    //1156
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
        else if (eixoX >= 280 && eixoX <= 420) //280
        {
           for(int cont = 0; cont>=14; cont++){
                frente = 1920-cont;
                FW_PKS.writeMicroseconds(frente);
                if(Angularspeed>-1){
                    ANG_PKS.writeMicroseconds(1500-Angularspeed);
                }
                else{
                    ANG_PKS.writeMicroseconds(1500);
                }

            }
        }
    }
    delay(400);
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