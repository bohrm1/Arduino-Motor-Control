#ifndef doEncoderB_h
#define doEncoderB_h
#include "Arduino.h"

void doEncoderB() {
  int encoder1A = 2;
  int encoder1B = 3;
  int encoder2A = 0;
  int encoder2B = 0;

  if(digitalRead(3) == HIGH)
  {
    if(digitalRead(2) == LOW)
    {
      posi++;
    }
    else 
    {
      posi--;
    }
  }
  else 
  {
    if(digitalRead(2) == LOW) 
    {
      posi++;
    }
    else 
    {
      posi--;
    }
  }
}
#endif
