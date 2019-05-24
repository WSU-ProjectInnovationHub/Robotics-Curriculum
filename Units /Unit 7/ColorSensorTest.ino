#include "TCS3200.h"

const int s0 = 8;
const int s1 = 9;
const int s2 = 10;
const int s3 = 11;

TCS3200 colorSensor = TCS3200(s0, s1, s2, s3);
uint8_t colors[3];

void setup() {
  colorSensor.begin();
}

void loop() {
  colorSensor.loop();
  colorSensor.getRGB(colors); 
  Serial.print("C:\t"); Serial.print(1000);
      Serial.print("\tR:\t"); Serial.print(colors[0]);
      Serial.print("\tG:\t"); Serial.print(colors[1]);
      Serial.print("\tB:\t"); Serial.print(colors[2]);
      Serial.print("\t");
      Serial.println(); 
}
