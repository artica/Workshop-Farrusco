/*

DiffTurn (PWM p/ motor da Esquerda, PWM p/ motor da Direita)

o valor PWM pode ir de -255 a 0 para o motor andar para tras
e de 0 a 255 para o motor andar para frente

*/


// --------------------------------------------------------------------------- MOTORES DC

// motor pins
int motorA0 = 6;
int motorA1 = 11;

int motorB0 = 3;
int motorB1 = 5;
 
// --------------------------------------------------------------------------- SETUP

void setup() 
{
  Serial.begin(9600);
  
  //the motor control wires are outputs
  pinMode(motorA0, OUTPUT);
  pinMode(motorA1, OUTPUT);
  pinMode(motorB0, OUTPUT);
  pinMode(motorB1, OUTPUT);
  
  delay(1000);
}

void loop() 
{
  motorTeste();
  delay(1000);
  //aceleraDesacelera();
  delay(1000);
}

void motorTeste()
{
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
}
  
  
void aceleraDesacelera()
{
  // ANDA PARA FRENTE
  // acelera
   for (int fadeValue=0; fadeValue<=255; fadeValue+=5)
  {
    DiffTurn(fadeValue, fadeValue);
    Serial.println(fadeValue);
    delay(50);
  }
  
  // desacelera
  for(int fadeValue = 255 ; fadeValue >= 0; fadeValue -=5) { 
    DiffTurn(fadeValue, fadeValue);
    Serial.println(fadeValue);
    delay(50);
  }
  
  
  // ANDA PARA TRAS
  // acelera
   for (int fadeValue=0; fadeValue<=255; fadeValue+=5)
  {
    DiffTurn(-fadeValue, -fadeValue);
    Serial.println(fadeValue);
    delay(50);
  }
  
  // desacelera
  for(int fadeValue = 255 ; fadeValue >= 0; fadeValue -=5) { 
    DiffTurn(-fadeValue, -fadeValue);
    Serial.println(fadeValue);
    delay(50);
  }
 
  
} 
 
