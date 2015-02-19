// BUTTON PRESS

// check debounce example
// http://arduino.cc/en/Tutorial/Debounce

// declare your variables
int bt1 = 4;
int bt1_state;

int ledRed = 7;

// SETUP - runs only once
void setup()
{
  // open serial port for communications
  Serial.begin(9600);
  
  // declare inputs
  pinMode(bt1, INPUT_PULLUP);
  pinMode(ledRed, OUTPUT);
  
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

}
