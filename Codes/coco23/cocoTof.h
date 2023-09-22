Adafruit_VL6180X lox61 = Adafruit_VL6180X();

#define TCAADDR 0x70

void tcaselect(uint8_t bus) {
  Wire.beginTransmission(TCAADDR);
  Wire.write(1<< bus);
  Wire.endTransmission();  
}

void tofSetup()
{
    delay(50);
    Serial.begin(9600);
    Serial.print("Start.");
    Wire.begin();

    delay(50);
    tcaselect(6);
    if (!lox61.begin()) {
    Serial.println(F("Failed to boot VL6180X 45 L"));
    while(1);
    }
    delay(50);
    tcaselect(3);
    if (!lox61.begin()) {
    Serial.println(F("Failed to boot VL6180X 45 R"));
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

    tcaselect(4);
    if (!lox61.begin()) {
    Serial.println(F("Failed to boot VL6180x C"));
    while(1);
    }

    Serial.println(" End setup");
}

void tofPid()
{
    tcaselect(7);
//    delay(10);  
    tof[0] = lox61.readRange() - 14;
    //Serial.print("tof[0] "); Serial.print(tof[0]); Serial.print("   ");

    tcaselect(2);
//    delay(10);  
    tof[4] = lox61.readRange() - 4;
    //Serial.print("tof[4] "); Serial.print(tof[4]); Serial.print("   ");

    tcaselect(0);
//    delay(10);  
    tof[5] = lox61.readRange() + 1;
    //Serial.print("tof[5] "); Serial.print(tof[5]); Serial.print("   ");

    tcaselect(1);
//    delay(10);  
    tof[6] = lox61.readRange() - 6;
    //Serial.print("tof[6] "); Serial.print(tof[6]); Serial.print("   ");
}

void tofStart()
{

    tcaselect(2);
//    delay(10);  
    tof[4] = lox61.readRange();
    //Serial.print("tof[4] "); Serial.print(tof[4]); Serial.print("   ");

    tcaselect(7);
//    delay(10);  
    tof[0] = lox61.readRange();
    //Serial.print("tof[0] "); Serial.print(tof[0]); Serial.print("   ");
    
    tcaselect(4);
//    delay(10);  
    tof[2] = lox61.readRange();
    //Serial.print("tof[2] "); Serial.print(tof[2]); Serial.println("");
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
  tofStart();
  if(tof[2] < 120){
    return true;
    }
    else{
      return false;
      }
  }
