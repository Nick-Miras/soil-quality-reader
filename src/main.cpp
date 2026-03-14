#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <OneWire.h>
#include <DallasTemperature.h>
#include <DHT.h>

// -----------------------------------------
// OLED Display Configuration
// -----------------------------------------
#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels
#define OLED_RESET    -1 // Reset pin # (or -1 if sharing Arduino reset pin)
#define SCREEN_ADDRESS 0x3C // See datasheet for Address; 0x3D for 128x64, 0x3C for 128x32/128x64
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

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

void setup() {
  Serial.begin(9600);

  // Initialize DS18B20
  ds18b20.begin();

  // Initialize DHT
  dht.begin();

  // Initialize OLED display
  // SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
  if(!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;); // Don't proceed, loop forever
  }

  // Clear the buffer and display a boot message
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(10, 25);
  display.print(F("Initializing..."));
  display.display();
  delay(2000); // Pause for 2 seconds
}

void loop() {
  // 1. Read DS18B20 Waterproof Temperature
  ds18b20.requestTemperatures();
  float waterTemp = ds18b20.getTempCByIndex(0);

  // 2. Read DHT Humidity
  float humidity = dht.readHumidity();
  // Check if any reads failed and exit early (to try again).
  if (isnan(humidity)) {
    Serial.println(F("Failed to read from DHT sensor!"));
    humidity = 0.0; // Fallback value
  }

  // 3. Read Soil Moisture
  int moistureAnalog = analogRead(MOISTURE_PIN);
  // Map the analog value to a percentage (0-100%)
  int moisturePercent = map(moistureAnalog, AirValue, WaterValue, 0, 100);
  // Constrain the percentage to stay between 0 and 100
  moisturePercent = constrain(moisturePercent, 0, 100);

  // 4. Update OLED Display
  display.clearDisplay();

  // Title
  display.setTextSize(1);
  display.setCursor(0, 0);
  display.print(F("--- SENSOR FUSION ---"));

  // Display DS18B20 Temp
  display.setCursor(0, 16);
  display.print(F("Water Temp: "));
  if(waterTemp != DEVICE_DISCONNECTED_C) {
    display.print(waterTemp, 1);
    display.print(F(" C"));
  } else {
    display.print(F("Error"));
  }

  // Display Air Humidity
  display.setCursor(0, 32);
  display.print(F("Air Humid:  "));
  display.print(humidity, 1);
  display.print(F(" %"));

  // Display Soil Moisture
  display.setCursor(0, 48);
  display.print(F("Soil Moist: "));
  display.print(moisturePercent);
  display.print(F(" %"));

  display.display();

  // Print to Serial Monitor for debugging
  Serial.print("Water Temp: "); Serial.print(waterTemp); Serial.print("C | ");
  Serial.print("Humidity: "); Serial.print(humidity); Serial.print("% | ");
  Serial.print("Moisture: "); Serial.print(moisturePercent); Serial.println("%");

  // Wait 2 seconds between readings (DHT sensors are slow and shouldn't be polled faster than this)
  delay(2000);
}