#include "SP0256A.h"

SP0256A::SP0256A(int aldPin, int lrqPin, int resetPin)
    : _aldPin(aldPin), _lrqPin(lrqPin), _resetPin(resetPin) {
  pinMode(_aldPin, OUTPUT);
  pinMode(_lrqPin, INPUT);
  pinMode(_resetPin, OUTPUT);
}

void SP0256A::begin() {
  digitalWrite(_resetPin, LOW);
  delay(10);
  digitalWrite(_resetPin, HIGH);
}

void SP0256A::speakNumber(int number) {
  byte allophoneCodes[] = {0x35, 0x30, 0x31, 0x37, 0x34, 0x3C, 0x3B, 0x3E, 0x3A, 0x3D};
  
  if (number < 0 || number > 9) {
    return;
  }

  byte allophoneCode = allophoneCodes[number];
  
  while (digitalRead(_lrqPin) == HIGH) {
    delay(1);
  }

  // Set the address lines to the corresponding allophone code
  for (int i = 0; i < 8; i++) {
    pinMode(13 + i, OUTPUT);
    digitalWrite(13 + i, (allophoneCode & (1 << i)) ? HIGH : LOW);
  }

  // Load the allophone code into the SP0256A
  digitalWrite(_aldPin, LOW);
  delay(1);
  digitalWrite(_aldPin, HIGH);

  // Set the address lines back to INPUT mode to avoid interference
  for (int i = 0; i < 8; i++) {
    pinMode(13 + i, INPUT);
  }
}

