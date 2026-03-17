#include <Arduino.h>
#include "sensors.h"
#include <Adafruit_SSD1306.h>
#include <Adafruit_GFX.h>


// -----------------------------------------
// OLED Display Configuration
// -----------------------------------------
#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels
#define OLED_RESET    -1 // Reset pin # (or -1 if sharing Arduino reset pin)
#define SCREEN_ADDRESS 0x3C // See datasheet for Address; 0x3D for 128x64, 0x3C for 128x32/128x64
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);


void setup() {
  Serial.begin(9600);

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

  setupSensors();

  delay(2000); // Pause for 2 seconds
}

void loop() {
  // 4. Update OLED Display
  display.clearDisplay();

  // Title
  display.setTextSize(1);
  display.setCursor(0, 0);
  display.print(F("--- SENSOR FUSION ---"));

  // Display DS18B20 Temp
  display.setCursor(0, 16);
  display.print(F("Water Temp: "));

  const float temp = getTemperature();
  if(temp != DEVICE_DISCONNECTED_C) {
    display.print(temp, 1);
    display.print(F(" C"));
  } else {
    display.print(F("Error"));
  }

  // Display Air Humidity
  const float humidity = getHumidity();
  display.setCursor(0, 32);
  display.print(F("Air Humid:  "));
  display.print(humidity, 1);
  display.print(F(" %"));

  // Display Soil Moisture
  const int moisturePercent = getMoistureLevel();
  display.setCursor(0, 48);
  display.print(F("Soil Moist: "));
  display.print(moisturePercent);
  display.print(F(" %"));

  display.display();

  // Print to Serial Monitor for debugging
  Serial.print("Water Temp: "); Serial.print(temp); Serial.print("C | ");
  Serial.print("Humidity: "); Serial.print(humidity); Serial.print("% | ");
  Serial.print("Moisture: "); Serial.print(moisturePercent); Serial.println("%");

  // Wait 2 seconds between readings (DHT sensors are slow and shouldn't be polled faster than this)
  delay(2000);
}