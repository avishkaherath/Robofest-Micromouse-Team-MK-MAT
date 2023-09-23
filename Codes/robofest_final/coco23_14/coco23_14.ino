#include "Wire.h"
#include "Adafruit_VL6180X.h"
//#include "QueueArray.h"
#include "cocoVariables.h"
#include "piccolaZlgoVariables.h"
<<<<<<< Updated upstream
=======
#include "piccolaZlgo.h"
>>>>>>> Stashed changes
#include "cocoPins.h"
#include "cocoTof.h"
#include "cocoMotors.h"
#include "cocoWallPid.h"
#include "cocoMoves.h"
#include "cocoSpeed.h"
#include "cocoTurns.h"
<<<<<<< Updated upstream

#include "piccolaZlgo.h"
#include "new_functions.h"

#include "piccolaMazeSolve.h"
=======
#include "piccolaMazeSolve.h"

>>>>>>> Stashed changes
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
<<<<<<< Updated upstream
//   delay(1000);
//     //searchStates();

//    while(1){
//   L=wallLeft();
//   R=wallRight();
//   F=wallFront();
//   updateWalls(x,y,orient,L,R,F);

//   if (flood[y][x]!=0){
//     if (state==0){
//       appendDestination(0,0,true);
//     }
//       else if(state==1){
//       appendDestination(13,0,false);
//        shortPath=false;
//       }


    
//     floodFill3();
//   }
                
  
//   else{

//     if(state==1){
//      changeDestination(0,0);
//       state+=1;

//     }
//     else if(state==0){
//       center();
//       changeDestination(13,0);
//       state=state+1;
//     }

//   }
//   floodFill2();

// if (shortPath){
//   dir=toMove2();
// }
// else{
//   dir=toMove(x,y,xprev,yprev,orient);
// }

// if(dir=='L'){
//   leftAboutTurn();
//   delay(500);
//   orient = orientation(orient,'L');
// }

// else if(dir=='R'){
//   rightAboutTurn();
//   delay(500);
//   orient = orientation(orient,'R');
// }

// else if(dir=='B'){
//   turnBack();
//   delay(500);
//   orient = orientation(orient,'B');
// }

// goCell();
// xprev=x;
// yprev=y;
// x,y = updateCoordinates();

// }
  if(!wallLeft()){

    leftAboutTurn();
  }
  else (wallFront()){
    rightAboutTurn();
    delay(250);
  }
  goCell();
  delay(250);
}
  


=======
  delay(1000);
    //searchStates();

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
      appendDestination(13,0,false);
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
      appendDestination(13,0,false);
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
  delay(500);
  orient = orientation(orient,'L');
}

else if(dir=='R'){
  rightAboutTurn();
  delay(500);
  orient = orientation(orient,'R');
}

else if(dir=='B'){
  turnBack();
  delay(500);
  orient = orientation(orient,'B');
}

goCell();
xprev=x;
yprev=y;
x,y = updateCoordinates();

}
  

}
>>>>>>> Stashed changes
