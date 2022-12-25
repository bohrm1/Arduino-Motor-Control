# Arduino-Motor-Control

This repository is part of the Disaster Rover's TCNJ ECE Senior Project of 2022-2023. The most relevant directory is the MotorNoEncoder_steering_main directory. This code greatly simplifies the process of interfacing with multiple motors, especially in a robotics context.

1. MotorEncoder_main contains a MotorEncoder class that encapsulates all of the pins and functionality of a motor with encoder.

2. MotorNoEncoder_main contains a MotorNoEncoder class that encapsulates all of the pins and functionality of a motor without encoder. 

3. MotorNoEncoder_steering_main contains the MotorNoEncoder class as well as two header files with functions DriveRover() and RotateRover() to simplify rover driving, steering, and rotating. These are especially helpful since they reduce the complexity of programming four motors to achieve proper rover movement.

4. MotorSerialComms_main contains motor .ino files using the UART to accept inputs so that the rover can be controlled in real time. 

5. Tests/test_speed contains Arduino files for stress testing the motors to figure out no-load current and stall current. 
