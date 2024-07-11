#include <BleKeyboard.h>
#include <Arduino.h>

int redButton = 36;
int yellowButton = 39;
int blueButton = 34;
int greenButton = 35;
int orangeButton = 15;

int yOnePin = 32;
int yTwoPin = 33;
int xOnePin = 25;
int xTwoPin = 26;

/*
yOne = w
yTwo = s
xOne = d
xTwo = a
*/
int yOne;
int yTwo;
int xOne;
int xTwo;

bool wPress = false; 
bool sPress = false;
bool dPress = false;
bool aPress = false;

BleKeyboard bleKeyboard("V.Smile Controller", "Zapien Industries");

void setup() {
  Serial.begin(115200);
  pinMode(redButton, INPUT);
  pinMode(yellowButton, INPUT);
  pinMode(blueButton, INPUT);
  pinMode(greenButton, INPUT);
  pinMode(orangeButton, INPUT);
  pinMode(yOnePin, INPUT);
  pinMode(yTwoPin, INPUT);
  pinMode(xOnePin, INPUT);
  pinMode(xTwoPin, INPUT);

  yOne = analogRead(yOnePin);
  yTwo = analogRead(yTwoPin);
  xOne = analogRead(xOnePin);
  xTwo = analogRead(xTwoPin);

  Serial.println("Starting BLE work!");
  bleKeyboard.begin();
}

void loop() {
  int redVal = analogRead(redButton);
  int yellowVal = analogRead(yellowButton);
  int blueVal = analogRead(blueButton);
  int greenVal = analogRead(greenButton);
  int orangeVal = analogRead(orangeButton);

  int curr_yOne = analogRead(yOnePin);
  int curr_yTwo = analogRead(yTwoPin);
  int curr_xOne = analogRead(xOnePin);
  int curr_xTwo = analogRead(xTwoPin);

  if(bleKeyboard.isConnected()) {
    // Buttons
    if (redVal > 4000) {
      bleKeyboard.write('u');
    } 
    if (yellowVal > 4000) {
      bleKeyboard.write('j');
    } 
    if (blueVal > 4000) {
      bleKeyboard.write('i');
    } 
    if (greenVal > 4000) {
      bleKeyboard.write('k');
    } 
    if (orangeVal > 4000) {
      bleKeyboard.write('o');
    }

    // JoyStick
    if (yOne && curr_yOne > 4000) {
        bleKeyboard.press('w');
        wPress = true;
    } else {
      if (wPress) {
        bleKeyboard.release('w');
      }
    }
    if (yTwo && curr_yTwo > 4000) {
        bleKeyboard.press('s');
        sPress = true;
    } else {
      if (sPress) {
        bleKeyboard.release('s');
      }
    }
    if (xOne && curr_xOne > 4000) {
      if (!dPress) {
        bleKeyboard.press('d');        
      }
      dPress = true;
    } else {
      if (dPress) {
        bleKeyboard.release('d');
        dPress = false;
      }
    }
    if (xTwo && curr_xTwo > 4000) {
        bleKeyboard.press('a');
        aPress = true;
    } else {
      if (aPress) {
        bleKeyboard.release('a');
      }
    }

   yOne = curr_yOne;
   yTwo = curr_yTwo;
   xOne = curr_xOne;
   xTwo = curr_xTwo;
  }
// This is just serial monitor code to verify that the microcontroller is properly reading and certain values are being met.
    if (redVal > 4000) {
      Serial.println("Punch");
    } 
    if (yellowVal > 4000) {
      Serial.println("Kick");
    } 
    if (blueVal > 4000) {
      Serial.println("Slash");
    } 
    if (greenVal > 4000) {
      Serial.println("Heavy Slash");
    } 
    if (orangeVal > 4000) {
      Serial.println("Dust");
    }

    if (yOne > 4000) {
      Serial.println("y One");
    }
    if (yTwo > 4000) {
      Serial.println("y Two");
    }
    if (xOne > 4000) {
      Serial.println("x One");
    }
    if (xTwo > 4000) {
      Serial.println("x Two");
    }
  delay(50);
}