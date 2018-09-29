/*
  potScan.cpp - Library with:
  theshold, hysteresis, output range mapping
  and parameter feedback ability
  Created by Rolf Meurer, September 27, 2018
  Released into the public domain.
*/

#include "potScan.h"

potScan::potScan() {
}

void potScan::begin(int potPin, int outMax, bool forceOutput) {
  if (forceOutput == NULL) forceOutput = false;
  _potPin = potPin;
  _outMax = outMax;
  _forceOutput = forceOutput;
}

int potScan::getVal(bool recall) {
  if (recall == NULL) recall = false;

  static int _potBuf;
  static int _outBuf = _iniVal;
  static bool _potMov;

  _threshold = 1023 / _outMax;
  _potVal = analogRead(_potPin);


  if (_forceOutput) {
    _potBuf = _iniVal;
    _outBuf = _iniVal;
  }

  _potMov = _potVal - _potBuf >= _threshold | _potBuf - _potVal >= _threshold;
  if (_potMov) {
    _outVal = map(_potVal, 0, 1023, 0, _outMax);
  }
  else if (recall) {
    return _outVal;
  }
  if (_outVal != _outBuf ) {
    _potBuf = _potVal;
    _outBuf = _outVal;
    return _outVal;
  }
  else {
    return -1;
  }
}

