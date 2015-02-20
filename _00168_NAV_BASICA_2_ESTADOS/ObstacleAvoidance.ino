void ObstacleAvoidance() 
{

  ServoRange(60, 140, servoDelay, 5);
  
  ReadIR();
  
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
  // se 'servoPos' for menor do que 90 quer dizer que estamos a olhar para a esquerda
  // logo querermos que o robot se afaste, sendo assim vamos parar o motor da direita
  // girando apenas o motor da esquerda 
  if (servoPos > 90 && IRValue >= 300)   {
      motorRightSpeed = maxSpeedRight;
      motorLeftSpeed = 0;
      // slow down servo speed
      servoDelay = 250;
      
      digitalWrite(red_pin, LOW);
      digitalWrite(green_pin, HIGH);
      digitalWrite(blue_pin, LOW);
    }
  
  // se 'servoPos' for maior do que 90 quer dizer que estamos a olhar para a direita
  // logo querermos que o robot se afaste, sendo assim vamos parar o motor da esquerda
  // girando apenas o motor da direita 
  if (servoPos < 90 && IRValue >= 300) {
      motorRightSpeed = 0;
      motorLeftSpeed = maxSpeedLeft;
      // slow down servo speed
      servoDelay = 250;
      
      digitalWrite(red_pin, LOW);
      digitalWrite(green_pin, HIGH);
      digitalWrite(blue_pin, LOW);
    }
    
   if(IRValue < 299) {
      motorRightSpeed = maxSpeedRight;
      motorLeftSpeed = maxSpeedLeft;
      // speed up servo speed
      servoDelay = 50;
      
      digitalWrite(red_pin, LOW);
      digitalWrite(green_pin, LOW);
      digitalWrite(blue_pin, HIGH);
      
    } 
    

  delay(10);

  // chamada da função 'DiffTurn' atribuindo sempre os valores de rotação dos motores
  DiffTurn(motorLeftSpeed,motorRightSpeed);
 
  }

}
