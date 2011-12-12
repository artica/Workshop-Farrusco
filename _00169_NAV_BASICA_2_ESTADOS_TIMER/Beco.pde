void Beco(int from) 
{
  
  Serial.print("    Beco: ");
  Serial.println(from);
  
  digitalWrite(red_pin, HIGH);
  digitalWrite(green_pin, LOW);
  digitalWrite(blue_pin, LOW);
  
  DiffTurn(-maxSpeedLeft, -maxSpeedRight);
  delay(250);
  
  // se detectou obstáculo pela esquerda, vira p direita
  if (from == 1)
   DiffTurn(-maxSpeedLeft, maxSpeedRight);
  
  // se detectou pela direita, vira p esquerda
  if (from == 2)
    DiffTurn(maxSpeedLeft, -maxSpeedRight);
  
  delay(100);


}
