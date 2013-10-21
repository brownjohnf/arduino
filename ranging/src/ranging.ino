#include "../lib/Ultrasonic.h"

Ultrasonic ultrasonic(3,4);

void setup() {
  Serial.begin(9600);
}

void loop() {
  Serial.println(ultrasonic.Ranging(CM));
  delay(1000);
}
