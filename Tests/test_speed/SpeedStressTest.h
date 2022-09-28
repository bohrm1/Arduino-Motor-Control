#ifndef SpeedStressTest_h
#define SpeedStressTest_h
#include "Arduino.h"

void SpeedStressTest(MotorNoEncoder &motor1, MotorNoEncoder &motor2, MotorNoEncoder &motor3, MotorNoEncoder &motor4)  
{
    int maxSpeed = 255;
    int minSpeed = 0;


    Serial.println("All Motors Test");
    delay(1000);
    Serial.println("3");
    delay(1000);
    Serial.println("2");
    delay(1000);
    Serial.println("1");
    delay(1000);
    delay(2000);
    Serial.println("ALL MOTORS ON FULL SPEED");
    Serial.println("");
    motor1.Drive(maxSpeed);
    motor2.Drive(maxSpeed);
    motor3.Drive(maxSpeed);
    motor4.Drive(maxSpeed);
    delay(2000);
    motor1.Drive(minSpeed);
    motor2.Drive(minSpeed);
    motor3.Drive(minSpeed);
    motor4.Drive(minSpeed);
    delay(3000);

    Serial.println("Motor 1 Test");
    delay(1000);
    Serial.println("3");
    delay(1000);
    Serial.println("2");
    delay(1000);
    Serial.println("1");
    delay(1000);
    Serial.println("MOTOR 1 FULL POWER");
    Serial.println("");
    motor1.Drive(maxSpeed);
    delay(2000);
    motor1.Drive(minSpeed);
    delay(3000);


    Serial.println("Motor 2 Test");
    delay(1000);
    Serial.println("3");
    delay(1000);
    Serial.println("2");
    delay(1000);
    Serial.println("1");
    delay(1000);
    Serial.println("MOTOR 2 FULL POWER");
    Serial.println("");
    motor2.Drive(maxSpeed);
    delay(2000);
    motor2.Drive(minSpeed);
    delay(3000);


    Serial.println("Motor 3 Test");
    delay(1000);
    Serial.println("3");
    delay(1000);
    Serial.println("2");
    delay(1000);
    Serial.println("1");
    delay(1000);
    Serial.println("MOTOR 3 FULL POWER");
    Serial.println("");
    motor3.Drive(maxSpeed);
    delay(2000);
    motor3.Drive(minSpeed);
    delay(3000);


    Serial.println("Motor 4 Test");
    delay(1000);
    Serial.println("3");
    delay(1000);
    Serial.println("2");
    delay(1000);
    Serial.println("1");
    delay(1000);
    Serial.println("MOTOR 4 FULL POWER");
    Serial.println("");
    motor4.Drive(maxSpeed);
    delay(2000);
    motor4.Drive(minSpeed);
    delay(3000);
}
#endif 
