int relayPin1 = 7;                 // IN1 connected to digital pin 7
int relayPin2 = 8;                 // IN2 connected to digital pin 8
int onBtn = 2;
int offBtn = 3;

int btnOn = 0;
int btnOff = 0;

void setup()
{
  pinMode(relayPin1, OUTPUT);      // sets the digital pin as output
  pinMode(relayPin2, OUTPUT);      // sets the digital pin as output
  
  digitalWrite(relayPin1, LOW);
  digitalWrite(relayPin2, HIGH);

  pinMode(onBtn, INPUT);
  pinMode(offBtn, INPUT);
}

void loop()
{
  btnOn = digitalRead(onBtn);
  btnOff = digitalRead(offBtn);

  if (btnOn == HIGH) {
    if (relayPin2 == HIGH) {
      //digitalWrite(relayPin1, LOW);   // energizes the relay and lights the LED
      digitalWrite(relayPin2, LOW);   // energizes the relay and lights the LED
    } else {
      digitalWrite(relayPin2, HIGH);
    }
    
  }

  //if (btnOff == LOW) {
    //digitalWrite(relayPin1, HIGH);    // de-energizes the relay and LED is off
  //  digitalWrite(relayPin2, HIGH);    // de-energizes the relay and LED is off
  //  delay(1000);
  //}
}
