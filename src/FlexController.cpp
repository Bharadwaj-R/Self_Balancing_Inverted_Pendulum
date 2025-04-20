#include "FlexController.h"

#define FLEX_PIN A0
#define LEFT_MAX_FLEX 500    // Update from calibration
#define MEAN_POS_FLEX 512
#define RIGHT_MAX_FLEX 524   // Update from calibration
#define LEFT_MAX_ANGLE -30
#define RIGHT_MAX_ANGLE 30

void SetupFlex()
{
    pinMode(FLEX_PIN, INPUT);
}

void Testing()  //  For calibration
{
    pinMode(FLEX_PIN, INPUT);
    Serial.println(analogRead(FLEX_PIN));
}

int8_t FlexReading()
{
    return (MEAN_POS_FLEX - (analogRead(FLEX_PIN), LEFT_MAX_FLEX, RIGHT_MAX_FLEX, LEFT_MAX_ANGLE, RIGHT_MAX_ANGLE));
}