/*
** Example Arduino sketch for SainSmart I2C LCD Screen 16x2
** based on https://bitbucket.org/celem/sainsmart-i2c-lcd/src/3adf8e0d2443/sainlcdtest.ino
** by
** Edward Comer
** LICENSE: GNU General Public License, version 3 (GPL-3.0)

** This example uses F Malpartida's NewLiquidCrystal library. Obtain from:
** https://bitbucket.org/fmalpartida/new-liquidcrystal 

** Modified – Ian Brennan ianbren at hotmail.com 23-10-2012 to support Tutorial posted to Arduino.cc

** Written for and tested with Arduino 1.0
**
** NOTE: Tested on Arduino Uno whose I2C pins are A4==SDA, A5==SCL

*/

// libs for lcd
#include <Wire.h>
#include <LCD.h>
#include <LiquidCrystal_I2C.h>

// libs for dht sensor
#include "DHT.h"

// initialize lcd
#define I2C_ADDR 0x3F // <<----- Add your address here.  Find it from I2C Scanner
#define BACKLIGHT_PIN 3
#define En_pin  2
#define Rw_pin  1
#define Rs_pin  0
#define D4_pin  4
#define D5_pin  5
#define D6_pin  6
#define D7_pin  7

int n = 1;

LiquidCrystal_I2C lcd(I2C_ADDR,En_pin,Rw_pin,Rs_pin,D4_pin,D5_pin,D6_pin,D7_pin);

// initialize dht sensor
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

// set everything up
void setup()
{
  // set up cols,rows
  lcd.begin(20,4);
  
  // start up the sensor
  dht.begin();

  
  // Switch on the backlight
  lcd.setBacklightPin(BACKLIGHT_PIN,POSITIVE);
  lcd.setBacklight(HIGH);
  

  // set basics
  lcd.home();
  lcd.print("Temperature (C/F):");
  
  lcd.setCursor(0,2);
  lcd.print("Humidity (%):");
  
  delay(2000);
}

void loop()
{
  
  // Reading temperature or humidity takes about 250 milliseconds!
  // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
  float h = dht.readHumidity();
  float t = dht.readTemperature();

  // check if returns are valid, if they are NaN (not a number) then something went wrong!
  if (isnan(t) || isnan(h)) {
    // print temp
    lcd.setCursor(0,1);
    lcd.print("error");
    
    // print humidity
    lcd.setCursor(0,3);
    lcd.print("error");
  } else {
    
    // print temp
    lcd.setCursor(0,1);
    lcd.print(t);
    lcd.print(" / ");
    lcd.print(t*1.8+32);
    
    // print humidity
    lcd.setCursor(0,3);
    lcd.print(h);
  }
  
  
  delay(2000);
}