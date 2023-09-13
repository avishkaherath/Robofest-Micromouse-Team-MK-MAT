void left90() {
  int turnStep = 200;
  rightEncoder = 0;
  leftEncoder = 0;
  while (rightEncoder - leftEncoder < turnStep) {
    int error = turnStep - (rightEncoder - leftEncoder);
    leftPwm = int(leftTurnBase + error * 0.5);
    if (leftPwm > 255) {
      leftPwm = 255;
    }
    rightPwm = int(rightTurnBase + error * 0.5);
    if (rightPwm > 255) {
      rightPwm = 255;
    }
    turnLeft();
    delay(20);
  }
  mBreak();
  rightPwm = rightBase;
  leftPwm = leftBase;
}



void right90() {

  int turnStep = 200;
  leftEncoder = 0;
  rightEncoder = 0;
  while (leftEncoder - rightEncoder < turnStep) {
    int error = turnStep - (leftEncoder - rightEncoder);
    leftPwm = int(leftTurnBase + error * 0.5);
    if (leftPwm > 255) {
      leftPwm = 255;
    }
    rightPwm = int(rightTurnBase + error * 0.5);
    if (rightPwm > 255) {
      rightPwm = 255;
    }
    turnRight();
    delay(20);
  }
  mBreak();
  leftPwm = leftBase;
  rightPwm = rightBase;
}

void turnBack()
{

  leftEncoder = 0;
  rightEncoder = 0;

  while (leftEncoder - rightEncoder <= 40 * 2 )
  {
    int   dif = (leftEncoder - rightEncoder) / 2;
    rightPwm = int(70 + 100 / (1 + pow(2.73, ((20 - dif) * 0.1))));
    leftPwm = int(70 + 100 / (1 + pow(2.73, ((20 - dif) * 0.1))));
    turnRight();
    delay(10);
  }
  rightPwm = 172;
  leftPwm = 180;
  leftEncoder = 0;
  rightEncoder = 0;
  while (leftEncoder - rightEncoder <= 70 * 2)
  {
    turnRight();
    delay(20);
  }
  leftEncoder = 0;
  rightEncoder = 0;
  while (leftEncoder - rightEncoder <= 40 * 2)
  {
    int    dif = (leftEncoder - rightEncoder) / 2;
    rightPwm = int(176 - 100 / (1 + pow(2.73, ((20 - dif) * 0.1))));
    leftPwm = int(180 - 100 / (1 + pow(2.73, ((20 - dif) * 0.1))));
    turnRight();
    delay(10);
  }
  mBreak();
  leftBase = 180;
  rightBase = 176;
  leftEncoder = 0;
  rightEncoder = 0;
}

//------------------------------------------------------------------------

void rightAboutTurn()
{
  leftEncoder = 0;
  rightEncoder = 0;

  while (leftEncoder - rightEncoder <= 30 * 2 )
  {
    int   dif = (leftEncoder - rightEncoder) / 2;
    rightPwm = int(75 + 85 / (1 + pow(2.73, ((15 - dif) * 0.1))));
    leftPwm = int(70 + 85 / (1 + pow(2.73, ((15 - dif) * 0.1))));
    turnRight();
    delay(10);
  }
  rightPwm = 140;
  leftPwm = 135;
  leftEncoder = 0;
  rightEncoder = 0;
  while (leftEncoder - rightEncoder <= 10 * 2)
  {
    turnRight();
    delay(10);
  }
  leftEncoder = 0;
  rightEncoder = 0;
  while (leftEncoder - rightEncoder <= 30 * 2)
  {
    int    dif = (leftEncoder - rightEncoder) / 2;
    rightPwm = int(140 - 85 / (1 + pow(2.73, ((15 - dif) * 0.1))));
    leftPwm = int(135 - 85 / (1 + pow(2.73, ((15 - dif) * 0.1))));
    turnRight();
    delay(10);
  }
  mBreak();
  leftBase = 180;
  rightBase = 176;
  leftEncoder = 0;
  rightEncoder = 0;
}
