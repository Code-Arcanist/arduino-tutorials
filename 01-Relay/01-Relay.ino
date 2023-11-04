// The pin connected to signal on the relay board 
#define RELAY_PIN 10

void setup() {
  // Set the signal pin to Output 
  pinMode(RELAY_PIN, OUTPUT);
}

void loop() {
  // Turn relay on
  digitalWrite(RELAY_PIN, 255);
  delay(2000);

  // Turn relay off
  digitalWrite(RELAY_PIN, 0);
  delay(2000);
}
