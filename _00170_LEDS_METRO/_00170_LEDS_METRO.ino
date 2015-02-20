#include <Metro.h>
Metro ledRED_metro = Metro(200);

// declare your variables
int ledRED = 19;
int ledRED_State = HIGH;

// SETUP - runs only once
void setup()
{
  // open serial port for communications
  Serial.begin(9600);
  // declare inputs
  pinMode(ledRED, OUTPUT);

}

// LOOP - runs forever
void loop()
{
  HeartRate();
}

void HeartRate () 
{
  if (ledRED_metro.check() == 1) { // check if the metro has passed it's interval .
    if (ledRED_State==HIGH) {
      ledRED_State=LOW;
      ledRED_metro.reset(); // if the pin is HIGH, set the interval to 0.25 seconds.
    }
    else {
      ledRED_metro.reset(); // if the pin is LOW, set the interval to 1 second.
      ledRED_State=HIGH;
    }
    digitalWrite(ledRED,ledRED_State);
  }
}


