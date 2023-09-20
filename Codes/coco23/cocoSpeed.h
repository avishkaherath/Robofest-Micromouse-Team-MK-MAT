void cellMiddle() {
  tofStart();
  if (tof[2] < 100) {
    rightEncoder = 0;
    leftEncoder = 0;
    leftPwm = leftBase;
    rightPwm = rightBase;
    if (tof[2] > 45) {
      int encoderRightCount = (tof[2] - 40) * 1.4;
      int encoderLeftCount = (tof[2] - 40) * 1.4;
      while (rightEncoder <= encoderRightCount || leftEncoder <= encoderLeftCount)
      {
        forward();
        delay(10);
      }
      brake();
    }
    else if (tof[2] < 40) {
      int encoderRightCount = (40 - tof[2]) * 1.4;
      int encoderLeftCount = (40 - tof[2]) * 1.4;
      while (rightEncoder <= encoderRightCount || leftEncoder <= encoderLeftCount)
      {
        reverse();
        delay(10);
      }
      brake();
    }
  }
}


void cellPara() {
  tofPid();
  if (state = 0) {
    if (tof[0] > tof[4]) {
      int encoderRightCount = (tof[0] - tof[4]) * 1.4;
      int encoderLeftCount = (tof[0] - tof[4]) * 1.4;
      while (rightEncoder <= encoderRightCount || leftEncoder <= encoderLeftCount)
      {
        turnLeft();
        delay(10);
      }
      brake();
    }
    else if (tof[0] < tof[4]) {
      int encoderRightCount = (tof[0] - tof[4]) * 1.4;
      int encoderLeftCount = (tof[0] - tof[4]) * 1.4;
      while (rightEncoder <= encoderRightCount || leftEncoder <= encoderLeftCount)
      {
        turnRight();
        delay(10);
      }
      brake();
    }
  } 
  else if (state = 1) {
    if (tof[0] > tof[5]) {
      int encoderRightCount = (tof[0] - tof[5]) * 1.4;
      int encoderLeftCount = (tof[0] - tof[5]) * 1.4;
      while (rightEncoder <= encoderRightCount || leftEncoder <= encoderLeftCount)
      {
        turnLeft();
        delay(10);
      }
      brake();
    }
    else if (tof[0] < tof[5]) {
      int encoderRightCount = (tof[0] - tof[5]) * 1.4;
      int encoderLeftCount = (tof[0] - tof[5]) * 1.4;
      while (rightEncoder <= encoderRightCount || leftEncoder <= encoderLeftCount)
      {
        turnRight();
        delay(10);
      }
      brake();
    }
  } 
  else if (state = 2) {
    if (tof[4] > tof[6]) {
      int encoderRightCount = (tof[4] - tof[6]) * 1.4;
      int encoderLeftCount = (tof[4] - tof[6]) * 1.4;
      while (rightEncoder <= encoderRightCount || leftEncoder <= encoderLeftCount)
      {
        turnRight();
        delay(10);
      }
      brake();
    }
    else if (tof[4] < tof[6]) {
      int encoderRightCount = (tof[4] - tof[6]) * 1.4;
      int encoderLeftCount = (tof[4] - tof[6]) * 1.4;
      while (rightEncoder <= encoderRightCount || leftEncoder <= encoderLeftCount)
      {
        turnLeft();
        delay(10);
      }
      brake();
    }
  }
}

void goCell() {
  rightEncoder = 0;
  leftEncoder = 0;
  encoderRightCount = 225;
  encoderLeftCount = 225;
  while (rightEncoder <= encoderRightCount || leftEncoder <= encoderLeftCount)
  {
    wallFollow();
    delay(10);
  }
  brake();
  cellMiddle();
  cellPara();
}


//void cellStart()
//{
//  leftWallAvailable = 0;
//  rightWallAvailable = 0;
//  frontWallAvailable = 0;
//  encoderRightCount = encoderRightCount + 220;
//  encoderLeftCount = encoderLeftCount + 220;
//  rightBase = 70;
//  leftBase = 70;
//  while (rightEncoder <= encoderRightCount || leftEncoder <= encoderLeftCount)
//  {
//    dif = leftEncoder - encoderLeftCount + 220;
//    rightBase = 70 + int(dif / 2);
//    leftBase = 70 + int(dif / 2);
//    forwardBase();
//    delay(10);
//  }
//  rightBase = 176;
//  leftBase = 180;
//  encoderRightCount = encoderRightCount + 267;
//  encoderLeftCount = encoderLeftCount + 267;
//
//  while (rightEncoder <= encoderRightCount || leftEncoder <= encoderLeftCount)
//  {
//    wallFollow();
//    delay(10);
//  }
//  encoderLeftCount = encoderLeftCount + 150;
//  encoderRightCount = encoderRightCount + 150;
//  while (leftEncoder <= encoderLeftCount || rightEncoder <= encoderRightCount)
//  {
//    wallFollow();
//    //encoderPid();
//    if (tof[2] <= 180)
//    {
//      frontWallAvailable = frontWallAvailable + 1;
//    }
//    else
//    {
//      frontWallAvailable = frontWallAvailable - 1;
//    }
//    if (tof[0] <= 150)
//    {
//      leftWallAvailable = leftWallAvailable + 1;
//    }
//    else
//    {
//      leftWallAvailable = leftWallAvailable - 1;
//    }
//    if (tof[4] <= 150)
//    {
//      rightWallAvailable = rightWallAvailable + 1;
//    }
//    else
//    {
//      rightWallAvailable = rightWallAvailable - 1;
//    }
//    delay(10);
//  }
//}

//void cellBrake()
//{
//  encoderRightCount = encoderRightCount + 417;
//  encoderLeftCount = encoderLeftCount + 417;
//  rightBase = 176;
//  leftBase = 180;
//  while (rightEncoder <= encoderRightCount || leftEncoder <= encoderLeftCount)
//  {
//    wallFollow();
//  }
//  encoderRightCount = encoderRightCount + 220;
//  encoderLeftCount = encoderLeftCount + 220;
//  if (front == true)
//  {
//    VL53L0X_RangingMeasurementData_t measure;
//    tcaselect(4);
//    tof[2] = measure.RangeMilliMeter;
//
//    while (tof[2] > 52)
//    {
//      tof[2] = measure.RangeMilliMeter;
//      dif = leftEncoder - encoderLeftCount + 220;
//      rightBase = 176 - int(dif * 0.75);
//      leftBase = 180 - int(dif * 0.85);
//      if (rightBase <= 70)
//      {
//        rightBase = 70;
//      }
//      if (leftBase <= 70)
//      {
//        leftBase = 70;
//      }
//      forwardBase();
//    }
//  }
//  else
//  {
//    while (rightEncoder <= encoderRightCount || leftEncoder <= encoderLeftCount)
//    {
//      dif = leftEncoder - encoderLeftCount + 220;
//      rightBase = 176 - int(dif / 2);
//      leftBase = 180 - int((dif * 3) / 5);
//      if (rightBase <= 70)
//      {
//        rightBase = 70;
//      }
//      if (leftBase <= 70)
//      {
//        leftBase = 70;
//      }
//      forwardBase();
//    }
//  }
//  brake();
//}
