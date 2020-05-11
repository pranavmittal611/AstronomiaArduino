// output pin is 8, you can change it down in the void loop.
#include "pitches.h"
int button = 5;
int loop = 2;// how many times do you want the tune to loop
loop = loop * 72;
int melody[] = {
  NOTE_G5, NOTE_G5, NOTE_G5, NOTE_G5, 
  NOTE_C5, NOTE_AS4, NOTE_A4, NOTE_F4,
  NOTE_G4, 0, NOTE_G4, NOTE_D5,
  NOTE_C5, 0, NOTE_AS4, 0,
  NOTE_A4, 0, NOTE_A4, NOTE_A4,
  NOTE_C5, 0, NOTE_AS4, NOTE_A4, 
  NOTE_G4,0, NOTE_G4, NOTE_AS5,
  NOTE_A5, NOTE_AS5, NOTE_A5, NOTE_AS5,
  NOTE_G4,0, NOTE_G4, NOTE_AS5,
  NOTE_A5, NOTE_AS5, NOTE_A5, NOTE_AS5,
  NOTE_G4, 0, NOTE_G4, NOTE_D5,
  NOTE_C5, 0, NOTE_AS4, 0,
  NOTE_A4, 0, NOTE_A4, NOTE_A4,
  NOTE_C5, 0, NOTE_AS4, NOTE_A4, 
  NOTE_G4,0, NOTE_G4, NOTE_AS5,
  NOTE_A5, NOTE_AS5, NOTE_A5, NOTE_AS5,
  NOTE_G4,0, NOTE_G4, NOTE_AS5,
  NOTE_A5, NOTE_AS5, NOTE_A5, NOTE_AS5
 };

void setup() {
  pinMode(button, INPUT_PULLUP);
}

void loop() {
  if (digitalRead(button)==LOW){
    for (int thisNote = 0; thisNote < loop; thisNote++) {
  
      int noteDuration = 750/4;
      tone(8, melody[thisNote%72], noteDuration);
  
      int pauseBetweenNotes = noteDuration * 1.30;
      delay(pauseBetweenNotes);
      
      noTone(8);
    }
  }
}
