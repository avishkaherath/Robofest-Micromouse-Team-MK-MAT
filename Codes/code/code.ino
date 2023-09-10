#include "pin_declare.h"
#include "variables.h"
#include "motor_without_lib.h"

static unsigned long lastMilli = 0;

void setup() {
  // put your setup code here, to run once:
  motor_setup();
  interrupt_setup();
  attachInterrupt(digitalPinToInterrupt(ENCL1), countLeftEnc, RISING);
  attachInterrupt(digitalPinToInterrupt(ENCR1), countRightEnc, RISING);
  Serial.begin(9600);
  delay(100);
  Serial.println("start");
  left90();
//  delay(1000);
//  mBreak();
  delay(500);
  right90();
//  delay(1000);
//  mBreak();
//  delay(100);
}

void loop() {
  Serial.print(leftEncoder);
  Serial.print(" , ");
  Serial.println(rightEncoder);
  delay(500);
}
