#include "Wire.h"
#include "Adafruit_VL6180X.h"
#include "cocoVariables.h"
#include "cocoZlgoVariables.h"
#include "cocoPins.h"
#include "cocoTof.h"
#include "cocoMotors.h"
#include "cocoWallPid.h"
#include "cocoMoves.h"
#include "cocoSpeed.h"
#include "cocoTurns.h"
#include "cocoNewFunctions.h"
#include "cocoZlgo.h"
#include "cocoMazeSolve.h"
#include "EEPROM.h"



void setup() {

byte x=0;
byte y=0;
byte cell=0;
byte xprev=0;
byte yprev=0;
byte orient=0;
byte state=0;
boolean shortPath= false;
//char dir ='F';
  tofSetup();
  Wire.begin();
  motorDiver();
  motorInterrupt();
  attachInterrupt(digitalPinToInterrupt(ENCL1), countLeftOut1, RISING);
  attachInterrupt(digitalPinToInterrupt(ENCR1), countRightOut1, RISING);
  Serial.begin(9600);

  //    turnBack();
  //    rightAboutTurn();
  //    delay(1000);
  //    leftAboutTurn();
  //    delay(1000);
  //      goCell();
  //      goCell();

//        while (true) {
//                  if(!wallLeft()){
//                leftAboutTurn();
//            }
//    
//            else if(wallLeft() && wallRight() && wallFront()){
//                turnBack();
//    
//              }
//            else if (wallLeft()&& wallFront()){
//              rightAboutTurn();
//            }
//            goCell();
//            wallFollow();
//            delay(50);
//            forwardBase();
//            delay(250);

    //          tofPid();
    //        tofStart();
    //         delay(250);
    //          tofFront();
    //          delay(250);
//    tofStart();
//    tofFront();
//    cellPara();
//    delay(1000);
// }
//eepromClear();




}

void loop() {
  delay(1000);
  

  while (1) {
    L = wallLeft();
    R = wallRight();
    F = wallFront();
    
    updateWalls(x, y, orient, L, R, F);
    

    if (flood[y][x] != 0) {
      if (state == 0) {
        appendDestination(0, 0, true);
        
      }
      else if (state == 1) {
        appendDestination(13, 0, false);
        
        shortPath = false;
      }

      floodFill3();
      
    }


    else {

      if (state == 1) {
        changeDestination(0, 0);
        
        state += 1;

      }
      else if (state == 0) {
        center();
//        writeCells();
        changeDestination(13, 0);
        state = state + 1;
      }

      floodFill2();

    }
    

    if (shortPath) {
      dir = toMove2();
      
    }
    else {
      dir = toMove(x, y, xprev, yprev, orient);
      
    }
    

    if (dir == 'L') {
      leftAboutTurn();
      //delay(100);
      orient = orientation(orient, 'L');
    }

    else if (dir == 'R') {
      rightAboutTurn();
      //delay(100);
      orient = orientation(orient, 'R');
    }

    else if (dir == 'B') {
      turnBack();
      //delay(100);
      orient = orientation(orient, 'B');
    }

    goCell();
    
    xprev = x;
    yprev = y;
    x, y = updateCoordinates();
    

  }
}
