#include <Arduino.h>

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

void setup()
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

void loop()
{
    // LEFT MOVEMENT - cable away form us - left AB right CD
    digitalWrite(ENABLE_A, HIGH);
    digitalWrite(INPUT_A1, HIGH);
    digitalWrite(INPUT_A2, LOW);
    digitalWrite(INPUT_B1, LOW);
    digitalWrite(INPUT_B2, HIGH);
    digitalWrite(ENABLE_B, HIGH);

    digitalWrite(ENABLE_C, HIGH);
    digitalWrite(INPUT_C1, HIGH);
    digitalWrite(INPUT_C2, LOW);
    digitalWrite(INPUT_D1, LOW);
    digitalWrite(INPUT_D2, HIGH);
    digitalWrite(ENABLE_D, HIGH);
    delay(5000);

    // RIGHT MOVEMENT - cable away form us - left AB right CD
    digitalWrite(ENABLE_A, HIGH);
    digitalWrite(INPUT_A1, LOW);
    digitalWrite(INPUT_A2, HIGH);
    digitalWrite(INPUT_B1, HIGH);
    digitalWrite(INPUT_B2, LOW);
    digitalWrite(ENABLE_B, HIGH);
    
    digitalWrite(ENABLE_C, HIGH);
    digitalWrite(INPUT_C1, LOW);
    digitalWrite(INPUT_C2, HIGH);
    digitalWrite(INPUT_D1, HIGH);
    digitalWrite(INPUT_D2, LOW);
    digitalWrite(ENABLE_D, HIGH);
    delay(5000);  

}