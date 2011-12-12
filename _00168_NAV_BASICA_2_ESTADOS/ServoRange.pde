// --------------------------------------------------------------------------- SERVO RANGE

void ServoRange (int _min, int _max, int _del, int _inc) 
{  
  servo.write(i);
  delay(_del);
  
  if(i >= _max) dir = DEC_POS;
  if(i <= _min) dir = INC_POS;

  if(dir == INC_POS)
    i += _inc;
  else
    i -= _inc;
}

