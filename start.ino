// What Each Pin Is Used For//
#define PIN_LED    13
#define PIN_MELODY  3
#define PIN_POT    A0

// Each Songs Unique Assigned Number//
#define MARIO_BROS     1
#define HAPPY_BIRTHDAY 2
#define FUNKY_TOWN     3

// What Happens When The Arduino Is Turned On//
void setup(void) {
  
  // Start Up Monitor//
  Serial.begin(9600);
  
  // Speaker//
  pinMode(PIN_MELODY, OUTPUT);
  
  //LED Feedback When Note Is Played//
  pinMode(PIN_LED, OUTPUT);
  
  // Potentiometer For Song Switching//
  pinMode(PIN_POT, INPUT);
}

// What Happens Repeatedly After Arduino Runs Through The Setup//
void loop() {
  
  // map it to the range of the analog out:
  int outputValue = map(analogRead(PIN_POT), 0, 1023, 0, 255);
  
  if (outputValue >= 0 && outputValue <= 80) playMarioBros();
  
  if (outputValue >= 81 && outputValue <= 180) playHappyBirthday();
  
  if (outputValue >= 201 && outputValue <= 300) playFunkyTown();
}

// What Happens When The User Increases / Decreases The Potentiometer Mid-Song//
int switchSong(int song) {

  // map it to the range of the analog out:
  int outputValue = map(analogRead(PIN_POT), 0, 1023, 0, 255);

  // Resistence Range For Mario Bros//
  if (outputValue >= 0 && outputValue <= 80 && song != 1)    { playMarioBros(); return 1; }

   // Resistence Range For Happy Birthday//
  if (outputValue >= 81 && outputValue <= 180 && song != 2)  { playHappyBirthday(); return 1; }

   // Resistence Range For Funky Town//
  if (outputValue >= 201 && outputValue <= 300  && song !=3) { playFunkyTown(); return 1; }

  return 0;
}
