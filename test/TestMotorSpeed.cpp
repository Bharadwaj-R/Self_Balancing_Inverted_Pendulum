#include <Arduino.h>

#define ENCODER_PIN 2
#define ENCODER_SLOTS 20

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

// Update from testing
#define RPM_MIN 0
#define RPM_MAX 300

volatile uint32_t lastPulseTime = 0;
uint8_t motorRPM = 0;

void SpeedISR()
{    
    motorRPM = (60*1000*1000)/((micros() - lastPulseTime) * ENCODER_SLOTS);
    lastPulseTime = micros();
}

void Setup()
{
    pinMode(ENCODER_PIN, INPUT);
    attachInterrupt(digitalPinToInterrupt(ENCODER_PIN), SpeedISR, RISING);
    Serial.begin(2000000);

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
}

void loop ()
{
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
    
    Serial.println(motorRPM);
}
