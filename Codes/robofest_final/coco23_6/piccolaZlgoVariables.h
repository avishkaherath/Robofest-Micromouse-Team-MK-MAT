#include <QueueArray.h>

byte x=0;
byte y=0;

byte xprev=0;
byte yprev=0;
byte orient=0;
byte state=0;
boolean shortPath= false;
boolean middleSquare= true;
byte x_0;
byte y_0;
byte x_1;
byte y_1;
byte x_2;
byte y_2;
byte x_3;
byte y_3;
byte mazeSize = 16;
char dir;
char turning;
QueueArray <byte> queue;
QueueArray <byte> pathQueue;
bool L = true;
bool R= true;
bool F= false; 
byte xdes;
byte ydes;
unsigned long timer;
int cellCount =0;
boolean runningNext;

byte cells[14][14] = {{0,0,0,0,0,0},
            {0,0,0,0,0,0},
            {0,0,0,0,0,0},
            {0,0,0,0,0,0},
            {0,0,0,0,0,0},
            {0,0,0,0,0,0}
          };

byte flood2[14][14] = {{0,0,0,0,0,0},
            {0,0,0,0,0,0},
            {0,0,0,0,0,0},
            {0,0,0,0,0,0},
            {0,0,0,0,0,0},
            {0,0,0,0,0,0}
            };

byte flood[14][14]={
        {4,3,2,2,3,4},
        {3,2,1,1,2,3},
        {2,1,0,0,1,2},
        {2,1,0,0,1,2},
        {3,2,1,1,2,3},
        {4,3,2,2,3,4}
        };



char bluetoothWalls;
byte xrun=0;
byte yrun=0;
  
