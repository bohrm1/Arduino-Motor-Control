#include "MotorNoEncoder.h"

#define IN1A 24
#define IN2A 25
#define PWMA 4

#define IN1B 26
#define IN2B 27
#define PWMB 5

#define IN1C 28
#define IN2C 29
#define PWMC 6

#define IN1D 30
#define IN2D 31
#define PWMD 7

MotorNoEncoder motor1;
MotorNoEncoder motor2;
MotorNoEncoder motor3;
MotorNoEncoder motor4;

void setup() 
{
  pinMode(PWMA,OUTPUT);
  pinMode(IN1A,OUTPUT);
  pinMode(IN2A,OUTPUT);
  
  pinMode(PWMB,OUTPUT);
  pinMode(IN1B,OUTPUT);
  pinMode(IN2B,OUTPUT);

  pinMode(PWMC,OUTPUT);
  pinMode(IN1C,OUTPUT);
  pinMode(IN2C,OUTPUT);
  
  pinMode(PWMD,OUTPUT);
  pinMode(IN1D,OUTPUT);
  pinMode(IN2D,OUTPUT);
  
  motor1.ConnectPins(IN1A, IN2A, PWMA);
  motor2.ConnectPins(IN1B, IN2B, PWMB);
  motor3.ConnectPins(IN1C, IN2C, PWMC);
  motor4.ConnectPins(IN1D, IN2D, PWMD);
}

void loop() 
{
  motor1.Drive(255);
  motor2.Drive(255);
  motor3.Drive(255);
  motor4.Drive(255);
}
