Adafruit_VL53L0X lox53 = Adafruit_VL53L0X();
Adafruit_VL6180X lox61 = Adafruit_VL6180X();

#define TCAADDR 0x70
MPU6050 mpu(Wire);
unsigned long timer3 = 0;

void tcaselect(uint8_t bus) {
  Wire.beginTransmission(TCAADDR);
  Wire.write(1<< bus);
  Wire.endTransmission();  
}

void angle_val(){
  mpu.update();    //Get values from MPU

  if ((millis() - timer3) > 100) { // print data every 100ms
    timer3 = millis();
    Serial.print(" Angle X: ");
    Serial.print(int(mpu.getAngleX()));     //Print Z angle value on LCD 
    Serial.print(" Angle Y: ");
    Serial.println(int(mpu.getAngleY()));
    delay(10);
    }
}

void tofSetup()
{
    delay(70);
    Serial.begin(9600);
    Serial.print("Start.");
    Wire.begin();
    
    tcaselect(6);
    if (!lox61.begin()) {
    Serial.println(F("Failed to boot VL6180X 45 L"));
    while(1);
    }
    
    tcaselect(3);
    if (!lox61.begin()) {
    Serial.println(F("Failed to boot VL6180X 45 R"));
    while(1);
    }
    
    tcaselect(4);
    if (!lox53.begin()) {
    Serial.println(F("Failed to boot VL53L0X C"));
    while(1);
    }

    tcaselect(7);
    if (!lox61.begin()) {
    Serial.println(F("Failed to boot VL6180X front L"));
    while(1);
    }
    
    tcaselect(2);
    if (!lox61.begin()) {
    Serial.println(F("Failed to boot VL6180X front R"));
    while(1);
    }

    tcaselect(0);
    if (!lox61.begin()) {
    Serial.println(F("Failed to boot VL6180X back L"));
    while(1);
    }

    tcaselect(1);
    if (!lox61.begin()) {
    Serial.println(F("Failed to boot VL6180X back R"));
    while(1);
    }

    Serial.println(" End setup");
    delay(1000);
}

void tofPid()
{
    tcaselect(7);
    uint8_t range1 = lox61.readRange();
    tof[0] = range1;
    Serial.print("tof[0] "); Serial.print(tof[0]); Serial.print("   ");

    tcaselect(2);
    uint8_t range2 = lox61.readRange();
    tof[4] = range2;
    Serial.print("tof[4] "); Serial.print(tof[4]); Serial.print("");

    tcaselect(0);
    uint8_t range3 = lox61.readRange();
    tof[5] = range3;
    Serial.print("tof[5] "); Serial.print(tof[5]); Serial.print("   ");

    tcaselect(1);
    uint8_t range4 = lox61.readRange();
    tof[6] = range4;
    Serial.print("tof[6] "); Serial.print(tof[6]); Serial.println("");
}

void tofStart()
{

//    tcaselect(6);
//    uint8_t range5 = lox61.readRange();
//    tof[1] = range5;
//    Serial.print("tof[1] "); Serial.print(tof[1]); Serial.print("   ");
//
//    tcaselect(3);
//    uint8_t range6 = lox61.readRange();
//    tof[3] = range6;
//    Serial.print("tof[3] "); Serial.print(tof[3]); Serial.println("");
    
    VL53L0X_RangingMeasurementData_t measure;
    tcaselect(4);
    lox53.rangingTest(&measure, false);
    tof[2] = measure.RangeMilliMeter;
    Serial.print("tof[2] "); Serial.print(tof[2]); Serial.print("   ");

    
}

bool wallLeft(){
  tofPid();
  if((tof[0]+tof[5])/2 < 80){
    return true;
    }
    else{
      return false;
      }
  }

bool wallRight(){
  tofPid();
  if((tof[4]+tof[6])/2 < 80){
    return true;
    }
    else{
      return false;
      }
  }

bool wallFront(){
  tofPid();
  if(tof[2] < 120){
    return true;
    }
    else{
      return false;
      }
  }
