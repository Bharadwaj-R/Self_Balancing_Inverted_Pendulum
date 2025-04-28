#include <Arduino.h>

#define FLEX_PIN A0
#define MEAN_POS_FLEX 517
#define LEFT_MAX_FLEX 512
#define RIGHT_MAX_FLEX 522
#define LEFT_MAX LEFT_MAX_FLEX - MEAN_POS_FLEX
#define RIGHT_MAX RIGHT_MAX_FLEX - MEAN_POS_FLEX
#define LEFT_MAX_ANGLE -45
#define RIGHT_MAX_ANGLE 45

void setup()
{
    pinMode(FLEX_PIN, INPUT);
    Serial.begin(2000000);
}

void loop()
{
    Serial.println(analogRead(FLEX_PIN));
    delay(1000);
    // Serial.println(map(analogRead(FLEX_PIN) - MEAN_POS_FLEX, LEFT_MAX, RIGHT_MAX, LEFT_MAX_ANGLE, RIGHT_MAX_ANGLE));
}