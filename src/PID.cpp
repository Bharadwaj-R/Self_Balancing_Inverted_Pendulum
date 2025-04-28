#include "PID.h"

/*
Proportional Integral Differential controller

A set point it decided for the controller to reach. The difference between the current
position and the setpoint is the error signal.

This error is appropriately weighted proportionally, with an integration and also
differentiation to obtian the values of P, I and D.

The final output from the PID will be the speed of the motor to be controlled. This can
be achieved by adding the P, I and D individual parts.
*/

// Calculations for the PID constants in the assets folder
#define Kp_base 1.5     // Proportional Gain constant
#define Kd_base 0.3     // Differential Gain constant
#define Ki 0.01         // Integral Gain constant
#define Ap 0.03         // Alpha P, to dynamically adjust Proportional Gain constant
#define Ad 0.001        // Alpha d, to dynamically adjust Differnetial Gain constant
#define BASELINE 60

float Kp = Kp_base;
float Kd = Kd_base;

float P = 0;            // Value of Proportional output
float I = 0;            // Value of Integral output
float D = 0;            // Value of Differential output

int16_t speed = 0;      // Controls the motor speed to balance the pendulum: [-255, 255]

int16_t prevAngle = 0;
float currentPIDTime = 0;
float prevPIDTime = 0;



int16_t PIDController(int8_t angle)
{
    currentPIDTime = millis()/1000.0;

    Kp = Kp_base + float(angle*Ap);
    Kd = Kd_base + float(angle*Ad);
    if(angle == 0) I = 0;


    P = Kp * angle;
    I += Ki * angle * float(currentPIDTime - prevPIDTime);
    D = Kd * (angle - prevAngle) / float(currentPIDTime - prevPIDTime);
    speed = ceil(P + I + D);
    
    // Serial.println("PID Values");
    // Serial.println(P);
    // Serial.println(I);
    // Serial.println(D);

    if(speed > 0)
    {
        speed += BASELINE;
    }
    else if (speed <0)
    {
        speed -= BASELINE;
    }
    
    
    prevAngle = angle;
    prevPIDTime = currentPIDTime;

    return speed;
}