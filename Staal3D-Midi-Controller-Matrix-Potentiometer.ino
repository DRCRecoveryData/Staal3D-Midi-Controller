#include <MIDIUSB.h>

// The note numbers corresponding to the buttons in the matrix
const byte addresses[4][4] = {
  {36, 37, 38, 39},
  {40, 41, 42, 43},
  {44, 45, 46, 47},
  {48, 49, 50, 51}
};

// Pins for the rows and columns of the button matrix
const byte rowPins[4] = {2, 3, 4, 5};
const byte colPins[4] = {6, 7, 8, 9};

// Pins for the potentiometers
const byte potPins[4] = {A0, A1, A2, A3};

void setup() {
  Serial.begin(115200); // Initialize Serial communication
  setupButtonMatrix();
  setupPotentiometers();
}

void loop() {
  checkButtonMatrix();
  readPotentiometers();
}

// Function to set up the button matrix
void setupButtonMatrix() {
  for (byte i = 0; i < 4; i++) {
    pinMode(rowPins[i], INPUT_PULLUP); // Set row pins as input with pull-up resistors
    pinMode(colPins[i], OUTPUT); // Set column pins as output
    digitalWrite(colPins[i], HIGH); // Set column pins to high
  }
}

// Function to set up the potentiometers
void setupPotentiometers() {
  for (byte i = 0; i < 4; i++) {
    pinMode(potPins[i], INPUT); // Set potentiometer pins as input
  }
}

// Function to check the state of the buttons in the matrix
void checkButtonMatrix() {
  for (byte i = 0; i < 4; i++) {
    digitalWrite(colPins[i], LOW); // Set current column pin to low
    for (byte j = 0; j < 4; j++) {
      if (digitalRead(rowPins[j]) == LOW) { // If button is pressed
        byte note = addresses[j][i];
        sendNoteOn(note);
        delay(50); // Debouncing delay
        while (digitalRead(rowPins[j]) == LOW) {} // Wait until button is released
        sendNoteOff(note);
      }
    }
    digitalWrite(colPins[i], HIGH); // Set current column pin back to high
  }
}

// Function to read potentiometer values and send MIDI controller messages
void readPotentiometers() {
  for (byte i = 0; i < 4; i++) {
    int value = analogRead(potPins[i]); // Read potentiometer value
    int controllerNumber = 20 + i; // MIDI controller number (assumed)
    sendControllerMessage(controllerNumber, map(value, 0, 1023, 0, 127)); // Map potentiometer value to MIDI controller value and send MIDI message
  }
}

// Function to send MIDI note-on message
void sendNoteOn(byte note) {
  Serial.write(0x90); // Note-on status byte
  Serial.write(note); // Note number
  Serial.write(127);  // Velocity
}

// Function to send MIDI note-off message
void sendNoteOff(byte note) {
  Serial.write(0x80); // Note-off status byte
  Serial.write(note); // Note number
  Serial.write((uint8_t)0);    // Velocity (zero velocity)
}

// Function to send MIDI controller message
void sendControllerMessage(byte controllerNumber, byte value) {
  Serial.write(0xB0); // Controller message status byte
  Serial.write(controllerNumber); // Controller number
  Serial.write(value); // Controller value
}
