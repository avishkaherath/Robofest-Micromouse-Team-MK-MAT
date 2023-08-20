#include "pin_declare.h"
#include "variables.h"
#include "motor_without_lib.h"

static unsigned long lastMilli = 0;

void leftcount() {
  leftEncoder ++;
}

void rightcount() {
  rightEncoder ++;
}

void setup() {
  // put your setup code here, to run once:
  motor_setup();
  interrupt_setup();
  attachInterrupt(digitalPinToInterrupt(ENCL1), countLeftEnc, RISING);
  attachInterrupt(digitalPinToInterrupt(ENCR1), countRightEnc, RISING);
  Serial.begin(9600);
  motorL.reverse(leftPwm);
  motorR.reverse(rightPwm);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (millis() - lastMilli > 250) { // every 50 millisecond
    lastMilli = millis();
    Serial.print(leftEncoder);
    Serial.print(" , ");
    Serial.println(rightEncoder);
    leftEncoder = 0;
    rightEncoder = 0;
  }
}
