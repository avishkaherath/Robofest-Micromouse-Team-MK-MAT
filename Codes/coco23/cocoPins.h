#define PINL1 26  // IN1 LEFT MOTOR
#define PINL2 12   // IN2
#define PINR1 27   // IN3 RIGHT MOTOR
#define PINR2 14  // IN4

#define ENCL1 17   //interrupt pins of motors 
#define ENCL2 16        
#define ENCR1 4
#define ENCR2 18

void motorDiver()
{
    pinMode(PINL1, OUTPUT);
    pinMode(PINL2, OUTPUT);
    pinMode(PINR1, OUTPUT);
    pinMode(PINR2, OUTPUT);
}

void motorInterrupt()
{
    pinMode(ENCL1, INPUT);
    pinMode(ENCL2, INPUT);
    pinMode(ENCR1, INPUT);
    pinMode(ENCR2, INPUT);
}
