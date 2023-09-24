#include "Arduino.h"
//#include <analogWrite.h>
#include "Wire.h"
#include "Adafruit_VL6180X.h"
#include "QueueArray.h"
#include "cocoVariables.h"
#include "cocoPins.h"
#include "cocoTof.h"
#include "cocoMotors.h"
#include "cocoWallPid.h"
#include "cocoMoves.h"
#include "cocoSpeed.h"
#include "cocoTurns.h"



void setup() {
  tofSetup();
  Wire.begin();
  motorDiver();
  motorInterrupt();
  attachInterrupt(digitalPinToInterrupt(ENCL1), countLeftOut1, RISING);
  attachInterrupt(digitalPinToInterrupt(ENCR1), countRightOut1, RISING);
  Serial.begin(9600);
  int x = 0;
  int y = 0;
  int orient = 0;
goCell();
}
void loop() {
//  if (!wallLeft()) {
//    leftAboutTurn();
//    delay(250);
//  }
//  while (wallFront()) {
//    rightAboutTurn();
//    delay(100);
//  }
//
//  goCell();
//  delay(250);

//leftAboutTurn();
//delay(750);
//rightAboutTurn();
//delay(750);
}
