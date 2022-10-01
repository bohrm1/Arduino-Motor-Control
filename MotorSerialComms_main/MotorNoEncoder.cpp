#include "Arduino.h"
#include "MotorNoEncoder.h"

MotorNoEncoder::MotorNoEncoder(void){}

//ConnectPins is used for holding the arduino pins connected to the motor instance
void MotorNoEncoder::ConnectPins(int in1, int in2, int pwmPin) 
{
  In1 = in1;
  In2 = in2;
  PWMPin = pwmPin;
}

//to turn motor forward, In1 HIGH and In2 LOW
//to turn backwards, In1 LOW and In2 HIGH
//pwr corresponds to pwm signal, value ranges from 0-255
//use analogWrite() to send pwm signal 
void MotorNoEncoder::Drive(int pwr) 
{
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
