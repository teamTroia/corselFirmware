#include <Arduino.h>
#include <Wire.h>

#define SD1_PK1 PA1
#define SD2_PK1 PA3
#define SD1_PK2 PB0
#define SD2_PK2 PA6

#define ENB1_PK1 PA0
#define ENB2_PK1 PA2
#define ENB1_PK2 PB1
#define ENB2_PK2 PA7

#define Wire WIRE2
#define MPU_ADDR 0x68