#include "MotorNoEncoder.h"
#include "SpeedStressTest.h"

#define IN1A 3
#define IN2A 4
#define PWMA 5

#define IN1B 7
#define IN2B 8
#define PWMB 9

#define IN1C 2
#define IN2C 6
#define PWMC 10

#define IN1D 12
#define IN2D 13
#define PWMD 11

MotorNoEncoder motor1;
MotorNoEncoder motor2;
MotorNoEncoder motor3;
MotorNoEncoder motor4;

void setup() 
{
  Serial.begin(9600);
  Serial.println("Motor Stress Test");
  delay(2000);

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
  SpeedStressTest(motor1, motor2, motor3, motor4);
}
