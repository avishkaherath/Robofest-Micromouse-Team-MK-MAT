void turnBack()
{
  encoderLeftCount = 0;
  encoderRightCount = 0;
  leftEncoder = 0;
  rightEncoder = 0;
  encoderRightCount = encoderRightCount + 40;
  encoderLeftCount = encoderLeftCount + 50;
  while (rightEncoder <= encoderRightCount || leftEncoder <= encoderLeftCount)
  {
    dif = leftEncoder - encoderLeftCount + 50;
    rightPwm = int(77 + 50 / (1 + pow(2.73, ((25 - dif) * 0.05))));
    leftPwm = int(81 + 50 / (1 + pow(2.73, ((25 - dif) * 0.05))));
    turnRight();
    delay(10);
  }
  rightPwm = rightTurnBase;
  leftPwm = leftTurnBase;
  encoderRightCount = encoderRightCount + 95;
  encoderLeftCount = encoderLeftCount + 100;
  while (rightEncoder <= encoderRightCount || leftEncoder <= encoderLeftCount)
  {
    turnRight();
    delay(10);
  }
  encoderRightCount = encoderRightCount + 51;
  encoderLeftCount = encoderLeftCount + 50;
  while (rightEncoder <= encoderRightCount || leftEncoder <= encoderLeftCount)
  {
    dif = leftEncoder - encoderLeftCount + 50;
    rightPwm = int(119 - 50 / (1 + pow(2.73, ((25 - dif) * 0.05))));
    leftPwm = int(120 - 50 / (1 + pow(2.73, ((25 - dif) * 0.05))));
    turnRight();
    delay(10);
  }
  brake();
  leftPwm = leftBase;
  rightPwm = rightBase;
  encoderLeftCount = 0;
  encoderRightCount = 0;
  leftEncoder = 0;
  rightEncoder = 0;
}

void rightAboutTurn()
{
  encoderLeftCount = 0;
  encoderRightCount = 0;
  leftEncoder = 0;
  rightEncoder = 0;
  encoderRightCount = encoderRightCount + 42;
  encoderLeftCount = encoderLeftCount + 44;
  while (rightEncoder <= encoderRightCount || leftEncoder <= encoderLeftCount)
  {
    dif = leftEncoder - encoderLeftCount + 50;
    rightPwm = int(80 + 50 / (1 + pow(2.73, ((25 - dif) * 0.05))));
    leftPwm = int(80 + 50 / (1 + pow(2.73, ((25 - dif) * 0.05))));
    turnRight();
    delay(10);
  }
  rightPwm = rightTurnBase;
  leftPwm = leftTurnBase;
  encoderRightCount = encoderRightCount + 1;
  encoderLeftCount = encoderLeftCount + 1;
  while (rightEncoder <= encoderRightCount || leftEncoder <= encoderLeftCount)
  {
    turnRight();
    delay(10);
  }
  encoderRightCount = encoderRightCount + 46;
  encoderLeftCount = encoderLeftCount + 46;
  while (rightEncoder <= encoderRightCount || leftEncoder <= encoderLeftCount)
  {
    dif = leftEncoder - encoderLeftCount + 50;
    rightPwm = int(120 - 50 / (1 + pow(2.73, ((25 - dif) * 0.05))));
    leftPwm = int(120 - 50 / (1 + pow(2.73, ((25 - dif) * 0.05))));
    turnRight();
    delay(10);
  }
  brake();
  leftPwm = leftBase;
  rightPwm = rightBase;
  encoderLeftCount = 0;
  encoderRightCount = 0;
  leftEncoder = 0;
  rightEncoder = 0;
}


//-------------------------------- Turn right by 90 degree about axis-------------------------
void leftAboutTurn()
{
  encoderLeftCount = 0;
  encoderRightCount = 0;
  leftEncoder = 0;
  rightEncoder = 0;
  encoderRightCount = encoderRightCount + 55;
  encoderLeftCount = encoderLeftCount + 55;
  while (rightEncoder <= encoderRightCount || leftEncoder <= encoderLeftCount)
  {
    dif = leftEncoder - encoderLeftCount + 50;
    rightPwm = int(81 + 50 / (1 + pow(2.73, ((25 - dif) * 0.05))));
    leftPwm = int(80 + 50 / (1 + pow(2.73, ((25 - dif) * 0.05))));
    turnLeft();
    delay(10);
  }
  rightPwm = rightTurnBase;
  leftPwm = leftTurnBase;
  encoderRightCount = encoderRightCount + 1;
  encoderLeftCount = encoderLeftCount + 1;
  while (rightEncoder <= encoderRightCount || leftEncoder <= encoderLeftCount)
  {
    turnLeft();
    delay(10);
  }
  encoderRightCount = encoderRightCount + 55;
  encoderLeftCount = encoderLeftCount + 55;
  while (rightEncoder <= encoderRightCount || leftEncoder <= encoderLeftCount)
  {
    dif = leftEncoder - encoderLeftCount + 50;
    rightPwm = int(118 - 50 / (1 + pow(2.73, ((25 - dif) * 0.05))));
    leftPwm = int(79 - 50 / (1 + pow(2.73, ((25 - dif) * 0.05))));
    turnLeft();
    delay(10);
  }
  brake();
  leftPwm = leftBase;
  rightPwm = rightBase;
  encoderLeftCount = 0;
  encoderRightCount = 0;
  leftEncoder = 0;
  rightEncoder = 0;
}

void rightHalfTurn()
{
  encoderLeftCount = 0;
  encoderRightCount = 0;
  leftEncoder = 0;
  rightEncoder = 0;
  encoderRightCount = encoderRightCount + 100;
  encoderLeftCount = encoderLeftCount + 100;
  rightPwm = 70;
  leftPwm = 70;
  while (rightEncoder <= encoderRightCount || leftEncoder <= encoderLeftCount)
  {
    dif = leftEncoder - encoderLeftCount + 100;
    rightPwm = int(70 + 110 / (1 + pow(2.73, ((50 - dif) * 0.05))));
    leftPwm = int(70 + 110 / (1 + pow(2.73, ((50 - dif) * 0.05))));
    turnRight();
  }
  rightPwm = 176;
  leftPwm = 180;
  encoderRightCount = encoderRightCount + 1;
  encoderLeftCount = encoderLeftCount + 1;
  while (rightEncoder <= encoderRightCount)
  {
    turnRight();
  }
  encoderRightCount = encoderRightCount + 100;
  encoderLeftCount = encoderLeftCount + 100;
  while (rightEncoder <= encoderRightCount || leftEncoder <= encoderLeftCount)
  {
    dif = leftEncoder - encoderLeftCount + 100;
    rightPwm = int(176 - 110 / (1 + pow(2.73, ((50 - dif) * 0.05))));
    leftPwm = int(180 - 110 / (1 + pow(2.73, ((50 - dif) * 0.05))));
    turnRight();
  }
  brake();
  leftPwm = leftBase;
  rightPwm = rightBase;
  encoderLeftCount = 0;
  encoderRightCount = 0;
  leftEncoder = 0;
  rightEncoder = 0;
}
