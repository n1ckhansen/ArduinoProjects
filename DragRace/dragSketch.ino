#include "pitches.h"

// Using digital pins

#define RED 12
#define GREEN 11
#define BLUE 10

#define LEFT_WIN 8
#define RIGHT_WIN 9

#define LEFT_BUTTON 6
#define RIGHT_BUTTON 7

#define BUZZER 5

#define COUNTDOWN 1
#define BUTTON_STAGE 2
#define RESULTS_STAGE 3
#define END_GAME 4

void setup() {
Serial.begin( 9600 );
pinMode( RED, OUTPUT );
pinMode( GREEN, OUTPUT );
pinMode( BLUE, OUTPUT );
pinMode( LEFT_BUTTON, INPUT_PULLUP );
pinMode( RIGHT_BUTTON, INPUT_PULLUP );
digitalWrite( RED, LOW );
digitalWrite( GREEN, LOW );
digitalWrite( BLUE, LOW );
digitalWrite( LEFT_WIN, HIGH );
digitalWrite( RIGHT_WIN, HIGH );
}

int redValue;
int greenValue;
int blueValue;
int gameState = COUNTDOWN;

void loop() {
  while( gameState == COUNTDOWN ) {
    countDown();
  }

  while( gameState == BUTTON_STAGE ) {
    buttonStage();
  }

  while( gameState == RESULTS_STAGE ) {
    resultsStage();
  }

}

void countDown() {

  delay( 100 );
  digitalWrite( LEFT_WIN, LOW );
  digitalWrite( RIGHT_WIN, LOW );

  analogWrite( RED, 255);
  analogWrite( GREEN, 0);
  analogWrite( BLUE, 0 );
tone(BUZZER, NOTE_G5, 250);
  delay( random( 400, 1000 ) );

  analogWrite( RED, 0);
  analogWrite( GREEN, 0);
  analogWrite( BLUE, 0 );

  delay( random( 400, 1000 ) );

  analogWrite( RED, 255);
  analogWrite( GREEN, 45);
  analogWrite( BLUE, 0 );
tone(BUZZER, NOTE_G5, 250);
  delay( random( 400, 1000 ) );

  analogWrite( RED, 0);
  analogWrite( GREEN, 0);
  analogWrite( BLUE, 0 );

  delay( random( 400, 1000 ) );

  analogWrite( RED, 255);
  analogWrite( GREEN, 45);
  analogWrite( BLUE, 0 );
tone(BUZZER, NOTE_G5, 250);
  delay( random( 400, 1000 ) );

  analogWrite( RED, 0);
  analogWrite( GREEN, 0);
  analogWrite( BLUE, 0 );

  delay( random( 400, 1000 ) );

  analogWrite( RED, 0);
  analogWrite( GREEN, 255);
  analogWrite( BLUE, 0 );
tone(BUZZER, NOTE_F6, 2000);
  gameState = BUTTON_STAGE;  
}

void buttonStage() {

  int buttonsPressed = 0;

  while( buttonsPressed == 0 ) {
    if( digitalRead( LEFT_BUTTON ) == LOW ) {
      digitalWrite( LEFT_WIN, HIGH );
      buttonsPressed = 1;
    }

    if( digitalRead( RIGHT_BUTTON ) == LOW ) {
      digitalWrite( RIGHT_WIN, HIGH );
      buttonsPressed = 1;
    }
  }
  gameState = RESULTS_STAGE;
}

void resultsStage() {
  int song = 0;
  while( song == 0 ) {
    // Let's stay between G6 and G4
    noTone( BUZZER );
    tone( BUZZER, NOTE_D6, 250 );
    delay( 250 );
    noTone( BUZZER );
    tone( BUZZER, NOTE_E6, 250 );
    delay( 250 );
    noTone( BUZZER );
    tone( BUZZER, 1380, 250 );
    delay( 250 );
    noTone( BUZZER );
    tone( BUZZER, NOTE_E6, 250 );
    delay( 250 );
    noTone( BUZZER );
    tone( BUZZER, NOTE_D6, 250 );
    delay( 250 );
    noTone( BUZZER );
    tone( BUZZER, NOTE_C6, 750 );
    delay( 400 );
    noTone( BUZZER );
    tone( BUZZER, NOTE_G6, 1000 );
    delay( 7000 );
    noTone( BUZZER );
    song = 1;
  }
  gameState = END_GAME;
}




