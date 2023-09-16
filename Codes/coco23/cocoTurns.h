
void turnBack()
{
  encoderLeftCount = 0;
  encoderRightCount = 0;
  leftEncoder = 0;
  rightEncoder = 0;
  encoderRightCount = encoderRightCount + 50;
  encoderLeftCount = encoderLeftCount + 50;
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
  encoderRightCount = encoderRightCount + 100;
  encoderLeftCount = encoderLeftCount + 100;
  while (rightEncoder <= encoderRightCount || leftEncoder <= encoderLeftCount)
  {
    turnRight();
    delay(10);
  }
  encoderRightCount = encoderRightCount + 50;
  encoderLeftCount = encoderLeftCount + 50;
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
void rightTurn90(){
  rightEncoder =0;
  leftEncoder = 0;
    rightPwm = rightTurnBase;
  leftPwm = leftTurnBase;
  encoderRightCount = encoderRightCount + 120;
  encoderLeftCount = encoderLeftCount + 120;
  while (rightEncoder <= encoderRightCount || leftEncoder <= encoderLeftCount)
  {
    turnRight();
    delay(10);
  }
  brake();
}


void rightAboutTurn()
{
  encoderLeftCount = 0;
  encoderRightCount = 0;
  leftEncoder = 0;
  rightEncoder = 0;
  encoderRightCount = encoderRightCount + 46;
  encoderLeftCount = encoderLeftCount + 46;
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
  encoderRightCount = encoderRightCount + 48;
  encoderLeftCount = encoderLeftCount + 48;
  while (rightEncoder <= encoderRightCount || leftEncoder <= encoderLeftCount)
  {
    dif = leftEncoder - encoderLeftCount + 50;
    rightPwm = int(80 + 50 / (1 + pow(2.73, ((25 - dif) * 0.05))));
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
  encoderRightCount = encoderRightCount + 50;
  encoderLeftCount = encoderLeftCount + 50;
  while (rightEncoder <= encoderRightCount || leftEncoder <= encoderLeftCount)
  {
    dif = leftEncoder - encoderLeftCount + 50;
    rightPwm = int(120 - 50 / (1 + pow(2.73, ((25 - dif) * 0.05))));
    leftPwm = int(120 - 50 / (1 + pow(2.73, ((25 - dif) * 0.05))));
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




//------------------------------------------------------------------------------------------------------
//
//void turnBack()
//{
//    int param1 = 40;
//  int param2 = 70;   // increase to increase turning angle
//
//  leftEncoder = 0;
//  rightEncoder = 0;
//
//  while (leftEncoder - rightEncoder <= param1 * 2 )
//  {
//    int   dif = (leftEncoder - rightEncoder) / 2;
//    rightPwm = int(70 + 100 / (1 + pow(2.73, ((param1/2 - dif) * 0.1))));
//    leftPwm = int(70 + 100 / (1 + pow(2.73, ((param1/2 - dif) * 0.1))));
//    turnRight();
//    delay(10);
//  }
//  rightPwm = 172;
//  leftPwm = 180;
//  leftEncoder = 0;
//  rightEncoder = 0;
//  while (leftEncoder - rightEncoder <= param2 * 2)
//  {
//    turnRight();
//    delay(20);
//  }
//  leftEncoder = 0;
//  rightEncoder = 0;
//  while (leftEncoder - rightEncoder <= param1 * 2)
//  {
//    int    dif = (leftEncoder - rightEncoder) / 2;
//    rightPwm = int(176 - 100 / (1 + pow(2.73, ((param1/2 - dif) * 0.1))));
//    leftPwm = int(180 - 100 / (1 + pow(2.73, ((param1/2 - dif) * 0.1))));
//    turnRight();
//    delay(10);
//  }
//  brake();
//  leftBase = 132;
//  rightBase = 137;
//  leftEncoder = 0;
//  rightEncoder = 0;
//}
//
//void rightAboutTurn()
//{
//    int param1 = 32;
//  int param2 = 11;        // increase to increase turning angle
//
//  leftEncoder = 0;
//  rightEncoder = 0;
//
//  while (leftEncoder - rightEncoder <= param1 * 2 )
//  {
//    int   dif = (leftEncoder - rightEncoder) / 2;
//    rightPwm = int(72 + 85 / (1 + pow(2.73, ((param1 /2 - dif) * 0.1))));
//    leftPwm = int(70 + 85 / (1 + pow(2.73, ((param1 /2 - dif) * 0.1))));
//    turnRight();
//    delay(10);
//  }
//  rightPwm = 137;
//  leftPwm = 135;
//  leftEncoder = 0;
//  rightEncoder = 0;
//  while (leftEncoder - rightEncoder <= param2 * 2)
//  {
//    turnRight();
//    delay(10);
//  }
//  leftEncoder = 0;
//  rightEncoder = 0;
//  while (leftEncoder - rightEncoder <= param1 * 2)
//  {
//    int    dif = (leftEncoder - rightEncoder) / 2;
//    rightPwm = int(137 - 85 / (1 + pow(2.73, ((param1 /2 - dif) * 0.1))));
//    leftPwm = int(135 - 85 / (1 + pow(2.73, ((param1 /2 - dif) * 0.1))));
//    turnRight();
//    delay(10);
//  }
//  brake();
//  leftPwm = leftBase;
//  rightPwm = rightBase;
//  leftEncoder = 0;
//  rightEncoder = 0;
//}
//
//void leftAboutTurn()
//{
//    int param1 = 30;
//  int param2 = 8;            // increase to increase turning angle
//
//  leftEncoder = 0;
//  rightEncoder = 0;
//
//  while (rightEncoder - leftEncoder <= param1 * 2 )
//  {
//    int   dif = (rightEncoder - leftEncoder) / 2;
//    rightPwm = int(75 + 85 / (1 + pow(2.73, ((param1 /2 - dif) * 0.1))));
//    leftPwm = int(73 + 85 / (1 + pow(2.73, ((param1 /2 - dif) * 0.1))));
//    turnLeft();
//    delay(10);
//  }
//  rightPwm = 140;
//  leftPwm = 137;
//  leftEncoder = 0;
//  rightEncoder = 0;
//  while (rightEncoder - leftEncoder <= param2 * 2)
//  {
//    turnLeft();
//    delay(10);
//  }
//  leftEncoder = 0;
//  rightEncoder = 0;
//  while (rightEncoder - leftEncoder <= param1 * 2)
//  {
//    int    dif = (rightEncoder - leftEncoder) / 2;
//    rightPwm = int(140 - 85 / (1 + pow(2.73, ((param1 /2 - dif) * 0.1))));
//    leftPwm = int(137 - 85 / (1 + pow(2.73, ((param1 /2 - dif) * 0.1))));
//    turnLeft();
//    delay(10);
//  }
//  brake();
//  leftPwm = leftBase;
//  rightPwm = rightBase;
//  leftEncoder = 0;
//  rightEncoder = 0;
//}
//
//void rightHalfTurn()
//{
//    encoderLeftCount = 0;
//    encoderRightCount = 0;
//    leftEncoder = 0;
//    rightEncoder = 0;
//    encoderRightCount= encoderRightCount + 100;
//    encoderLeftCount= encoderLeftCount + 100;
//    rightBase = 70;
//    leftBase = 70;
//    while (rightEncoder <= encoderRightCount || leftEncoder <= encoderLeftCount)
//    {
//        dif = leftEncoder - encoderLeftCount + 100;
//        rightBase = int(70+110/(1+pow(2.73,((50-dif)*0.05))));
//        leftBase = int(70+110/(1+pow(2.73,((50-dif)*0.05))));
//        turnRight();
//    }
//    rightBase=176;
//    leftBase=180;
//    encoderRightCount= encoderRightCount + 1;
//    encoderLeftCount= encoderLeftCount + 1;
//    while(rightEncoder <= encoderRightCount)
//    {
//        turnRight();
//    }
//    encoderRightCount= encoderRightCount + 100;
//    encoderLeftCount= encoderLeftCount + 100;
//    while (rightEncoder <= encoderRightCount || leftEncoder <= encoderLeftCount)
//    {
//        dif = leftEncoder - encoderLeftCount + 100;
//        rightBase = int(176-110/(1+pow(2.73,((50-dif)*0.05))));
//        leftBase = int(180-110/(1+pow(2.73,((50-dif)*0.05))));
//        turnRight();
//    }
//    brake();
//    leftBase = 180;
//    rightBase = 176;
//    encoderLeftCount = 0;
//    encoderRightCount = 0;
//    leftEncoder = 0;
//    rightEncoder = 0;
//}
