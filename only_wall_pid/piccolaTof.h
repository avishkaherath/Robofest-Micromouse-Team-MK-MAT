Adafruit_VL53L0X lox53 = Adafruit_VL53L0X();
Adafruit_VL6180X lox61 = Adafruit_VL6180X();
MPU6050 mpu(Wire);

#define TCAADDR 0x70
unsigned long timer = 0;

void tcaselect(uint8_t bus) {
  Wire.beginTransmission(TCAADDR);
  Wire.write(1<< bus);
  Wire.endTransmission();
  Serial.print(bus);  
}

void angle_val(){
  mpu.update();    //Get values from MPU

  if ((millis() - timer) > 100) { // print data every 100ms
    timer = millis();
    Serial.print(" Angle X: ");
    Serial.print(int(mpu.getAngleX()));     //Print Z angle value on LCD 
    Serial.print(" Angle Y: ");
    Serial.print(int(mpu.getAngleY()));
    delay(10);
    }
}

void tofSetup()
{
    delay(70);
    Serial.begin(9600);
    Serial.print("Start.");
    Wire.begin();
    mpu.begin(); 
    mpu.calcGyroOffsets();
    
    tcaselect(6);
    if (!lox53.begin()) {
    Serial.println(F("Failed to boot VL53L0X L"));
    while(1);
    }
    
    tcaselect(3);
    if (!lox53.begin()) {
    Serial.println(F("Failed to boot VL53L0X R"));
    while(1);
    }
    
    tcaselect(4);
    if (!lox53.begin()) {
    Serial.println(F("Failed to boot VL53L0X C"));
    while(1);
    }

    tcaselect(7);
    if (!lox61.begin()) {
    Serial.println(F("Failed to boot VL6180X L"));
    while(1);
    }
    
    tcaselect(2);
    if (!lox61.begin()) {
    Serial.println(F("Failed to boot VL6180X R"));
    while(1);
    }
    
    Serial.println(" End setup");
    delay(2000);
}

void tofPid()
{
    VL53L0X_RangingMeasurementData_t measure;

    tcaselect(7);
    uint8_t range1 = lox61.readRange();
    tof[0] = range1;

    tcaselect(4);
    tof[2] = measure.RangeMilliMeter;

    tcaselect(3);
    uint8_t range2 = lox61.readRange();
    tof[4] = range2;
}

void tofStart()
{
    VL53L0X_RangingMeasurementData_t measure;
    
    tcaselect(6);
    tof[1] = measure.RangeMilliMeter;

    tcaselect(4);
    tof[2] = measure.RangeMilliMeter;

    tcaselect(3);
    tof[3] = measure.RangeMilliMeter;
}

void printTof()
{
    
    Serial.print(tof[0]);
    Serial.print(",  ");
    Serial.print(tof[2]);
    Serial.print(",  ");
    Serial.print(tof[4]);
    Serial.println();
}

//void checkWallsCell()
//{
//    if (x == 0 && y == 0)
//    {
//        time1 = 0;
//        while(time1 <10)
//        {
//            tofStart();
//            if (tof[2] <= 180)
//            {
//            frontWallAvailable = frontWallAvailable + 1;
//            }
//            else
//            {
//            frontWallAvailable = frontWallAvailable - 1;
//            }
//            if (tof[1] <= 150)
//            {
//            leftWallAvailable= leftWallAvailable + 1;
//            }
//            else
//            {
//            leftWallAvailable= leftWallAvailable - 1;
//            }
//            if (tof[3] <= 150)
//            {
//            rightWallAvailable= rightWallAvailable + 1;
//            }
//            else
//            {
//            rightWallAvailable= rightWallAvailable - 1;
//            }
//            time1 = time1 + 1;
//        }
//    }
//    if (frontWallAvailable >=0 )
//    {
//        cellWalls[1] =  0;
//        F = true;
//        //frontWallAvailable = 0;
//    }
//    else
//    {
//        cellWalls[1] =  1;
//        F = false;
//        //frontWallAvailable = 0;
//    } 
//    if (leftWallAvailable >= 0)
//    {
//        cellWalls[0] = 1;
//        L = true;
//        //leftWallAvailable = 0;
//    }
//    else
//    {
//        cellWalls[0] = 0;
//        L = false;
//        //leftWallAvailable = 0;
//    }
//    if (rightWallAvailable >= 0)
//    {
//        cellWalls[2] = 1;
//        R = true;
//        //rightWallAvailable = 0;
//    }
//    else
//    {
//        cellWalls[2] = 0;
//        R = false;
//        //rightWallAvailable = 0;
//    }
//    
//}

void printWallState()
{
    for (int i=0; i<3; i++)
    {
        Serial.print(cellWalls[i]);
        Serial.print("   ");
    }
    Serial.println("");
}