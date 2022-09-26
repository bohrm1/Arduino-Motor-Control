#include "readEncoder.h"
#include "doEncoderA.h"
#include "doEncoderB.h"
#include "Motor.h"


#define ENCA 2 // YELLOW
#define ENCB 3 // WHITE
#define PWM 9
#define IN2 8
#define IN1 7

Motor motor1;

void setup() 
{
  Serial.begin(9600);
  pinMode(ENCA, INPUT);
  pinMode(ENCB, INPUT);
  pinMode(PWM,OUTPUT);
  pinMode(IN1,OUTPUT);
  pinMode(IN2,OUTPUT);
  
  attachInterrupt(digitalPinToInterrupt(ENCA), doEncoderA, CHANGE);
  attachInterrupt(digitalPinToInterrupt(ENCB), doEncoderB, CHANGE);
  
  int kp = 2;
  int kd = .2;
  int ki = 0.02;

  motor1.CreateMotor(PWM, IN1, IN2);
  motor1.SetPID(kp, ki, kd);
}

/*##############################################################################*/
/* motor1.Drive() will compute a PID pwr signal to be sent to the motor         */
/* connected to pins IN1, IN2, and PWM. The motor position is also updated.     */
/*##############################################################################*/
void loop()
{
  int target = 2000*sin(micros()/1e6);
  motor1.SetMotor(target);

  noInterrupts();
  motor1.SetPos(posi); 
  interrupts();  
}
