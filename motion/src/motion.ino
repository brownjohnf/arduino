const int pirPin = 2; //digital 2
const int relay = 8;

void setup(){
 Serial.begin(9600); 
 pinMode(pirPin, INPUT);
 pinMode(relay, OUTPUT);
}


void loop(){
  int pirVal = digitalRead(pirPin);

  if(pirVal == HIGH){ //was motion detected
    Serial.println("motion");
    digitalWrite(relay, LOW);
    delay(5000); 
  } else {
    Serial.println("no motion.");
    digitalWrite(relay, HIGH);
    delay(10);
  }

}
