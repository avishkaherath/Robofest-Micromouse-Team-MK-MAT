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


// define motor class
class motor {
  public:
    motor(int IN1, int IN2, int baseSpeed);
    void forward(int PWM);
    void reverse(int PWM);
    void brake();
    void idle();
    int _baseSpeed;

  private:
    int _IN1;
    int _IN2;
    
};

motor::motor(int IN1, int IN2, int baseSpeed){
  _IN1 = IN1;
  _IN2 = IN2;
  _baseSpeed = baseSpeed;
}

void motor::forward(int PWM){
  analogWrite(_IN1,PWM);
  digitalWrite(_IN2,LOW);  
}

void motor::reverse(int PWM){
  analogWrite(_IN2,PWM);
  digitalWrite(_IN1,LOW);  
}

void motor::brake(){
  digitalWrite(_IN1,HIGH);
  digitalWrite(_IN2,HIGH);
}

void motor::idle(){
  digitalWrite(_IN1,LOW);
  digitalWrite(_IN2,LOW);
}
//-----------------------------------------


motor motorL(PINA1,PINA2,leftBase);
motor motorR(PINB1,PINB2,rightBase);

void forward(){
  motorL.forward(leftPwm);
  motorR.forward(rightPwm);
}

void reverse(){
  motorL.reverse(leftPwm);
  motorR.reverse(rightPwm);
}

void brake(){
  motorL.brake();
  motorR.brake();
}

void turnLeft(){
  motorL.reverse(leftPwm);
  motorR.forward(rightPwm);
}

void turnRight(){
  motorL.forward(leftPwm);
  motorR.reverse(rightPwm);
}
