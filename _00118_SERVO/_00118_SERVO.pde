// --------------------------------------------------------------------------- SERVO
#include <Servo.h>
Servo servo;
int servoPin = 9;

// --------------------------------------------------------------------------- SETUP

void setup() 
{
  Serial.begin(9600);

  servo.attach(servoPin); // servo attach pin
  servo.write(90); // center servo
  
  delay(1000);
}

// --------------------------------------------------------------------------- LOOP

void loop() 
{
  
  servo.write(90);
  delay(1000);
  
  servo.write(160);
  delay(1000);
  
  servo.write(95);
  delay(1000);
  
  servo.write(20);
  delay(1000);
  
}

