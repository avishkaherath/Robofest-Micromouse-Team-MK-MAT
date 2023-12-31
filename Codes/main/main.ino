#include "Wire.h"
//#include "EEPROM.h"
#include "Adafruit_VL53L0X.h"
#include "Adafruit_VL6180X.h"
#include "MPU6050_light.h"
#include "piccolaPins.h"
//#include "piccolaZlgoVariables.h"
#include "piccolaVariables.h"
#include "piccolaTof.h"
#include "piccolaMotors.h"
#include "piccolaTurns.h"
#include "piccolaWallPid.h"
#include "piccolaSpeed.h"
#include "piccolaMoves.h"
//#include "piccolaZlgo.h"
//#include "piccolaMazeSolve.h"


void setup() {
    tofSetup();
    motorDiver();
    motorInterrupt();
    attachInterrupt(digitalPinToInterrupt(ENCL1), countLeftOut1, RISING);
    attachInterrupt(digitalPinToInterrupt(ENCR1), countRightOut1, RISING);
    Serial.begin(9600);
}

void loop() {

  rightAboutTurn();
  delay(1000);
//    if(wallLeft() && wallRight() && wallFront()){ //turnback
//      turnBack();
//      }
//    else if(wallLeft() && !wallRight() && !wallFront()){  //leftpid
//      goCell();
//      }
//     else if(!wallLeft() && wallRight() && !wallFront()){ //rightpid
//      goCell();
//      }
//     else if(wallLeft() && wallRight() && !wallFront()){ //wallPid
//      goCell(); 
//      }
//     else if(wallLeft() && !wallRight() && wallFront()){ //turnright
//      rightAboutTurn();
//      }
//      else if(!wallLeft() && wallRight() && wallFront()){ //turnright
//      leftAboutTurn();
//      }
//     
}
