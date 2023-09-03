#include <Keyboard.h>

/*
 * Mushroom Button Return Key
 * 2023-09-03
 * 
 * Monitors pin 2. Sends a return key through usb hid if it goes low.
 * 
 * Requirements: Arduino Leonardo
 * 
 */

#define RETURN_PIN 2
 
void setup() {
  // make pin 2 an input and turn on the
  // pullup resistor so it goes high unless
  // connected to ground:
  pinMode(RETURN_PIN, INPUT_PULLUP);
  // initialize control over the keyboard:
  Keyboard.begin();
}

void loop() {
  while (digitalRead(RETURN_PIN) == HIGH) {
    // do nothing until pin 2 goes low
    delay(200);
  }

  Keyboard.press(KEY_RETURN);
  delay(100);
  Keyboard.release(KEY_RETURN);
  
  delay(200);
}
