
#define PINA1 10  // IN1 LEFT MOTOR
#define PINA2 9   // IN2
#define PINB1 6   // IN3 RIGHT MOTOR
#define PINB2 5   // IN4

#define ENCL1 3   //should be an interrupt pin
#define ENCL2 13
#define ENCR1 2   //should be an interrupt pin
#define ENCR2 8

//motor
void motor_setup(){
  pinMode(PINA1, OUTPUT);
  pinMode(PINA2, OUTPUT);
  pinMode(PINB1, OUTPUT);
  pinMode(PINB2, OUTPUT);
}

void interrupt_setup(){
  pinMode(ENCL1, INPUT);
  pinMode(ENCL2, INPUT);
  pinMode(ENCR1, INPUT);
  pinMode(ENCR2, INPUT);
//  attachInterrupt(digitalPinToInterrupt(ENCL1), countLeftEnc, RISING);
//  attachInterrupt(digitalPinToInterrupt(ENCR1), countRightEnc, RISING);
}
