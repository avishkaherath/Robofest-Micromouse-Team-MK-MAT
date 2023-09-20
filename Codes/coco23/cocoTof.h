Adafruit_VL6180X lox61 = Adafruit_VL6180X();

#define TCAADDR 0x70

void tcaselect(uint8_t bus) {
  Wire.beginTransmission(TCAADDR);
  Wire.write(1<< bus);
  Wire.endTransmission();  
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
    delay(1000);
}

void tofPid()
{
    tcaselect(7);
    tof[0] = lox61.readRange() - 14;
    Serial.print("tof[0] "); Serial.print(tof[0]); Serial.print("   ");

    tcaselect(2);
    tof[4] = lox61.readRange();
    Serial.print("tof[4] "); Serial.print(tof[4]); Serial.print("   ");

    tcaselect(0);
    tof[5] = lox61.readRange();
    Serial.print("tof[5] "); Serial.print(tof[5]); Serial.print("   ");

    tcaselect(1);
    tof[6] = lox61.readRange()-5;
    Serial.print("tof[6] "); Serial.print(tof[6]); Serial.print("   ");
}

void tofStart()
{

    tcaselect(6);
    //uint8_t range5 = lox61.readRange();
    tof[1] = lox61.readRange();
    Serial.print("tof[1] "); Serial.print(tof[1]); Serial.print("   ");

    tcaselect(3);
    //uint8_t range6 = lox61.readRange();
    tof[3] = lox61.readRange();
    Serial.print("tof[3] "); Serial.print(tof[3]); Serial.print("   ");
    
    tcaselect(4);
   // uint8_t range7 = lox61.readRange();
    tof[2] = lox61.readRange();
    Serial.print("tof[2] "); Serial.print(tof[2]); Serial.println("");
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
