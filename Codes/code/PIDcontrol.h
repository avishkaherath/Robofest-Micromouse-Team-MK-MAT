int encoderP = 0.2;
int encoderD = 0;
int encoderI = 0;

encoderError = 0;
encoderLastError = 0;

void encoderPid()
{
    encoderError = leftEncoder - rightEncoder;
    if (encoderError > 50 )
    {
        encoderError = 10;
    }
    else if (encoderError < -50)
    {
        encoderError = -10;
    }
    encoderCorrection = float(encoderError * encoderP) + float((encoderError - encoderLastError) * encoderD)+ float((encoderError + encoderLastError) * encoderI);
    encoderLastError = encoderError;
    leftPwm = leftBase - encoderCorrection;
    rightPwm = rightBase + encoderCorrection;
    forward();
}
