#include "MotorSpeed.h"

#define ENCODER_PIN 2
#define ENCODER_SLOTS 20

#define RPM_MIN 0
#define RPM_MAX 300

volatile uint32_t lastPulseTime = 0;
uint8_t motorRPM = 0;

void SpeedISR()
{    
    motorRPM = (60*1000*1000)/((micros() - lastPulseTime) * ENCODER_SLOTS);
    lastPulseTime = micros();
}

void SetupSpeed()
{
    pinMode(ENCODER_PIN, INPUT);
    attachInterrupt(digitalPinToInterrupt(ENCODER_PIN), SpeedISR, RISING);
}

uint16_t SpeedMeasure()
{
    return map(motorRPM, RPM_MIN, RPM_MAX, 0, 1024);
}