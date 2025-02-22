#include <DHT.h>

#define DHT11_PIN 7     // Define the pin where the DHT11 is connected
#define DHTTYPE DHT11   // Define the type of DHT sensor you're using (DHT11 or DHT22)

DHT dht(DHT11_PIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  dht.begin();
}

void loop() {
  float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();

  if (isnan(temperature) || isnan(humidity)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  Serial.print("Temperature = ");
  Serial.print(temperature);
  Serial.println(" °C");

  Serial.print("Humidity = ");
  Serial.print(humidity);
  Serial.println(" %");

  delay(1000);  // Wait a second between readings
}