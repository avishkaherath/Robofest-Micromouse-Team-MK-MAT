#define PINL1 12  // IN1 LEFT MOTOR
#define PINL2 26   // IN2
#define PINR1 14   // IN3 RIGHT MOTOR
#define PINR2 27  // IN4

#define leftOut1 2   //interrupt pins of motors 
#define leftOut2 4         
#define rightOut1 16
#define rightOut2 17

void motorDiver()
{
    pinMode(PINL1, OUTPUT);
    pinMode(PINL2, OUTPUT);
    pinMode(PINR1, OUTPUT);
    pinMode(PINR2, OUTPUT);
}

void motorInterrupt()
{
    pinMode(leftOut1, INPUT);
    pinMode(leftOut2, INPUT);
    pinMode(rightOut1, INPUT);
    pinMode(rightOut2, INPUT);
}
