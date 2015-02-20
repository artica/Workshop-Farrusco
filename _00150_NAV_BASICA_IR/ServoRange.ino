// --------------------------------------------------------------------------- SERVO RANGE
void ServoRange (int _min, int _max, int _del, int _inc) 
{  
  servo.write(servoPos);
  delay(_del);
  
  if(servoPos >= _max) 
    servoDir = DECREMENTA_POSICAO;
  
  if(servoPos <= _min) 
    servoDir = INCREMENTA_POSICAO;

  if(servoDir == INCREMENTA_POSICAO)
    servoPos += _inc;
  else
    servoPos -= _inc;
    
}

