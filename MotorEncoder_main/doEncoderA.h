#ifndef doEncoderA_h
#define doEncoderA_h
#include "Arduino.h"


void doEncoderA() {
  int encoder1A = 2;
  int encoder1B = 3;
  int encoder2A = 0;
  int encoder2B = 0;
  
  if(digitalRead(2) == HIGH) 
  {
    if(digitalRead(3) == LOW)
    {
      posi++;
    }
    else
    {
      posi--;
    }
  }
  else {
    if(digitalRead(3) == HIGH) 
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
