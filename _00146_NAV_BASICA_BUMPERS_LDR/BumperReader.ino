// --------------------------------------------------------------------------- BUMPERS

void BumperReader() 
{
  BLeft = digitalRead(bumperLeft);
  BRight = digitalRead(bumperRight);
  //Serial.print(BLeft);
  //Serial.print("  ");
  //Serial.println(BRight);
}

