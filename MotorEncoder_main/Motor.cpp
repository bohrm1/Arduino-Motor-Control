#include "Motor.h"

Motor::Motor(void){}


void Motor::CreateMotor(int pwm, int in1, int in2) 
{
  PWM = pwm;
  In1 = in1;
  In2 = in2;
}
//
//void Motor::SetPID(int kp, int ki, int kd) 
//{
//  Kp = kp;
//  Ki = ki;
//  Kd = kd;
//}

void Motor::SetMotor(int target, int kp, int ki, int kd) 
{
  long currT = micros();
  float deltaT = ((float) (currT - prevT))/( 1.0e6 );
  prevT = currT;

  // Read the position

  Serial.print(target);
  Serial.print(" ");
  Serial.print(ActualPos);
  Serial.println();
  
  // error
  noInterrupts(); // disable interrupts temporarily while reading
  int e = target - ActualPos;
  interrupts(); // turn interrupts back on

  // derivative
  float dedt = (e-eprev)/(deltaT);

  // integral
  eintegral = eintegral + e*deltaT;

  // control signal
  float u = kp*e + kd*dedt + ki*eintegral;

  float pwr = fabs(u);
  if( pwr > 255 )
  {
    pwr = 255;
  }
  
  int dir = 1;
  if(e<0)
  {
    dir = -1;
  }
  Motor::Drive(dir, pwr); 

  eprev = e;
}

void Motor::Drive(int dir, int pwr) 
{
  if(dir == 1)
  {
    analogWrite(PWM,pwr);
    digitalWrite(In1,HIGH);
    digitalWrite(In2,LOW);
  }
  else if(dir == -1)
  {
    analogWrite(PWM,pwr);
    digitalWrite(In1,LOW);
    digitalWrite(In2,HIGH);
  }
  else
  {
    digitalWrite(In1,LOW);
    digitalWrite(In2,LOW);
  }  
}

void Motor::SetPos(int pos) 
{
  ActualPos = pos;
}

int Motor::GetPos(void) 
{
  return ActualPos;
}
