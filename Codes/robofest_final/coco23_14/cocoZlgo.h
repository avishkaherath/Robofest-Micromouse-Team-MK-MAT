byte getSurrounds(byte x,byte y){
    x_3= x-1;
    y_3=y;
    x_0=x;
    y_0=y+1;
    x_1=x+1;
    y_1=y;
    x_2=x;
    y_2=y-1;
    if(x_1>= 14){
        x_1=-1;}
    if(y_0>= 14){
        y_0=-1;}
       
   
    return (x_0,y_0,x_1,y_1,x_2,y_2,x_3,y_3);  //order of cells- north,east,south,west
    
}






void appendDestination(byte xdes,byte ydes, boolean middleSquare){
  
    if (middleSquare == true){
      for (int i=0; i<14; i++){
        for (int j=0; j<14; j++){
            flood[i][j]=254;
        }
    }

    flood[6][6]=0;
    flood[7][6]=0;
    flood[6][7]=0;
    flood[7][7]=0;

    queue.enqueue(6);
    queue.enqueue(6);
    queue.enqueue(7);
    queue.enqueue(6);
    queue.enqueue(6);
    queue.enqueue(7);
    queue.enqueue(7);
    queue.enqueue(7);
    }

    else{
    for (int i=0; i<14; i++){
        for (int j=0; j<14; j++){
            flood[i][j]=254;
        }
    }

    flood[ydes][xdes]=0;

    queue.enqueue(ydes);
    queue.enqueue(xdes);
    }
   
}



void changeDestination(byte xdes,byte ydes){
  
    
      for (int i=0; i<14; i++){
        for (int j=0; j<14; j++){
            flood[i][j]=254;
        }
      }
      flood[ydes][xdes]=0;
       queue.enqueue(ydes);
       queue.enqueue(xdes);

      while (!queue.isEmpty ()){
        yrun=queue.dequeue();
        xrun=queue.dequeue();
        
        x_0,y_0,x_1,y_1,x_2,y_2,x_3,y_3= getSurrounds(xrun,yrun);
        if(x_0>=0 && y_0>=0 ){
            if (flood[y_0][x_0]==254){
                
                    flood[y_0][x_0]= flood[yrun][xrun]+1;
                    queue.enqueue(y_0);
                    queue.enqueue(x_0);
                
            }
        }
        if(x_1>=0 && y_1>=0){
            if (flood[y_1][x_1]==254){
                
                    flood[y_1][x_1]= flood[yrun][xrun]+1;
                    queue.enqueue(y_1);
                    queue.enqueue(x_1);
                }
            
        }
        if(x_2>=0 && y_2>=0 ){
            if (flood[y_2][x_2]==254){
                
                    flood[y_2][x_2]=flood[yrun][xrun]+1;
                    queue.enqueue(y_2);
                    queue.enqueue(x_2);
                
            }
        }
        if(x_3>=0 && y_3>=0 ){
            if (flood[y_3][x_3]==254){
                
                    flood[y_3][x_3]=flood[yrun][xrun]+1;
                    queue.enqueue(y_3);
                    queue.enqueue(x_3);
                }
            
        }
     }
    
      }







byte orientation(byte orient, char turning){
  if (turning== 'L'){
        orient=orient-1;
        if (orient==-1){
            orient=3;}
  }
    else if(turning== 'R'){
        orient=orient+1;
        if (orient==4){
            orient=0;}
    }
    else if(turning== 'B'){
        if (orient==0){
            orient=2;}
        else if (orient==1){
            orient=3;}
        else if (orient==2){
            orient=0;}
        else if (orient==3){
            orient=1;}
    }
  

    return(orient);
}






byte updateCoordinates(byte x, byte y, byte orient){//byte x, byte y, byte orient){
    
    if (orient==0){
        y=y+1;}
    if (orient==1){
        x=x+1;}
    if (orient==2){
        y=y-1;}
    if (orient==3){
        x=x-1;}
        

    return(x,y);
}






