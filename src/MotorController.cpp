#include "MotorController.h"

#define ENABLE_A 3 
#define INPUT_A1 2
#define INPUT_A2 4

#define ENABLE_B 11
#define INPUT_B1 12
#define INPUT_B2 13

#define ENABLE_C 5
#define INPUT_C1 6
#define INPUT_C2 7

#define ENABLE_D 10
#define INPUT_D1 9
#define INPUT_D2 8

void SetupMotors()
{
    pinMode(ENABLE_A, OUTPUT);
    pinMode(INPUT_A1, OUTPUT);
    pinMode(INPUT_A2, OUTPUT);

    pinMode(ENABLE_B, OUTPUT);
    pinMode(INPUT_B1, OUTPUT);
    pinMode(INPUT_B2, OUTPUT);

    pinMode(ENABLE_C, OUTPUT);
    pinMode(INPUT_C1, OUTPUT);
    pinMode(INPUT_C2, OUTPUT);

    pinMode(ENABLE_D, OUTPUT);
    pinMode(INPUT_D1, OUTPUT);
    pinMode(INPUT_D2, OUTPUT);
    
}

void MotorRight()
{
    digitalWrite(INPUT_A1, HIGH);
    digitalWrite(INPUT_A2, LOW);

    digitalWrite(INPUT_B1, HIGH);
    digitalWrite(INPUT_B2, LOW);

    digitalWrite(INPUT_C1, HIGH);
    digitalWrite(INPUT_C2, LOW);

    digitalWrite(INPUT_D1, HIGH);
    digitalWrite(INPUT_D2, LOW);
}

void MotorLeft()
{
    digitalWrite(INPUT_A1, LOW);
    digitalWrite(INPUT_A2, HIGH);

    digitalWrite(INPUT_B1, LOW);
    digitalWrite(INPUT_B2, HIGH);

    digitalWrite(INPUT_C1, LOW);
    digitalWrite(INPUT_C2, HIGH);

    digitalWrite(INPUT_D1, LOW);
    digitalWrite(INPUT_D2, HIGH);
}

void MotorSpeedControl(uint16_t speed)
{
    analogWrite(ENABLE_A, speed);
    analogWrite(ENABLE_B, speed);
    analogWrite(ENABLE_C, speed);
    analogWrite(ENABLE_D, speed);
}