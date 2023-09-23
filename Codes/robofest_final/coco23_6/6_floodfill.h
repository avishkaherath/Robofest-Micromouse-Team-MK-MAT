#include <QueueArray.h>

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
  delay(100);
}

else if(dir=='R'){
  rightAboutTurn();
  orient = orientation(orient,'R');
  delay(100);
}

else if(dir=='B'){
  turnBack();
  orient = orientation(orient,'B');
  delay(100);
}

goCell();
xprev=x;
yprev=y;
x,y = updateCoordinates();

}
  


