#ifndef DriverRover_h
#define DriveRover_h
#include "MotorNoEncoder.h"
#include "Arduino.h"

void RotateRover (int pwr, MotorNoEncoder &motor1, MotorNoEncoder &motor2, MotorNoEncoder &motor3, MotorNoEncoder &motor4) 
{
    motor1.Drive(pwr);
    motor2.Drive(-pwr);
    motor3.Drive(pwr);
    motor4.Drive(-pwr);
}
#endif
