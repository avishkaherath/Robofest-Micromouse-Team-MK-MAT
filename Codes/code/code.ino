#include "pin_declare.h"
#include "variables.h"
#include "motor_without_lib.h"
#include "Turns.h"

static unsigned long lastMilli = 0;
static unsigned long lastMilli1 = 0;
void setup() {
  // put your setup code here, to run once:
  motor_setup();
  interrupt_setup();
  attachInterrupt(digitalPinToInterrupt(ENCL1), countLeftEnc, RISING);
  attachInterrupt(digitalPinToInterrupt(ENCR1), countRightEnc, RISING);
  Serial.begin(115200);
  delay(100);
  Serial.println("start");
//    forward();
//    delay(500);
//    mBreak();
//    delay(500);
//    reverse();
//    delay(500);
//    mBreak();
//    delay(500);
//  lastMilli1 = millis();
}
 
void loop() {
 rightAboutTurn();
  delay(1000);

  leftAboutTurn();
  delay(1000);

  turnBack();
  delay(1000);
  

//  if (millis()-lastMilli1 < 2000) {
//    forward();
//  }
//  else if (millis()-lastMilli1 < 4000) {
//    
//    reverse();
//  }
//  else if (millis()-lastMilli1 < 6000) {
//  turnLeft();
//  }
//  else if (millis()-lastMilli1 < 8000) {
//    turnRight();
//  }
//  else {
//    mBreak();
//  }
//
//    Serial.print(leftEncoder);
//    Serial.print(" , ");
//    Serial.println(rightEncoder);
//    leftEncoder = 0;
//    rightEncoder = 0;
//delay(100);
  }

  //  Serial.println("turn left by 90 degree");
  //  left90();
  //  //delay(1000);
  //  Serial.println("turn right by 90 degree");
  //  //mBreak();
  //  delay(250);
  //  right90();
  //  //delay(1000);
  //  //mBreak();
  //  delay(250);
