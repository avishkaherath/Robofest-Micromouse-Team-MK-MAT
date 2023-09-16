#include "Wire.h"
#include "Adafruit_VL6180X.h"
#include "Adafruit_VL53L0X.h"
#include "QueueArray.h"
#include "cocoVariables.h"
#include "cocoPins.h"
#include "cocoTof.h"
#include "cocoMotors.h"
#include "cocoWallPid.h"
#include "cocoMoves.h"
#include "cocoSpeed.h"
#include "cocoTurns.h"
#include "cocoMaze.h"


void setup() {
  tofSetup();
    motorDiver();
    motorInterrupt();
    attachInterrupt(digitalPinToInterrupt(ENCL1), countLeftOut1, RISING);
    attachInterrupt(digitalPinToInterrupt(ENCR1), countRightOut1, RISING);
  Serial.begin(9600);
    int x = 0;
    int y = 0;
    
    int orient = 0;
    
  // put your setup code here, to run once:
    
    
}

void loop() {
  
  // put your main code here, to run repeatedly:
    while (true){
        
       
        bool L = wallLeft();
        bool R = wallRight();
        bool F = wallFront();
        updateWalls(x, y, orient, L, R, F);

        if (flood[y][x] != 0) {
            if (state == 0) {
                appendZero(flood);
            } else if (state == 1) {
                appendDestination(13, 0, flood);
                shortPath = false;
            } else if (state == 2) {
                appendDestination(0, 0, flood);
                shortPath = false;
            } else if (state == 3) {
                appendZero(flood);
                floodFill2(flood2);
                shortPath = true;
            } else if (state == 4) {
                appendDestination(0, 13, flood);
                shortPath = false;
            } else if (state == 5) {
                appendDestination(0, 0, flood);
                shortPath = false;
            } else if (state == 6) {
                appendZero(flood);
                floodFill2(flood2);
                shortPath = true;
            }

            floodFill3(flood);
        } else {
            if (state == 5) {
                appendZero(flood);
                floodFill3(flood);
                state++;
            } else if (state == 4) {
                changeDestination(flood, 0, 0);
                state++;
            } else if (state == 3) {
                x, y, xprev, yprev, orient = center(x, y, orient);
                changeDestination(flood, 0, 13);
                state++;
            } else if (state == 2) {
                appendZero(flood);
                floodFill3(flood);
                state++;
            } else if (state == 1) {
                changeDestination(flood, 0, 0);
                state++;
            } else if (state == 0) {
                x, y, xprev, yprev, orient = center(x, y, orient);
                changeDestination(flood, 13, 0);
                state++;
            }

            floodFill2(flood2);
        }

        String direction;

        if (shortPath) {
            direction = toMove2(flood2, x, y, xprev, yprev, orient);
        } else {
            direction = toMove(flood, x, y, xprev, yprev, orient);
        }

        if (direction == "L") {
            leftAboutTurn();
            orient = orientation(orient, 'L');
        } else if (direction == "R") {
            rightAboutTurn();
            orient = orientation(orient, 'R');
        } else if (direction == "B") {
            leftAboutTurn();
            orient = orientation(orient, 'L');
            leftAboutTurn();
            orient = orientation(orient, 'L');
        }

       // show(flood, state);
        goCell();
        xprev = x;
        yprev = y;
        x, y = updateCoordinates(x, y, orient);
 }

}
