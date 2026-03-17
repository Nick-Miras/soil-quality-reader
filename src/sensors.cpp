//
// Created by Nick Anthony Miras on 3/17/26.
//
#include "sensors.h"


// -----------------------------------------
// DS18B20 Temperature Sensor Configuration
// -----------------------------------------
#define ONE_WIRE_BUS 2
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature ds18b20(&oneWire);

// -----------------------------------------
// DHT Humidity Sensor Configuration
// -----------------------------------------
#define DHTPIN 3
#define DHTTYPE DHT22 // Change to DHT11 if you are using a DHT11 sensor
DHT dht(DHTPIN, DHTTYPE);

// -----------------------------------------
// Soil Moisture Sensor Configuration
// -----------------------------------------
#define MOISTURE_PIN A0
// Calibration values for moisture sensor (adjust these based on your specific sensor)
const int AirValue = 600;   // Analog value when sensor is completely dry in air
const int WaterValue = 250; // Analog value when sensor is submerged in water


void setupSensors() {
    // Initialize DS18B20
    ds18b20.begin();

    // Initialize DHT
    dht.begin();
}

/* Function: getMoistureLevel; reads soil moisture.
 * Returns: Moisture Value of the soil in percent.
 */
int getMoistureLevel() {
    int moistureAnalog = analogRead(MOISTURE_PIN);
    // Map the analog value to a percentage (0-100%)
    int moisturePercent = map(moistureAnalog, AirValue, WaterValue, 0, 100);
    // Constrain the percentage to stay between 0 and 100
    moisturePercent = constrain(moisturePercent, 0, 100);
    return moisturePercent;
}

float getHumidity() {
    // Read DHT Humidity
    float humidity = dht.readHumidity();
    // Check if any reads failed and exit early (to try again).
    if (isnan(humidity)) {
        Serial.println(F("Failed to read from DHT sensor!"));
        humidity = 0.0; // Fallback value
    }
    return humidity;
}

float getTemperature() {
    // Read DS18B20 Waterproof Temperature
    ds18b20.requestTemperatures();
    float waterTemp = ds18b20.getTempCByIndex(0);
    return waterTemp;
}