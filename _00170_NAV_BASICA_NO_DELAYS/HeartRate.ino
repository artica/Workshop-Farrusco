void HeartRate () 
{
  if (ledMetro.check() == 1) { // check if the metro has passed it's interval .
    if (state==HIGH) {
      state=LOW;
      ledMetro.reset(); // if the pin is HIGH, set the interval to 0.25 seconds.
    }
    else {
      ledMetro.reset(); // if the pin is LOW, set the interval to 1 second.
      state=HIGH;
    }
    digitalWrite(LED,state);
  }
}



