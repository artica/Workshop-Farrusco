
void FollowLine() 
{
  int resTemp;
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
    
    // Farrusco will seek for light if the motorSpeedLeft is assigned the LDR_Right
  //  motorLeftSpeed = map (LDRLeft, 0, 1023, 0, 255);
  //  motorRightSpeed = map (LDRRight, 0, 1023, 0, 255);
   for(int count =0; count < 4; count++)
   {
     
     resTemp = analogRead(irPins[count]);
     line[count]= resTemp>threshold;
     Serial.print(" ");
     Serial.print(line[count]);
 
   }
   Serial.println();
   //apenas sensor Ext Esq
   if(line[0] && !line[1])
   {
     motorLeftSpeed = 230;
     motorRightSpeed = -200;
   }
   //apenas Ext Esq e  Esq
   else if(line[0] && line[1])
   {
     motorLeftSpeed = 230;
     motorRightSpeed = 200;
   }
   //apenas Esq
   else if(line[1] && !line[2])
   {
     motorLeftSpeed = 230;
     motorRightSpeed = 230;
   }
   //apenas Esq e Dir
   else if(line[1] && line[2])
   {
     motorLeftSpeed = 250;
     motorRightSpeed = 250;
   }
   //apenas Dir
   else if(line[2] && ! line[3])
   {
     motorLeftSpeed = 230;
     motorRightSpeed = 230;
   }
   //apenas Ext Dir e Dir
   else if(line[2] && line[3])
   {
     motorLeftSpeed = 200;
     motorRightSpeed = 230;
   }
   //apenas Ext Dir
    else if(line[3]&& !line[2])
   {
     motorLeftSpeed = -200;
     motorRightSpeed = 230;
   }

    DiffTurn(motorLeftSpeed, motorRightSpeed);
  } 
}
