#include <QueueArray.h>

<<<<<<< Updated upstream
  while(1){
=======
while(1){
>>>>>>> Stashed changes
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


<<<<<<< Updated upstream
    
    floodFill3();
  }
                
  
  else{

    if(state==1){
     changeDestination(0,0);
=======
    }
    floodFill3();
                
  }
  else{

    if(state==1){
     appendDestination(0,0,true);
>>>>>>> Stashed changes
      state+=1;

    }
    else if(state==0){
      center();
<<<<<<< Updated upstream
      changeDestination(13,0);
      state=state+1;
    }

=======
      sppendDestination(13,0,false);
      state=state+1;
    }


>>>>>>> Stashed changes
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
<<<<<<< Updated upstream
  rightAboutTurn();
=======
  righttAboutTurn();
>>>>>>> Stashed changes
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
<<<<<<< Updated upstream
x,y = updateCoordinates();

}

=======
x,y = updateCoordinates(x,y,orient);

}
>>>>>>> Stashed changes
