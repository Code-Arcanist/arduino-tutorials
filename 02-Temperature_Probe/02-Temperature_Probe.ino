#include <DS18B20.h>

// Setup the temperature probe connected to D4
DS18B20 ds(2);

void setup() {
  Serial.begin(9600);

  // Make the first probe sensor active
  ds.selectNext();

  // Set the resolution to 9 bit
  ds.setResolution(RES_9_BIT);
}

void loop() {
  // Output the temperature to the serial monitor every 10 seconds
  Serial.println(ds.getTempC());
  delay(10000);
}
