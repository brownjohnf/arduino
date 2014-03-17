// constants won't change. They're used here to 
// set pin numbers:
const int btnFan = 5;     // the number of the pushbutton pin
const int btnHeat = 4;
const int btnPulse = 6;
const int counter = 11;

long debounceDelay = 50;

int btnOff = HIGH;

const int fan =  2;      // the number of the LED pin
const int heat = 3;
const int pulse = 7;

// variables will change:
int btnFanState;         // variable for reading the pushbutton status
int btnHeatState;
int btnPulseState;

int lastBtnHeatState = btnOff;
int lastBtnFanState = btnOff;
int lastBtnPulseState = LOW;

long lastFanDebounceTime = 0;
long lastHeatDebounceTime = 0;
long lastPulseDebounceTime = 0;
long pulseDelay = 0;

int fanState = btnOff;
int heatState = btnOff;
int pulseState = LOW;

long lastPulsedAt = 0;

void setup() {
  // initialize the LED pin as an output:
  pinMode(fan, OUTPUT);
  pinMode(heat, OUTPUT);
  pinMode(pulse, OUTPUT);
  pinMode(counter, OUTPUT);
  
  // initialize the pushbutton pin as an input:
  pinMode(btnFan, INPUT);
  pinMode(btnHeat, INPUT);  
  pinMode(btnPulse, INPUT);
  
  digitalWrite(fan, fanState);
  digitalWrite(heat, heatState);
  digitalWrite(pulse, pulseState);
  
  digitalWrite(counter, LOW);
}

void resetTimer() {
  digitalWrite(counter, HIGH);
  delay(150);
  digitalWrite(counter, LOW);
}

void setOutputs() {
  // set all the pins
  digitalWrite(fan, fanState);
  digitalWrite(heat, heatState);
}

void runPulse() {
  if (pulseDelay > 0) {
    digitalWrite(pulse, HIGH);
    if (digitalRead(fan) != btnOff) {
      if ((millis() - lastPulsedAt) > pulseDelay) {
    
        digitalWrite(fan, btnOff);
        delay(50);
        digitalWrite(fan, !btnOff);
        
        lastPulsedAt = millis();
      }
    }
  } else {
    digitalWrite(pulse, LOW);
  }
}

void readFan() {
  // read the state of the fan pushbutton value:
  int fanReading = digitalRead(btnFan);
  
  // if there's a change in btn state, reset the debounce time
  if (fanReading != lastBtnFanState) {
    // reset the debouncing timer
    lastFanDebounceTime = millis();
  }
  
  // if the button has been held down long enough
  if ((millis() - lastFanDebounceTime) > debounceDelay) {
    // ... and if the current state doesn't equal the reading
    if (fanReading != btnFanState) {
      btnFanState = fanReading;
      
      // if the button is high, or depressed
      if (btnFanState == HIGH) {
        if (pulseDelay == 0) {
          // change the state
          fanState = !fanState;
        
          if (fanState != btnOff) {
            resetTimer();
          }
        } else {
          pulseDelay = 0;
        }
      }
    }
  }
  
  digitalWrite(fan, fanState);
  lastBtnFanState = fanReading;
}

void readHeat() {
  // read the state of the heat pushbutton value:
  int heatReading = digitalRead(btnHeat);
  
  if (heatReading != lastBtnHeatState) {
    // reset the debouncing timer
    lastHeatDebounceTime = millis();
  }
  
  if ((millis() - lastHeatDebounceTime) > debounceDelay) {
    if (heatReading != btnHeatState) {
      btnHeatState = heatReading;
      
      if (btnHeatState == HIGH) {
        heatState = !heatState;
      }
    }
  }
  
  if (fanState == btnOff) {
    heatState = btnOff;
  }
  lastBtnHeatState = heatReading;
}

void readPulse() {
  // read the state of the pulse pushbutton value:
  int pulseReading = digitalRead(btnPulse);
  
  if (pulseReading != lastBtnPulseState) {
    // reset the debouncing timer
    lastPulseDebounceTime = millis();
  }
  
  if ((millis() - lastPulseDebounceTime) > debounceDelay) {
    if (pulseReading != btnPulseState) {
      btnPulseState = pulseReading;
      
      if (btnPulseState == HIGH) {
        if (pulseDelay < 3000) {
          pulseDelay = pulseDelay + 300;
          digitalWrite(pulse, LOW);
          delay(50);
        } else {
          pulseDelay = 0;
        }
      }
    }
  }
  lastBtnPulseState = pulseReading;
}

void loop(){
  setOutputs();
  runPulse();
  readFan();
  
  if (fanState == btnOff) {
    heatState = btnOff;
    pulseDelay = 0;
  } else {
    readHeat();
    readPulse();
  }
}
