int leftBase = 81;
int rightBase = 82;
int leftPwm = leftBase;
int rightPwm = rightBase;
int leftTurnBase = 120;
int rightTurnBase = 120;
//byte state=0;  // remove this in final code

unsigned long leftEncoder = 0;
unsigned long rightEncoder = 0;
unsigned long encoderLeftCount = 0;
unsigned long encoderRightCount = 0;


int dif = 0;
int test = 0;

float tof[5];
int wallAvailable[3];
int cellWalls[3];

int leftWallAvailable = 0;
int rightWallAvailable = 0;
int frontWallAvailable = 0;

int rightWall  = 1;
int leftWall = 1;

float leftP = 0.15;
float leftD = 4;

float leftError = 0;
float leftLastError = 0;
float leftDiff = 0;

float rightP = 0.2;
float rightD = 2;

float rightError = 0;
float rightLastError = 0;
float rightDiff = 0;

float wallP = 0.2;
float wallD = 2; 

float wallError = 0;
float wallLastError = 0;
float wallDiff = 0;

float encoderP = 0.2 ;
float encoderD = 0; 

float encoderError = 0;
float encoderLastError = 0;
float encoderDiff = 0;

float encoderCorrection = 0;
float correction;

char nextMove = 'F';

int start = 0;

int time1;


boolean left,right,front;
int cell =0;

int jump = 0;
int preState = 0;
int selectMode = -1;
