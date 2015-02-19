// more LEDS

// declare your variables
int ledRed = 7;
int ledGreen = 6;
int ledBlue = 5;

// SETUP - runs only once
void setup()
{
  // open serial port for communications
  Serial.begin(9600);
  // declare inputs
  pinMode(ledRed, OUTPUT);
  pinMode(ledGreen, OUTPUT);
  pinMode(ledBlue, OUTPUT);
}

// LOOP - runs forever
void loop()
{
  // turns one LED on and others OFF
  digitalWrite(ledRed, HIGH);
  digitalWrite(ledGreen, LOW);
  digitalWrite(ledBlue, LOW);
  
  // wait
  delay(1000);
  
  // turns one LED on and others OFF
  digitalWrite(ledRed, LOW);
  digitalWrite(ledGreen, HIGH);
  digitalWrite(ledBlue, LOW);
  
  // wait
  delay(1000);
  
  // turns one LED on and others OFF
  digitalWrite(ledRed, LOW);
  digitalWrite(ledGreen, LOW);
  digitalWrite(ledBlue, HIGH);
  
  // wait
  delay(1000);
}
