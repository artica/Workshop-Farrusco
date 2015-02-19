// LEDS

// declare your variables
int ledRed = 7;

// SETUP - runs only once
void setup()
{
  // open serial port for communications
  Serial.begin(9600);
  
  // declare inputs
  pinMode(ledRed, OUTPUT);
  
}

// LOOP - runs forever
void loop()
{
  // turns LED on
  digitalWrite(ledRed, HIGH);
  
  // wait
  delay(1000);
  
  // turns LED off
  digitalWrite(ledRed, LOW);
  
  // wait
  delay(1000);
}
