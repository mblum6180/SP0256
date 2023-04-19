#include <SP0256A.h>

// Pin assignments for the ESP32
const int aldPin = 5;       // ALD pin connected to ESP32 GPIO5
const int lrqPin = 4;       // LRQ pin connected to ESP32 GPIO4
const int resetPin = 2;     // RESET pin connected to ESP32 GPIO2
const int addressPins[] = {13, 14, 15, 16, 17, 18, 19, 20}; // Address pins connected to ESP32 GPIO13-GPIO20

// Create an SP0256A object with the specified pin assignments
SP0256A sp0256a(aldPin, lrqPin, resetPin);

void setup() {
  Serial.begin(115200);
  sp0256a.begin();
}

void loop() {
  for (int i = 0; i <= 9; i++) {
    Serial.println("Speaking number: " + String(i));
    sp0256a.speakNumber(i);
    delay(1000);
  }
  delay(5000);
}
