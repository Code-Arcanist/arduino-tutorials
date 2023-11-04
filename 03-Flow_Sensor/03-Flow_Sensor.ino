// A counter to keep track of the number of pulses from the
// flow sensor
volatile uint16_t count = 0;

/*
 * Function that is called every time a pulse is detected on
 * the D8 pin. When the signal drops from HIGH to LOW (hence why
 * it is call a FALLING edge) a interupt will be triggered.
 */
void pulse_detected() {
  count++;
}

// The time in milliseconds since we last cleared the current
// pulse counter.
uint16_t last;

void setup() {
  Serial.begin(9600);

  // Attach the function to the interupt 0 and set it to trigger
  // on a falling edge
  attachInterrupt(0, pulse_detected, FALLING);

  // Set time we last cleared the counter to now
  last = millis();
}

void loop() {
  // Copy the current count into a temporary variable
  uint16_t prev_count = count;
  // Reset the count
  count = 0;

  uint16_t now = millis();

  // Reset the last time we reset the counter 
  last = now;
  
  // How many milliseconds between calculations
  uint16_t prev_period = now - last;
  
  // The frequence is calculated as the number of counts
  // divided by the number of seconds (milliseconds / 1000)
  float freq = (1.0 * prev_count) / (prev_period / 1000.0);

  // The 6.6 is a correction factor from my flow sensor - yours might vary
  float flow = freq / 6.6;

  // Dump the data to the serial monitor
  Serial.print(prev_count);
  Serial.print(" - ");
  Serial.print(prev_period);
  Serial.print(" - ");
  Serial.print(freq);
  Serial.print(" - ");
  Serial.println(flow);
  delay(5000);
}
