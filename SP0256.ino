#include "SP0256A.h"

// Define the pin connections for the SP0256A module
#define ALD_PIN 5
#define LRQ_PIN 4
#define RESET_PIN 2

SP0256A sp0256a(ALD_PIN, LRQ_PIN, RESET_PIN);

void setup() {
  sp0256a.begin();
}

void loop() {
  int numberToSpeak = 5; // Change this to the number you want to speak
  sp0256a.speakNumber(numberToSpeak);
  delay(3000); // Wait for 3 seconds before speaking the number again
}
