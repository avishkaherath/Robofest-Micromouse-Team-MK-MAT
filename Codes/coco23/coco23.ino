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
}


void loop() {

//        if(!wallLeft()){
//            leftAboutTurn();
//            delay(250);
//        }
//
//        else if(wallLeft() && wallRight() && wallFront()){
//            turnBack();
//            delay(250);
//  
//          }
//        else if (wallLeft()&& wallFront()){
//          rightAboutTurn();
//          delay(250);
//        }
//             
//        goCell();
//        delay(250);
          wallFollow();
          delay(10);

}
