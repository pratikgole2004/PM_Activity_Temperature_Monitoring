// Temperature and Humidity Monitoring using DHT11 Sensor
// Author: Pratik Gole
// Description: Reads temperature and humidity data from DHT11 sensor and prints it on the Serial Monitor.

#include "DHT.h"

#define DHTPIN 7        // Pin connected to DHT11 data pin
#define DHTTYPE DHT11   // Define sensor type

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  dht.begin();
  Serial.println("DHT11 Temperature and Humidity Monitoring Started...");
}

void loop() {
  float temp = dht.readTemperature();  // Read temperature in Celsius
  float humidity = dht.readHumidity(); // Read humidity

  if (isnan(temp) || isnan(humidity)) {
    Serial.println("Error reading from DHT sensor!");
    return;
  }

  Serial.print("Temperature: ");
  Serial.print(temp);
  Serial.print(" °C | Humidity: ");
  Serial.print(humidity);
  Serial.println(" %");

  delay(2000); // wait 2 seconds between readings
}
