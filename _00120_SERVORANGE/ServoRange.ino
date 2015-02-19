// --------------------------------------------------------------------------- SERVO RANGE
void ServoRange (int _min, int _max, int _del, int _inc) 
{  
  s1.write(servoPos);
  delay(_del);
  
  if(servoPos >= _max) dir = DEC_POS;
  if(servoPos <= _min) dir = INC_POS;

  if(dir == INC_POS)
    servoPos += _inc;
  else
    servoPos -= _inc;
}