void updateWalls(byte x, byte y, byte orient, boolean L, boolean R, boolean F){
    if(L && R && F){
        if (orient==0)
            cells[y][x]= 13;
        else if (orient==1)
            cells[y][x]= 12;
        else if (orient==2)
            cells[y][x]= 11;
        else if (orient==3)
            cells[y][x]= 14;
    }

    else if (L && R && !F){
        if (orient==0 || orient== 2)
            cells[y][x]= 9;
        else if (orient==1 || orient==3)
            cells[y][x]= 10;
    }

    else if (L && F && !R){
        if (orient==0)
            cells[y][x]= 8;
        else if (orient==1)
            cells[y][x]= 7;
        else if (orient==2)
            cells[y][x]= 6;
        else if (orient==3)
            cells[y][x]= 5;
    }

    else if (R && F && !L){
        if (orient==0)
            cells[y][x]= 7;
        else if (orient==1)
            cells[y][x]= 6;
        else if (orient==2)
            cells[y][x]= 5;
        else if (orient==3)
            cells[y][x]= 8;
    }

    else if(F){
        if (orient==0)
            cells[y][x]= 2;
        else if (orient==1)
            cells[y][x]= 3;
        else if (orient==2)
            cells[y][x]= 4;
        else if (orient==3)
            cells[y][x]= 1;
    }

    else if(L){
        if (orient==0)
            cells[y][x]= 1;
        else if (orient==1)
            cells[y][x]= 2;
        else if (orient==2)
            cells[y][x]= 3;
        else if (orient==3)
            cells[y][x]= 4;
    }

    else if(R){
        if (orient==0)
            cells[y][x]= 3;
        else if (orient==1)
            cells[y][x]= 4;
        else if (orient==2)
            cells[y][x]= 1;
        else if (orient==3)
            cells[y][x]= 2;
    }

    else
        cells[y][x]= 15;
       


}





boolean isAccessible(byte x, byte y, byte xNext, byte yNext){
  // if (xNext==254 || yNext== 254){
  //   return(false);
  // }
  if (x==xNext){
        if(y>yNext){
            if(cells[y][x]==4 || cells[y][x]==5 || cells[y][x]==6 || cells[y][x]==10 || cells[y][x]==11 || cells[y][x]==12 || cells[y][x]==14 || cells[yNext][xNext]==2 || cells[yNext][xNext]==7 || cells[yNext][xNext]==8 || cells[yNext][xNext]==10 || cells[yNext][xNext]==12 || cells[yNext][xNext]==13 || cells[yNext][xNext]==14 )
                return (false);
            else
                return(true);
        }
        else{
            if(cells[y][x]==2 || cells[y][x]==7 || cells[y][x]==8 || cells[y][x]==10 || cells[y][x]==12 || cells[y][x]==13 || cells[y][x]==14 || cells[yNext][xNext]==4 || cells[yNext][xNext]==5 || cells[yNext][xNext]==6 || cells[yNext][xNext]==10 || cells[yNext][xNext]==11 || cells[yNext][xNext]==12 || cells[yNext][xNext]==14 )
                return (false);
            else
                return(true);
        }
  }
    else if (y==yNext){
        if(x>xNext){
            if(cells[y][x]==1 || cells[y][x]==5 || cells[y][x]==8 || cells[y][x]==9 || cells[y][x]==11 || cells[y][x]==13 || cells[y][x]==14 || cells[yNext][xNext]==3 || cells[yNext][xNext]==6 || cells[yNext][xNext]==7 || cells[yNext][xNext]==9 || cells[yNext][xNext]==11 || cells[yNext][xNext]==12 || cells[yNext][xNext]==13 )
                return (false);
            else
                return (true);
        }
        else{
            if(cells[y][x]==3 || cells[y][x]==6 || cells[y][x]==7 || cells[y][x]==9 || cells[y][x]==11 || cells[y][x]==12 || cells[y][x]==13 || cells[yNext][xNext]==1 || cells[yNext][xNext]==5 || cells[yNext][xNext]==8 || cells[yNext][xNext]==9 || cells[yNext][xNext]==11 || cells[yNext][xNext]==13 || cells[yNext][xNext]==14 )
                return (false);
            else
                return (true);
        }


    }

}







