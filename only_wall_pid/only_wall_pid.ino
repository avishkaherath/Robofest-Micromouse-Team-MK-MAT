#include "Wire.h"
#include "Adafruit_VL53L0X.h"
#include "Adafruit_VL6180X.h"
#include "MPU6050_light.h"
#include "piccolaPins.h"
#include "piccolaVariables.h"
#include "piccolaTof.h"
#include "piccolaMotors.h"
#include "piccolaTurns.h"
#include "piccolaWallPid.h"
#include "piccolaSpeed.h"
//#include "piccolaMoves.h"


void setup() {
    tofSetup();
    motorDiver();
    motorInterrupt();
    attachInterrupt(digitalPinToInterrupt(2), countLeftOut1, RISING);
    attachInterrupt(digitalPinToInterrupt(4), countLeftOut1, RISING);
    attachInterrupt(digitalPinToInterrupt(16), countRightOut1, RISING);
    attachInterrupt(digitalPinToInterrupt(17), countRightOut1, RISING);
    Serial.begin(9600);
}

void loop() {
    
  //cellForward();
  //wallFollow();
}
