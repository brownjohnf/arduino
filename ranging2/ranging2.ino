/*
 * Define the pins you want to use as trigger and echo.
 */

const int ECHOPIN = 2;        // Pin to receive echo pulse
const int TRIGPIN  =3;        // Pin to send trigger pulse
const int LED = 13;
  
int ledState = LOW;

/*
 * setup function
 * Initialize the serial line (D0 & D1) at 115200.
 * Then set the pin defined to receive echo in INPUT 
 * and the pin to trigger to OUTPUT.
 */
 
void setup()
{
  Serial.begin(115200);
  pinMode(ECHOPIN, INPUT);
  pinMode(TRIGPIN, OUTPUT);
  pinMode(LED, OUTPUT);
  
  digitalWrite(LED, ledState);
}

/*
 * loop function.
 * 
 */
void loop()
{
  // Start Ranging
  digitalWrite(TRIGPIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIGPIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGPIN, LOW);
  // Compute distance
  float distance = pulseIn(ECHOPIN, HIGH);
  distance= distance/58;
  Serial.println(distance);
  if (distance < 20) {
    ledState = !ledState;
    digitalWrite(LED, ledState);
    delay(1000);
  }
  delay(200);
}
