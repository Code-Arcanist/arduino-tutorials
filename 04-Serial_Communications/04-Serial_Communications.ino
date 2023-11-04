#define BUFFER_SIZE 512

// Create a buffer to hold the incoming communication
// Note: Most commands should be less than 20 characters long so picking a
// larger number just to be safe.
char buffer[BUFFER_SIZE];
int current_index = 0;

// Setup a couple of booleans to show what state we are in
bool start_character_detected = false;
bool end_character_detected = false;

void setup() {
  Serial.begin(9600);
}

void update_buffer() {
  // If we have a character ready to be read the process it.
  if (Serial.available()) {
    char c = Serial.read();

    // If we haven't started reading a command yet
    if (start_character_detected == false) {
      // If we have received a start character then we record the fact
      if (c == '<') {
        start_character_detected = true;
      }
    }

    // If we have started the command but not detected a end character yet
    // this means that we are in the middle of reading a command
    if (start_character_detected == true && end_character_detected == false) {
      // If we have received an end character then we can record the fact
      if (c == '>') {
        end_character_detected = true;
      }
    }

    // If we have received a start character then we need to keep track of
    // all the characters we have received so far 
    if (start_character_detected) {
      buffer[current_index] = c;
      current_index++;
      // If we have gone over 500 characters then we reset the index back to the start
      // to stop any chance of a buffer override error.
      if (current_index > 500) {
        current_index = 0;
      }
      // Mark the end of the string with a NUL character
      buffer[current_index] = '\0';
    }
  }
}

void process_command() {
  // Send back a identifier string when requested 
  if (strcmp("<id>", buffer) == 0) {
    Serial.println("<arduino>");
  }  
}

void loop() {
  // Process the incoming buffer 
  update_buffer();

  // If we have received a valid command string structure, that is
  // we have received a start character, zero of more other characters and then
  // an end character.
  if (start_character_detected == true && end_character_detected == true) {
    // Process the received command
    process_command();

    // Reset the buffer and start/end flags.
    start_character_detected = false;
    end_character_detected = false;
    current_index = 0;
  }
}
