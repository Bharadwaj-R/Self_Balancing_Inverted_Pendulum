#include "EventHandler.h"
#include "StateMachine.h"

/*
Init state is the initial state. 
Once the angle received is not 0, then the system moves into the check angle state.
In the check angle state, it uses the flex sensors to check for the angle.
If mod angle is greater than 25, give up the balance.
If the mod angle is less than 25, go into the balance state.
The balance state calls the PID controller.
*/

uint32_t currentTime = 0;
uint32_t lastTime = 0;
int8_t angle = 0;
int16_t speedPID = 0;

StateVariable State = Init;

void StateMachine()
{
    currentTime = millis();

    switch(State)
    {
        case Init:
        Serial.println("Enter the Init State");
        if(angle == 0)
        {
            State = CheckAngle;
        }
        return;

        /////////////////////////////////////////////////////////////////

        case CheckAngle:
        Serial.println("Enter the Check Angle State");
        noInterrupts();
        angle = FlexReading();
        if(abs(angle) > 0 && abs(angle) <= 25)
        {
            State = Balance;
        }
        else if(abs(angle) > 25)
        {
            State = GiveUp;
            lastTime = currentTime;
        }
        else
        {
            State = CheckAngle;
        }
        return;

        /////////////////////////////////////////////////////////////////

        case Balance:
        interrupts();
        Serial.println("Enter the Balance State");
        speedPID = PIDController(angle);
        MotorSpeedControl(speedPID);
        State = CheckAngle;
        return;

        /////////////////////////////////////////////////////////////////

        case GiveUp:
        // Wait for 5 seconds and check if the pendulum is in 0 position again. 
        noInterrupts();
        Serial.println("Give Up, Waiting for 10 seconds");
        if(currentTime - lastTime > 5000)
        {
            State = CheckAngle;
            lastTime = currentTime;
        }
        return;

    }
}