#ifndef Motor_h
#define Motor_h
#include "Arduino.h"

class Motor {
  private:
    int PWM;
    int In1;
    int In2;
    int ActualPos = 0;
    int Dir;

    long prevT = 0;
    float eprev = 0;
    float eintegral = 0;
    
  public:
    Motor(void);
    void CreateMotor(int pwm, int in1, int in2);
    void DrivePID(int kp, int ki, int kd, int target);
    void Drive(int dir, int pwr);
    void SetPos(int pos);
    int GetPos(void);
};
#endif