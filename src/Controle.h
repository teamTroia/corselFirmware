#include <defines.h>
#include <motor.h>

void testeMotor(int eixoX)
{
    int ang, frente;
    if (eixoX != 0)
    {
        if (eixoX < 305)
        {
            frente = 1850;
            ang = 1200;
        }
        else if (eixoX > 335)
        {
            frente = 1850;
            ang = (1800);
        }
        else if (eixoX >= 305 && eixoX <= 335)
        {
            frente = 1850;
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
