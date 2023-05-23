#include "MotorNoEncoder.h"
#include "DriveRover.h"
#include "RotateRover.h"

#define IN1A 24
#define IN2A 25
#define PWMA 4

#define IN1B 27
#define IN2B 26
#define PWMB 5

#define IN1C 28
#define IN2C 29
#define PWMC 6

#define IN1D 31
#define IN2D 30
#define PWMD 7

#define buzzerPin 8

MotorNoEncoder motor1;
MotorNoEncoder motor2;
MotorNoEncoder motor3;
MotorNoEncoder motor4;

int x;

void doNothing(void)
{
  tone(buzzerPin, 1000); // play a tone of 2000Hz on the buzzer
  delay(1000); // wait for 1 second
  noTone(buzzerPin); // stop the tone
  delay(1000); // wait for 1 second
  while(1);
}
void setup() 
{
  Serial.begin(115200);
  Serial.setTimeout(1);

  pinMode(buzzerPin, OUTPUT);
  pinMode(LED_BUILTIN, OUTPUT);
  
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

  delay(2000);
}

void loop() 
{
//
//DriveRover(255, 0, &motor1, &motor2, &motor4, &motor3);
//delay(10000);
//  
//DriveRover(0, 0, &motor1, &motor2, &motor4, &motor3);
//delay(1500);
//
//doNothing();


  // DriveRover(200, 0, &motor1, &motor2, &motor4, &motor3);
  // delay(3000);

  // DriveRover(-200, 0, &motor1, &motor2, &motor4, &motor3);
  // delay(3000);
  
  // RotateRover(200, &motor1, &motor2, &motor4, &motor3);
  // delay(3000);

  // RotateRover(-200, &motor1, &motor2, &motor4, &motor3);
  // delay(4000);

  // DriveRover(0, 0, &motor1, &motor2, &motor4, &motor3);
  // delay(1500);

  // DriveRover(0, 0, &motor1, &motor2, &motor4, &motor3);
  // doNothing();
  //  
  //  RotateRover(100, motor1, motor2, motor4, motor3);
  //  delay(3000);
  //  DriveRover(0, 0, &motor1, &motor2, &motor4, &motor3);
  //  doNothing();
  
  
while(!Serial.available());
int drivePower = Serial.readString().toInt();
int rotatePower = 50;
drivePower = constrain(drivePower, 0, 75);

/*
 * 1 = left forward 
 * 2 = straight forward
 * 3 = right forward
 * 4 = rotate left
 * 5 = rotate right
 * 6 = left backward
 * 7 = backward 
 * 8 = right backward 
 */


if(drivePower == 0) 
{
 DriveRover(0, 0, &motor1, &motor2, &motor4, &motor3);
 delay(5);
}
if(drivePower == 1) 
{
 DriveRover(200, -1, &motor1, &motor2, &motor4, &motor3);
}
else if (drivePower == 2)
{
  DriveRover(200, 0, &motor1, &motor2, &motor4, &motor3);
  delay(5);
}
else if (drivePower == 3)
{
  DriveRover(200, 1, &motor1, &motor2, &motor3, &motor4);
  delay(5);
}
else if (drivePower == 4)
{
 RotateRover(-100, &motor1, &motor2, &motor4, &motor3);
 delay(5);
}
else if (drivePower == 5)
{ 
 RotateRover(100, &motor1, &motor2, &motor4, &motor3);
 delay(5);
}
else if (drivePower == 6)
{
 DriveRover(-200, -1, &motor1, &motor2, &motor4, &motor3);
 delay(5);
}
else if (drivePower == 7)
{
 DriveRover(-200, 0, &motor1, &motor2, &motor4, &motor3);
 delay(5);
}
else if (drivePower == 8)
{
 DriveRover(-200, 1, &motor1, &motor2, &motor4, &motor3);
 delay(5);
}
delay(2);
}
