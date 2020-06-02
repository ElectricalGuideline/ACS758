#include "ACS758.h"

/*
  This example shows how to set zero point of your sensor
*/

// We have 30 amps version sensor connected to A1 pin of arduino
// Replace with your version if necessary
ACS758 sensor(ACS758LCB_100B, A1);

void setup() {
  Serial.begin(9600);

  // Value obtained using sensor.calibrate() when no current flows through the sensor
  sensor.setZeroPoint(438);
}

void loop() {}
