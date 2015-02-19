void DiffTurn(int speedLeft, int speedRight) {
 
 if (speedLeft > 0) 
 {  
  analogWrite(motorB0, speedLeft);
  digitalWrite(motorB1, LOW);
 }
 
 if (speedLeft < 0) 
 {  
  digitalWrite(motorB0, LOW);
  analogWrite(motorB1, map(speedLeft, 0, -255, 0, 255));
 }
 
 if (speedLeft == 0) 
 {  
  digitalWrite(motorB0, LOW);
  digitalWrite(motorB1, LOW); 
 }
  
 if (speedRight > 0 ) 
 {
  analogWrite(motorA0, speedRight);
  digitalWrite(motorA1, LOW);
 }
 
 if (speedRight < 0 ) 
 {
  digitalWrite(motorA0, LOW);
  analogWrite(motorA1, map(speedRight, 0, -255, 0, 255));
 }
 
 if (speedRight == 0)
 {
  digitalWrite(motorA0, LOW);
  digitalWrite(motorA1, LOW);
 }
}

