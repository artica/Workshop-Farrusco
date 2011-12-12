void FollowLight() 
{
   BumperReader();
  
  if (BLeft == 1) 
  {
    Beco (1);
  }
  else if (BRight == 1) 
  {
    Beco (2);
  }
  else 
  {
  
  // call 'DiffTurn' with motors speed
  LDRLeft = analogRead (LDRLeft_pin);
  LDRRight = analogRead (LDRRight_pin);
  
  // Farrusco will seek for light if the motorSpeedLeft is assigned the LDR_Right
  motorRightSpeed = map (LDRLeft, 0, 1023, 0, 255);
  motorLeftSpeed = map (LDRRight, 0, 1023, 0, 255);
  
  DiffTurn(motorLeftSpeed, motorRightSpeed);
  } 
}
