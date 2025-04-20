#include <Arduino.h>

#define FLEX_PIN A0
#define LEFT_MAX_FLEX 500
#define MEAN_POS_FLEX 512
#define RIGHT_MAX_FLEX 524
#define LEFT_MAX_ANGLE -30
#define RIGHT_MAX_ANGLE 30

void setup()
{
    pinMode(FLEX_PIN, INPUT);
    Serial.begin(2000000);
}

void loop()
{
    Serial.println(analogRead(FLEX_PIN));
    // Update the #define statements accoordingly
}