void floodFill3(){
  
    while (!queue.isEmpty ()){
        
        yrun=queue.dequeue();
        xrun=queue.dequeue();
        
        x_0,y_0,x_1,y_1,x_2,y_2,x_3,y_3 = getSurrounds(xrun,yrun);
        if(x_0>=0 && y_0>=0 ){
            if (flood[y_0][x_0]==254){
                if (isAccessible(xrun,yrun,x_0,y_0)){
                    flood[y_0][x_0]=flood[yrun][xrun]+1;
                    queue.enqueue(y_0);
                    queue.enqueue(x_0);
                }
            }
        }
        if(x_1>=0 and y_1>=0){
            if (flood[y_1][x_1]==254){
                if (isAccessible(xrun,yrun,x_1,y_1)){
                    flood[y_1][x_1]=flood[yrun][xrun]+1;
                    queue.enqueue(y_1);
                    queue.enqueue(x_1);
                }
            }
        }
        if(x_2>=0 and y_2>=0 ){
            if (flood[y_2][x_2]==254){
                if (isAccessible(xrun,yrun,x_2,y_2)){
                    flood[y_2][x_2]=flood[yrun][xrun]+1;
                    queue.enqueue(y_2);
                    queue.enqueue(x_2);
                }
            }
        }
        if(x_3>=0 and y_3>=0 ){
            if (flood[y_3][x_3]==254){
                if (isAccessible(xrun,yrun,x_3,y_3)){
                    flood[y_3][x_3]=flood[yrun][xrun]+1;
                    queue.enqueue(y_3);
                    queue.enqueue(x_3);
                }
            }
        }
    }

}



void floodFill2(){

  for (int i=0;i<14;i++){
        for (int j=0;j<14;j++){
            flood2[i][j]=0;
        }
 }

    flood2[6][6]=1;
    flood2[7][6]=1;
    flood2[6][7]=1;
    flood2[7][7]=1;

    queue.enqueue(6);
    queue.enqueue(6);
    queue.enqueue(7);
    queue.enqueue(6);
    queue.enqueue(6);
    queue.enqueue(7);
    queue.enqueue(7);
    queue.enqueue(7);

     while (!queue.isEmpty ()){
        yrun=queue.dequeue();
        xrun=queue.dequeue();
        
        x_0,y_0,x_1,y_1,x_2,y_2,x_3,y_3= getSurrounds(xrun,yrun);
        if(x_0>=0 && y_0>=0 && cells[y_0][x_0]!=0){
            if (flood2[y_0][x_0]==0){
                if (isAccessible(xrun,yrun,x_0,y_0)){
                    flood2[y_0][x_0]= flood2[yrun][xrun]+1;
                    queue.enqueue(y_0);
                    queue.enqueue(x_0);
                }
            }
        }
        if(x_1>=0 && y_1>=0 && cells[y_1][x_1]!=0){
            if (flood2[y_1][x_1]==0){
                if (isAccessible(xrun,yrun,x_1,y_1)){
                    flood2[y_1][x_1]= flood2[yrun][xrun]+1;
                    queue.enqueue(y_1);
                    queue.enqueue(x_1);
                }
            }
        }
        if(x_2>=0 && y_2>=0 && cells[y_2][x_2]!=0){
            if (flood2[y_2][x_2]==0){
                if (isAccessible(xrun,yrun,x_2,y_2)){
                    flood2[y_2][x_2]=flood2[yrun][xrun]+1;
                    queue.enqueue(y_2);
                    queue.enqueue(x_2);
                }
            }
        }
        if(x_3>=0 && y_3>=0 && cells[y_3][x_3]!=0){
            if (flood2[y_3][x_3]==0){
                if (isAccessible(xrun,yrun,x_3,y_3)){
                    flood2[y_3][x_3]=flood2[yrun][xrun]+1;
                    queue.enqueue(y_3);
                    queue.enqueue(x_3);
                }
            }
        }
     }

}






