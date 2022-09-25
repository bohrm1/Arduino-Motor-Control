#include "Arduino.h"
#include "MotorNoEncoder.h"

MotorNoEncoder::MotorNoEncoder(void){}
void MotorNoEncoder::ConnectPins(int in1, int in2, int pwmPin) {
  In1 = in1;
  In2 = in2;
  PWMPin = pwmPin;
}
void MotorNoEncoder::Drive(int pwr) {
    analogWrite(PWMPin, abs(pwr));
    if (pwr < 0) { 
      digitalWrite(In1,HIGH);
      digitalWrite(In2,LOW);
    }
    else if (pwr >= 0) {
      digitalWrite(In1,LOW);
      digitalWrite(In2,HIGH);
    }
    else {
      digitalWrite(In1,LOW);
      digitalWrite(In2,LOW);
    }
}
