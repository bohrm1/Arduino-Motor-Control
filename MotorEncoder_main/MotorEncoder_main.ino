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
  
/*##############################################################################*/
/* Two external interrupts on the arduino are attached to the two quadrature    */
/* encoders on the motor with encoder. When the motor rotates, the encoder      */
/* is triggered. The digitalPinToInterrupt() converts the arduino pin           */
/* number to the interrupt number which in this case is 0 and 1. So,            */
/* we are attaching interrupts 0 and 1 to arduino pins 2 and 3 that trigger on  */  
/* on either the rising or falling edge (hence CHANGE), and will invoke the ISR */
/* function called doEncoderA if ENCA triggers and doEncoderB if ENCB triggers  */
/*##############################################################################*/
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
  //micros() function returns microseconds since start of program. 
  int target = 2000*sin(micros()/1e6);
  motor1.SetMotor(target);

  //disabling interrupts while updating motor position 
  noInterrupts();
  motor1.SetPos(posi); 
  interrupts();  
}
/*##############################################################################*/
/* The encoder counter ISR can trigger multiple times inbetween                 */
/* motor.SetPos(pos) instances, so the ActuaLPos member variable will           */
/* have worse resolution than the posi variable.                                */
/*##############################################################################*/
