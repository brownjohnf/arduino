
// CONSTANTS
// IN1 connected to digital pin 7
const int k1 = 7;
// IN2 connected to digital pin 8
const int k2 = 8;

// button
int btn1 = 2;

// VARS
int k1State = HIGH;
int k2State = HIGH;

// current reading from input
int btn1State;

// previous reading from input pin
int lastBtn1State = LOW;

// the following variables are long's because the time, measured in miliseconds,
// will quickly become a bigger number than can be stored in an int.
// the last time the outpin pin was toggled
long lastBtn1DebounceTime = 0;
long debounceDelay = 50;

void setup() {
  // sets the digital pin as output
  pinMode(k1, OUTPUT);
  pinMode(k2, OUTPUT);

  // we'll read data from the button
  pinMode(btn1, INPUT);
  
  // write highs to the relays so they're off by default
  digitalWrite(k1, k1State);
  digitalWrite(k2, k2State);
}

void loop() {
  // read the state of the switch into a local variable
  int reading = digitalRead(btn1);
  
  // if the switch changed, due to noise or pressing
  if (reading != lastBtn1State) {
    // store the press time
    lastBtn1DebounceTime = millis();
  }
  
  // if there's been enough delay to be a real press
  if ((millis() - lastBtn1DebounceTime) > debounceDelay) {
    // if state has changed
    if (reading != btn1State) {
      btn1State = reading;
      
      // only toggle if the new btn state is high
      if (btn1State == HIGH) {
        k2State = !k2State;
      }
    }
  }
  
  digitalWrite(k2, k2State);
  
  // save the reading
  lastBtn1State = reading;
}

