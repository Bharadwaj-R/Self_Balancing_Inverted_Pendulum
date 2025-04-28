#include "FlexController.h"

/*
[Cable away from us]
Left flex is connected to power, right is connected to ground.
If the pendulum moves towards right, resistance increases, value increases -> positive angle
If the pendulum moves towards left, resistnace decreases, value decreases -> negative angle
*/


/*
#define FLEX_PIN A0
#define LEFT_MAX_FLEX 0
#define RIGHT_MAX_FLEX 658
#define LEFT_MAX_ANGLE -90
#define RIGHT_MAX_ANGLE 90

void SetupFlex()
{
    pinMode(FLEX_PIN, INPUT);
}



int8_t FlexReading()
{
    Serial.println(analogRead(FLEX_PIN));
    return(map(analogRead(FLEX_PIN), LEFT_MAX_FLEX, RIGHT_MAX_FLEX, LEFT_MAX_ANGLE, RIGHT_MAX_ANGLE));
}
*/


#define FLEX_PIN A0
#define MEAN_POS_FLEX 517
#define LEFT_MAX_FLEX 512
#define RIGHT_MAX_FLEX 522
#define LEFT_MAX LEFT_MAX_FLEX - MEAN_POS_FLEX
#define RIGHT_MAX RIGHT_MAX_FLEX - MEAN_POS_FLEX
#define LEFT_MAX_ANGLE -45
#define RIGHT_MAX_ANGLE 45
// Update the pre-processor directives from calibration, from /test/FlexTesting.cpp

void SetupFlex()
{
    pinMode(FLEX_PIN, INPUT);
}


int8_t FlexReading()
{
    return (map(analogRead(FLEX_PIN) - MEAN_POS_FLEX, LEFT_MAX, RIGHT_MAX, LEFT_MAX_ANGLE, RIGHT_MAX_ANGLE));
}
