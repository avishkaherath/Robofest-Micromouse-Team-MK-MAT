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


//-----------------------------------------------------------------------------------------------


void cellPara() {
  //  tofPid();
  //  if ((tof[0] + tof[5]) / 2 <= 70) {
  //    if (tof[0] > tof[5]) {
  //      int encoderRightCount = (tof[0] - tof[5]) * 0.9;
  //      int encoderLeftCount = (tof[0] - tof[5]) * 0.9;
  //      while (rightEncoder <= encoderRightCount || leftEncoder <= encoderLeftCount)
  //      {
  //        turnLeft();
  //        delay(10);
  //      }
  //      brake();
  //    }
  //    else if (tof[0] < tof[5]) {
  //      int encoderRightCount = (tof[5] - tof[0]) * 0.9;
  //      int encoderLeftCount = (tof[5] - tof[0]) * 0.9;
  //      while (rightEncoder <= encoderRightCount || leftEncoder <= encoderLeftCount)
  //      {
  //        turnRight();
  //        delay(10);
  //      }
  //      brake();
  //    }
  //  }
  //  else if ((tof[4] + tof[6]) / 2 <= 70) {
  //    if (tof[4] > tof[6]) {
  //      int encoderRightCount = (tof[4] - tof[6]) * 0.9;
  //      int encoderLeftCount = (tof[4] - tof[6]) * 0.9;
  //      while (rightEncoder <= encoderRightCount || leftEncoder <= encoderLeftCount)
  //      {
  //        turnRight();
  //        delay(10);
  //      }
  //      brake();
  //    }
  //    else if (tof[4] < tof[6]) {
  //      int encoderRightCount = (tof[6] - tof[4]) * 0.9;
  //      int encoderLeftCount = (tof[6] - tof[4]) * 0.9;
  //      while (rightEncoder <= encoderRightCount || leftEncoder <= encoderLeftCount)
  //      {
  //        turnLeft();
  //        delay(10);
  //      }
  //      brake();
  //    }
  //  }


  if ((tof[0] + tof[5]) / 2 <= 70) {
    
    while (tof[0] > tof[5]) {

      //      Serial.print(tof[0]);
      //      Serial.print(" , ");
      //      Serial.println(tof[5]);
      turnLeft();
      tcaselect(7);
      //delay(10);
      tof[0] = lox61.readRange() - 14;
      tcaselect(0);
      //delay(10);
      tof[5] = lox61.readRange() + 1;
    }
    brake();

    while (tof[0] < tof[5]) {
      Serial.print(tof[0]);
      Serial.print(" , ");
      Serial.println(tof[5]);
      turnRight();
      tcaselect(7);
      //delay(10);
      tof[0] = lox61.readRange() - 14;
      tcaselect(0);
      // delay(10);
      tof[5] = lox61.readRange() + 1;
    }
    brake();
  }

  else if ((tof[4] + tof[6]) / 2 <= 70) {
    while (tof[4] > tof[6]) {
      //
      //      Serial.print(tof[0]);
      //      Serial.print(" , ");
      //      Serial.println(tof[5]);
      turnRight();
      tcaselect(2);
//    delay(10);  
    tof[4] = lox61.readRange() - 4;
      tcaselect(1);
//    delay(10);  
    tof[6] = lox61.readRange() - 6;
    }
    brake();

    while (tof[4] < tof[6]) {
      //      Serial.print(tof[0]);
      //      Serial.print(" , ");
      //      Serial.println(tof[5]);
      turnLeft();
     tcaselect(2);
//    delay(10);  
    tof[4] = lox61.readRange() - 4;
      tcaselect(1);
//    delay(10);  
    tof[6] = lox61.readRange() - 6;
    }
    brake();
  }
}


//------------------------------------------------------------------------------------------

void goCell() {
  rightEncoder = 0;
  leftEncoder = 0;
  encoderRightCount = 50;
  encoderLeftCount = 50;
  while (rightEncoder <= encoderRightCount || leftEncoder <= encoderLeftCount)
  {
    rightForward(rightBase + 10);
    leftForward(leftBase + 5);
    delay(10);
  }
  encoderRightCount += 235;
  encoderLeftCount += 235;
  while (rightEncoder <= encoderRightCount || leftEncoder <= encoderLeftCount)
  {
    wallFollow();
    delay(10);
  }
  brake();
//  cellPara();
//  delay(50);
  cellMiddle();
  delay(50);
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
