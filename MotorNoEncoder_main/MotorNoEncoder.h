#ifndef MotorNoEncoder_h
#define MotorNoEncoder_h
#include "Arduino.h"

class MotorNoEncoder {
  private:
    int In1;
    int In2;
    int PWMPin;
  public:
    MotorNoEncoder(void);
    void ConnectPins(int in1, int in2, int pwmPin);
    void Drive(int pwr);
};
#endif
