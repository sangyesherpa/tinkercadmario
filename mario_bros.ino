//https://noobnotes.net/super-mario-bros-theme-nintendo/?transpose=0//
//https://www.quora.com/Do-the-88-keys-of-a-piano-cover-the-full-range-of-frequencies-that-the-human-ear-can-perceive//

// Note Frequencies For Mario Bro's Theme Song//
#define NOTE_A4B 466
#define NOTE_A4W 440
#define NOTE_A5W 880
#define NOTE_B4W 493
#define NOTE_C5W 523
#define NOTE_C6W 1046
#define NOTE_D5B 622
#define NOTE_D5W 587
#define NOTE_E4W 329
#define NOTE_E5W 659
#define NOTE_F5B 739
#define NOTE_F5W 698
#define NOTE_G5W 783
#define NOTE_G4W 392

// The Melody For The MarioBros Theme Song//
const int MARIO_BROS_MELODY[] = {
            
    NOTE_E5W, NOTE_E5W, NOTE_E5W,
    NOTE_C5W, NOTE_E5W, NOTE_G5W, NOTE_G4W,
                      
    NOTE_C5W, NOTE_G4W, NOTE_E4W,      
    NOTE_A4W, NOTE_B4W, NOTE_A4B, NOTE_A4W,
    NOTE_G4W, NOTE_E5W, NOTE_G5W, NOTE_A5W,
    NOTE_F5W, NOTE_G5W, NOTE_E5W, NOTE_C5W, NOTE_D5W, NOTE_B4W,

    NOTE_C5W, NOTE_G4W, NOTE_E4W,
    NOTE_A4W, NOTE_B4W, NOTE_A4B, NOTE_A4W,
    NOTE_G4W, NOTE_E5W, NOTE_G5W, NOTE_A5W,
    NOTE_F5W, NOTE_G5W, NOTE_E5W, NOTE_C5W, NOTE_D5W, NOTE_B4W,

    NOTE_G5W, NOTE_F5B, NOTE_F5W, NOTE_D5W, NOTE_E5W,
    NOTE_G4W, NOTE_A4W, NOTE_C5W,
    NOTE_A4W, NOTE_C5W, NOTE_D5W,
    NOTE_G5W, NOTE_F5B, NOTE_F5W, NOTE_D5W, NOTE_E5W,
    NOTE_C6W, NOTE_C6W, NOTE_C6W,

    NOTE_G5W, NOTE_F5B, NOTE_F5W, NOTE_D5W, NOTE_E5W,
    NOTE_G4W, NOTE_A4W, NOTE_C5W,
    NOTE_A4W, NOTE_C5W, NOTE_D5W,
    NOTE_D5B, NOTE_D5W, NOTE_C5W,

    NOTE_C5W, NOTE_C5W, NOTE_C5W,
    NOTE_C5W, NOTE_D5W, NOTE_E5W, NOTE_C5W, NOTE_A4W, NOTE_G4W,
    NOTE_C5W, NOTE_C5W, NOTE_C5W,
    NOTE_C5W, NOTE_D5W, NOTE_E5W,

    NOTE_C5W, NOTE_C5W, NOTE_C5W,
    NOTE_C5W, NOTE_D5W, NOTE_E5W, NOTE_C5W, NOTE_A4W, NOTE_G4W,
    NOTE_E5W, NOTE_E5W, NOTE_E5W,
    NOTE_C5W, NOTE_E5W, NOTE_G5W,
    NOTE_G4W 
};

// The Tempo For The MarioBros Theme Song//
const int MARIO_BROS_TEMPO[] = {
    10, 10, 10,
    10, 10, 10, 10,
    
    10, 10, 10,
    10, 10, 10, 10,
    10, 10, 10, 10,
    10, 10, 10, 10, 10, 10,
  
    10, 10, 10,
    10, 10, 10, 10,
    10, 10, 10, 10,
    10, 10, 10, 10, 10, 10,
  
    9, 9, 9, 9, 9,
    9, 9, 9,
    9, 9, 9,
    9, 9, 9, 9, 9,
    10, 10, 10,
  
    9, 9, 9, 9, 9,
    9, 9, 9,
    9, 9, 9,
    9, 9, 9, 
    9, 9, 9,
  
    10, 10, 10,
    10, 10, 10, 10, 10, 10,
    10, 10, 10,
    10, 10, 10,
  
    10, 10, 10,
    10, 10, 10, 10, 10, 10,
    10, 10, 10,
    10, 10, 10,
    10
};

// Function That Plays The Mario Bros Theme Song//
void playMarioBros() {
  
    // Show The User What Song Is Playing//
    Serial.println("Mario Bros Theme Song");
  
    // The Amount Of Notes That Are In The Song//
    int totalNotes = sizeof(MARIO_BROS_MELODY) / sizeof(int);
    
    // What Happens For Each Note In The Melody//
    for (int currentNote = 0; currentNote < totalNotes; currentNote++) {

        // Switches The Song If The Potentiometer Was Changed//
        int switched = switchSong(MARIO_BROS);
        if (switched == 1) break;
    
        // Determines The Duritation Of Each Note//
        long int noteDuration = 1000 / MARIO_BROS_TEMPO[currentNote];
    
        // Play The Current Note//
        playNote(PIN_MELODY, MARIO_BROS_MELODY[currentNote], noteDuration);
        
        // Determines The Pause Between Each Note//
        delay(noteDuration * 1.40);   
    }
}

// Function That Creates And Plays The Current Note//
void playNote(int targetPin, long double frequency, long int noteDuration) {
  
    // Sets The LED To Bright// 
    digitalWrite(PIN_LED, HIGH);
 
    // Determines The Delay Between Transitions And Number Of Cycles For Proper Timing//
    long transition    = 1000000 / frequency / 2; 
    long speakerCycles = frequency * noteDuration / 1000; 
  
    // Procuce The Cycles So The Speaker Can Create The Sound For The Note//
    for (long i = 0; i < speakerCycles; i++) { 
   
        digitalWrite(targetPin, HIGH); 
        delayMicroseconds(transition); 
        digitalWrite(targetPin, LOW); 
        delayMicroseconds(transition); 
    }
  
    // Sets The LED To Dim// 
    digitalWrite(PIN_LED, LOW);
}
