//
// Created by Nick Anthony Miras on 3/17/26.
//

#ifndef SOIL_QUALITY_READER_SENSORS_H
#define SOIL_QUALITY_READER_SENSORS_H

#include <DallasTemperature.h>
#include <Wire.h>
#include <OneWire.h>
#include <DHT.h>

extern void setupSensors();
extern int getMoistureLevel();
extern float getHumidity();
extern float getTemperature();

#endif //SOIL_QUALITY_READER_SENSORS_H