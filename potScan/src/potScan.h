/*
  potScan.h - Library with:
  theshold, hysteresis, output range mapping
  and parameter feedback ability
  Created by Rolf Meurer, September 27, 2018
  Released into the public domain.
*/

#ifndef potScan_h
#define potScan_h

#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#include "pins_arduino.h"
#include "WConstants.h"
#endif

#define _iniVal 5000

class potScan {

  public:
    potScan();
    int getVal(bool recall = NULL);
    void begin(int potPin, int outMax, bool forceOutput = NULL);

  private:
    int _potPin;
    int _outMax;
    bool _forceOutput;
    int _threshold;
    int _potVal;
    int _outVal;
};
#endif
