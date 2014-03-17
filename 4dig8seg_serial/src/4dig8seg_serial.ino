// 2-dimensional array of row pin numbers:
const int row[8] = {
  2,3,4,5,6,7,8,9
};

// 2-dimensional array of column pin numbers:
const int col[4] = {
  10,11,12,13
};
  
int num[10][8];

int reset = A0;
int startTime = 0;
  
// 2-dimensional array of pixels:
int pixels[8][8];

void setup() {
  pinMode(reset, INPUT);
  
  // initialize the I/O pins as outputs
  // iterate over the pins:
  for (int thisPin = 0; thisPin < 8; thisPin++) {
    // initialize the output pins:
    pinMode(row[thisPin], OUTPUT);
  }

  for (int thisPin = 0; thisPin < 4; thisPin++) {  
    pinMode(col[thisPin], OUTPUT); 
    // take the col pins (i.e. the cathodes) high to ensure that
    // the LEDS are off: 
    digitalWrite(col[thisPin], HIGH);    
  }

  // initialize the pixel matrix:
  for (int x = 0; x < 4; x++) {
    for (int y = 0; y < 8; y++) {
      pixels[x][y] = LOW;
    }
  }
  
  num[0][0] = LOW;
  num[0][1] = HIGH;
  num[0][2] = HIGH;
  num[0][3] = HIGH;
  num[0][4] = HIGH;
  num[0][5] = HIGH;
  num[0][6] = HIGH;
  num[0][7] = LOW;
  
  num[1][0] = LOW;
  num[1][1] = LOW;
  num[1][2] = LOW;
  num[1][3] = LOW;
  num[1][4] = HIGH;
  num[1][5] = HIGH;
  num[1][6] = LOW;
  num[1][7] = LOW;
  
  num[2][0] = HIGH;
  num[2][1] = LOW;
  num[2][2] = HIGH;
  num[2][3] = HIGH;
  num[2][4] = LOW;
  num[2][5] = HIGH;
  num[2][6] = HIGH;
  num[2][7] = LOW;
  
  num[3][0] = HIGH;
  num[3][1] = LOW;
  num[3][2] = LOW;
  num[3][3] = HIGH;
  num[3][4] = HIGH;
  num[3][5] = HIGH;
  num[3][6] = HIGH;
  num[3][7] = LOW;
  
  num[4][0] = HIGH;
  num[4][1] = HIGH;
  num[4][2] = LOW;
  num[4][3] = LOW;
  num[4][4] = HIGH;
  num[4][5] = HIGH;
  num[4][6] = LOW;
  num[4][7] = LOW;
  
  num[5][0] = HIGH;
  num[5][1] = HIGH;
  num[5][2] = LOW;
  num[5][3] = HIGH;
  num[5][4] = HIGH;
  num[5][5] = LOW;
  num[5][6] = HIGH;
  num[5][7] = LOW;
  
  num[6][0] = HIGH;
  num[6][1] = HIGH;
  num[6][2] = HIGH;
  num[6][3] = HIGH;
  num[6][4] = HIGH;
  num[6][5] = LOW;
  num[6][6] = HIGH;
  num[6][7] = LOW;
  
  num[7][0] = LOW;
  num[7][1] = LOW;
  num[7][2] = LOW;
  num[7][3] = LOW;
  num[7][4] = HIGH;
  num[7][5] = HIGH;
  num[7][6] = HIGH;
  num[7][7] = LOW;
  
  num[8][0] = HIGH;
  num[8][1] = HIGH;
  num[8][2] = HIGH;
  num[8][3] = HIGH;
  num[8][4] = HIGH;
  num[8][5] = HIGH;
  num[8][6] = HIGH;
  num[8][7] = LOW;
  
  num[9][0] = HIGH;
  num[9][1] = HIGH;
  num[9][2] = LOW;
  num[9][3] = LOW;
  num[9][4] = HIGH;
  num[9][5] = HIGH;
  num[9][6] = HIGH;
  num[9][7] = LOW;
  
  Serial.begin(9600);
}

void loop() {
  if (analogRead(reset) > 512) {
    startTime = millis();
  }
  
  int sec = ((millis() - startTime) / 1000);
  
  Serial.println(sec);
  
  setDigit(0, ((sec) % 60 % 10));
  setDigit(1, ((sec) % 60 / 10));
  setDigit(2, ((sec) / 60 % 10));
  setDigit(3, ((sec) / 600 % 10));
  
  pixels[2][7] = HIGH;
  
  // draw the screen:
  refreshScreen();
}

void refreshScreen() {
  // iterate over the digits (anodes):
  for (int thisCol = 0; thisCol < 4; thisCol++) {
    // take the row pin (anode) high:
    digitalWrite(col[thisCol], LOW);
    // iterate over the cols (cathodes):
    for (int thisRow = 0; thisRow < 8; thisRow++) {
      // get the state of the current pixel;
      int thisPixel = pixels[thisCol][thisRow];
      // when the segment is HIGH and the digit is LOW,
      // the LED where they meet turns on:
      digitalWrite(row[thisRow], thisPixel);
      // turn the pixel off:
      if (thisPixel == HIGH) {
        digitalWrite(row[thisRow], LOW);
      }
    }
    // take the digit pin HIGH to turn off the whole col:
    digitalWrite(col[thisCol], HIGH);
  }
}

void setDigit(int digit, int value) {
  setPixels(digit, value);
}

void setPixels(int digit, int value) {
  for (int thisPixel = 0; thisPixel < 8; thisPixel++) {
    pixels[digit][thisPixel] = num[value][thisPixel];
  }
}
