// BUTTON PRESS

// check debounce example
// http://arduino.cc/en/Tutorial/Debounce

// declare your variables
int bt1 = 4;
int bt2 = 3;
int bt3 = 2;

int bt1_state;
int bt2_state;
int bt3_state;

int ledRed = 7;
int ledGreen = 6;
int ledBlue = 5;


// SETUP - runs only once
void setup()
{
  // open serial port for communications
  Serial.begin(9600);
  
  // declare inputs
  pinMode(bt1, INPUT_PULLUP);
  pinMode(bt2, INPUT_PULLUP);
  pinMode(bt3, INPUT_PULLUP);
  
  pinMode(ledRed, OUTPUT);
  pinMode(ledGreen, OUTPUT);
  pinMode(ledBlue, OUTPUT);
}

// LOOP - runs forever
void loop()
{
  bt1_state = digitalRead(bt1);
  
  if (!bt1_state) {
    Serial.println("bt1 pressed");
    digitalWrite(ledRed, HIGH);
  }
  else
  {
    digitalWrite(ledRed, LOW);
  }
  
  bt2_state = digitalRead(bt2);
  
  if (!bt2_state) {
    Serial.println("bt2 pressed");
    digitalWrite(ledGreen, HIGH);
  }
  else
  {
    digitalWrite(ledGreen, LOW);
  }
  
  bt3_state = digitalRead(bt3);
  
  if (!bt3_state) {
    Serial.println("bt3 pressed");
    digitalWrite(ledBlue, HIGH);
  }
  else
  {
    digitalWrite(ledBlue, LOW);
  }

}
