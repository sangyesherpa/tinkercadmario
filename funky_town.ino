
#define NOTE_A4  440
#define NOTE_E5  659
#define NOTE_G5  784
#define NOTE_A5  880
#define NOTE_B6  1976
#define NOTE_D6  1175
#define NOTE_CS6 1109
#define NOTE_CS5 554
#define NOTE_AS5 932
#define NOTE_B5  988
#define NOTE_C6  1047
#define NOTE_A6  1760

int pinNum =3;

int funky_town_melody[] =
{
  NOTE_A5, NOTE_A5, NOTE_G5,NOTE_A5,0,
  NOTE_E5,0,NOTE_E5,NOTE_A5,NOTE_D6,
  NOTE_CS6,NOTE_A5,0, 

  NOTE_A5, NOTE_A5, NOTE_G5,NOTE_A5,0,
  NOTE_E5,0,NOTE_E5,NOTE_A5,NOTE_D6,
  NOTE_CS6,NOTE_A5,//26 

  NOTE_A4,NOTE_A4,NOTE_A4,NOTE_CS5,
  NOTE_CS5,NOTE_CS5,NOTE_E5,NOTE_E5,
  NOTE_E5,NOTE_CS6,NOTE_B6,NOTE_A6,

  0,0
};

int funky_town_tempo[] =
{
  250,250,250,250,250,
  250,250,250,250,250,
  250,250,250,
  
  250,250,250,250,250,
  250,250,250,250,250,
  250,250,

  250,250,250,250,
  250,250,250,250,
  250,250,250,250,

  250,250
};

void playFunkyTown() {
  
  int songSpeed = 1.5;
  
  for (int i=0;i<38;++i) 
  {

      int switched = switchSong(FUNKY_TOWN);
      if (switched == 1) break;
      
      int waitTime = funky_town_tempo[i]*songSpeed;
      tone(pinNum,funky_town_melody[i],waitTime);
      delay(waitTime);
  }
}
  
