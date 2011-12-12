// Define the Heart bitled's pin
const int heartBitLedPin = 13; 
int heartBitLedState = HIGH;

Metro heartBitLedMetro = Metro (250);

void HeartBitSetup() 
{
  pinMode(heartBitLedPin, OUTPUT);
}

void HeartBit () 
{
  
  if (heartBitLedMetro.check() == 1) { // check if the metro has passed it's interval .
    if (heartBitLedState == HIGH) {
      heartBitLedState = LOW;
      heartBitLedMetro.interval(250); // if the pin is HIGH, set the interval to 0.25 seconds.
    }
    else {
      heartBitLedMetro.interval(250); // if the pin is LOW, set the interval to 1 second.
      heartBitLedState = HIGH;
    }
    digitalWrite(heartBitLedPin, heartBitLedState);
  }
}



