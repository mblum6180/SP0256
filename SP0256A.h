#ifndef SP0256A_h
#define SP0256A_h

#include "Arduino.h"

class SP0256A {
  public:
    SP0256A(int aldPin, int lrqPin, int resetPin);
    void begin();
    void speakNumber(int number);

  private:
    int _aldPin;
    int _lrqPin;
    int _resetPin;
};

#endif
