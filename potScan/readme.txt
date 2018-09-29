/*
  potScan.ino EXAMPLE scetch, unsing the – potScan Library with:
  theshold, hysteresis, output range mapping
  and parameter feedback ability
  This library returns:
  The current potentiometer value within a defined range, in hysteresis protected steps, without any jitter
  Created by Rolf Meurer, September 27, 2018
  Released into the public domain.

  before we call the function, we must set 2 or 3 parameters e.g. in void setup():
                scanPot.begin(int potPin, int maxVal);                    // 2 parameter
                scanPot.begin(int potPin, int maxVal, bool forceOutput);  // or 3 parameter (explained below)

  description:
  potPin:       the pin number where the potentiometer is connected to
  maxVal:       the maximum value we wanna get back from the potentiometer
  forceOutput:  the forceOutput argument is optional! (false by default)
                if false, only if the pot has been moved, return potVal, othewise return -1
                if true, each call will return potVal, but never ever -1
  The purpose of the forceOutput flag:
                we might wanna cycle call the current potentiometer value, perhaps for any kind of sensor
  function cal:
                int potVal = scanPot.getVal();
                if (potVal >= 0) Serial.println(potVal, DEC);
  not forget to mention, there is another optional parameter scanPot.getVal(bool recall);
                if false, everything as usual explained before
                if true, the function will return the current value of the potentiometer (without being touched)
  The purpose of the recall flag:
                e.g. parameter feedback in applications where we need to dump the current value on demand


  The example scetch hardware:
  connect a potentiometer, one end pin to VCC, the other end pin to GROUND, and the center pin to A0
  connect a momentary switch, one pin to GROUND, and the other pin to D9
*/
