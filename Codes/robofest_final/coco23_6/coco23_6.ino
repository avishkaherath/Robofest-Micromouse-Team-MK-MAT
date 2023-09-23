#include "Wire.h"
#include "Adafruit_VL6180X.h"
//#include "QueueArray.h"
#include "cocoVariables.h"
#include "piccolaZlgoVariables.h"
#include "piccolaZlgo.h"
#include "cocoPins.h"
#include "cocoTof.h"
#include "cocoMotors.h"
#include "cocoWallPid.h"
#include "cocoMoves.h"
#include "cocoSpeed.h"
#include "cocoTurns.h"
#include "piccolaMazeSolve.h"

#include "EEPROM.h"






void setup() {
  tofSetup();
  Wire.begin();
  motorDiver();
  motorInterrupt();
  attachInterrupt(digitalPinToInterrupt(ENCL1), countLeftOut1, RISING);
  attachInterrupt(digitalPinToInterrupt(ENCR1), countRightOut1, RISING);
  Serial.begin(9600);
  // int x = 0;
  // int y = 0;
  // int orient = 0;

 
      // while(true) {
      //   if(!wallLeft()) {
      //       leftAboutTurn();
      //   }
      //   while(wallFront()) {
      //       rightAboutTurn();
      //   }
      //   goCell();
      //   }
        
//          while(true){
//            tofPid();
//          
//            //turnBack();
//            cellPara();
//            delay(1000);
//            }
          
}

void loop() {
      while(1){
  L=wallLeft();
  R=wallRight();
  F=wallFront();
  updateWalls(x,y,orient,L,R,F);

  if (flood[y][x]!=0){
    if (state==0){
      appendDestination(0,0,true);
    }
      else if(state==1){
      appendDestination(5,0,false);
       shortPath=false;
      }


    
    floodFill3();
                
  }
  else{

    if(state==1){
     appendDestination(0,0,false);
      state+=1;

    }
    else if(state==0){
      center();
      appendDestination(5,0,false);
      state=state+1;
    }


  }
  floodFill2();

if (shortPath){
  dir=toMove2();
}
else{
  dir=toMove(x,y,xprev,yprev,orient);
}

if(dir=='L'){
  leftAboutTurn();
  orient = orientation(orient,'L');
  delay(500);
}

else if(dir=='R'){
  rightAboutTurn();
  orient = orientation(orient,'R');
  delay(500);
}

else if(dir=='B'){
  turnBack();
  orient = orientation(orient,'B');
  delay(500);
}

goCell();
xprev=x;
yprev=y;
x,y = updateCoordinates();

}
          

}