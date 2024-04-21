#include <MIDI.h>

MIDI_CREATE_DEFAULT_INSTANCE();

const int NButtons = 16;
const int buttonPin[NButtons] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 14, 15, 16, 17, 18};
int buttonPState[NButtons] = {0};

const int NPots = 4;
const int potPin[NPots] = {A0, A1, A2, A3};
int potPState[NPots] = {0};

void setup() {
  Serial.begin(31250);

  for (int i = 0; i < NButtons; i++) {
    pinMode(buttonPin[i], INPUT_PULLUP);
  }
}

void loop() {
  readButtons();
  readPotentiometers();
}

void readButtons() {
  for (int i = 0; i < NButtons; i++) {
    int buttonState = digitalRead(buttonPin[i]);
    if (buttonState != buttonPState[i]) {
      buttonPState[i] = buttonState;
      if (buttonState == LOW) {
        MIDI.sendNoteOn(36 + i, 127, 1); // Send note on message
      } else {
        MIDI.sendNoteOff(36 + i, 0, 1); // Send note off message
      }
    }
  }
}

void readPotentiometers() {
  for (int i = 0; i < NPots; i++) {
    int potValue = analogRead(potPin[i]);
    int mappedValue = map(potValue, 0, 1023, 0, 127);
    if (mappedValue != potPState[i]) {
      potPState[i] = mappedValue;
      MIDI.sendControlChange(1 + i, mappedValue, 1); // Send control change message
    }
  }
}
