#include "FlexController.h"

#define FLEX_PIN A0
#define LEFT_MAX_FLEX 500
#define MEAN_POS_FLEX 512
#define RIGHT_MAX_FLEX 524
#define LEFT_MAX_ANGLE -30
#define RIGHT_MAX_ANGLE 30
// Update the pre-processor directives from calibration, from /test/FlexTesting.cpp

void SetupFlex()
{
    pinMode(FLEX_PIN, INPUT);
}

void LoopTesting()  //  For calibration
{
    Serial.begin(2000000);
    pinMode(FLEX_PIN, INPUT);
    Serial.println(analogRead(FLEX_PIN));
}

int8_t FlexReading()
{
    return (MEAN_POS_FLEX - map(analogRead(FLEX_PIN), LEFT_MAX_FLEX, RIGHT_MAX_FLEX, LEFT_MAX_ANGLE, RIGHT_MAX_ANGLE));
}