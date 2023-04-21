#include <Arduino.h>
#include <Wire.h>
#include <GLEE_Sensor.h>
#include "TMP117.h"

#define SLAVE_ADDRESS 0x8

TMP117 thermometer(1,false);
double temperatureC;

void setup() {
  Wire.begin(SLAVE_ADDRESS);
}

void loop() {

  temperatureC = thermometer.getTemperatureC();

  //uint8_t* pointer1 = (uint8_t *)&temperatureC;
  //byte* pointer2 = (byte *)&temperatureC;
  // Send temperature data to Raspberry Pi
  Wire.beginTransmission(SLAVE_ADDRESS);
  Wire.write((byte *)&temperatureC, 8);
  Wire.endTransmission();

  delay(1000);
}

