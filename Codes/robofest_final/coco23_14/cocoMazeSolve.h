#include "EEPROM.h"

void eepromClear(){
  for (int i=0 ;i< 250; i++){
    EEPROM.write(i,0);
  }
  EEPROM.commit();
}


void calculatePath(boolean runningNext){
  floodFill2();
  
  byte xprevious=x;
  byte yprevious=y;
  x=0;
  y=0;
  byte oldOrient= orient;
  orient=0;
  
  cellCount=0;
  
    while(flood2[y][x]!=1){
        toMove2();
        //pathQueue.enqueue(dir);

        
        if (runningNext== true){
        pathQueue.enqueue(dir);
        }
        
        //Serial2.println(dir);
    
        if (dir=='L'){
            orient = orientation(orient,'L');
        }

        else if (dir=='R'){
            orient = orientation(orient,'R');
        }

        else if (dir=='B'){
            orient = orientation(orient,'L');
            orient = orientation(orient,'L');
        }

        
        xprev=x;
        yprev=y;
        updateCoordinates();
        
        
  }

        
        x= xprevious;
        y= yprevious;
        orient=oldOrient;   
       // buzz();
}


void traverse(byte xdes, byte ydes, boolean middleSquare, boolean shortPath, boolean smooth){

  byte currentx= x;
  byte currenty= y; 
  
  if (shortPath== false){
    
  appendDestination(xdes,ydes,middleSquare);
  floodFill3();
  checkWallsCell();
  updateWalls(x, y, orient, L, R, F);
  
  while(flood[y][x]!=0){
    
    checkWallsCell();
    updateWalls(x, y, orient, L, R, F);
    appendDestination(xdes,ydes,middleSquare);
    floodFill3();
    dir= toMove(x,y,xprev,yprev,orient);
    
        if (dir=='L'){
            orient = orientation(orient,'L');
            if(x==0 || x== currentx){
              if(y==0 || y== currenty){
                leftAboutTurn();
                delay(500);
                goCell();
                currentx=0;
                currenty=0;
              }
              else{
               leftAboutTurn();
                delay(500);
                goCell();
                currentx=0;
                currenty=0;
              }
            }
            else{
            leftAboutTurn();
                delay(500);
                goCell();
                currentx=0;
                currenty=0;}
        }

        else if (dir=='R'){
          orient = orientation(orient,'R');
            if(x==0 || x== currentx){
              if(y==0 || y== currenty){
                rightAboutTurn();
                delay(500);
                goCell();
                currentx=0;
                currenty=0;
              }
              else{
                rightAboutTurn();
                delay(500);
                goCell();
                currentx=0;
                currenty=0;;
              }
            }
            else{
            rightAboutTurn();
                delay(500);
                goCell();
                currentx=0;
                currenty=0;}
        }

        else if (dir=='B'){
            orient = orientation(orient,'L');
            orient = orientation(orient,'L');
            if((x==0 && y==0)||(x== currentx && y== currenty)){
              turnBack();
              delay(500);
              goCell();
              currentx=0;
                currenty=0;
              }
              else{
              turnBack();
              delay(500);
              goCell();
              currentx=0;
                currenty=0;
              }
        }
        else{
          if((x==0 && y==0)||(x== currentx && y== currenty)){
            goCell();
            currentx=0;
                currenty=0;
          }
          else{
          goCell();
          }
        }
        xprev=x;
        yprev=y;
        updateCoordinates();
  }
  }

  else{

        F= false;
        R= false;
        L= false;

    if (smooth == true){
        calculatePath(true);
    
        while (!pathQueue.isEmpty ()){

        dir= pathQueue.dequeue();

        if (dir=='L'){
            orient = orientation(orient,'L');
            if((x==0 && y==0)||(x== currentx && y== currenty)){
              leftAboutTurn();
              delay(500);
              goCell();
              currentx=0;
              currenty=0;
            }
            else{
            leftAboutTurn();
              delay(500);
              goCell();
              currentx=0;
              currenty=0;}
            
        }

        else if (dir=='R'){
            orient = orientation(orient,'R');
            if((x==0 && y==0)||(x== currentx && y== currenty)){
              rightAboutTurn();
              delay(500);
              goCell();
              currentx=0;
              currenty=0;
            }
            else{
            rightAboutTurn();
              delay(500);
              goCell();
              currentx=0;
              currenty=0;}
        }

        else if (dir=='B'){
            orient = orientation(orient,'L');
            orient = orientation(orient,'L');
            if((x==0 && y==0)||(x== currentx && y== currenty)){
              turnBack();
              delay(500);
              goCell();
              currentx=0;
              currenty=0;
            }
            else{
            turnBack();
              delay(500);
              goCell();
              currentx=0;
              currenty=0;}
          }
        
        else{
          if((x==0 && y==0)||(x== currentx && y== currenty)){
              goCell();
              currentx=0;
              currenty=0;
            }
            else{
            goCell();}
          }

          xprev=x;
          yprev=y;
          updateCoordinates();
        
      }

      
    }

    else{
      
    calculatePath(true);
    
    while (!pathQueue.isEmpty ()){
    checkWallsCell();
    dir= pathQueue.dequeue();
    
        if (dir=='L'){
            orient = orientation(orient,'L');
            if((x==0 && y==0)){
              leftAboutTurn();
              delay(500);
              goCell();
            }
            else{
            leftAboutTurn();
              delay(500);
              goCell();}
            
        }

        else if (dir=='R'){
            orient = orientation(orient,'R');
            if((x==0 && y==0)){
              rightAboutTurn();
              delay(500);
              goCell();
            }
            else{
            rightAboutTurn();
              delay(500);
              goCell();}
        }

        else if (dir=='B'){
            orient = orientation(orient,'L');
            orient = orientation(orient,'L');
            if((x==0 && y==0)){
              turnBack();
              delay(500);
              goCell();
            }
            else{
            turnBack();
              delay(500);
              goCell();}
          }
        
        else{
          if((x==0 && y==0)){
              goCell();
            }
            else{
            goCell();}
          }

          xprev=x;
          yprev=y;
          updateCoordinates();
          
        }   
    }
  }
  }


