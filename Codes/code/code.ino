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
  delay(1000);
  Serial.println("start");
  for(int i = 1; i <= 5; i++) {
    forward();
    delay(500 * i);
    mBrake();
    delay(100);
    Serial.print(leftEncoder);
    Serial.print(" , ");
    Serial.println( rightEncoder);
  }
}

  void loop() {
    // put your main code here, to run repeatedly:
    //  forward();
    //  Serial.print("forward");
    //  delay(1500);
    //  mBrake();
    //  Serial.print(", brake");
    //  delay(1500);
    //  reverse();
    //  Serial.print(", reverse");
    //  delay(1500);
    //  mBrake();
    //  Serial.print(", brake");
    //  delay(1500);
    //  turnLeft();
    //  Serial.print(", turn left");
    //  delay(1500);
    //  mBrake();
    //  Serial.print(", brake");
    //  delay(1500);
    //  turnRight();
    //  Serial.print(", turn right");
    //  delay(1500);
    //  mBrake();
    //  Serial.println(", brake");
    //  delay(1500);
    //Serial.print(leftEncoder);
    //Serial.print(" , ");
    //Serial.println(rightEncoder);
    //leftEncoder = 0;
    //rightEncoder = 0;
    //delay(100);
  }