char toMove(byte x,byte y,byte xprev,byte yprev,byte orient){
    
    x_0,y_0,x_1,y_1,x_2,y_2,x_3,y_3 = getSurrounds(x,y);
    
    byte val= flood[y][x];
    byte prev=0;
    byte minVals[4]={254,254,254,254};
    //byte visited[4]={2,2,2,2};

    if (isAccessible(x,y,x_0,y_0)){
        if (x_0==xprev && y_0==yprev){
            prev=0;
        }
        minVals[0]= flood[y_0][x_0];
    }
    
    if (isAccessible(x,y,x_1,y_1)){
        if (x_1==xprev && y_1==yprev){
            prev=1;
         }   
        minVals[1]= flood[y_1][x_1];
    }
    
    
      
    if (isAccessible(x,y,x_2,y_2)){
        if (x_2==xprev && y_2==yprev){
            prev=2;
        }
        
        minVals[2]= flood[y_2][x_2];
    }
  
      
    if (isAccessible(x,y,x_3,y_3)){
        if (x_3==xprev && y_3==yprev){
            prev=3;
        }
        
        minVals[3]= flood[y_3][x_3];
    }
   

    
    byte minVal=minVals[0];
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
              if(i==prev){
                
              }
                else {
                    minVal= minVals[i];
                    minCell= i;
                    
                }
            }
        }
    }


    



    
    if (minCell==orient){
        return ('F');}
    else if((minCell==orient-1) || (minCell== orient+3)){
        return('L');}
    else if ((minCell==orient+1) || (minCell== orient-3)){
        return('R');}
    else{
        return('B');}
        


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



void center(){
  L=wallLeft();
  R=wallRight();
  F=wallFront();

  if(L){
    updateWalls(x,y,orient,L,R,F);
    goCell();
    xprev=x;
    yprev=y;
    x,y = updateCoordinates(x,y,orient);

    L=wallLeft();
  R=wallRight();
  F=wallFront();
    updateWalls(x,y,orient,L,R,F);

    rightAboutTurn();
    orient = orientation(orient,'R');
    goCell();
    xprev=x;
    yprev=y;
    x,y = updateCoordinates(x,y,orient);

    L=wallLeft();
  R=wallRight();
  F=wallFront();
    updateWalls(x,y,orient,L,R,F);

     rightAboutTurn();
    orient = orientation(orient,'R');
    goCell();
    xprev=x;
    yprev=y;
    x,y = updateCoordinates(x,y,orient);

    L=wallLeft();
  R=wallRight();
  F=wallFront();
    updateWalls(x,y,orient,L,R,F);

     rightAboutTurn();
    orient = orientation(orient,'R');
    goCell();
    xprev=x;
    yprev=y;
    x,y = updateCoordinates(x,y,orient);

    L=wallLeft();
  R=wallRight();
  F=wallFront();
    updateWalls(x,y,orient,L,R,F);

  


  }

  else{
    updateWalls(x,y,orient,L,R,F);
    goCell();
    xprev=x;
    yprev=y;
    x,y = updateCoordinates(x,y,orient);

    L=wallLeft();
  R=wallRight();
  F=wallFront();
    updateWalls(x,y,orient,L,R,F);

    leftAboutTurn();
    orient = orientation(orient,'R');
    goCell();
    xprev=x;
    yprev=y;
    x,y = updateCoordinates(x,y,orient);

    L=wallLeft();
  R=wallRight();
  F=wallFront();
    updateWalls(x,y,orient,L,R,F);

     leftAboutTurn();
    orient = orientation(orient,'R');
    goCell();
    xprev=x;
    yprev=y;
    x,y = updateCoordinates(x,y,orient);

    L=wallLeft();
  R=wallRight();
  F=wallFront();
    updateWalls(x,y,orient,L,R,F);

     leftAboutTurn();
    orient = orientation(orient,'R');
    goCell();
    xprev=x;
    yprev=y;
    x,y = updateCoordinates(x,y,orient);

    L=wallLeft();
  R=wallRight();
  F=wallFront();
    updateWalls(x,y,orient,L,R,F);

    
  }

  


}