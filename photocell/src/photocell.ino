int LDR_Pin = A0; //analog pin 0

void setup(){
  Serial.begin(9600);
}

void loop(){
  int LDRReading = analogRead(LDR_Pin);

  Serial.print(map(analogRead(A0), 0, 1023, 0, 100));
  Serial.print(", ");
  Serial.print(map(analogRead(A1), 0, 1023, 0, 100));
  Serial.print(", ");
  Serial.print(map(analogRead(A2), 0, 1023, 0, 100));
  Serial.println(", ");
  delay(250); //just here to slow down the output for easier reading
}
