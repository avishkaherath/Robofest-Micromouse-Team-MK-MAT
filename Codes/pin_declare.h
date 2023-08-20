
#define PINA1 10  // IN1 LEFT MOTOR
#define PINA2 9   // IN2
#define PINB1 6   // IN3 RIGHT MOTOR
#define PINB2 5   // IN4

//motor
void motor_setup(){
  pinMode(PINA1, OUTPUT);
  pinMode(PINA2, OUTPUT);
  pinMode(PINB1, OUTPUT);
  pinMode(PINB2, OUTPUT);
}
