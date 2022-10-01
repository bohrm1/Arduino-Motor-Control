#ifndef MotorNoEncoder_h
#define MotorNoEncoder_h
#include "Arduino.h"

class MotorNoEncoder 
{
  private:
    int In1;           //arduino pin connected to In1 and In2 of motor driver for motor
    int In2;           
    int PWMPin;        //arduino pin connected sending pwm to be amplified by driver for motor
  public:
    MotorNoEncoder(void);
    void ConnectPins(int in1, int in2, int pwmPin);     
    void Drive(int pwr);
};
#endif
