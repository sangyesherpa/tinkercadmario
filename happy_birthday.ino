// used pin 3//
int speakerPin = 3;

 // the number of notes//
int length = 28;

char happy_birthday_notes[] = "GGAGcB GGAGdc GGxecBA yyecdc";

//notes of the song//
int happy_birthday_beats[] = { 2, 2, 8, 8, 8, 16, 1, 2, 2, 8, 8,8, 16, 1, 2,2,8,8,8,8,16, 1,2,2,8,8,8,16 };

int happy_birthday_tempo = 150;

//function that creates notes//
void playTone(int tone, int duration) {

  //determines how long the length of each notes are//
    for (long i = 0; i < duration * 1000L; i += tone * 2) {

      digitalWrite(speakerPin, HIGH);

      delayMicroseconds(tone);

      digitalWrite(speakerPin, LOW);

      delayMicroseconds(tone);

    }
}

//notes for the song//
void playNote(char note, int duration) {

    char names[] = {'C', 'D', 'E', 'F', 'G', 'A', 'B',           

                 'c', 'd', 'e', 'f', 'g', 'a', 'b',

                 'x', 'y' };

    int tones[] = { 1915, 1700, 1519, 1432, 1275, 1136, 1014,

                 956,  834,  765,  593,  468,  346,  224,

                 655 , 715 };

    int SPEE = 5;

    // play the tone corresponding to the note name//
    for (int i = 0; i < 15; i++) {

      if (names[i] == note) {

          //determines how long each notes are//
          int newduration = duration/SPEE;
          playTone(tones[i], newduration);
      }
   }
}

//function that plays the song//
void playHappyBirthday() {
  
  for (int i = 0; i < length; i++) {

    int switched = switchSong(HAPPY_BIRTHDAY);

    if (switched == 1) { break; }

    if (happy_birthday_notes[i] == ' ') { delay(happy_birthday_beats[i] * happy_birthday_tempo); } 
   
    else { playNote(happy_birthday_notes[i], happy_birthday_beats[i] * happy_birthday_tempo); }

    // pause between notes//
    delay(happy_birthday_tempo);

  }
}
