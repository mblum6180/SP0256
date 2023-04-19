#include "SP0256A.h"

SP0256A::SP0256A(int aldPin, int lrqPin, int resetPin)
    : _aldPin(aldPin), _lrqPin(lrqPin), _resetPin(resetPin) {
  pinMode(_aldPin, OUTPUT);
  pinMode(_lrqPin, INPUT);
  pinMode(_resetPin, OUTPUT);
}

void SP0256A::begin() {
  // Reset the SP0256A
  digitalWrite(_resetPin, LOW);
  delay(10);
  digitalWrite(_resetPin, HIGH);
}

void SP0256A::speakNumber(int number) {
  // Define a list of allophone codes for numbers from 0 to 9
  byte allophoneCodes[] = {0x35, 0x30, 0x31, 0x37, 0x34, 0x3C, 0x3B, 0x3E, 0x3A, 0x3D};

  // Check if the number is within the range 0-9
  if (number < 0 || number > 9) {
    return;
  }

  // Get the allophone code for the given number
  byte allophoneCode = allophoneCodes[number];

  // Wait for the LRQ pin to go LOW
  while (digitalRead(_lrqPin) == HIGH) {
    delay(1);
  }

  // Send the allophone code to the SP0256A
  digitalWrite(_aldPin, LOW);
  shiftOut(_resetPin, _lrqPin, LSBFIRST, allophoneCode);
  digitalWrite(_aldPin, HIGH);
}
