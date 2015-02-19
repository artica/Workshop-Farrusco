// more LEDS

// abstractions
// use abstractions to simplify and reuse code

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
  // 
  ledManager(true, false, false);  
  delay(1000);
  
  ledManager(false, true, false);
  delay(1000);
  
  ledManager(false, false, true);
  delay(1000);
}

// ledManager function as an abstration
void ledManager(boolean r, boolean g, boolean b)
{
  if (r)
     digitalWrite(ledRed, HIGH);
  else
     digitalWrite(ledRed, LOW);
     
  if (g)
     digitalWrite(ledGreen, HIGH);
  else
     digitalWrite(ledGreen, LOW);
     
  if (b)
     digitalWrite(ledBlue, HIGH);
  else
     digitalWrite(ledBlue, LOW);
}

