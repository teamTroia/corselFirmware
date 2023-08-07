#include <defines.h>
#include <motor.h>

int ang, frente;

float PID(float target, float atual)
{
    float kp = 500;   //500 day4

    float error = target - atual;
    float output = error * kp;
    return output;
}

void testeMotor(int eixoX)
{
    if (eixoX != 0)
    {
        if (eixoX >= 280 && eixoX <= 421) // 280
        {
            frente = 1878;
            FW_PKS.writeMicroseconds(frente);
            ANG_PKS.writeMicroseconds(1500);
        }
        else if (eixoX > 421 && eixoX < 500)
        {
            frente = 1760;
            ang = 1880;
            FW_PKS.writeMicroseconds(frente);
            ANG_PKS.writeMicroseconds(ang);
        }
        else if (eixoX >= 10 && eixoX < 280) // 220
        {
            frente = 1340;
            ang = 1105; // 1140 // 1080 day1 RCX 32% de forca no giro.
            FW_PKS.writeMicroseconds(frente);
            ANG_PKS.writeMicroseconds(ang);
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

void getpulse(int frente, int ang)
{
    FW_PKS.writeMicroseconds(frente);
    ANG_PKS.writeMicroseconds(ang);
}