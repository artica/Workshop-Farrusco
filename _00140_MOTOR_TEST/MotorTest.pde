// --------------------------------------------------------------------------- MOTORES DC

int inc = 10;

void MotorTest() 
{
 /* */
  
  // acelera
  for(int fadeValue = 0 ; fadeValue <= 255; fadeValue += inc) { 
      DiffTurn(fadeValue, fadeValue);  
      delay(50);
  }
  
  // desacelera
  for(int fadeValue = 255 ; fadeValue >= 0; fadeValue -= inc) { 
    DiffTurn(fadeValue, fadeValue);
    delay(50);
  }
  
  DiffTurn(0, 0);
  
  delay(500);
  
  // acelera
  for(int fadeValue = 0 ; fadeValue >= -255; fadeValue -= inc) { 
      DiffTurn(fadeValue, fadeValue);  
      delay(50);
  }
  
  // desacelera
  for(int fadeValue = -255 ; fadeValue <= 0; fadeValue += inc) { 
    DiffTurn(fadeValue, fadeValue);
    delay(50);
  }

  DiffTurn(0, 0);
  
  delay(500);
 
  /* 
  
  DiffTurn(255, 255);  
  Serial.println("255, 255 - frente");
  delay(1500);  
  
  DiffTurn (-255, -255);  
  Serial.println("-255, -255 - tras");
  delay(1500);  
  
  DiffTurn (0, 0);  
  Serial.println("0, 0 - stop");
  delay(1500);  
  
  DiffTurn (-255, 255);  
  Serial.println("-255, 255 - left");  
  delay(1500);  
  
  DiffTurn (255, -255);
  Serial.println("255, -255 - right");
  delay(1500);  
  
  /**/
}
