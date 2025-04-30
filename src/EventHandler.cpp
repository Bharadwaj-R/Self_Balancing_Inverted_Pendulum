#include "EventHandler.h"
#include "StateMachine.h"

/*
In the check angle state, it uses the flex sensors to check for the angle.
If mod angle is greater than 45, give up the balance.
If the mod angle is less than 45, go into the balance state.
The balance state calls the PID controller.
*/

uint32_t currentTime = 0;
uint32_t lastTime = 0;
int8_t angle = 0;
int16_t speedPID = 0;

StateVariable State = CheckAngle;

void StateMachine()
{
    currentTime = millis();

    switch(State)
    {
        /*
        case Init:
        Serial.println("Enter the Init State");
        if(angle == 0)
        {
            State = CheckAngle;
        }
        return;
        */

        /////////////////////////////////////////////////////////////////

        case CheckAngle:
        // Serial.println("Enter the Check Angle State");
        angle = FlexReading();
        Serial.println("Angle is:");
        Serial.println(angle);
        if(abs(angle) <= 40)
        {
            State = Balance;
        }
        else if(abs(angle) > 40)
        {
            State = GiveUp;
            lastTime = currentTime;
        }
        delay(50);
        return;

        /////////////////////////////////////////////////////////////////

        case Balance:
        // Serial.println("Enter the Balance State");
        speedPID = PIDController(angle);
        // Serial.println("Speed is:");
        // Serial.println(speedPID);
        MotorSpeedControl(speedPID);
        State = CheckAngle;
        delay(50);
        return;

        /////////////////////////////////////////////////////////////////

        case GiveUp:
        // Wait for 5 seconds and check if the pendulum is in 0 position again. 
        MotorSpeedControl(0);
        // Serial.println("Give Up, Waiting for 5 seconds");
        if(currentTime - lastTime > 5000)   
        {
            State = CheckAngle;
            lastTime = currentTime;
        }
        delay(50);
        return;

    }
}