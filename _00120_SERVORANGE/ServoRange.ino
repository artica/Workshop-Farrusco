// --------------------------------------------------------------------------- SERVO RANGE
void ServoRange (int _min, int _max, int _del, int _inc) 
{  
  s1.write(servoPos);
  delay(_del);
  
  if(servoPos >= _max) 
    dir = DECREMENTA_POSICAO;
  
  if(servoPos <= _min) 
    dir = INCREMENTA_POSICAO;

  if(dir == INCREMENTA_POSICAO)
    servoPos += _inc;
  else
    servoPos -= _inc;
    
}

