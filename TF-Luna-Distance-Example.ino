/*
  Project: TF-Luna LiDAR Distance Measurement Example
  Description:
    This example demonstrates how to measure distance using the TF-Luna,
    a single-point LiDAR sensor from Benewake. The measured distance is
    printed to the Serial Monitor for observation.

  Hardware:
    - Benewake TF-Luna LiDAR Sensor
    - Arduino Uno (or compatible board)
    - I2C (SDA/SCL) communication

  Connections: TF-Luna -> Arduino
    - Pin #1 : +5V     -> Arduino 5V
    - Pin #2 : SDA/RXD -> Arduino SDA/RXD
    - Pin #3 : SCL/TXD -> Arduino SCL/TXD
    - Pin #4 : GND     -> Arduino GND
    - Pin #5 : Configuration Input
              - I2C Communication    -> Arduino GND
              - Serial Communicarion -> Arduino Disconnected/+3.3V
    - Pin #6 : Multiplexing Output
              - On/Off mode : Output
              - I2C mode : Data ready signal

  Author: Mobilution
  Date: October 5, 2025
  Version: 1.0
  Repository: https://github.com/mobilution1025/LiDAR/TF-Luna-Distance-Example
  Youtube Link : 
*/

#include <Arduino.h>
#include <Wire.h>     // I2C Library
#include <TFLI2C.h>   // TF-Luna I2C Library

TFLI2C TFLunarI2C;

int16_t tfDist;
int16_t tfAddr = TFL_DEF_ADR;

void setup() {
  Serial.begin(115200);   // Initialize Serial Communicarion between Arduino and PC
  Wire.begin();           // Start I2C Communicarion between Arduino and TF-Luna
}

void loop() {
  if (TFLunarI2C.getData(tfDist, tfAddr)) {
    Serial.println(String(tfDist)+" cm / " + String(tfDist/2.54)+" inches");
  }
  delay(50);
}
