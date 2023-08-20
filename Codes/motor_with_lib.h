#include <MX1508.h>


#define PINA1 10  // IN1 LEFT MOTOR
#define PINA2 9   // IN2
#define PINB1 6   // IN3 RIGHT MOTOR
#define PINB2 5   // IN4
#define NUMPWM 2

MX1508 motorL(PINA1, PINA2, FAST_DECAY, NUMPWM);
MX1508 motorR(PINB1, PINB2, FAST_DECAY, NUMPWM);

//int leftPwm = 150;
//int rightPwm = 150;

void forward(){
  motorL.motorGo(leftPwm);
  motorR.motorGo(rightPwm);
}

void reverse(){
  motorL.motorGo(-1*leftPwm);
  motorR.motorGo(-1*rightPwm);
}

void turnLeft(){
  motorL.motorGo(-1*leftBase);
  motorR.motorGo(rightBase);
}

void turnRiht(){
  motorL.motorGo(leftBase);
  motorR.motorGo(-1*rightBase);
}

void brake(){
  motorL.stopMotor();
  motorR.stopMotor();
}

void forwardBase(){
  motorL.motorGo(leftBase);
  motorR.motorGo(rightBase);
}

void reverseBase(){
  motorL.motorGo(-1*leftBase);
  motorR.motorGo(-1*rightBase);
}
