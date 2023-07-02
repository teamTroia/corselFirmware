#include <defines.h>
#include <motor.h>

void testeMotor(int eixoX)
{
    int ang, frente;
    if (eixoX != 0)
    {
        if (eixoX > 0 && eixoX < 280)
        {
            frente = 1925;
            ang = 1160;
        }
        else if (eixoX > 380)
        {
            frente = 1925;
            ang = 1840;
        }
        else if (eixoX >= 280 && eixoX <= 380)
        {
            frente = 1925;
            ang = 1500;
        }
    }
    else
    {
        frente = 1500;
        ang = 1500;
    }

    FW_PKS.writeMicroseconds(frente);
    ANG_PKS.writeMicroseconds(ang);
    delay(1000);
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
