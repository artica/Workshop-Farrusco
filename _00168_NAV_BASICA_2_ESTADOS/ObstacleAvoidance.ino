void ObstacleAvoidance() 
{

  ServoRange(60, 140, del, 5);
  
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
  // se 'i' for menor do que 90 quer dizer que estamos a olhar para a esquerda
  // logo querermos que o robot se afaste, sendo assim vamos parar o motor da direita
  // girando apenas o motor da esquerda 
  if (i < 90) {
    
    if (IRValue >= 300)   {
      
      digitalWrite(red_pin, LOW);
      digitalWrite(green_pin, HIGH);
      digitalWrite(blue_pin, LOW);
      
      motorLeftSpeed = maxSpeedLeft;
      motorRightSpeed = 0;

      // slow down servo speed
      del = 250;
    }
    if(IRValue < 299) {
      
      digitalWrite(red_pin, LOW);
      digitalWrite(green_pin, LOW);
      digitalWrite(blue_pin, HIGH);
      
      motorLeftSpeed = maxSpeedLeft;
      motorRightSpeed = maxSpeedRight;
      
      // speed up servo speed
      del = 50;
    }
  }
  
  // se 'i' for maior do que 90 quer dizer que estamos a olhar para a direita
  // logo querermos que o robot se afaste, sendo assim vamos parar o motor da esquerda
  // girando apenas o motor da direita 
  if (i > 90) {
    if (IRValue >= 300) {
      
      digitalWrite(red_pin, LOW);
      digitalWrite(green_pin, HIGH);
      digitalWrite(blue_pin, LOW);
      motorRightSpeed = maxSpeedRight;
      motorLeftSpeed = 0;

      // slow down servo speed
      del = 250;
    }
    if(IRValue < 299) {
      
      digitalWrite(red_pin, LOW);
      digitalWrite(green_pin, LOW);
      digitalWrite(blue_pin, HIGH);
      
      motorRightSpeed = maxSpeedRight;
      motorLeftSpeed = maxSpeedLeft;
      
      // speed up servo speed
      del = 50;
    }
  }
  
  // chamada da função 'DiffTurn' atribuindo sempre os valores de rotação dos motores
  DiffTurn(motorLeftSpeed,motorRightSpeed);
 
  }

}
