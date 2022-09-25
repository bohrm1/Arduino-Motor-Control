#ifndef DriveRover_h
#define DriveRover_h
#include "MotorNoEncoder.h"
#include "Arduino.h"

//BLAH BLAH TESTING MAIN VS MASTER

void DriveRover (int pwr, int dir, MotorNoEncoder &motor1, MotorNoEncoder &motor2, MotorNoEncoder &motor3, MotorNoEncoder &motor4) 
{
    if (pwr != 0) 
    {
        int turning_power  = 30;
        if (pwr < 0) 
        {
            turning_power = -1 * turning_power;
        }

        if (dir == -1) 
        {
            motor1.Drive(pwr);
            motor2.Drive(pwr+30);
            motor3.Drive(pwr);
            motor4.Drive(pwr+30);     
        }
        else if (dir == 1) 
        {
            motor1.Drive(pwr+30);
            motor2.Drive(pwr);
            motor3.Drive(pwr+30);
            motor4.Drive(pwr);
        }
        else if (dir == 0)
        {
            motor1.Drive(pwr);
            motor2.Drive(pwr);
            motor3.Drive(pwr);
            motor4.Drive(pwr);
        }
        else 
        {
        }
    }
    else 
    {
        motor1.Drive(0);
        motor2.Drive(0);
        motor3.Drive(0);
        motor4.Drive(0);
    }
}
#endif
