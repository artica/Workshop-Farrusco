// --------------------------------------------------------------------------- SERVO
#include <Servo.h>
Servo servo;

const int SERVOPIN = 9;

const int INC_POS = 0;
const int DEC_POS = 1;

// variavel 'dir' (direcção) define a rotacao do servo
// variable 'dir' (direction) defines servo rotation 
byte servoDir = INC_POS;

// o valor para ser enviado ao servo
// value to be sent to the servo
int servoPos = 90;

// increment
int servoInc = 5;

// delay
int servoDelay = 50;

int servoMin = 50;
int servoMax = 120;


void ServoSetup() 
{  
  servo.attach(SERVOPIN); // servo attach
  servo.write(90); // center servo
}

void ServoSetInterval(int _servoDelay, int _servoMin, int _servoMax) 
{
  servoDelay = _servoDelay;
  servoMin = _servoMin;
  servoMax = _servoMax;
}




void ServoWrite(int _pos)
{
  servo.write(_pos);
}
// --------------------------------------------------------------------------- SERVO RANGE
void ServoRange() 
{
  ServoRange(servoMin, servoMax, servoInc);
}

void ServoRange (int _min, int _max)
{
  ServoRange (_min, _max, servoInc);
}

void ServoRange (int _min, int _max, int _servoInc) 
{  
  if (servoDelayMetro.check() == 1) {
    servo.write(servoPos);

    if(servoPos >= _max) servoDir = DEC_POS;
    if(servoPos <= _min) servoDir = INC_POS;

    if(servoDir == INC_POS)
      servoPos += _servoInc;
    else
      servoPos -= _servoInc;

    servoDelayMetro.interval(servoDelay);
  }
}

int ServoGetPos() 
{
  return servoPos;
}