void fixOrientation(){
  while(orient!=0){
    leftAboutTurn();
    orient = orientation(orient,'L');
    delay(500);
  }
}

void loadCells(){                           //walls configuration
  for (int i=0;i<14;i++){
    for (int j=0; j<14;j++){
      cells[j][i]= EEPROM.read(i*14+j); 
    }
  }
}

void writeCells(){
  for (int i=0;i<14;i++){
    for (int j=0; j<14;j++){
      EEPROM.write(i*14+j ,cells[j][i]);
    }
  }
  EEPROM.commit();
}


// void searchStates(){
//   byte searchState= EEPROM.read(200);

//   if (searchState==3){ 
//     searchState=0; }
//   loadCells();    // read cells from EEPROM


//   if (searchState==0){
//     mazeStart();
//       if (selectMode==1){
//         traverse(0,0,true,false,false);
//         L= false; R= false; F= false;
//         center();
//         brake();
        
//         delay(3000);
//         writeCells();
//         traverse(13,0,false,false,false);
//         brake();
        
//         traverse(0,0,false,false,false);
//         brake();
        
//         fixOrientation();
//         delay(3000);
//         mazeStart();

//         if (selectMode==2){
//           writeCells();
//           EEPROM.write(200,searchState+1);
//         }
//         else if(selectMode==3){
//           eepromClear();
//           delay(1000);
          
//         }
//     }

//     else if (selectMode==2){
//         traverse(0,0,true,true,false);
//         L= false; R= false; F= false;
//         center();
//         brake();
//         //buzz();
//         delay(3000);
//         traverse(0,0,false,false,false);
//         brake();
//         //buzz();
//         fixOrientation();
//         delay(3000);
//         mazeStart();

//         if (selectMode==2){
//           writeCells();
//         }
//         else if(selectMode==3){
//           eepromClear();
//           delay(1000);
//          // buzzDone();
        
//         }
//     }
//     else if (selectMode==3){
//       eepromClear();
//       delay(1000);
//      // buzzDone();
//     }
//   }





  
//   else if (searchState==1){
//     mazeStart();
//     if (selectMode==1){
//       traverse(0,0,true,false,false);
//       L=0; R=0; F=0;
//       brake();
//       center();
//       traverse(0,13,false,false,false);
//       brake();
     
//       delay(500);
//       traverse(0,0,false,false,false);
//       brake();
//       fixOrientation();
//       mazeStart();

//       if (selectMode==2){
//         writeCells();
//         EEPROM.write(200,searchState+1);
//       }
//       else if (selectMode==3){
//         eepromClear();
//        // buzzDone();
//       }

//     }
//     else if(selectMode==2){
//       floodFill2();
//       traverse(0,0,true,true,false);
//       L=0; R=0; F=0;
//       brake();
//       center();
      
//       delay(500);
//       traverse(0,0,false,false,false);
//       brake();
//       fixOrientation();
//       mazeStart();

//       if (selectMode==2){
//         writeCells();
//       }
//       else if (selectMode==3){
//         eepromClear();
//         delay(1000);
        
//       }
//     }
//     else if(selectMode==3){
//       eepromClear();
//       delay(1000);
      
    
//     }
//   }
  
  
  
  
  
  
//   else if(searchState==2){
//     mazeStart();
//     if (selectMode==1){
//       traverse(0,0,true,false,false);
//       L=0; R=0; F=0;
//       brake();
//       center();
      
//       delay(500);
//       traverse(13,13,false,false,false);
//       brake();
      
//       delay(500);
//       traverse(0,0,false,false,false);
//       brake();
//       fixOrientation();
//       mazeStart();

//       if (selectMode==2){
//         writeCells();
//         EEPROM.write(200,searchState+1);
//       }
//       else if (selectMode==3){
//         eepromClear();
        
//       }
//     }
//     else if(selectMode==2){
//       floodFill2();
//       traverse(0,0,true,true,false);
//       L=0; R=0; F=0;
//       brake();
//       center();
      
//       delay(500);
//       traverse(0,0,false,false,false);
//       brake();
//       fixOrientation();
//       mazeStart();

//       if (selectMode==2){
//         writeCells();
//     }
//       else if (selectMode==3){
//         eepromClear();
//         delay(1000);
        
//     }
    
//     }
//     else if(selectMode==3){
//       eepromClear();
//       delay(1000);
      
    
//     }

//   }
    
  
  


// }


