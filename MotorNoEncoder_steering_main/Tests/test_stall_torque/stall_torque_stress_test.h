#ifndef stall_torque_stress_test_h
#define stall_torque_test_h
#include "Arduino.h"

void speed_test_stress(MotorNoEncoder &motor1, MotorNoEncoder &motor2, MotorNoEncoder &motor3, MotorNoEncoder &motor4)  
{
    int maxSpeed = 255;
    int minSpeed = 0;

    Serial.print("3");
    delay(1000);
    Serial.print("2");
    delay(1000);
    Serial.print("1");
    delay(1000);
    Serial.print("MOTOR 1 FULL POWER");
    Serial.print("")
    motor1.Drive(maxSpeed);
    Delay(2000);
    motor1.Drive(minSpeed);
    delay(3000);

    Serial.print("3");
    delay(1000);
    Serial.print("2");
    delay(1000);
    Serial.print("1");
    delay(1000);
    Serial.print("MOTOR 2 FULL POWER");
    Serial.print("")
    motor2.Drive(maxSpeed);
    Delay(2000);
    motor2.Drive(minSpeed);
    delay(3000);

    Serial.print("3");
    delay(1000);
    Serial.print("2");
    delay(1000);
    Serial.print("1");
    delay(1000);
    Serial.print("MOTOR 3 FULL POWER");
    Serial.print("")
    motor3.Drive(maxSpeed);
    Delay(2000);
    motor3.Drive(minSpeed);
    delay(3000);

    Serial.print("3");
    delay(1000);
    Serial.print("2");
    delay(1000);
    Serial.print("1");
    delay(1000);
    Serial.print("MOTOR 4 FULL POWER");
    Serial.print("")
    motor4.Drive(maxSpeed);
    Delay(2000);
    motor4.Drive(minSpeed);
    delay(3000);
}
#endif 