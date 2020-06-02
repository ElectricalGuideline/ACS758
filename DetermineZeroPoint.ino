#include "ACS758.h"

/*
  This example shows how to determine zero point of your sensor
*/

// We have 200 amps version sensor connected to A1 pin of arduino
// Replace with your version if necessary
ACS758 sensor(ACS758ECB_200B, A1);

void setup() {
  Serial.begin(9600);

  float zero_point = sensor.calibrate();
  
  Serial.print("Zero point for this sensor is ");
  Serial.println(zero_point);
}

void loop() {}
