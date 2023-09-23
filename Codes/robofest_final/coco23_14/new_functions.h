void changeDestination(byte xdes,byte ydes){
  
    
      for (int i=0; i<14; i++){
        for (int j=0; j<14; j++){
            flood[i][j]=254;
        }
      flood[ydes][xdes]=0;
       queue.enqueue(ydes);
       queue.enqueue(xdes);

      while (!queue.isEmpty ()){
        yrun=queue.dequeue();
        xrun=queue.dequeue();
        
        x_0,y_0,x_1,y_1,x_2,y_2,x_3,y_3= getSurrounds(xrun,yrun);
        if(x_0>=0 && y_0>=0 && cells[y_0][x_0]!=0){
            if (flood[y_0][x_0]==0){
                
                    flood[y_0][x_0]= flood[yrun][xrun]+1;
                    queue.enqueue(y_0);
                    queue.enqueue(x_0);
                
            }
        }
        if(x_1>=0 && y_1>=0 && cells[y_1][x_1]!=0){
            if (flood[y_1][x_1]==0){
                
                    flood[y_1][x_1]= flood[yrun][xrun]+1;
                    queue.enqueue(y_1);
                    queue.enqueue(x_1);
                }
            
        }
        if(x_2>=0 && y_2>=0 && cells[y_2][x_2]!=0){
            if (flood[y_2][x_2]==0){
                
                    flood[y_2][x_2]=flood[yrun][xrun]+1;
                    queue.enqueue(y_2);
                    queue.enqueue(x_2);
                
            }
        }
        if(x_3>=0 && y_3>=0 && cells[y_3][x_3]!=0){
            if (flood[y_3][x_3]==0){
                
                    flood[y_3][x_3]=flood[yrun][xrun]+1;
                    queue.enqueue(y_3);
                    queue.enqueue(x_3);
                }
            
        }
     }
      }
}

void center(){
  L=wallLeft();
  L=wallRight();
  L=wallFront();

  if(L){
    updateWalls(x,y,orient,L,R,F);
    goCell();
    xprev=x;
    yprev=y;
    x,y = updateCoordinates();

    L=wallLeft();
    L=wallRight();
    L=wallFront();
    updateWalls(x,y,orient,L,R,F);

    rightAboutTurn();
    orient = orientation(orient,'R');
    goCell();
    xprev=x;
    yprev=y;
    x,y = updateCoordinates();

    L=wallLeft();
    L=wallRight();
    L=wallFront();
    updateWalls(x,y,orient,L,R,F);

     rightAboutTurn();
    orient = orientation(orient,'R');
    goCell();
    xprev=x;
    yprev=y;
    x,y = updateCoordinates();

    L=wallLeft();
    L=wallRight();
    L=wallFront();
    updateWalls(x,y,orient,L,R,F);

     rightAboutTurn();
    orient = orientation(orient,'R');
    goCell();
    xprev=x;
    yprev=y;
    x,y = updateCoordinates();

    L=wallLeft();
    L=wallRight();
    L=wallFront();
    updateWalls(x,y,orient,L,R,F);

  


  }

  else{
    updateWalls(x,y,orient,L,R,F);
    goCell();
    xprev=x;
    yprev=y;
    x,y = updateCoordinates();

    L=wallLeft();
    L=wallRight();
    L=wallFront();
    updateWalls(x,y,orient,L,R,F);

    leftAboutTurn();
    orient = orientation(orient,'R');
    goCell();
    xprev=x;
    yprev=y;
    x,y = updateCoordinates();

    L=wallLeft();
    L=wallRight();
    L=wallFront();
    updateWalls(x,y,orient,L,R,F);

     leftAboutTurn();
    orient = orientation(orient,'R');
    goCell();
    xprev=x;
    yprev=y;
    x,y = updateCoordinates();

    L=wallLeft();
    L=wallRight();
    L=wallFront();
    updateWalls(x,y,orient,L,R,F);

     leftAboutTurn();
    orient = orientation(orient,'R');
    goCell();
    xprev=x;
    yprev=y;
    x,y = updateCoordinates();

    L=wallLeft();
    L=wallRight();
    L=wallFront();
    updateWalls(x,y,orient,L,R,F);

    
  }
  


}






    

