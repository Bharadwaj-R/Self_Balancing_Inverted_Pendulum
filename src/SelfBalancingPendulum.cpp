#include "EventHandler.h"

void setup()
{
    SetupFlex();
    SetupMotors();
    // SetupSpeed();
    Serial.begin(2000000);
    Serial.println("Setup Successful");
}

void loop()
{
    StateMachine();
}