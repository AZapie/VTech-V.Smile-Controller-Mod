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

BleKeyboard bleKeyboard("VSmile Modded Controller", "Zapien Industries");

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

  Serial.println("Starting BLE work!");
  bleKeyboard.begin();
}

void loop() {
  int redVal = analogRead(redButton);
  int yellowVal = analogRead(yellowButton);
  int blueVal = analogRead(blueButton);
  int greenVal = analogRead(greenButton);
  int orangeVal = analogRead(orangeButton);

  int yOne = analogRead(yOnePin);
  int yTwo = analogRead(yTwoPin);
  int xOne = analogRead(xOnePin);
  int xTwo = analogRead(xTwoPin);

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

    // JoyStick Stuff
    if (yOne > 4000) {
      bleKeyboard.write('w');
    }
    if (yTwo > 4000) {
      bleKeyboard.write('s');
    }
    if (xOne > 4000) {
      bleKeyboard.write('d');
    }
    if (xTwo > 4000) {
      bleKeyboard.write('a');
    }
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