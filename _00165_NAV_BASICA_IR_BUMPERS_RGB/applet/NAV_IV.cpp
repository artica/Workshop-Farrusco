#include <MegaServo.h>

// --------------------------------------------------------------------------- MOTORES

// motor pins
#include "WProgram.h"
void setup();
void loop();
void DiffTurn(int speedLeft, int speedRight);
int motor1_Pin0 = 5;
int motor1_Pin1 = 6;

int motor2_Pin0 = 8;
int motor2_Pin1 = 3;

// --------------------------------------------------------------------------- SERVO

MegaServo servo;

#define INC_POS  0
#define DEC_POS  1

// variavel 'dir' (direc\u00e7\u00e3o) que diz ao programa para aumentar ou diminuir o valor
byte dir = INC_POS;

// o valor da vari\u00e1vel vai ser atribuido \u00e0 posi\u00e7\u00e3o do servo
int i = 90;

// tempo de espera da rota\u00e7\u00e3o do servo
int inc = 10;


// --------------------------------------------------------------------------- SHARP
// defini\u00e7\u00e3o do pin do sensor IV 
#define IR_SENSOR_PIN  0

// vari\u00e1vel que vai conter o valor de leitura do SHARP
int ir_value;

// variaveis que v\u00e3o conter a velocidade dos motores
int motorRightSpeed, motorLeftSpeed;


// --------------------------------------------------------------------------- SETUP

void setup() {
  Serial.begin(9600);
  
  //the motor control wires are outputs
  pinMode(motor1_Pin0, OUTPUT);
  pinMode(motor1_Pin1, OUTPUT);
  
  pinMode(motor2_Pin0, OUTPUT);
  pinMode(motor2_Pin1, OUTPUT);
  
  servo.attach(9);
  servo.write(90);
  
  delay(1000);
}

void loop() {
  
  servo.write(i);
  delay(inc);
  
  if(i >= 160) dir = DEC_POS;
  if(i <= 45) dir = INC_POS;

  if(dir == INC_POS)
    i += 5;
  else
    i -= 5;
    
    
    
  int dist = 3 + analogRead(IR_SENSOR_PIN);  
  //Serial.println(dist);
  
  
  // se 'i' for menor do que 90 quer dizer que estamos a olhar para a esquerda
  // logo querermos que o robot se afaste, sendo assim vamos parar o motor da direita
  // girando apenas o motor da esquerda 
  if (i > 90) {
    if (dist >= 300)   {
      motorRightSpeed = 0;
      motorLeftSpeed = 255;
      inc = 250;
    }
    if(dist < 299) {
      motorRightSpeed = 255;
      motorLeftSpeed = 255;
      inc = 50;
    }
  }
  
  // se 'i' for maior do que 90 quer dizer que estamos a olhar para a direita
  // logo querermos que o robot se afaste, sendo assim vamos parar o motor da esquerda
  // girando apenas o motor da direita 
  if (i < 90) {
    if (dist >= 300) {
      motorRightSpeed = 255;
      motorLeftSpeed = 0;
      inc = 250;
    }
    if(dist < 299) {
      motorRightSpeed = 255;
      motorLeftSpeed = 255;
      inc = 50;
    }
  }
  
  // chamada da fun\u00e7\u00e3o 'DiffTurn' atribuindo sempre os valores de rota\u00e7\u00e3o dos motores
  DiffTurn(motorRightSpeed, motorLeftSpeed);

  
}




void DiffTurn(int speedLeft, int speedRight) {
 
 if (speedLeft > 0) 
 {  
  analogWrite(motor1_Pin0, speedLeft);
  digitalWrite(motor1_Pin1, LOW);
 }
 
 if (speedLeft < 0) 
 {  
  digitalWrite(motor1_Pin0, LOW);
  analogWrite(motor1_Pin1, map(speedLeft, 0, -255, 0, 255));
 }
 
 if (speedLeft == 0) 
 {  
  digitalWrite(motor1_Pin0, LOW);
  digitalWrite(motor1_Pin1, LOW); 
 }
  
 if (speedRight > 0 ) 
 {
  analogWrite(motor2_Pin0, speedRight);
  digitalWrite(motor2_Pin1, LOW);
 }
 
 if (speedRight < 0 ) 
 {
  digitalWrite(motor2_Pin0, LOW);
  analogWrite(motor2_Pin1, map(speedRight, 0, -255, 0, 255));
 }
 
 if (speedRight == 0)
 {
  digitalWrite(motor2_Pin0, LOW);
  digitalWrite(motor2_Pin1, LOW);
 }
  
}


int main(void)
{
	init();

	setup();
    
	for (;;)
		loop();
        
	return 0;
}

