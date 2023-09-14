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



//----------------------------------------------------------------------------

void turnBack()
{
  int param1 = 40;
  int param2 = 70;   // increase to increase turning angle
  
  leftEncoder = 0;
  rightEncoder = 0;

  while (leftEncoder - rightEncoder <= param1 * 2 )
  {
    int   dif = (leftEncoder - rightEncoder) / 2;
    rightPwm = int(70 + 100 / (1 + pow(2.73, ((param1/2 - dif) * 0.1))));
    leftPwm = int(70 + 100 / (1 + pow(2.73, ((param1/2 - dif) * 0.1))));
    turnRight();
    delay(10);
  }
  rightPwm = 172;
  leftPwm = 180;
  leftEncoder = 0;
  rightEncoder = 0;
  while (leftEncoder - rightEncoder <= param2 * 2)
  {
    turnRight();
    delay(20);
  }
  leftEncoder = 0;
  rightEncoder = 0;
  while (leftEncoder - rightEncoder <= param1 * 2)
  {
    int    dif = (leftEncoder - rightEncoder) / 2;
    rightPwm = int(176 - 100 / (1 + pow(2.73, ((param1/2 - dif) * 0.1))));
    leftPwm = int(180 - 100 / (1 + pow(2.73, ((param1/2 - dif) * 0.1))));
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
  int param1 = 32;
  int param2 = 11;        // increase to increase turning angle
  
  leftEncoder = 0;
  rightEncoder = 0;

  while (leftEncoder - rightEncoder <= param1 * 2 )
  {
    int   dif = (leftEncoder - rightEncoder) / 2;
    rightPwm = int(75 + 85 / (1 + pow(2.73, ((param1 /2 - dif) * 0.1))));
    leftPwm = int(70 + 85 / (1 + pow(2.73, ((param1 /2 - dif) * 0.1))));
    turnRight();
    delay(10);
  }
  rightPwm = 140;
  leftPwm = 135;
  leftEncoder = 0;
  rightEncoder = 0;
  while (leftEncoder - rightEncoder <= param2 * 2)
  {
    turnRight();
    delay(10);
  }
  leftEncoder = 0;
  rightEncoder = 0;
  while (leftEncoder - rightEncoder <= param1 * 2)
  {
    int    dif = (leftEncoder - rightEncoder) / 2;
    rightPwm = int(140 - 85 / (1 + pow(2.73, ((param1 /2 - dif) * 0.1))));
    leftPwm = int(135 - 85 / (1 + pow(2.73, ((param1 /2 - dif) * 0.1))));
    turnRight();
    delay(10);
  }
  mBreak();
  leftBase = 180;
  rightBase = 176;
  leftEncoder = 0;
  rightEncoder = 0;
}

//----------------------------------------------------------------

void leftAboutTurn()
{
  int param1 = 32;
  int param2 = 11;            // increase to increase turning angle
  
  leftEncoder = 0;
  rightEncoder = 0;

  while (rightEncoder - leftEncoder <= param1 * 2 )
  {
    int   dif = (rightEncoder - leftEncoder) / 2;
    rightPwm = int(75 + 85 / (1 + pow(2.73, ((param1 /2 - dif) * 0.1))));
    leftPwm = int(70 + 85 / (1 + pow(2.73, ((param1 /2 - dif) * 0.1))));
    turnLeft();
    delay(10);
  }
  rightPwm = 140;
  leftPwm = 135;
  leftEncoder = 0;
  rightEncoder = 0;
  while (rightEncoder - leftEncoder <= param2 * 2)
  {
    turnLeft();
    delay(10);
  }
  leftEncoder = 0;
  rightEncoder = 0;
  while (rightEncoder - leftEncoder <= param1 * 2)
  {
    int    dif = (rightEncoder - leftEncoder) / 2;
    rightPwm = int(140 - 85 / (1 + pow(2.73, ((param1 /2 - dif) * 0.1))));
    leftPwm = int(135 - 85 / (1 + pow(2.73, ((param1 /2 - dif) * 0.1))));
    turnLeft();
    delay(10);
  }
  mBreak();
  leftBase = 180;
  rightBase = 176;
  leftEncoder = 0;
  rightEncoder = 0;
}
