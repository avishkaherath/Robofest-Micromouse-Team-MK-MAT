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

char toMove(byte x,byte y,byte xprev,byte yprev,byte orient){
    
    x_0,y_0,x_1,y_1,x_2,y_2,x_3,y_3 = getSurrounds(x,y);
    
    byte val= flood[y][x];
    byte prev=0;
    byte minVals[4]={254,254,254,254};
    //byte visited[4]={2,2,2,2};



    if (isAccessible(x,y,x_0,y_0)){
        if (x_0==xprev && y_0==yprev)
            prev=0;
        // if (cells[y_0][x_0]!=0)
        //     visited[0]= 1;
        // else
        //     visited[0]= 2;
        minVals[0]= flood[y_0][x_0];
    }
    // else
    //   minVals[0]=254;
    
    if (isAccessible(x,y,x_1,y_1)){
        if (x_1==xprev && y_1==yprev)
            prev=1;
        // if (cells[y_1][x_1]!=0)
        //     visited[1]= 1;
        // else
        //     visited[1]= 2;
            
        minVals[1]= flood[y_1][x_1];
    }
    // else
    //   minVals[1]=254;
      
    if (isAccessible(x,y,x_2,y_2)){
        if (x_2==xprev && y_2==yprev)
            prev=2;
        // if (cells[y_2][x_2]!=0)
        //     visited[2]= 1;
        // else
        //     visited[2]= 2;
        minVals[2]= flood[y_2][x_2];
    }
    // else
    //   minVals[2]=254;
      
    if (isAccessible(x,y,x_3,y_3)){
        if (x_3==xprev && y_3==yprev)
            prev=3;
        // if (cells[y_3][x_3]!=0)
        //     visited[3]= 1;
        // else
        //     visited[3]= 2;
        minVals[3]= flood[y_3][x_3];
    }
    // else
    //   minVals[3]=254;

    
    byte minVal=254;
    byte minCell=0;
    byte noMovements=0;
    
    
    for (int i=0; i<4;i++){
        if (minVals[i]!= 254){
            noMovements+=1;}
    }
    
    for (int i=0; i<4;i++){
        if (minVals[i]<minVal){
            if (noMovements==1){
                minVal= minVals[i];
                minCell= i;
            }
            else{
                if(i!=prev){
                    minVal= minVals[i];
                    minCell= i;
                    
                }
            }
        }
    }


    // byte bla[4] ={254,254,254,254};
    // for (int i=0; i<4;i++){
    //     if (minVals[i]==minVal)
    //         bla[i]= visited[i];
    // }

    // byte blaCount=0;
    // for (int i=0; i<4;i++){
    //     if (bla[i]== 2){
    //         minCell=i ;
    //         blaCount+=1;
    //     }
    // }
      
    // if (blaCount==0){
    //     for (int i=0; i<4;i++){
    //         if (bla[i]== 1)
    //             minCell=i;
    //     }
    // }



    
    if (minCell==orient)
        return ('F');
    else if((minCell==orient-1) || (minCell== orient+3))
        return('L');
    else if ((minCell==orient+1) || (minCell== orient-3))
        return('R');
    else
        return('B');


}


char toMove2(){

    x_0,y_0,x_1,y_1,x_2,y_2,x_3,y_3 = getSurrounds(x,y);
    
    byte val= flood2[y][x];
    byte minCell=0;

    
    if (isAccessible(x,y,x_0,y_0)){
        if (flood2[y_0][x_0]==val-1)
            minCell=0;
    }

    if (isAccessible(x,y,x_1,y_1)){
        if (flood2[y_1][x_1]==val-1)
            minCell=1;
    }

    if (isAccessible(x,y,x_2,y_2)){
        if (flood2[y_2][x_2]==val-1)
            minCell=2;
    }

    if (isAccessible(x,y,x_3,y_3)){
        if (flood2[y_3][x_3]==val-1)
            minCell=3;
    }
    

    
    if (minCell==orient)
        dir= 'F';
    else if((minCell==orient-1) || (minCell== orient+3))
        dir= 'L';
    else if ((minCell==orient+1) || (minCell== orient-3))
        dir= 'R';
    else
        dir= 'B';

}






    

