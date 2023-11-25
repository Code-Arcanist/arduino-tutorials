#include <SoftwareSerial.h>

// Setup the serial connection to the mp2 unit
// Note: 
//   TX pin on the device is the RX pin on the Nano
//   RX pin on the device is the TX pin on the Nano
#define MP3_RX_PIN 12
#define MP3_TX_PIN 10

SoftwareSerial mp3(MP3_TX_PIN, MP3_RX_PIN);

void setup() {
  Serial.begin(9600);

  // Datasheet says 9600 baud
  mp3.begin(9600);

  // Send the command string to select the MicroSD Card
  mp3.write(0x7e); // Start Byte
  mp3.write(0x03); // 3 bytes between start/end bytes
  mp3.write(0x35); // Set Storage Device
  mp3.write(0x01); // 0x01 -> MicroSD Card
  mp3.write(0xef); // End Byte
}

void loop() {
  // Send the play with volume command
  mp3.write(0x7e); // Start Byte
  mp3.write(0x04); // 4 bytes between start/end bytes
  mp3.write(0x31); // Play
  mp3.write(0x1e); // Volume
  mp3.write(0x01); // Track Index 01 -> /mp3/001track.mp3
  mp3.write(0xef); // End Byte
  delay(3000);
}
