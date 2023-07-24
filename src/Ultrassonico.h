#include <defines.h>
long duracao;
int distancia;

void initUltrassonico()
{
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

int distCone()
{
  // Clears the trigPin
  digitalWrite(trigPin, LOW);
  // delayMicroseconds(2);
  //  Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH);
  // delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duracao = pulseIn(echoPin, HIGH);
  // Calculating the distance
  distancia = duracao * 0.034 / 2;
  // Prints the distance on the Serial Monitor
  if (distancia > 5)
  {
    Serial.print("Distance: ");
    Serial.println(distancia);
    return distancia;
  }
}
