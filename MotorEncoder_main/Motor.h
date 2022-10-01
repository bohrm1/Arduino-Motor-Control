#ifndef Motor_h
#define Motor_h
#include "Arduino.h"

class Motor 
{
  private:
    int PWM;                               //creating member variables to describe motor with encoder
    int In1;
    int In2;
    int ActualPos = 0; 
    int Dir;

    int Kp = 0;                            //constants for PID controller internal to class
    int Ki = 0;
    int Kd = 0;

    long prevT = 0;
    float eprev = 0;
    float eintegral = 0;
    
  public:
    Motor(void);
    void CreateMotor(int pwm, int in1, int in2);
    void SetPID(int kp, int ki, int kd);
    void SetMotor(int target);
    void Drive(int dir, int pwr);
    void SetPos(int pos);
    int GetPos(void);
};
#endif
