#ifndef speed_stress_test_h
#define speed_stress_test_h
#include "Arduino.h"

void speed_test_stress(MotorNoEncoder &motor1, MotorNoEncoder &motor2, MotorNoEncoder &motor3, MotorNoEncoder &motor4)  
{
    int maxSpeed = 255;
    int minSpeed = 0;

    Serial.print("ALL MOTORS ON FULL SPEED");
    Serial.print("");
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

    Serial.print("MOTOR 1 FULL SPEED");
    Serial.print("")
    motor1.Drive(maxSpeed);
    Delay(2000);
    motor1.Drive(minSpeed);
    delay(3000);

    Serial.print("MOTOR 2 FULL SPEED");
    Serial.print("")
    motor2.Drive(maxSpeed);
    Delay(2000);
    motor2.Drive(minSpeed);
    delay(3000);

    Serial.print("MOTOR 3 FULL SPEED");
    Serial.print("")
    motor3.Drive(maxSpeed);
    Delay(2000);
    motor3.Drive(minSpeed);
    delay(3000);

    Serial.print("MOTOR 4 FULL SPEED");
    Serial.print("")
    motor4.Drive(maxSpeed);
    Delay(2000);
    motor4.Drive(minSpeed);
    delay(3000);
}
#endif 