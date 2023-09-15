void countLeftOut1()
{
    if(digitalRead(ENCL2)){
      leftEncoder ++;
      }
      else{
        leftEncoder ++;
        }
        
}

void countRightOut1()
{
    if(digitalRead(ENCR2)){
      rightEncoder ++;
      }
      else{
        rightEncoder ++;
        }
}

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
  brake();
  leftBase = 132;
  rightBase = 137;
  leftEncoder = 0;
  rightEncoder = 0;
}

void rightAboutTurn()
{
    int param1 = 32;
  int param2 = 11;        // increase to increase turning angle
  
  leftEncoder = 0;
  rightEncoder = 0;

  while (leftEncoder - rightEncoder <= param1 * 2 )
  {
    int   dif = (leftEncoder - rightEncoder) / 2;
    rightPwm = int(72 + 85 / (1 + pow(2.73, ((param1 /2 - dif) * 0.1))));
    leftPwm = int(70 + 85 / (1 + pow(2.73, ((param1 /2 - dif) * 0.1))));
    turnRight();
    delay(10);
  }
  rightPwm = 137;
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
    rightPwm = int(137 - 85 / (1 + pow(2.73, ((param1 /2 - dif) * 0.1))));
    leftPwm = int(135 - 85 / (1 + pow(2.73, ((param1 /2 - dif) * 0.1))));
    turnRight();
    delay(10);
  }
  brake();
  leftPwm = leftBase;
  rightPwm = rightBase;
  leftEncoder = 0;
  rightEncoder = 0;
}

void leftAboutTurn()
{
    int param1 = 30;
  int param2 = 8;            // increase to increase turning angle
  
  leftEncoder = 0;
  rightEncoder = 0;

  while (rightEncoder - leftEncoder <= param1 * 2 )
  {
    int   dif = (rightEncoder - leftEncoder) / 2;
    rightPwm = int(75 + 85 / (1 + pow(2.73, ((param1 /2 - dif) * 0.1))));
    leftPwm = int(73 + 85 / (1 + pow(2.73, ((param1 /2 - dif) * 0.1))));
    turnLeft();
    delay(10);
  }
  rightPwm = 140;
  leftPwm = 137;
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
    leftPwm = int(137 - 85 / (1 + pow(2.73, ((param1 /2 - dif) * 0.1))));
    turnLeft();
    delay(10);
  }
  brake();
  leftPwm = leftBase;
  rightPwm = rightBase;
  leftEncoder = 0;
  rightEncoder = 0;
}

void rightHalfTurn()
{
    encoderLeftCount = 0;
    encoderRightCount = 0;
    leftEncoder = 0;
    rightEncoder = 0;
    encoderRightCount= encoderRightCount + 100;
    encoderLeftCount= encoderLeftCount + 100;
    rightBase = 70;
    leftBase = 70;
    while (rightEncoder <= encoderRightCount || leftEncoder <= encoderLeftCount)
    {
        dif = leftEncoder - encoderLeftCount + 100;
        rightBase = int(70+110/(1+pow(2.73,((50-dif)*0.05))));
        leftBase = int(70+110/(1+pow(2.73,((50-dif)*0.05))));
        turnRight();
    }
    rightBase=176;
    leftBase=180;
    encoderRightCount= encoderRightCount + 1;
    encoderLeftCount= encoderLeftCount + 1;
    while(rightEncoder <= encoderRightCount)
    {
        turnRight();
    }
    encoderRightCount= encoderRightCount + 100;
    encoderLeftCount= encoderLeftCount + 100;
    while (rightEncoder <= encoderRightCount || leftEncoder <= encoderLeftCount)
    {
        dif = leftEncoder - encoderLeftCount + 100;
        rightBase = int(176-110/(1+pow(2.73,((50-dif)*0.05))));
        leftBase = int(180-110/(1+pow(2.73,((50-dif)*0.05))));
        turnRight();  
    }
    brake();
    leftBase = 180;
    rightBase = 176;
    encoderLeftCount = 0;
    encoderRightCount = 0;
    leftEncoder = 0;
    rightEncoder = 0;
}
