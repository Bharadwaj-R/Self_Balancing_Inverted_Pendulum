#include "MotorController.h"

#define ENABLE_A 3  // High -- for same direction rotation of 2 motors
#define INPUT_A1 A1 // High -- In1::In4
#define INPUT_A2 A2 // Low  -- In2::In3
#define INPUT_B1 12 // Low
#define INPUT_B2 13 // High
#define ENABLE_B 11 // High

#define ENABLE_C 5
#define INPUT_C1 6
#define INPUT_C2 7
#define INPUT_D1 9
#define INPUT_D2 8
#define ENABLE_D 10

void MotorLeft();
void MotorRight();


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

void MotorSpeedControl(int16_t speed)
{
    if (speed > 0)
    {
        analogWrite(ENABLE_A, speed);
        analogWrite(ENABLE_B, speed);
        analogWrite(ENABLE_C, speed);
        analogWrite(ENABLE_D, speed);
        MotorRight();
    }
    else if (speed < 0)
    {
        analogWrite(ENABLE_A, -(speed));
        analogWrite(ENABLE_B, -(speed));
        analogWrite(ENABLE_C, -(speed));
        analogWrite(ENABLE_D, -(speed));
        MotorLeft();
    }
    else
    {
        analogWrite(ENABLE_A, 0);
        analogWrite(ENABLE_B, 0);
        analogWrite(ENABLE_C, 0);
        analogWrite(ENABLE_D, 0);
    }
    return;
}

void MotorRight()
{
    digitalWrite(INPUT_A1, LOW);
    digitalWrite(INPUT_A2, HIGH);

    digitalWrite(INPUT_B1, HIGH);
    digitalWrite(INPUT_B2, LOW);
    
    digitalWrite(INPUT_C1, LOW);
    digitalWrite(INPUT_C2, HIGH);

    digitalWrite(INPUT_D1, HIGH);
    digitalWrite(INPUT_D2, LOW);
}

void MotorLeft()
{
    digitalWrite(INPUT_A1, HIGH);
    digitalWrite(INPUT_A2, LOW);

    digitalWrite(INPUT_B1, LOW);
    digitalWrite(INPUT_B2, HIGH);

    digitalWrite(INPUT_C1, HIGH);
    digitalWrite(INPUT_C2, LOW);
    
    digitalWrite(INPUT_D1, LOW);
    digitalWrite(INPUT_D2, HIGH);
}