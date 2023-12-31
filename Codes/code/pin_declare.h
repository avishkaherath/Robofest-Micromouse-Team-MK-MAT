
#define PINL1 26 //PB9  // IN1 LEFT MOTOR
#define PINL2 12 //PB8   // IN2
#define PINR1 27 //PB7   // IN3 RIGHT MOTOR
#define PINR2 14 //PB6  // IN4

#define ENCL1 17 //PA1   //should be an interrupt pin
#define ENCL2 16 //PA0
#define ENCR1 4 //PB4   //should be an interrupt pin
#define ENCR2 18 //PB5


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
