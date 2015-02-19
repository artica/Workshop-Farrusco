// --------------------------------------------------------------------------- SERVO RANGE

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

    servoDelayMetro.interval(servoDel);
  }
}


