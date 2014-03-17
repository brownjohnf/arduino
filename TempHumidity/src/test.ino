// Example testing sketch for various DHT humidity/temperature sensors
// Written by ladyada, public domain

#include "DHT.h"

#define DHTPIN 2     // what pin we're connected to

// Uncomment whatever type you're using!
//#define DHTTYPE DHT11   // DHT 11 
#define DHTTYPE DHT22   // DHT 22  (AM2302)
//#define DHTTYPE DHT21   // DHT 21 (AM2301)

// Connect pin 1 (on the left) of the sensor to +5V
// Connect pin 2 of the sensor to whatever your DHTPIN is
// Connect pin 4 (on the right) of the sensor to GROUND
// Connect a 10K resistor from pin 2 (data) to pin 1 (power) of the sensor

DHT dht(DHTPIN, DHTTYPE);

const int a0 = A0;
const int a1 = A1;
const int a4 = A4;
const int a5 = A5;

void setup() {
  Serial.begin(9600); 
  Serial.println("DHTxx test!");
 
  dht.begin();
}

void loop() {
  // Reading temperature or humidity takes about 250 milliseconds!
  // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
  float h = dht.readHumidity();
  float t = dht.readTemperature() * 1.8 + 32;

  int hum = map(h, 0, 100, 0, 1023);
  int temp = map(t, 0, 100, 0, 1023);

  // check if returns are valid, if they are NaN (not a number) then something went wrong!
  if (isnan(t) || isnan(h)) {
    Serial.println("Failed to read from DHT");
  } else {
    analogWrite(a0, hum);
    analogWrite(a1, temp);

    Serial.print("Humidity: "); 
    Serial.print(h);
    Serial.print("%, ");
    Serial.print(hum);
    Serial.print("/1023; ");
    Serial.print("Temperature: "); 
    Serial.print(t);
    Serial.print(" degC, ");
    Serial.print(temp);
    Serial.println("/1023");

    int hum_read = analogRead(a4);
    int temp_read = analogRead(a5);
    Serial.print("Analog readings: humidity: ");
    Serial.print(hum_read);
    Serial.print(", temperature: ");
    Serial.println(temp_read);
  }
}
