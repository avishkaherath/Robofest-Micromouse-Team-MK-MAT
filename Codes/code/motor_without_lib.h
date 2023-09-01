// encoder read
void countLeftEnc(){
  if (digitalRead(ENCL2)){
    leftEncoder ++;
  }else{
    leftEncoder --;
  }
}

void countRightEnc(){
  if (digitalRead(ENCR2)){
    rightEncoder ++;
  }else{
    rightEncoder --;
  }
}


//-------------------------------------------------------------------------------
void leftForward(int Pwm){
  analogWrite(PINL1,leftPwm);
  analogWrite(PINL2,1);   
}

void rightForward(int Pwm){
  analogWrite(PINR1,rightPwm);
  analogWrite(PINR2,1); 
}

void leftBackward(int Pwm){
  analogWrite(PINL2,Pwm);
  analogWrite(PINL1,1); 
}

void rightBackward(int Pwm){
  analogWrite(PINR2,Pwm);
  analogWrite(PINR1,1); 
}

void leftBrake(){
  analogWrite(PINL1, 1);
  analogWrite(PINL2, 1);
}

void rightBrake(){
  analogWrite(PINR1, 1);
  analogWrite(PINR2, 1);
}

//--------------------------------------------------------------------------------

void forward(){
  leftForward(leftPwm);
  rightForward(rightPwm);
}

void reverse(){
  leftBackward(leftPwm);
  rightBackward(rightPwm);
}

void turnLeft(){
  leftBackward(leftPwm);
  rightForward(rightPwm);
}

void turnRight(){
  leftForward(leftPwm);
  rightBackward(rightPwm);
}

void mBrake(){
  leftBrake();
  rightBrake();
}

void idle(){
  digitalWrite(PINR1, LOW);
  digitalWrite(PINR2, LOW);
  digitalWrite(PINL1, LOW);
  digitalWrite(PINL2, LOW);
}
//----------------------------------------

//// define motor class
//class motor {
//  public:
//    motor(byte IN1, byte IN2, int baseSpeed);
//    void forward(int PWM);
//    void backward(int PWM);
//    void brake();
//    void idle();
//    int _baseSpeed;
//
//  private:
//    byte _IN1;
//    byte _IN2;
//    
//};
//
//motor::motor(byte IN1, byte IN2, int baseSpeed){
//  _IN1 = IN1;
//  _IN2 = IN2;
//  _baseSpeed = baseSpeed;
//}
//
//void motor::forward(int PWM){
//  analogWrite(_IN1,PWM);
//  digitalWrite(_IN2,LOW);  
//}
//
//void motor::backward(int PWM){
//  analogWrite(_IN2,PWM);
//  digitalWrite(_IN1,LOW);  
//}
//
//void motor::brake(){
//  digitalWrite(_IN1,HIGH);
//  digitalWrite(_IN2,HIGH);
//}
//
//void motor::idle(){
//  digitalWrite(_IN1,LOW);
//  digitalWrite(_IN2,LOW);
//}
////-----------------------------------------
//
//
//motor motorL(PINL1,PINL2,leftBase);
//motor motorR(PINR1,PINR2,rightBase);
//
//void forward(){
//  motorL.forward(leftPwm);
//  motorR.forward(rightPwm);
//}
//
//void reverse(){
//  motorL.backward(leftPwm);
//  motorR.backward(rightPwm);
//}
//
//void brake(){
//  motorL.brake();
//  motorR.brake();
//}
//
//void turnLeft(){
//  motorL.backward(leftPwm);
//  motorR.forward(rightPwm);
//}
//
//void turnRight(){
//  motorL.forward(leftPwm);
//  motorR.backward(rightPwm);
//}
