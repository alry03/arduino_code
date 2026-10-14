
#include <DHT.h>

#define DHTPIN 4       // Data pin connected to digital pin 4
#define DHTTYPE DHT11  // Sensor type

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  dht.begin();

  Serial.println("DHT11 Sensor Initialized");
}

void loop() {
  delay(2000);  // DHT11 readings should be spaced apart

  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature();

  if (isnan(humidity) || isnan(temperature)) {
    Serial.println("Failed to read from DHT11 sensor!");
    return;
  }

  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.print(" °C | Humidity: ");
  Serial.print(humidity);
  Serial.println(" %");

}
