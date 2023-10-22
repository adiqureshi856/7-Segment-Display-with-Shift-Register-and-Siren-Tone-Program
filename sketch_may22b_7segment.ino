// Pin connections for shift register
const int latchPin = 5;  // Connect to RCLK pin of shift register
const int dataPin = 6;   // Connect to SER pin of shift register
const int clockPin = 3;  // Connect to SRCLK pin of shift register

// Define the 7-segment display patterns
byte segments[] = {
  B11000000, // 0
  B11111001, // 1
  B10100100, // 2
  B10110000, // 3
  B10011001, // 4
  B10010010, // 5
  B10000010, // 6
  B11111000, // 7
  B10000000, // 8
  B10011000  // 9
};

void setup() {
  // Set the shift register pins as outputs
  pinMode(latchPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
}

void loop() {
  // Display numbers from 0 to 9
  for (int i = 0; i < 10; i++) {
      digitalWrite(latchPin, LOW);
    // Shift out the pattern for the current digit
    shiftOut(dataPin, clockPin, MSBFIRST, segments[i]);
    
    // Latch the data to update the display
    digitalWrite(latchPin, HIGH);
  
    
    // Wait for a short delay
    delay(1000);
   
    
  }
   sirenTone();
  delay(1000);
  
}
void sirenTone() {
  // Increasing pitch
  for (int frequency = 200; frequency <= 1000; frequency += 100) {
    tone(13, frequency);
    delay(100);
  }

  // Decreasing pitch
  for (int frequency = 1000; frequency >= 200; frequency -= 100) {
    tone(13, frequency);
    delay(100);
  }

  // Turn off the buzzer
  noTone(13);

  // Pause between siren cycles
  delay(1000);
}
