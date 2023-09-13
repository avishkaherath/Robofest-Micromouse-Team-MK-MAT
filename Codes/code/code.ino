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
  Serial.begin(115200);
  delay(100);
  Serial.println("start");
//  left90();

 

}

void loop() {
//  if (millis() - lastMilli > 100) {
//    Serial.print(leftEncoder);
//    Serial.print(" , ");
//    Serial.println(rightEncoder);
//    leftEncoder = 0;
//    rightEncoder = 0;
//    lastMilli = millis();
//  }
  Serial.println("turn left by 90 degree");
  left90();
  //delay(1000);
  Serial.println("turn right by 90 degree");
  //mBreak();
  delay(250);
  right90();
  //delay(1000);
  //mBreak();
  delay(250);
}
