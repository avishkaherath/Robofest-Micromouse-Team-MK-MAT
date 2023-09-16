void countLeftOut1()
{
  leftEncoder ++;
}

void countRightOut1()
{
  rightEncoder ++;
}

//---------------------------------------------------


void leftForward(int Pwm)
{
  analogWrite(PINL1, Pwm);
  analogWrite(PINL2, 1);
}

void leftReverse(int Pwm)
{
  analogWrite(PINL2, Pwm);
  analogWrite(PINL1, 1);
}

void leftBrake()
{
  analogWrite(PINL1, 255);
  analogWrite(PINL2, 255);
}

void leftForwardBase()
{
  leftForward(leftBase);
}

void leftReverseBase()
{
  leftReverse(leftBase);
}

void rightForward(int Pwm)

{
  analogWrite(PINR1, Pwm);
  analogWrite(PINR2, 1);
}

void rightReverse(int Pwm)
{
  analogWrite(PINR2, Pwm);
  analogWrite(PINR1, 1);
}

void rightBrake()
{
  analogWrite(PINR1, 255);
  analogWrite(PINR2, 255);
}

void rightForwardBase()
{
  rightForward(rightBase);
}

void rightReverseBase()
{
  rightReverse(rightBase);
}

void forward()
{
  leftForward(leftPwm);
  rightForward(rightPwm);
}

void reverse()
{
  leftReverse(leftPwm);
  rightReverse(rightPwm);
}

void brake()
{
  leftBrake();
  rightBrake();
  delay(100);
}

void brakeNo()
{
  leftBrake();
  rightBrake();
}

void forwardBase()
{
  leftForward(leftBase);
  rightForward(rightBase);
}

void reverseBase()
{
  leftReverse(leftBase);
  rightReverse(rightBase);
}

void turnRight()
{
  leftForward(leftPwm);
  rightReverse(rightPwm);
}

void turnLeft()
{
  leftReverse(leftPwm);
  rightForward(rightPwm);
}
