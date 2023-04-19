#include <SP0256A.h>

// Pin assignments for the SP0256A chip
const int aldPin = 5;   // ALD pin connected to ESP32 GPIO 5
const int lrqPin = 4;   // LRQ pin connected to ESP32 GPIO 4
const int resetPin = 2; // RESET pin connected to ESP32 GPIO 2

// Create an instance of the SP0256A class
SP0256A sp0256a(aldPin, lrqPin, resetPin);

void setup() {
  // Initialize serial communication at 9600 baud rate
  Serial.begin(9600);

  // Initialize the SP0256A chip
  sp0256a.begin();

  // Print a message on the serial monitor
  Serial.println("SP0256A speech synthesis example");
}

void loop() {
  // Count from 0 to 9 and speak each number
  for (int i = 0; i <= 9; i++) {
    // Print the current number on the serial monitor
    Serial.print("Speaking number: ");
    Serial.println(i);

    // Speak the current number using the SP0256A chip
    sp0256a.speakNumber(i);

    // Wait for 2 seconds before speaking the next number
    delay(2000);
  }

  // Wait for 5 seconds before repeating the count
  delay(5000);
}
