
#define PINL1 PB6  // IN1 LEFT MOTOR
#define PINL2 PB7   // IN2
#define PINR1 PB8   // IN3 RIGHT MOTOR
#define PINR2 PB9   // IN4

#define ENCL1 PA1   //should be an interrupt pin
#define ENCL2 PA2
#define ENCR1 PA4   //should be an interrupt pin
#define ENCR2 PA3



//motor
void motor_setup(){
  pinMode(PINL1, OUTPUT);
  pinMode(PINL2, OUTPUT);
  pinMode(PINR1, OUTPUT);
  pinMode(PINR2, OUTPUT);
}

void interrupt_setup(){
  pinMode(ENCL1, INPUT);
  pinMode(ENCL2, INPUT);
  pinMode(ENCR1, INPUT);
  pinMode(ENCR2, INPUT);
//  attachInterrupt(digitalPinToInterrupt(ENCL1), countLeftEnc, RISING);
//  attachInterrupt(digitalPinToInterrupt(ENCR1), countRightEnc, RISING);
}
