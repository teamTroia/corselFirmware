#ifndef ODOMETRIA_H
#define ODOMETRIA_H

#include <Encoder.h>
#include <math.h>
#include <defines.h>

double raioRoda = 30;
double voltas, distEsq, distDir, distAnt, distPercorrido;
long positionEsq, positionDir, newPosEsq, newPosDir;
Encoder ENCESC(DE1, DE2);
Encoder ENCDIR(DE3, DE4);

int getDistPercorrida(Encoder encoder, long position, long newPos, double dist)
{
    newPos = encoder.read();
    if (newPos != position)
    {
        position = newPos;
    }
    voltas = position/400; 

    dist = (2 * raioRoda * PI) * voltas;
    distPercorrido = dist - distAnt;
    distAnt = dist;

    Serial.println("Distância Percorrida roda: ");
    Serial.println(distPercorrido);

    return distPercorrido;
}

void getPosicao(Encoder encoder, long position, long newPos){

    newPos = encoder.read();
    if (newPos != position)
    {
        position = newPos;
    }
    Serial.println("Posição encoder: ");
    Serial.println(position);

}

int Velocidade(Encoder encoder ,long position, long newPos, double dist){
    int tempo = millis();
    int deltaS,aproxVel,S0;
    S0 = getDistPercorrida(encoder, position, newPos, dist);
    while(millis()-tempo < 10){
        deltaS  = S0 + getDistPercorrida(encoder, position, newPos, dist);
    }
    aproxVel = deltaS/10;
    tempo = millis();
    return aproxVel;
}

#endif