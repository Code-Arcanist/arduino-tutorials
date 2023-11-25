// Using a HC-SR04 Ultrasonic distance sensor.

#define TRIG_PIN 8 // Used to trigger the ranging pulse
#define ECHO_PIN 9 // Used to listen for the timing of the echo

void setup() {
  Serial.begin(9600);

  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
}

void loop() {
  // Ranging pulse is triggered by sending a 10 microsecond high pulse
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  // PulseIn will return the amount of time that our echo pin is high
  float time_us = pulseIn(ECHO_PIN, HIGH);

  // distance travelled is time taken to go twice the distance
  // (hence why we halve it) multipled by the speed of sound 
  // measured in centimeters per microsecond
  float distance = (time_us / 2.0) * 0.034300;

  Serial.print("Time: ");
  Serial.print(time_us);
  Serial.print("  Distances: ");
  Serial.println(distance);
}
