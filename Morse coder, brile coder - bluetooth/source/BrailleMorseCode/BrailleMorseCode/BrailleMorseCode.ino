/*  

  Kodi për koduesin Brile, dhe Morse, me Arduino Pro Mini 8Mhz 3V3.

  Mërgim Halimi ( m.halimi@live.com, +377 (0) 45 590 509 )

*/

// // // // // Hardware : PS/2 Keyboard (Not working); Software : Brile chars (LED's) not staying on, but blinking. (Solved with WhileLoop, not tested with keyboard)

#include <PS2Keyboard.h> //Keyboard library
#define latchPin A1 //74HC595
#define clockPin A0 //74HC595
#define dataPin A2  //74HC595

const int DataPin = 8; //Keyboard
const int IRQpin =  3; //Keyboard

PS2Keyboard keyboard; //Keyboard object

char Shkronja; //Variable to store the incoming key

byte i; byte j; //Saving bits in a Matrix for 74HC595
byte dataToSend; //74HC595
byte *ledData; //Whitch LED's on (Array storing)
int *MorseCode; //Morse Coding characters

int Morse[] = {10, 11, 12}; //Pika, Viza, Hapsira ; ; ; ; ; Pika = 0, Viza = 1, Hapsira = 2. (Pin 10, 11, 12)
int ButoniMorse = 0;   // If 1, use morse, else, don't use
int PinMorse = 6;      // Where Morse button is connected
int ButoniBraille = 0; // If 1, use braille, else, don't use
int PinBraille = 7;    // Where Braille button is connected
int Buzzer = A3;        // Where the buzzer is connected

int Pika, Viza;

void setup() { Serial.begin(9600);
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
  pinMode(Buzzer, OUTPUT);
  pinMode(ButoniMorse, INPUT_PULLUP);
  pinMode(ButoniBraille, INPUT_PULLUP);
  keyboard.begin(DataPin, IRQpin);
}

void loop() {
  ButoniMorse = digitalRead(PinMorse); ButoniBraille = digitalRead(PinBraille);

    if ( keyboard.available() ) { Shkronja = keyboard.read();
      if (ButoniBraille == LOW) { KarakteretB (); delay(700); } //Thirr nenprogramin ku jane te ruajtura karakteret ne Braille

      if (ButoniMorse == LOW) { KarakteretM (); delay(700); }//Thirr nenprogramin ku jane te ruajtura karakteret ne Morse
    }
    if ( Serial.available() ) { Shkronja = Serial.read(); Serial.write(Shkronja);   
      if (ButoniBraille == LOW) { KarakteretB (); delay(700); } //Thirr nenprogramin ku jane te ruajtura karakteret ne Braille

      if (ButoniMorse == LOW) { KarakteretM (); delay(700); }//Thirr nenprogramin ku jane te ruajtura karakteret ne Morse   
    }
}

void KarakteretB () { int Ndezur = 0, NdezurMax = 700;
    switch (Shkronja) {
        case 'A': { byte ledData[] = {02, 00, 04, 00};
          while( Ndezur <= NdezurMax ) {
             for (i=0;i<4;i++){
                  byte dataToSend = (1 << (i+4)) | (15 & ~ledData[i]);
                  digitalWrite(latchPin, LOW); shiftOut(dataPin, clockPin, LSBFIRST, dataToSend); digitalWrite(latchPin, HIGH); } Ndezur++; } } break; //Shkronja A e madhe
        case 'B': { byte ledData[] = {02, 02, 04, 00};
          while( Ndezur <= NdezurMax ) {
             for (i=0;i<4;i++){
                  byte dataToSend = (1 << (i+4)) | (15 & ~ledData[i]);
                  digitalWrite(latchPin, LOW); shiftOut(dataPin, clockPin, LSBFIRST, dataToSend); digitalWrite(latchPin, HIGH); } Ndezur++; } } break; //Shkronja B e madhe
        case 'C': { byte ledData[] = {03, 00, 04, 00};
          while( Ndezur <= NdezurMax ) {
             for (i=0;i<4;i++){
                  byte dataToSend = (1 << (i+4)) | (15 & ~ledData[i]);
                  digitalWrite(latchPin, LOW); shiftOut(dataPin, clockPin, LSBFIRST, dataToSend); digitalWrite(latchPin, HIGH); } Ndezur++; } } break; //Shkronja C e madhe
        case 'D': { byte ledData[] = {03, 01, 04, 00};
          while( Ndezur <= NdezurMax ) {
             for (i=0;i<4;i++){
                  byte dataToSend = (1 << (i+4)) | (15 & ~ledData[i]);
                  digitalWrite(latchPin, LOW); shiftOut(dataPin, clockPin, LSBFIRST, dataToSend); digitalWrite(latchPin, HIGH); } Ndezur++; } } break; //Shkronja D e madhe
        case 'E': { byte ledData[] = {02, 01, 04, 00};
          while( Ndezur <= NdezurMax ) {
             for (i=0;i<4;i++){
                  byte dataToSend = (1 << (i+4)) | (15 & ~ledData[i]);
                  digitalWrite(latchPin, LOW); shiftOut(dataPin, clockPin, LSBFIRST, dataToSend); digitalWrite(latchPin, HIGH); } Ndezur++; } } break; //Shkronja E e madhe
        case 'F': { byte ledData[] = {03, 02, 04, 00};
          while( Ndezur <= NdezurMax ) {
             for (i=0;i<4;i++){
                  byte dataToSend = (1 << (i+4)) | (15 & ~ledData[i]);
                  digitalWrite(latchPin, LOW); shiftOut(dataPin, clockPin, LSBFIRST, dataToSend); digitalWrite(latchPin, HIGH); } Ndezur++; } } break; //Shkronja F e madhe
        case 'G': { byte ledData[] = {03, 03, 04, 00};
          while( Ndezur <= NdezurMax ) {
             for (i=0;i<4;i++){
                  byte dataToSend = (1 << (i+4)) | (15 & ~ledData[i]);
                  digitalWrite(latchPin, LOW); shiftOut(dataPin, clockPin, LSBFIRST, dataToSend); digitalWrite(latchPin, HIGH); } Ndezur++; } } break; //Shkronja G e madhe
        case 'H': { byte ledData[] = {02, 03, 04, 00};
          while( Ndezur <= NdezurMax ) {
             for (i=0;i<4;i++){
                  byte dataToSend = (1 << (i+4)) | (15 & ~ledData[i]);
                  digitalWrite(latchPin, LOW); shiftOut(dataPin, clockPin, LSBFIRST, dataToSend); digitalWrite(latchPin, HIGH); } Ndezur++; } } break; //Shkronja H e madhe
        case 'I': { byte ledData[] = {01, 02, 04, 00};
          while( Ndezur <= NdezurMax ) {
             for (i=0;i<4;i++){
                  byte dataToSend = (1 << (i+4)) | (15 & ~ledData[i]);
                  digitalWrite(latchPin, LOW); shiftOut(dataPin, clockPin, LSBFIRST, dataToSend); digitalWrite(latchPin, HIGH); } Ndezur++; } } break; //Shkronja I e madhe
        case 'J': { byte ledData[] = {01, 03, 04, 00};
          while( Ndezur <= NdezurMax ) {
             for (i=0;i<4;i++){
                  byte dataToSend = (1 << (i+4)) | (15 & ~ledData[i]);
                  digitalWrite(latchPin, LOW); shiftOut(dataPin, clockPin, LSBFIRST, dataToSend); digitalWrite(latchPin, HIGH); } Ndezur++; } } break; //Shkronja J e madhe
        case 'K': { byte ledData[] = {02, 00, 06, 00};
          while( Ndezur <= NdezurMax ) {
             for (i=0;i<4;i++){
                  byte dataToSend = (1 << (i+4)) | (15 & ~ledData[i]);
                  digitalWrite(latchPin, LOW); shiftOut(dataPin, clockPin, LSBFIRST, dataToSend); digitalWrite(latchPin, HIGH); } Ndezur++; } } break; //Shkronja K e madhe
        case 'L': { byte ledData[] = {02, 02, 06, 00};
          while( Ndezur <= NdezurMax ) {
             for (i=0;i<4;i++){
                  byte dataToSend = (1 << (i+4)) | (15 & ~ledData[i]);
                  digitalWrite(latchPin, LOW); shiftOut(dataPin, clockPin, LSBFIRST, dataToSend); digitalWrite(latchPin, HIGH); } Ndezur++; } } break; //Shkronja L e madhe
        case 'M': { byte ledData[] = {03, 00, 06, 00};
          while( Ndezur <= NdezurMax ) {
             for (i=0;i<4;i++){
                  byte dataToSend = (1 << (i+4)) | (15 & ~ledData[i]);
                  digitalWrite(latchPin, LOW); shiftOut(dataPin, clockPin, LSBFIRST, dataToSend); digitalWrite(latchPin, HIGH); } Ndezur++; } } break; //Shkronja M e madhe
        case 'N': { byte ledData[] = {03, 01, 06, 00};
          while( Ndezur <= NdezurMax ) {
             for (i=0;i<4;i++){
                  byte dataToSend = (1 << (i+4)) | (15 & ~ledData[i]);
                  digitalWrite(latchPin, LOW); shiftOut(dataPin, clockPin, LSBFIRST, dataToSend); digitalWrite(latchPin, HIGH); } Ndezur++; } } break; //Shkronja N e madhe
        case 'O': { byte ledData[] = {02, 01, 06, 00};
          while( Ndezur <= NdezurMax ) {
             for (i=0;i<4;i++){
                  byte dataToSend = (1 << (i+4)) | (15 & ~ledData[i]);
                  digitalWrite(latchPin, LOW); shiftOut(dataPin, clockPin, LSBFIRST, dataToSend); digitalWrite(latchPin, HIGH); } Ndezur++; } } break; //Shkronja O e madhe
        case 'P': { byte ledData[] = {03, 02, 06, 00};
          while( Ndezur <= NdezurMax ) {
             for (i=0;i<4;i++){
                  byte dataToSend = (1 << (i+4)) | (15 & ~ledData[i]);
                  digitalWrite(latchPin, LOW); shiftOut(dataPin, clockPin, LSBFIRST, dataToSend); digitalWrite(latchPin, HIGH); } Ndezur++; } } break; //Shkronja P e madhe
        case 'Q': { byte ledData[] = {03, 03, 06, 00};
          while( Ndezur <= NdezurMax ) {
             for (i=0;i<4;i++){
                  byte dataToSend = (1 << (i+4)) | (15 & ~ledData[i]);
                  digitalWrite(latchPin, LOW); shiftOut(dataPin, clockPin, LSBFIRST, dataToSend); digitalWrite(latchPin, HIGH); } Ndezur++; } } break; //Shkronja Q e madhe
        case 'R': { byte ledData[] = {02, 03, 06, 00};
          while( Ndezur <= NdezurMax ) {
             for (i=0;i<4;i++){
                  byte dataToSend = (1 << (i+4)) | (15 & ~ledData[i]);
                  digitalWrite(latchPin, LOW); shiftOut(dataPin, clockPin, LSBFIRST, dataToSend); digitalWrite(latchPin, HIGH); } Ndezur++; } } break; //Shkronja R e madhe
        case 'S': { byte ledData[] = {01, 02, 06, 00};
          while( Ndezur <= NdezurMax ) {
             for (i=0;i<4;i++){
                  byte dataToSend = (1 << (i+4)) | (15 & ~ledData[i]);
                  digitalWrite(latchPin, LOW); shiftOut(dataPin, clockPin, LSBFIRST, dataToSend); digitalWrite(latchPin, HIGH); } Ndezur++; } } break; //Shkronja S e madhe
        case 'T': { byte ledData[] = {01, 03, 06, 00};
          while( Ndezur <= NdezurMax ) {
             for (i=0;i<4;i++){
                  byte dataToSend = (1 << (i+4)) | (15 & ~ledData[i]);
                  digitalWrite(latchPin, LOW); shiftOut(dataPin, clockPin, LSBFIRST, dataToSend); digitalWrite(latchPin, HIGH); } Ndezur++; } } break; //Shkronja T e madhe
        case 'U': { byte ledData[] = {02, 00, 07, 00};
          while( Ndezur <= NdezurMax ) {
             for (i=0;i<4;i++){
                  byte dataToSend = (1 << (i+4)) | (15 & ~ledData[i]);
                  digitalWrite(latchPin, LOW); shiftOut(dataPin, clockPin, LSBFIRST, dataToSend); digitalWrite(latchPin, HIGH); } Ndezur++; } } break; //Shkronja U e madhe
        case 'V': { byte ledData[] = {02, 02, 07, 00};
          while( Ndezur <= NdezurMax ) {
             for (i=0;i<4;i++){
                  byte dataToSend = (1 << (i+4)) | (15 & ~ledData[i]);
                  digitalWrite(latchPin, LOW); shiftOut(dataPin, clockPin, LSBFIRST, dataToSend); digitalWrite(latchPin, HIGH); } Ndezur++; } } break; //Shkronja V e madhe
        case 'W': { byte ledData[] = {01, 03, 05, 00};
          while( Ndezur <= NdezurMax ) {
             for (i=0;i<4;i++){
                  byte dataToSend = (1 << (i+4)) | (15 & ~ledData[i]);
                  digitalWrite(latchPin, LOW); shiftOut(dataPin, clockPin, LSBFIRST, dataToSend); digitalWrite(latchPin, HIGH); } Ndezur++; } } break; //Shkronja W e madhe
        case 'X': { byte ledData[] = {03, 00, 07, 00};
          while( Ndezur <= NdezurMax ) {
             for (i=0;i<4;i++){
                  byte dataToSend = (1 << (i+4)) | (15 & ~ledData[i]);
                  digitalWrite(latchPin, LOW); shiftOut(dataPin, clockPin, LSBFIRST, dataToSend); digitalWrite(latchPin, HIGH); } Ndezur++; } } break; //Shkronja X e madhe
        case 'Y': { byte ledData[] = {03, 01, 07, 00};
          while( Ndezur <= NdezurMax ) {
             for (i=0;i<4;i++){
                  byte dataToSend = (1 << (i+4)) | (15 & ~ledData[i]);
                  digitalWrite(latchPin, LOW); shiftOut(dataPin, clockPin, LSBFIRST, dataToSend); digitalWrite(latchPin, HIGH); } Ndezur++; } } break; //Shkronja Y e madhe
        case 'Z': { byte ledData[] = {02, 01, 07, 00};
          while( Ndezur <= NdezurMax ) {
             for (i=0;i<4;i++){
                  byte dataToSend = (1 << (i+4)) | (15 & ~ledData[i]);
                  digitalWrite(latchPin, LOW); shiftOut(dataPin, clockPin, LSBFIRST, dataToSend); digitalWrite(latchPin, HIGH); } Ndezur++; } } break; //Shkronja Z e madhe
        case 'a': { byte ledData[] = {02, 04, 04, 00};
          while( Ndezur <= NdezurMax ) {
             for (i=0;i<4;i++){
                  byte dataToSend = (1 << (i+4)) | (15 & ~ledData[i]);
                  digitalWrite(latchPin, LOW); shiftOut(dataPin, clockPin, LSBFIRST, dataToSend); digitalWrite(latchPin, HIGH); } Ndezur++; } } break; //Shkronja A e vogel
        case 'b': { byte ledData[] = {02, 06, 04, 00};
          while( Ndezur <= NdezurMax ) {
             for (i=0;i<4;i++){
                  byte dataToSend = (1 << (i+4)) | (15 & ~ledData[i]);
                  digitalWrite(latchPin, LOW); shiftOut(dataPin, clockPin, LSBFIRST, dataToSend); digitalWrite(latchPin, HIGH); } Ndezur++; } } break; //Shkronja B e vogel
        case 'c': { byte ledData[] = {03, 04, 04, 00};
          while( Ndezur <= NdezurMax ) {
             for (i=0;i<4;i++){
                  byte dataToSend = (1 << (i+4)) | (15 & ~ledData[i]);
                  digitalWrite(latchPin, LOW); shiftOut(dataPin, clockPin, LSBFIRST, dataToSend); digitalWrite(latchPin, HIGH); } Ndezur++; } } break; //Shkronja C e vogel
        case 'd': { byte ledData[] = {03, 05, 04, 00};
          while( Ndezur <= NdezurMax ) {
             for (i=0;i<4;i++){
                  byte dataToSend = (1 << (i+4)) | (15 & ~ledData[i]);
                  digitalWrite(latchPin, LOW); shiftOut(dataPin, clockPin, LSBFIRST, dataToSend); digitalWrite(latchPin, HIGH); } Ndezur++; } } break; //Shkronja D e vogel
        case 'e': { byte ledData[] = {02, 05, 04, 00};
          while( Ndezur <= NdezurMax ) {
             for (i=0;i<4;i++){
                  byte dataToSend = (1 << (i+4)) | (15 & ~ledData[i]);
                  digitalWrite(latchPin, LOW); shiftOut(dataPin, clockPin, LSBFIRST, dataToSend); digitalWrite(latchPin, HIGH); } Ndezur++; } } break; //Shkronja E e vogel
        case 'f': { byte ledData[] = {03, 06, 04, 00};
          while( Ndezur <= NdezurMax ) {
             for (i=0;i<4;i++){
                  byte dataToSend = (1 << (i+4)) | (15 & ~ledData[i]);
                  digitalWrite(latchPin, LOW); shiftOut(dataPin, clockPin, LSBFIRST, dataToSend); digitalWrite(latchPin, HIGH); } Ndezur++; } } break; //Shkronja F e vogel
        case 'g': { byte ledData[] = {03, 07, 04, 00};
          while( Ndezur <= NdezurMax ) {
             for (i=0;i<4;i++){
                  byte dataToSend = (1 << (i+4)) | (15 & ~ledData[i]);
                  digitalWrite(latchPin, LOW); shiftOut(dataPin, clockPin, LSBFIRST, dataToSend); digitalWrite(latchPin, HIGH); } Ndezur++; } } break; //Shkronja G e vogel
        case 'h': { byte ledData[] = {02, 07, 04, 00};
          while( Ndezur <= NdezurMax ) {
             for (i=0;i<4;i++){
                  byte dataToSend = (1 << (i+4)) | (15 & ~ledData[i]);
                  digitalWrite(latchPin, LOW); shiftOut(dataPin, clockPin, LSBFIRST, dataToSend); digitalWrite(latchPin, HIGH); } Ndezur++; } } break; //Shkronja H e vogel
        case 'i': { byte ledData[] = {01, 06, 04, 00};
          while( Ndezur <= NdezurMax ) {
             for (i=0;i<4;i++){
                  byte dataToSend = (1 << (i+4)) | (15 & ~ledData[i]);
                  digitalWrite(latchPin, LOW); shiftOut(dataPin, clockPin, LSBFIRST, dataToSend); digitalWrite(latchPin, HIGH); } Ndezur++; } } break; //Shkronja I e vogel
        case 'j': { byte ledData[] = {01, 07, 04, 00};
          while( Ndezur <= NdezurMax ) {
             for (i=0;i<4;i++){
                  byte dataToSend = (1 << (i+4)) | (15 & ~ledData[i]);
                  digitalWrite(latchPin, LOW); shiftOut(dataPin, clockPin, LSBFIRST, dataToSend); digitalWrite(latchPin, HIGH); } Ndezur++; } } break; //Shkronja J e vogel
        case 'k': { byte ledData[] = {02, 04, 06, 00};
          while( Ndezur <= NdezurMax ) {
             for (i=0;i<4;i++){
                  byte dataToSend = (1 << (i+4)) | (15 & ~ledData[i]);
                  digitalWrite(latchPin, LOW); shiftOut(dataPin, clockPin, LSBFIRST, dataToSend); digitalWrite(latchPin, HIGH); } Ndezur++; } } break; //Shkronja K e vogel
        case 'l': { byte ledData[] = {02, 06, 06, 00};
          while( Ndezur <= NdezurMax ) {
             for (i=0;i<4;i++){
                  byte dataToSend = (1 << (i+4)) | (15 & ~ledData[i]);
                  digitalWrite(latchPin, LOW); shiftOut(dataPin, clockPin, LSBFIRST, dataToSend); digitalWrite(latchPin, HIGH); } Ndezur++; } } break; //Shkronja L e vogel
        case 'm': { byte ledData[] = {03, 04, 06, 00};
          while( Ndezur <= NdezurMax ) {
             for (i=0;i<4;i++){
                  byte dataToSend = (1 << (i+4)) | (15 & ~ledData[i]);
                  digitalWrite(latchPin, LOW); shiftOut(dataPin, clockPin, LSBFIRST, dataToSend); digitalWrite(latchPin, HIGH); } Ndezur++; } } break; //Shkronja M e vogel
        case 'n': { byte ledData[] = {03, 05, 06, 00};
          while( Ndezur <= NdezurMax ) {
             for (i=0;i<4;i++){
                  byte dataToSend = (1 << (i+4)) | (15 & ~ledData[i]);
                  digitalWrite(latchPin, LOW); shiftOut(dataPin, clockPin, LSBFIRST, dataToSend); digitalWrite(latchPin, HIGH); } Ndezur++; } } break; //Shkronja N e vogel
        case 'o': { byte ledData[] = {02, 05, 06, 00};
          while( Ndezur <= NdezurMax ) {
             for (i=0;i<4;i++){
                  byte dataToSend = (1 << (i+4)) | (15 & ~ledData[i]);
                  digitalWrite(latchPin, LOW); shiftOut(dataPin, clockPin, LSBFIRST, dataToSend); digitalWrite(latchPin, HIGH); } Ndezur++; } } break; //Shkronja O e vogel
        case 'p': { byte ledData[] = {03, 06, 06, 00};
          while( Ndezur <= NdezurMax ) {
             for (i=0;i<4;i++){
                  byte dataToSend = (1 << (i+4)) | (15 & ~ledData[i]);
                  digitalWrite(latchPin, LOW); shiftOut(dataPin, clockPin, LSBFIRST, dataToSend); digitalWrite(latchPin, HIGH); } Ndezur++; } } break; //Shkronja P e vogel
        case 'q': { byte ledData[] = {03, 07, 06, 00};
          while( Ndezur <= NdezurMax ) {
             for (i=0;i<4;i++){
                  byte dataToSend = (1 << (i+4)) | (15 & ~ledData[i]);
                  digitalWrite(latchPin, LOW); shiftOut(dataPin, clockPin, LSBFIRST, dataToSend); digitalWrite(latchPin, HIGH); } Ndezur++; } } break; //Shkronja Q e vogel
        case 'r': { byte ledData[] = {02, 07, 06, 00};
          while( Ndezur <= NdezurMax ) {
             for (i=0;i<4;i++){
                  byte dataToSend = (1 << (i+4)) | (15 & ~ledData[i]);
                  digitalWrite(latchPin, LOW); shiftOut(dataPin, clockPin, LSBFIRST, dataToSend); digitalWrite(latchPin, HIGH); } Ndezur++; } } break; //Shkronja R e vogel
        case 's': { byte ledData[] = {01, 06, 06, 00};
          while( Ndezur <= NdezurMax ) {
             for (i=0;i<4;i++){
                  byte dataToSend = (1 << (i+4)) | (15 & ~ledData[i]);
                  digitalWrite(latchPin, LOW); shiftOut(dataPin, clockPin, LSBFIRST, dataToSend); digitalWrite(latchPin, HIGH); } Ndezur++; } } break; //Shkronja S e vogel
        case 't': { byte ledData[] = {01, 07, 06, 00};
          while( Ndezur <= NdezurMax ) {
             for (i=0;i<4;i++){
                  byte dataToSend = (1 << (i+4)) | (15 & ~ledData[i]);
                  digitalWrite(latchPin, LOW); shiftOut(dataPin, clockPin, LSBFIRST, dataToSend); digitalWrite(latchPin, HIGH); } Ndezur++; } } break; //Shkronja T e vogel
        case 'u': { byte ledData[] = {02, 04, 07, 00};
          while( Ndezur <= NdezurMax ) {
             for (i=0;i<4;i++){
                  byte dataToSend = (1 << (i+4)) | (15 & ~ledData[i]);
                  digitalWrite(latchPin, LOW); shiftOut(dataPin, clockPin, LSBFIRST, dataToSend); digitalWrite(latchPin, HIGH); } Ndezur++; } } break; //Shkronja U e vogel
        case 'v': { byte ledData[] = {02, 06, 07, 00};
          while( Ndezur <= NdezurMax ) {
             for (i=0;i<4;i++){
                  byte dataToSend = (1 << (i+4)) | (15 & ~ledData[i]);
                  digitalWrite(latchPin, LOW); shiftOut(dataPin, clockPin, LSBFIRST, dataToSend); digitalWrite(latchPin, HIGH); } Ndezur++; } } break; //Shkronja V e vogel
        case 'w': { byte ledData[] = {01, 07, 05, 00};
          while( Ndezur <= NdezurMax ) {
             for (i=0;i<4;i++){
                  byte dataToSend = (1 << (i+4)) | (15 & ~ledData[i]);
                  digitalWrite(latchPin, LOW); shiftOut(dataPin, clockPin, LSBFIRST, dataToSend); digitalWrite(latchPin, HIGH); } Ndezur++; } } break; //Shkronja W e vogel
        case 'x': { byte ledData[] = {03, 04, 07, 00};
          while( Ndezur <= NdezurMax ) {
             for (i=0;i<4;i++){
                  byte dataToSend = (1 << (i+4)) | (15 & ~ledData[i]);
                  digitalWrite(latchPin, LOW); shiftOut(dataPin, clockPin, LSBFIRST, dataToSend); digitalWrite(latchPin, HIGH); } Ndezur++; } } break; //Shkronja X e vogel
        case 'y': { byte ledData[] = {03, 05, 07, 00};
          while( Ndezur <= NdezurMax ) {
             for (i=0;i<4;i++){
                  byte dataToSend = (1 << (i+4)) | (15 & ~ledData[i]);
                  digitalWrite(latchPin, LOW); shiftOut(dataPin, clockPin, LSBFIRST, dataToSend); digitalWrite(latchPin, HIGH); } Ndezur++; } } break; //Shkronja Y e vogel
        case 'z': { byte ledData[] = {02, 05, 07, 00};
          while( Ndezur <= NdezurMax ) {
             for (i=0;i<4;i++){
                  byte dataToSend = (1 << (i+4)) | (15 & ~ledData[i]);
                  digitalWrite(latchPin, LOW); shiftOut(dataPin, clockPin, LSBFIRST, dataToSend); digitalWrite(latchPin, HIGH); } Ndezur++; } } break; //Shkronja Z e vogel
        case '0': { byte ledData[] = {05, 07, 12, 00};
          while( Ndezur <= NdezurMax ) {
             for (i=0;i<4;i++){
                  byte dataToSend = (1 << (i+4)) | (15 & ~ledData[i]);
                  digitalWrite(latchPin, LOW); shiftOut(dataPin, clockPin, LSBFIRST, dataToSend); digitalWrite(latchPin, HIGH); } Ndezur++; } } break; //Numri 0
        case '1': { byte ledData[] = {06, 04, 12, 00};
          while( Ndezur <= NdezurMax ) {
             for (i=0;i<4;i++){
                  byte dataToSend = (1 << (i+4)) | (15 & ~ledData[i]);
                  digitalWrite(latchPin, LOW); shiftOut(dataPin, clockPin, LSBFIRST, dataToSend); digitalWrite(latchPin, HIGH); } Ndezur++; } } break; //Numri 1
        case '2': { byte ledData[] = {06, 06, 12, 00};
          while( Ndezur <= NdezurMax ) {
             for (i=0;i<4;i++){
                  byte dataToSend = (1 << (i+4)) | (15 & ~ledData[i]);
                  digitalWrite(latchPin, LOW); shiftOut(dataPin, clockPin, LSBFIRST, dataToSend); digitalWrite(latchPin, HIGH); } Ndezur++; } } break; //Numri 2
        case '3': { byte ledData[] = {07, 04, 12, 00};
          while( Ndezur <= NdezurMax ) {
             for (i=0;i<4;i++){
                  byte dataToSend = (1 << (i+4)) | (15 & ~ledData[i]);
                  digitalWrite(latchPin, LOW); shiftOut(dataPin, clockPin, LSBFIRST, dataToSend); digitalWrite(latchPin, HIGH); } Ndezur++; } } break; //Numri 3
        case '4': { byte ledData[] = {07, 05, 12, 00};
          while( Ndezur <= NdezurMax ) {
             for (i=0;i<4;i++){
                  byte dataToSend = (1 << (i+4)) | (15 & ~ledData[i]);
                  digitalWrite(latchPin, LOW); shiftOut(dataPin, clockPin, LSBFIRST, dataToSend); digitalWrite(latchPin, HIGH); } Ndezur++; } } break; //Numri 4
        case '5': { byte ledData[] = {06, 05, 12, 00};
          while( Ndezur <= NdezurMax ) {
             for (i=0;i<4;i++){
                  byte dataToSend = (1 << (i+4)) | (15 & ~ledData[i]);
                  digitalWrite(latchPin, LOW); shiftOut(dataPin, clockPin, LSBFIRST, dataToSend); digitalWrite(latchPin, HIGH); } Ndezur++; } } break; //Numri 5
        case '6': { byte ledData[] = {07, 06, 12, 00};
          while( Ndezur <= NdezurMax ) {
             for (i=0;i<4;i++){
                  byte dataToSend = (1 << (i+4)) | (15 & ~ledData[i]);
                  digitalWrite(latchPin, LOW); shiftOut(dataPin, clockPin, LSBFIRST, dataToSend); digitalWrite(latchPin, HIGH); } Ndezur++; } } break; //Numri 6
        case '7': { byte ledData[] = {07, 07, 12, 00};
          while( Ndezur <= NdezurMax ) {
             for (i=0;i<4;i++){
                  byte dataToSend = (1 << (i+4)) | (15 & ~ledData[i]);
                  digitalWrite(latchPin, LOW); shiftOut(dataPin, clockPin, LSBFIRST, dataToSend); digitalWrite(latchPin, HIGH); } Ndezur++; } } break; //Numri 7
        case '8': { byte ledData[] = {06, 07, 12, 00};
          while( Ndezur <= NdezurMax ) {
             for (i=0;i<4;i++){
                  byte dataToSend = (1 << (i+4)) | (15 & ~ledData[i]);
                  digitalWrite(latchPin, LOW); shiftOut(dataPin, clockPin, LSBFIRST, dataToSend); digitalWrite(latchPin, HIGH); } Ndezur++; } } break; //Numri 8
        case '9': { byte ledData[] = {05, 06, 12, 00};
          while( Ndezur <= NdezurMax ) {
             for (i=0;i<4;i++){
                  byte dataToSend = (1 << (i+4)) | (15 & ~ledData[i]);
                  digitalWrite(latchPin, LOW); shiftOut(dataPin, clockPin, LSBFIRST, dataToSend); digitalWrite(latchPin, HIGH); } Ndezur++; } } break; //Numri 9
        case '.': { byte ledData[] = {00, 03, 01, 00};
          while( Ndezur <= NdezurMax ) {
             for (i=0;i<4;i++){
                  byte dataToSend = (1 << (i+4)) | (15 & ~ledData[i]);
                  digitalWrite(latchPin, LOW); shiftOut(dataPin, clockPin, LSBFIRST, dataToSend); digitalWrite(latchPin, HIGH); } Ndezur++; } } break; //Pika
        case ',': { byte ledData[] = {00, 02, 00, 00};
          while( Ndezur <= NdezurMax ) {
             for (i=0;i<4;i++){
                  byte dataToSend = (1 << (i+4)) | (15 & ~ledData[i]);
                  digitalWrite(latchPin, LOW); shiftOut(dataPin, clockPin, LSBFIRST, dataToSend); digitalWrite(latchPin, HIGH); } Ndezur++; } } break; //Presje
        case ';': { byte ledData[] = {00, 02, 02, 00};
          while( Ndezur <= NdezurMax ) {
             for (i=0;i<4;i++){
                  byte dataToSend = (1 << (i+4)) | (15 & ~ledData[i]);
                  digitalWrite(latchPin, LOW); shiftOut(dataPin, clockPin, LSBFIRST, dataToSend); digitalWrite(latchPin, HIGH); } Ndezur++; } } break; //Pikpresje
        case ':': { byte ledData[] = {00, 03, 00, 00};
          while( Ndezur <= NdezurMax ) {
             for (i=0;i<4;i++){
                  byte dataToSend = (1 << (i+4)) | (15 & ~ledData[i]);
                  digitalWrite(latchPin, LOW); shiftOut(dataPin, clockPin, LSBFIRST, dataToSend); digitalWrite(latchPin, HIGH); } Ndezur++; } } break; //Dypika
        case '/': { byte ledData[] = {01, 00, 02, 00};
          while( Ndezur <= NdezurMax ) {
             for (i=0;i<4;i++){
                  byte dataToSend = (1 << (i+4)) | (15 & ~ledData[i]);
                  digitalWrite(latchPin, LOW); shiftOut(dataPin, clockPin, LSBFIRST, dataToSend); digitalWrite(latchPin, HIGH); } Ndezur++; } } break; //Slash
        case '?': { byte ledData[] = {00, 02, 03, 00};
          while( Ndezur <= NdezurMax ) {
             for (i=0;i<4;i++){
                  byte dataToSend = (1 << (i+4)) | (15 & ~ledData[i]);
                  digitalWrite(latchPin, LOW); shiftOut(dataPin, clockPin, LSBFIRST, dataToSend); digitalWrite(latchPin, HIGH); } Ndezur++; } } break; //Pikpyetje
        case '!': { byte ledData[] = {00, 03, 02, 00};
          while( Ndezur <= NdezurMax ) {
             for (i=0;i<4;i++){
                  byte dataToSend = (1 << (i+4)) | (15 & ~ledData[i]);
                  digitalWrite(latchPin, LOW); shiftOut(dataPin, clockPin, LSBFIRST, dataToSend); digitalWrite(latchPin, HIGH); } Ndezur++; } } break; //Pikquditese
        case '@': { byte ledData[] = {01, 01, 02, 00};
          while( Ndezur <= NdezurMax ) {
             for (i=0;i<4;i++){
                  byte dataToSend = (1 << (i+4)) | (15 & ~ledData[i]);
                  digitalWrite(latchPin, LOW); shiftOut(dataPin, clockPin, LSBFIRST, dataToSend); digitalWrite(latchPin, HIGH); } Ndezur++; } } break; //At
        case '#': { byte ledData[] = {01, 01, 03, 00};
          while( Ndezur <= NdezurMax ) {
             for (i=0;i<4;i++){
                  byte dataToSend = (1 << (i+4)) | (15 & ~ledData[i]);
                  digitalWrite(latchPin, LOW); shiftOut(dataPin, clockPin, LSBFIRST, dataToSend); digitalWrite(latchPin, HIGH); } Ndezur++; } } break; //Thurje
        case '+': { byte ledData[] = {00, 03, 02, 00};
          while( Ndezur <= NdezurMax ) {
             for (i=0;i<4;i++){
                  byte dataToSend = (1 << (i+4)) | (15 & ~ledData[i]);
                  digitalWrite(latchPin, LOW); shiftOut(dataPin, clockPin, LSBFIRST, dataToSend); digitalWrite(latchPin, HIGH); } Ndezur++; } } break; //Plus
        case '-': { byte ledData[] = {00, 03, 00, 00};
          while( Ndezur <= NdezurMax ) {
             for (i=0;i<4;i++){
                  byte dataToSend = (1 << (i+4)) | (15 & ~ledData[i]);
                  digitalWrite(latchPin, LOW); shiftOut(dataPin, clockPin, LSBFIRST, dataToSend); digitalWrite(latchPin, HIGH); } Ndezur++; } } break; //Minus
        case '*': { byte ledData[] = {00, 01, 02, 00};
          while( Ndezur <= NdezurMax ) {
             for (i=0;i<4;i++){
                  byte dataToSend = (1 << (i+4)) | (15 & ~ledData[i]);
                  digitalWrite(latchPin, LOW); shiftOut(dataPin, clockPin, LSBFIRST, dataToSend); digitalWrite(latchPin, HIGH); } Ndezur++; } } break; //Yll
        case '"': { byte ledData[] = {00, 02, 03, 00};
          while( Ndezur <= NdezurMax ) {
             for (i=0;i<4;i++){
                  byte dataToSend = (1 << (i+4)) | (15 & ~ledData[i]);
                  digitalWrite(latchPin, LOW); shiftOut(dataPin, clockPin, LSBFIRST, dataToSend); digitalWrite(latchPin, HIGH); } Ndezur++; } } break; //Thojza hapur
        case '<': { byte ledData[] = {02, 02, 01, 00};
          while( Ndezur <= NdezurMax ) {
             for (i=0;i<4;i++){
                  byte dataToSend = (1 << (i+4)) | (15 & ~ledData[i]);
                  digitalWrite(latchPin, LOW); shiftOut(dataPin, clockPin, LSBFIRST, dataToSend); digitalWrite(latchPin, HIGH); } Ndezur++; } } break; //Ma e vogel
        case '>': { byte ledData[] = {01, 01, 02, 00};
          while( Ndezur <= NdezurMax ) {
             for (i=0;i<4;i++){
                  byte dataToSend = (1 << (i+4)) | (15 & ~ledData[i]);
                  digitalWrite(latchPin, LOW); shiftOut(dataPin, clockPin, LSBFIRST, dataToSend); digitalWrite(latchPin, HIGH); } Ndezur++; } } break; //Ma e madhe
        case '(': { byte ledData[] = {00, 03, 03, 00};
          while( Ndezur <= NdezurMax ) {
             for (i=0;i<4;i++){
                  byte dataToSend = (1 << (i+4)) | (15 & ~ledData[i]);
                  digitalWrite(latchPin, LOW); shiftOut(dataPin, clockPin, LSBFIRST, dataToSend); digitalWrite(latchPin, HIGH); } Ndezur++; } } break; //Hape kllapen
        case ')': { byte ledData[] = {00, 03, 03, 00};
          while( Ndezur <= NdezurMax ) {
             for (i=0;i<4;i++){
                  byte dataToSend = (1 << (i+4)) | (15 & ~ledData[i]);
                  digitalWrite(latchPin, LOW); shiftOut(dataPin, clockPin, LSBFIRST, dataToSend); digitalWrite(latchPin, HIGH); } Ndezur++; } } break; //Mbylle kllapen
        case '_': { byte ledData[] = {00, 00, 03, 00};
          while( Ndezur <= NdezurMax ) {
             for (i=0;i<4;i++){
                  byte dataToSend = (1 << (i+4)) | (15 & ~ledData[i]);
                  digitalWrite(latchPin, LOW); shiftOut(dataPin, clockPin, LSBFIRST, dataToSend); digitalWrite(latchPin, HIGH); } Ndezur++; } } break; //Underline

        default : { byte ledData[] = {15, 15, 15, 00};
          while( Ndezur <= (NdezurMax + 300) ) {
             for (i=0;i<4;i++){
                  byte dataToSend = (1 << (i+4)) | (15 & ~ledData[i]);
                  digitalWrite(latchPin, LOW); shiftOut(dataPin, clockPin, LSBFIRST, dataToSend); digitalWrite(latchPin, HIGH); } Ndezur++; } } break; //Fundi Fjalise
      }
}

void KarakteretM () { 
    switch (Shkronja) {
        case 'A': { int MorseCode[] = {0, 1, 2};
             for ( int I = 0; I < 3; I++) { delay(100); //Time of waiting from letter to letter
                  if ( MorseCode[I] == 0 ){ digitalWrite( Morse[0], HIGH); tone(Buzzer, 200, 100);  delay(100); digitalWrite( Morse[0], LOW); }
                  if ( MorseCode[I] == 1 ){ digitalWrite( Morse[1], HIGH); tone(Buzzer, 200, 300);  delay(300); digitalWrite( Morse[1], LOW); }
                  if ( MorseCode[I] == 2 ){ digitalWrite( Morse[2], HIGH ); delay(700); digitalWrite( Morse[2], LOW ); } } } break; //Shkronja A
        case 'B': { int MorseCode[] = {1, 0, 0, 0, 2};
             for ( int I = 0; I < 5; I++) { delay(100); //Time of waiting from letter to letter
                  if ( MorseCode[I] == 0 ){ digitalWrite( Morse[0], HIGH); tone(Buzzer, 200, 100);  delay(100); digitalWrite( Morse[0], LOW); }
                  if ( MorseCode[I] == 1 ){ digitalWrite( Morse[1], HIGH); tone(Buzzer, 200, 300);  delay(300); digitalWrite( Morse[1], LOW); }
                  if ( MorseCode[I] == 2 ){ digitalWrite( Morse[2], HIGH ); delay(700); digitalWrite( Morse[2], LOW ); } } } break; //Shkronja B
        case 'C': { int MorseCode[] = {1, 0, 1, 0, 2};
             for ( int I = 0; I < 5; I++) { delay(100); //Time of waiting from letter to letter
                  if ( MorseCode[I] == 0 ){ digitalWrite( Morse[0], HIGH); tone(Buzzer, 200, 100);  delay(100); digitalWrite( Morse[0], LOW); }
                  if ( MorseCode[I] == 1 ){ digitalWrite( Morse[1], HIGH); tone(Buzzer, 200, 300);  delay(300); digitalWrite( Morse[1], LOW); }
                  if ( MorseCode[I] == 2 ){ digitalWrite( Morse[2], HIGH ); delay(700); digitalWrite( Morse[2], LOW ); } } } break; //Shkronja C
        case 'D': { int MorseCode[] = {1, 0, 0, 2};
             for ( int I = 0; I < 4; I++) { delay(100); //Time of waiting from letter to letter
                  if ( MorseCode[I] == 0 ){ digitalWrite( Morse[0], HIGH); tone(Buzzer, 200, 100);  delay(100); digitalWrite( Morse[0], LOW); }
                  if ( MorseCode[I] == 1 ){ digitalWrite( Morse[1], HIGH); tone(Buzzer, 200, 300);  delay(300); digitalWrite( Morse[1], LOW); }
                  if ( MorseCode[I] == 2 ){ digitalWrite( Morse[2], HIGH ); delay(700); digitalWrite( Morse[2], LOW ); } } } break; //Shkronja D
        case 'E': { int MorseCode[] = {0, 2};
             for ( int I = 0; I < 2; I++) { delay(100); //Time of waiting from letter to letter
                  if ( MorseCode[I] == 0 ){ digitalWrite( Morse[0], HIGH); tone(Buzzer, 200, 100);  delay(100); digitalWrite( Morse[0], LOW); }
                  if ( MorseCode[I] == 1 ){ digitalWrite( Morse[1], HIGH); tone(Buzzer, 200, 300);  delay(300); digitalWrite( Morse[1], LOW); }
                  if ( MorseCode[I] == 2 ){ digitalWrite( Morse[2], HIGH ); delay(700); digitalWrite( Morse[2], LOW ); } } } break; //Shkronja E
        case 'F': { int MorseCode[] = {0, 0, 1, 0, 2};
             for ( int I = 0; I < 5; I++) { delay(100); //Time of waiting from letter to letter
                  if ( MorseCode[I] == 0 ){ digitalWrite( Morse[0], HIGH); tone(Buzzer, 200, 100);  delay(100); digitalWrite( Morse[0], LOW); }
                  if ( MorseCode[I] == 1 ){ digitalWrite( Morse[1], HIGH); tone(Buzzer, 200, 300);  delay(300); digitalWrite( Morse[1], LOW); }
                  if ( MorseCode[I] == 2 ){ digitalWrite( Morse[2], HIGH ); delay(700); digitalWrite( Morse[2], LOW ); } } } break; //Shkronja F
        case 'G': { int MorseCode[] = {1, 1, 0, 2}; 
             for ( int I = 0; I < 4; I++) { delay(100); //Time of waiting from letter to letter
                  if ( MorseCode[I] == 0 ){ digitalWrite( Morse[0], HIGH); tone(Buzzer, 200, 100);  delay(100); digitalWrite( Morse[0], LOW); }
                  if ( MorseCode[I] == 1 ){ digitalWrite( Morse[1], HIGH); tone(Buzzer, 200, 300);  delay(300); digitalWrite( Morse[1], LOW); }
                  if ( MorseCode[I] == 2 ){ digitalWrite( Morse[2], HIGH ); delay(700); digitalWrite( Morse[2], LOW ); } } } break; //Shkronja G
        case 'H': { int MorseCode[] = {0, 0, 0, 0, 2};
             for ( int I = 0; I < 5; I++) { delay(100); //Time of waiting from letter to letter
                  if ( MorseCode[I] == 0 ){ digitalWrite( Morse[0], HIGH); tone(Buzzer, 200, 100);  delay(100); digitalWrite( Morse[0], LOW); }
                  if ( MorseCode[I] == 1 ){ digitalWrite( Morse[1], HIGH); tone(Buzzer, 200, 300);  delay(300); digitalWrite( Morse[1], LOW); }
                  if ( MorseCode[I] == 2 ){ digitalWrite( Morse[2], HIGH ); delay(700); digitalWrite( Morse[2], LOW ); } } } break; //Shkronja H
        case 'I': { int MorseCode[] = {0, 0, 2};
             for ( int I = 0; I < 3; I++) { delay(100); //Time of waiting from letter to letter
                  if ( MorseCode[I] == 0 ){ digitalWrite( Morse[0], HIGH); tone(Buzzer, 200, 100);  delay(100); digitalWrite( Morse[0], LOW); }
                  if ( MorseCode[I] == 1 ){ digitalWrite( Morse[1], HIGH); tone(Buzzer, 200, 300);  delay(300); digitalWrite( Morse[1], LOW); }
                  if ( MorseCode[I] == 2 ){ digitalWrite( Morse[2], HIGH ); delay(700); digitalWrite( Morse[2], LOW ); } } } break; //Shkronja I
        case 'J': { int MorseCode[] = {0, 1, 1, 1, 2};
             for ( int I = 0; I < 5; I++) { delay(100); //Time of waiting from letter to letter
                  if ( MorseCode[I] == 0 ){ digitalWrite( Morse[0], HIGH); tone(Buzzer, 200, 100);  delay(100); digitalWrite( Morse[0], LOW); }
                  if ( MorseCode[I] == 1 ){ digitalWrite( Morse[1], HIGH); tone(Buzzer, 200, 300);  delay(300); digitalWrite( Morse[1], LOW); }
                  if ( MorseCode[I] == 2 ){ digitalWrite( Morse[2], HIGH ); delay(700); digitalWrite( Morse[2], LOW ); } } } break; //Shkronja J
        case 'K': { int MorseCode[] = {1, 0, 1, 2};
             for ( int I = 0; I < 4; I++) { delay(100); //Time of waiting from letter to letter
                  if ( MorseCode[I] == 0 ){ digitalWrite( Morse[0], HIGH); tone(Buzzer, 200, 100);  delay(100); digitalWrite( Morse[0], LOW); }
                  if ( MorseCode[I] == 1 ){ digitalWrite( Morse[1], HIGH); tone(Buzzer, 200, 300);  delay(300); digitalWrite( Morse[1], LOW); }
                  if ( MorseCode[I] == 2 ){ digitalWrite( Morse[2], HIGH ); delay(700); digitalWrite( Morse[2], LOW ); } } } break; //Shkronja K
        case 'L': { int MorseCode[] = {0, 1, 0, 0, 2};
             for ( int I = 0; I < 5; I++) { delay(100); //Time of waiting from letter to letter
                  if ( MorseCode[I] == 0 ){ digitalWrite( Morse[0], HIGH); tone(Buzzer, 200, 100);  delay(100); digitalWrite( Morse[0], LOW); }
                  if ( MorseCode[I] == 1 ){ digitalWrite( Morse[1], HIGH); tone(Buzzer, 200, 300);  delay(300); digitalWrite( Morse[1], LOW); }
                  if ( MorseCode[I] == 2 ){ digitalWrite( Morse[2], HIGH ); delay(700); digitalWrite( Morse[2], LOW ); } } } break; //Shkronja L
        case 'M': { int MorseCode[] = {1, 1, 2};
             for ( int I = 0; I < 3; I++) { delay(100); //Time of waiting from letter to letter
                  if ( MorseCode[I] == 0 ){ digitalWrite( Morse[0], HIGH); tone(Buzzer, 200, 100);  delay(100); digitalWrite( Morse[0], LOW); }
                  if ( MorseCode[I] == 1 ){ digitalWrite( Morse[1], HIGH); tone(Buzzer, 200, 300);  delay(300); digitalWrite( Morse[1], LOW); }
                  if ( MorseCode[I] == 2 ){ digitalWrite( Morse[2], HIGH ); delay(700); digitalWrite( Morse[2], LOW ); } } } break; //Shkronja M
        case 'N': { int MorseCode[] = {1, 0, 2};
             for ( int I = 0; I < 3; I++) { delay(100); //Time of waiting from letter to letter
                  if ( MorseCode[I] == 0 ){ digitalWrite( Morse[0], HIGH); tone(Buzzer, 200, 100);  delay(100); digitalWrite( Morse[0], LOW); }
                  if ( MorseCode[I] == 1 ){ digitalWrite( Morse[1], HIGH); tone(Buzzer, 200, 300);  delay(300); digitalWrite( Morse[1], LOW); }
                  if ( MorseCode[I] == 2 ){ digitalWrite( Morse[2], HIGH ); delay(700); digitalWrite( Morse[2], LOW ); } } } break; //Shkronja N
        case 'O': { int MorseCode[] = {1, 1, 1, 2};
             for ( int I = 0; I < 4; I++) { delay(100); //Time of waiting from letter to letter
                  if ( MorseCode[I] == 0 ){ digitalWrite( Morse[0], HIGH); tone(Buzzer, 200, 100);  delay(100); digitalWrite( Morse[0], LOW); }
                  if ( MorseCode[I] == 1 ){ digitalWrite( Morse[1], HIGH); tone(Buzzer, 200, 300);  delay(300); digitalWrite( Morse[1], LOW); }
                  if ( MorseCode[I] == 2 ){ digitalWrite( Morse[2], HIGH ); delay(700); digitalWrite( Morse[2], LOW ); } } } break; //Shkronja O
        case 'P': { int MorseCode[] = {0, 1, 1, 0, 2};
             for ( int I = 0; I < 5; I++) { delay(100); //Time of waiting from letter to letter
                  if ( MorseCode[I] == 0 ){ digitalWrite( Morse[0], HIGH); tone(Buzzer, 200, 100);  delay(100); digitalWrite( Morse[0], LOW); }
                  if ( MorseCode[I] == 1 ){ digitalWrite( Morse[1], HIGH); tone(Buzzer, 200, 300);  delay(300); digitalWrite( Morse[1], LOW); }
                  if ( MorseCode[I] == 2 ){ digitalWrite( Morse[2], HIGH ); delay(700); digitalWrite( Morse[2], LOW ); } } } break; //Shkronja P
        case 'Q': { int MorseCode[] = {1, 1, 0, 1, 2};
             for ( int I = 0; I < 5; I++) { delay(100); //Time of waiting from letter to letter
                  if ( MorseCode[I] == 0 ){ digitalWrite( Morse[0], HIGH); tone(Buzzer, 200, 100);  delay(100); digitalWrite( Morse[0], LOW); }
                  if ( MorseCode[I] == 1 ){ digitalWrite( Morse[1], HIGH); tone(Buzzer, 200, 300);  delay(300); digitalWrite( Morse[1], LOW); }
                  if ( MorseCode[I] == 2 ){ digitalWrite( Morse[2], HIGH ); delay(700); digitalWrite( Morse[2], LOW ); } } } break; //Shkronja Q
        case 'R': { int MorseCode[] = {0, 1, 0, 2};
             for ( int I = 0; I < 4; I++) { delay(100); //Time of waiting from letter to letter
                  if ( MorseCode[I] == 0 ){ digitalWrite( Morse[0], HIGH); tone(Buzzer, 200, 100);  delay(100); digitalWrite( Morse[0], LOW); }
                  if ( MorseCode[I] == 1 ){ digitalWrite( Morse[1], HIGH); tone(Buzzer, 200, 300);  delay(300); digitalWrite( Morse[1], LOW); }
                  if ( MorseCode[I] == 2 ){ digitalWrite( Morse[2], HIGH ); delay(700); digitalWrite( Morse[2], LOW ); } } } break; //Shkronja R
        case 'S': { int MorseCode[] = {1, 1, 1, 2};
             for ( int I = 0; I < 4; I++) { delay(100); //Time of waiting from letter to letter
                  if ( MorseCode[I] == 0 ){ digitalWrite( Morse[0], HIGH); tone(Buzzer, 200, 100);  delay(100); digitalWrite( Morse[0], LOW); }
                  if ( MorseCode[I] == 1 ){ digitalWrite( Morse[1], HIGH); tone(Buzzer, 200, 300);  delay(300); digitalWrite( Morse[1], LOW); }
                  if ( MorseCode[I] == 2 ){ digitalWrite( Morse[2], HIGH ); delay(700); digitalWrite( Morse[2], LOW ); } } } break; //Shkronja S
        case 'T': { int MorseCode[] = {1, 2};
             for ( int I = 0; I < 2; I++) { delay(100); //Time of waiting from letter to letter
                  if ( MorseCode[I] == 0 ){ digitalWrite( Morse[0], HIGH); tone(Buzzer, 200, 100);  delay(100); digitalWrite( Morse[0], LOW); }
                  if ( MorseCode[I] == 1 ){ digitalWrite( Morse[1], HIGH); tone(Buzzer, 200, 300);  delay(300); digitalWrite( Morse[1], LOW); }
                  if ( MorseCode[I] == 2 ){ digitalWrite( Morse[2], HIGH ); delay(700); digitalWrite( Morse[2], LOW ); } } } break; //Shkronja T
        case 'U': { int MorseCode[] = {0, 0, 1, 2};
             for ( int I = 0; I < 4; I++) { delay(100); //Time of waiting from letter to letter
                  if ( MorseCode[I] == 0 ){ digitalWrite( Morse[0], HIGH); tone(Buzzer, 200, 100);  delay(100); digitalWrite( Morse[0], LOW); }
                  if ( MorseCode[I] == 1 ){ digitalWrite( Morse[1], HIGH); tone(Buzzer, 200, 300);  delay(300); digitalWrite( Morse[1], LOW); }
                  if ( MorseCode[I] == 2 ){ digitalWrite( Morse[2], HIGH ); delay(700); digitalWrite( Morse[2], LOW ); } } } break; //Shkronja U
        case 'V': { int MorseCode[] = {0, 0, 0, 1, 2};
             for ( int I = 0; I < 5; I++) { delay(100); //Time of waiting from letter to letter
                  if ( MorseCode[I] == 0 ){ digitalWrite( Morse[0], HIGH); tone(Buzzer, 200, 100);  delay(100); digitalWrite( Morse[0], LOW); }
                  if ( MorseCode[I] == 1 ){ digitalWrite( Morse[1], HIGH); tone(Buzzer, 200, 300);  delay(300); digitalWrite( Morse[1], LOW); }
                  if ( MorseCode[I] == 2 ){ digitalWrite( Morse[2], HIGH ); delay(700); digitalWrite( Morse[2], LOW ); } } } break; //Shkronja V
        case 'W': { int MorseCode[] = {0, 1, 1, 2};
             for ( int I = 0; I < 4; I++) { delay(100); //Time of waiting from letter to letter
                  if ( MorseCode[I] == 0 ){ digitalWrite( Morse[0], HIGH); tone(Buzzer, 200, 100);  delay(100); digitalWrite( Morse[0], LOW); }
                  if ( MorseCode[I] == 1 ){ digitalWrite( Morse[1], HIGH); tone(Buzzer, 200, 300);  delay(300); digitalWrite( Morse[1], LOW); }
                  if ( MorseCode[I] == 2 ){ digitalWrite( Morse[2], HIGH ); delay(700); digitalWrite( Morse[2], LOW ); } } } break; //Shkronja W
        case 'X': { int MorseCode[] = {1, 0, 0, 1, 2};
             for ( int I = 0; I < 5; I++) { delay(100); //Time of waiting from letter to letter
                  if ( MorseCode[I] == 0 ){ digitalWrite( Morse[0], HIGH); tone(Buzzer, 200, 100);  delay(100); digitalWrite( Morse[0], LOW); }
                  if ( MorseCode[I] == 1 ){ digitalWrite( Morse[1], HIGH); tone(Buzzer, 200, 300);  delay(300); digitalWrite( Morse[1], LOW); }
                  if ( MorseCode[I] == 2 ){ digitalWrite( Morse[2], HIGH ); delay(700); digitalWrite( Morse[2], LOW ); } } } break; //Shkronja X
        case 'Y': { int MorseCode[] = {1, 0, 1, 1, 2};
             for ( int I = 0; I < 5; I++) { delay(100); //Time of waiting from letter to letter
                  if ( MorseCode[I] == 0 ){ digitalWrite( Morse[0], HIGH); tone(Buzzer, 200, 100);  delay(100); digitalWrite( Morse[0], LOW); }
                  if ( MorseCode[I] == 1 ){ digitalWrite( Morse[1], HIGH); tone(Buzzer, 200, 300);  delay(300); digitalWrite( Morse[1], LOW); }
                  if ( MorseCode[I] == 2 ){ digitalWrite( Morse[2], HIGH ); delay(700); digitalWrite( Morse[2], LOW ); } } } break; //Shkronja Y
        case 'Z': { int MorseCode[] = {1, 1, 0, 0, 2};
             for ( int I = 0; I < 5; I++) { delay(100); //Time of waiting from letter to letter
                  if ( MorseCode[I] == 0 ){ digitalWrite( Morse[0], HIGH); tone(Buzzer, 200, 100);  delay(100); digitalWrite( Morse[0], LOW); }
                  if ( MorseCode[I] == 1 ){ digitalWrite( Morse[1], HIGH); tone(Buzzer, 200, 300);  delay(300); digitalWrite( Morse[1], LOW); }
                  if ( MorseCode[I] == 2 ){ digitalWrite( Morse[2], HIGH ); delay(700); digitalWrite( Morse[2], LOW ); } } } break; //Shkronja Z
        case 'a': { int MorseCode[] = {0, 1, 2};
             for ( int I = 0; I < 3; I++) { delay(100); //Time of waiting from letter to letter
                  if ( MorseCode[I] == 0 ){ digitalWrite( Morse[0], HIGH); tone(Buzzer, 200, 100);  delay(100); digitalWrite( Morse[0], LOW); }
                  if ( MorseCode[I] == 1 ){ digitalWrite( Morse[1], HIGH); tone(Buzzer, 200, 300);  delay(300); digitalWrite( Morse[1], LOW); }
                  if ( MorseCode[I] == 2 ){ digitalWrite( Morse[2], HIGH ); delay(700); digitalWrite( Morse[2], LOW ); } } } break; //Shkronja A
        case 'b': { int MorseCode[] = {1, 0, 0, 0, 2};
             for ( int I = 0; I < 5; I++) { delay(100); //Time of waiting from letter to letter
                  if ( MorseCode[I] == 0 ){ digitalWrite( Morse[0], HIGH); tone(Buzzer, 200, 100);  delay(100); digitalWrite( Morse[0], LOW); }
                  if ( MorseCode[I] == 1 ){ digitalWrite( Morse[1], HIGH); tone(Buzzer, 200, 300);  delay(300); digitalWrite( Morse[1], LOW); }
                  if ( MorseCode[I] == 2 ){ digitalWrite( Morse[2], HIGH ); delay(700); digitalWrite( Morse[2], LOW ); } } } break; //Shkronja B
        case 'c': { int MorseCode[] = {1, 0, 1, 0, 2};
             for ( int I = 0; I < 5; I++) { delay(100); //Time of waiting from letter to letter
                  if ( MorseCode[I] == 0 ){ digitalWrite( Morse[0], HIGH); tone(Buzzer, 200, 100);  delay(100); digitalWrite( Morse[0], LOW); }
                  if ( MorseCode[I] == 1 ){ digitalWrite( Morse[1], HIGH); tone(Buzzer, 200, 300);  delay(300); digitalWrite( Morse[1], LOW); }
                  if ( MorseCode[I] == 2 ){ digitalWrite( Morse[2], HIGH ); delay(700); digitalWrite( Morse[2], LOW ); } } } break; //Shkronja C
        case 'd': { int MorseCode[] = {1, 0, 0, 2};
             for ( int I = 0; I < 4; I++) { delay(100); //Time of waiting from letter to letter
                  if ( MorseCode[I] == 0 ){ digitalWrite( Morse[0], HIGH); tone(Buzzer, 200, 100);  delay(100); digitalWrite( Morse[0], LOW); }
                  if ( MorseCode[I] == 1 ){ digitalWrite( Morse[1], HIGH); tone(Buzzer, 200, 300);  delay(300); digitalWrite( Morse[1], LOW); }
                  if ( MorseCode[I] == 2 ){ digitalWrite( Morse[2], HIGH ); delay(700); digitalWrite( Morse[2], LOW ); } } } break; //Shkronja D
        case 'e': { int MorseCode[] = {0, 2};
             for ( int I = 0; I < 2; I++) { delay(100); //Time of waiting from letter to letter
                  if ( MorseCode[I] == 0 ){ digitalWrite( Morse[0], HIGH); tone(Buzzer, 200, 100);  delay(100); digitalWrite( Morse[0], LOW); }
                  if ( MorseCode[I] == 1 ){ digitalWrite( Morse[1], HIGH); tone(Buzzer, 200, 300);  delay(300); digitalWrite( Morse[1], LOW); }
                  if ( MorseCode[I] == 2 ){ digitalWrite( Morse[2], HIGH ); delay(700); digitalWrite( Morse[2], LOW ); } } } break; //Shkronja E
        case 'f': { int MorseCode[] = {0, 0, 1, 0, 2};
             for ( int I = 0; I < 5; I++) { delay(100); //Time of waiting from letter to letter
                  if ( MorseCode[I] == 0 ){ digitalWrite( Morse[0], HIGH); tone(Buzzer, 200, 100);  delay(100); digitalWrite( Morse[0], LOW); }
                  if ( MorseCode[I] == 1 ){ digitalWrite( Morse[1], HIGH); tone(Buzzer, 200, 300);  delay(300); digitalWrite( Morse[1], LOW); }
                  if ( MorseCode[I] == 2 ){ digitalWrite( Morse[2], HIGH ); delay(700); digitalWrite( Morse[2], LOW ); } } } break; //Shkronja F
        case 'g': { int MorseCode[] = {1, 1, 0, 2}; 
             for ( int I = 0; I < 4; I++) { delay(100); //Time of waiting from letter to letter
                  if ( MorseCode[I] == 0 ){ digitalWrite( Morse[0], HIGH); tone(Buzzer, 200, 100);  delay(100); digitalWrite( Morse[0], LOW); }
                  if ( MorseCode[I] == 1 ){ digitalWrite( Morse[1], HIGH); tone(Buzzer, 200, 300);  delay(300); digitalWrite( Morse[1], LOW); }
                  if ( MorseCode[I] == 2 ){ digitalWrite( Morse[2], HIGH ); delay(700); digitalWrite( Morse[2], LOW ); } } } break; //Shkronja G
        case 'h': { int MorseCode[] = {0, 0, 0, 0, 2};
             for ( int I = 0; I < 5; I++) { delay(100); //Time of waiting from letter to letter
                  if ( MorseCode[I] == 0 ){ digitalWrite( Morse[0], HIGH); tone(Buzzer, 200, 100);  delay(100); digitalWrite( Morse[0], LOW); }
                  if ( MorseCode[I] == 1 ){ digitalWrite( Morse[1], HIGH); tone(Buzzer, 200, 300);  delay(300); digitalWrite( Morse[1], LOW); }
                  if ( MorseCode[I] == 2 ){ digitalWrite( Morse[2], HIGH ); delay(700); digitalWrite( Morse[2], LOW ); } } } break; //Shkronja H
        case 'i': { int MorseCode[] = {0, 0, 2};
             for ( int I = 0; I < 3; I++) { delay(100); //Time of waiting from letter to letter
                  if ( MorseCode[I] == 0 ){ digitalWrite( Morse[0], HIGH); tone(Buzzer, 200, 100);  delay(100); digitalWrite( Morse[0], LOW); }
                  if ( MorseCode[I] == 1 ){ digitalWrite( Morse[1], HIGH); tone(Buzzer, 200, 300);  delay(300); digitalWrite( Morse[1], LOW); }
                  if ( MorseCode[I] == 2 ){ digitalWrite( Morse[2], HIGH ); delay(700); digitalWrite( Morse[2], LOW ); } } } break; //Shkronja I
        case 'j': { int MorseCode[] = {0, 1, 1, 1, 2};
             for ( int I = 0; I < 5; I++) { delay(100); //Time of waiting from letter to letter
                  if ( MorseCode[I] == 0 ){ digitalWrite( Morse[0], HIGH); tone(Buzzer, 200, 100);  delay(100); digitalWrite( Morse[0], LOW); }
                  if ( MorseCode[I] == 1 ){ digitalWrite( Morse[1], HIGH); tone(Buzzer, 200, 300);  delay(300); digitalWrite( Morse[1], LOW); }
                  if ( MorseCode[I] == 2 ){ digitalWrite( Morse[2], HIGH ); delay(700); digitalWrite( Morse[2], LOW ); } } } break; //Shkronja J
        case 'k': { int MorseCode[] = {1, 0, 1, 2};
             for ( int I = 0; I < 4; I++) { delay(100); //Time of waiting from letter to letter
                  if ( MorseCode[I] == 0 ){ digitalWrite( Morse[0], HIGH); tone(Buzzer, 200, 100);  delay(100); digitalWrite( Morse[0], LOW); }
                  if ( MorseCode[I] == 1 ){ digitalWrite( Morse[1], HIGH); tone(Buzzer, 200, 300);  delay(300); digitalWrite( Morse[1], LOW); }
                  if ( MorseCode[I] == 2 ){ digitalWrite( Morse[2], HIGH ); delay(700); digitalWrite( Morse[2], LOW ); } } } break; //Shkronja K
        case 'l': { int MorseCode[] = {0, 1, 0, 0, 2};
             for ( int I = 0; I < 5; I++) { delay(100); //Time of waiting from letter to letter
                  if ( MorseCode[I] == 0 ){ digitalWrite( Morse[0], HIGH); tone(Buzzer, 200, 100);  delay(100); digitalWrite( Morse[0], LOW); }
                  if ( MorseCode[I] == 1 ){ digitalWrite( Morse[1], HIGH); tone(Buzzer, 200, 300);  delay(300); digitalWrite( Morse[1], LOW); }
                  if ( MorseCode[I] == 2 ){ digitalWrite( Morse[2], HIGH ); delay(700); digitalWrite( Morse[2], LOW ); } } } break; //Shkronja L
        case 'm': { int MorseCode[] = {1, 1, 2};
             for ( int I = 0; I < 3; I++) { delay(100); //Time of waiting from letter to letter
                  if ( MorseCode[I] == 0 ){ digitalWrite( Morse[0], HIGH); tone(Buzzer, 200, 100);  delay(100); digitalWrite( Morse[0], LOW); }
                  if ( MorseCode[I] == 1 ){ digitalWrite( Morse[1], HIGH); tone(Buzzer, 200, 300);  delay(300); digitalWrite( Morse[1], LOW); }
                  if ( MorseCode[I] == 2 ){ digitalWrite( Morse[2], HIGH ); delay(700); digitalWrite( Morse[2], LOW ); } } } break; //Shkronja M
        case 'n': { int MorseCode[] = {1, 0, 2};
             for ( int I = 0; I < 3; I++) { delay(100); //Time of waiting from letter to letter
                  if ( MorseCode[I] == 0 ){ digitalWrite( Morse[0], HIGH); tone(Buzzer, 200, 100);  delay(100); digitalWrite( Morse[0], LOW); }
                  if ( MorseCode[I] == 1 ){ digitalWrite( Morse[1], HIGH); tone(Buzzer, 200, 300);  delay(300); digitalWrite( Morse[1], LOW); }
                  if ( MorseCode[I] == 2 ){ digitalWrite( Morse[2], HIGH ); delay(700); digitalWrite( Morse[2], LOW ); } } } break; //Shkronja N
        case 'o': { int MorseCode[] = {1, 1, 1, 2};
             for ( int I = 0; I < 4; I++) { delay(100); //Time of waiting from letter to letter
                  if ( MorseCode[I] == 0 ){ digitalWrite( Morse[0], HIGH); tone(Buzzer, 200, 100);  delay(100); digitalWrite( Morse[0], LOW); }
                  if ( MorseCode[I] == 1 ){ digitalWrite( Morse[1], HIGH); tone(Buzzer, 200, 300);  delay(300); digitalWrite( Morse[1], LOW); }
                  if ( MorseCode[I] == 2 ){ digitalWrite( Morse[2], HIGH ); delay(700); digitalWrite( Morse[2], LOW ); } } } break; //Shkronja O
        case 'p': { int MorseCode[] = {0, 1, 1, 0, 2};
             for ( int I = 0; I < 5; I++) { delay(100); //Time of waiting from letter to letter
                  if ( MorseCode[I] == 0 ){ digitalWrite( Morse[0], HIGH); tone(Buzzer, 200, 100);  delay(100); digitalWrite( Morse[0], LOW); }
                  if ( MorseCode[I] == 1 ){ digitalWrite( Morse[1], HIGH); tone(Buzzer, 200, 300);  delay(300); digitalWrite( Morse[1], LOW); }
                  if ( MorseCode[I] == 2 ){ digitalWrite( Morse[2], HIGH ); delay(700); digitalWrite( Morse[2], LOW ); } } } break; //Shkronja P
        case 'q': { int MorseCode[] = {1, 1, 0, 1, 2};
             for ( int I = 0; I < 5; I++) { delay(100); //Time of waiting from letter to letter
                  if ( MorseCode[I] == 0 ){ digitalWrite( Morse[0], HIGH); tone(Buzzer, 200, 100);  delay(100); digitalWrite( Morse[0], LOW); }
                  if ( MorseCode[I] == 1 ){ digitalWrite( Morse[1], HIGH); tone(Buzzer, 200, 300);  delay(300); digitalWrite( Morse[1], LOW); }
                  if ( MorseCode[I] == 2 ){ digitalWrite( Morse[2], HIGH ); delay(700); digitalWrite( Morse[2], LOW ); } } } break; //Shkronja Q
        case 'r': { int MorseCode[] = {0, 1, 0, 2};
             for ( int I = 0; I < 4; I++) { delay(100); //Time of waiting from letter to letter
                  if ( MorseCode[I] == 0 ){ digitalWrite( Morse[0], HIGH); tone(Buzzer, 200, 100);  delay(100); digitalWrite( Morse[0], LOW); }
                  if ( MorseCode[I] == 1 ){ digitalWrite( Morse[1], HIGH); tone(Buzzer, 200, 300);  delay(300); digitalWrite( Morse[1], LOW); }
                  if ( MorseCode[I] == 2 ){ digitalWrite( Morse[2], HIGH ); delay(700); digitalWrite( Morse[2], LOW ); } } } break; //Shkronja R
        case 's': { int MorseCode[] = {1, 1, 1, 2};
             for ( int I = 0; I < 4; I++) { delay(100); //Time of waiting from letter to letter
                  if ( MorseCode[I] == 0 ){ digitalWrite( Morse[0], HIGH); tone(Buzzer, 200, 100);  delay(100); digitalWrite( Morse[0], LOW); }
                  if ( MorseCode[I] == 1 ){ digitalWrite( Morse[1], HIGH); tone(Buzzer, 200, 300);  delay(300); digitalWrite( Morse[1], LOW); }
                  if ( MorseCode[I] == 2 ){ digitalWrite( Morse[2], HIGH ); delay(700); digitalWrite( Morse[2], LOW ); } } } break; //Shkronja S
        case 't': { int MorseCode[] = {1, 2};
             for ( int I = 0; I < 2; I++) { delay(100); //Time of waiting from letter to letter
                  if ( MorseCode[I] == 0 ){ digitalWrite( Morse[0], HIGH); tone(Buzzer, 200, 100);  delay(100); digitalWrite( Morse[0], LOW); }
                  if ( MorseCode[I] == 1 ){ digitalWrite( Morse[1], HIGH); tone(Buzzer, 200, 300);  delay(300); digitalWrite( Morse[1], LOW); }
                  if ( MorseCode[I] == 2 ){ digitalWrite( Morse[2], HIGH ); delay(700); digitalWrite( Morse[2], LOW ); } } } break; //Shkronja T
        case 'u': { int MorseCode[] = {0, 0, 1, 2};
             for ( int I = 0; I < 4; I++) { delay(100); //Time of waiting from letter to letter
                  if ( MorseCode[I] == 0 ){ digitalWrite( Morse[0], HIGH); tone(Buzzer, 200, 100);  delay(100); digitalWrite( Morse[0], LOW); }
                  if ( MorseCode[I] == 1 ){ digitalWrite( Morse[1], HIGH); tone(Buzzer, 200, 300);  delay(300); digitalWrite( Morse[1], LOW); }
                  if ( MorseCode[I] == 2 ){ digitalWrite( Morse[2], HIGH ); delay(700); digitalWrite( Morse[2], LOW ); } } } break; //Shkronja U
        case 'v': { int MorseCode[] = {0, 0, 0, 1, 2};
             for ( int I = 0; I < 5; I++) { delay(100); //Time of waiting from letter to letter
                  if ( MorseCode[I] == 0 ){ digitalWrite( Morse[0], HIGH); tone(Buzzer, 200, 100);  delay(100); digitalWrite( Morse[0], LOW); }
                  if ( MorseCode[I] == 1 ){ digitalWrite( Morse[1], HIGH); tone(Buzzer, 200, 300);  delay(300); digitalWrite( Morse[1], LOW); }
                  if ( MorseCode[I] == 2 ){ digitalWrite( Morse[2], HIGH ); delay(700); digitalWrite( Morse[2], LOW ); } } } break; //Shkronja V
        case 'w': { int MorseCode[] = {0, 1, 1, 2};
             for ( int I = 0; I < 4; I++) { delay(100); //Time of waiting from letter to letter
                  if ( MorseCode[I] == 0 ){ digitalWrite( Morse[0], HIGH); tone(Buzzer, 200, 100);  delay(100); digitalWrite( Morse[0], LOW); }
                  if ( MorseCode[I] == 1 ){ digitalWrite( Morse[1], HIGH); tone(Buzzer, 200, 300);  delay(300); digitalWrite( Morse[1], LOW); }
                  if ( MorseCode[I] == 2 ){ digitalWrite( Morse[2], HIGH ); delay(700); digitalWrite( Morse[2], LOW ); } } } break; //Shkronja W
        case 'x': { int MorseCode[] = {1, 0, 0, 1, 2};
             for ( int I = 0; I < 5; I++) { delay(100); //Time of waiting from letter to letter
                  if ( MorseCode[I] == 0 ){ digitalWrite( Morse[0], HIGH); tone(Buzzer, 200, 100);  delay(100); digitalWrite( Morse[0], LOW); }
                  if ( MorseCode[I] == 1 ){ digitalWrite( Morse[1], HIGH); tone(Buzzer, 200, 300);  delay(300); digitalWrite( Morse[1], LOW); }
                  if ( MorseCode[I] == 2 ){ digitalWrite( Morse[2], HIGH ); delay(700); digitalWrite( Morse[2], LOW ); } } } break; //Shkronja X
        case 'y': { int MorseCode[] = {1, 0, 1, 1, 2};
             for ( int I = 0; I < 5; I++) { delay(100); //Time of waiting from letter to letter
                  if ( MorseCode[I] == 0 ){ digitalWrite( Morse[0], HIGH); tone(Buzzer, 200, 100);  delay(100); digitalWrite( Morse[0], LOW); }
                  if ( MorseCode[I] == 1 ){ digitalWrite( Morse[1], HIGH); tone(Buzzer, 200, 300);  delay(300); digitalWrite( Morse[1], LOW); }
                  if ( MorseCode[I] == 2 ){ digitalWrite( Morse[2], HIGH ); delay(700); digitalWrite( Morse[2], LOW ); } } } break; //Shkronja Y
        case 'z': { int MorseCode[] = {1, 1, 0, 0, 2};
             for ( int I = 0; I < 5; I++) { delay(100); //Time of waiting from letter to letter
                  if ( MorseCode[I] == 0 ){ digitalWrite( Morse[0], HIGH); tone(Buzzer, 200, 100);  delay(100); digitalWrite( Morse[0], LOW); }
                  if ( MorseCode[I] == 1 ){ digitalWrite( Morse[1], HIGH); tone(Buzzer, 200, 300);  delay(300); digitalWrite( Morse[1], LOW); }
                  if ( MorseCode[I] == 2 ){ digitalWrite( Morse[2], HIGH ); delay(700); digitalWrite( Morse[2], LOW ); } } } break; //Shkronja Z
        case '0': { int MorseCode[] = {1, 1, 1, 1, 1, 2};
             for ( int I = 0; I < 6; I++) { delay(100); //Time of waiting from letter to letter
                  if ( MorseCode[I] == 0 ){ digitalWrite( Morse[0], HIGH); tone(Buzzer, 300, 100); delay(100); digitalWrite( Morse[0], LOW); }
                  if ( MorseCode[I] == 1 ){ digitalWrite( Morse[1], HIGH); tone(Buzzer, 300, 300); delay(300); digitalWrite( Morse[1], LOW); }
                  if ( MorseCode[I] == 2 ){ digitalWrite( Morse[2], HIGH ); delay(700); digitalWrite( Morse[2], LOW ); } } } break; //Numri 0
        case '1': { int MorseCode[] = {0, 1, 1, 1, 1, 2};
             for ( int I = 0; I < 6; I++) { delay(100); //Time of waiting from letter to letter
                  if ( MorseCode[I] == 0 ){ digitalWrite( Morse[0], HIGH); tone(Buzzer, 200, 100); delay(100); digitalWrite( Morse[0], LOW); }
                  if ( MorseCode[I] == 1 ){ digitalWrite( Morse[1], HIGH); tone(Buzzer, 200, 300); delay(300); digitalWrite( Morse[1], LOW); }
                  if ( MorseCode[I] == 2 ){ digitalWrite( Morse[2], HIGH ); delay(1000); digitalWrite( Morse[2], LOW ); } } } break; //Numri 1
        case '2': { int MorseCode[] = {0, 0, 1, 1, 1, 2};
             for ( int I = 0; I < 6; I++) { delay(100); //Time of waiting from letter to letter
                  if ( MorseCode[I] == 0 ){ digitalWrite( Morse[0], HIGH); tone(Buzzer, 200, 100); delay(100); digitalWrite( Morse[0], LOW); }
                  if ( MorseCode[I] == 1 ){ digitalWrite( Morse[1], HIGH); tone(Buzzer, 200, 300); delay(300); digitalWrite( Morse[1], LOW); }
                  if ( MorseCode[I] == 2 ){ digitalWrite( Morse[2], HIGH ); delay(700); digitalWrite( Morse[2], LOW ); } } } break; //Numri 2
        case '3': { int MorseCode[] = {0, 0, 0, 1, 1, 2};
             for ( int I = 0; I < 6; I++) { delay(100); //Time of waiting from letter to letter
                  if ( MorseCode[I] == 0 ){ digitalWrite( Morse[0], HIGH); tone(Buzzer, 200, 100); delay(100); digitalWrite( Morse[0], LOW); }
                  if ( MorseCode[I] == 1 ){ digitalWrite( Morse[1], HIGH); tone(Buzzer, 200, 300); delay(300); digitalWrite( Morse[1], LOW); }
                  if ( MorseCode[I] == 2 ){ digitalWrite( Morse[2], HIGH ); delay(700); digitalWrite( Morse[2], LOW ); } } } break; //Numri 3
        case '4': { int MorseCode[] = {0, 0, 0, 0, 1, 2};
             for ( int I = 0; I < 6; I++) { delay(100); //Time of waiting from letter to letter
                  if ( MorseCode[I] == 0 ){ digitalWrite( Morse[0], HIGH); tone(Buzzer, 200, 100); delay(100); digitalWrite( Morse[0], LOW); }
                  if ( MorseCode[I] == 1 ){ digitalWrite( Morse[1], HIGH); tone(Buzzer, 200, 300); delay(300); digitalWrite( Morse[1], LOW); }
                  if ( MorseCode[I] == 2 ){ digitalWrite( Morse[2], HIGH ); delay(700); digitalWrite( Morse[2], LOW ); } } } break; //Numri 4
        case '5': { int MorseCode[] = {0, 0, 0, 0, 0, 2};
             for ( int I = 0; I < 6; I++) { delay(100); //Time of waiting from letter to letter
                  if ( MorseCode[I] == 0 ){ digitalWrite( Morse[0], HIGH); tone(Buzzer, 200, 100); delay(100); digitalWrite( Morse[0], LOW); }
                  if ( MorseCode[I] == 1 ){ digitalWrite( Morse[1], HIGH); tone(Buzzer, 200, 300); delay(300); digitalWrite( Morse[1], LOW); }
                  if ( MorseCode[I] == 2 ){ digitalWrite( Morse[2], HIGH ); delay(700); digitalWrite( Morse[2], LOW ); } } } break; //Numri 5
        case '6': { int MorseCode[] = {1, 0, 0, 0, 0, 2};
             for ( int I = 0; I < 6; I++) { delay(100); //Time of waiting from letter to letter
                  if ( MorseCode[I] == 0 ){ digitalWrite( Morse[0], HIGH); tone(Buzzer, 200, 100);  delay(100); digitalWrite( Morse[0], LOW); }
                  if ( MorseCode[I] == 1 ){ digitalWrite( Morse[1], HIGH); tone(Buzzer, 200, 300);  delay(300); digitalWrite( Morse[1], LOW); }
                  if ( MorseCode[I] == 2 ){ digitalWrite( Morse[2], HIGH ); delay(700); digitalWrite( Morse[2], LOW ); } } } break; //Numri 6
        case '7': { int MorseCode[] = {1, 1, 0, 0, 0, 2};
             for ( int I = 0; I < 6; I++) { delay(100); //Time of waiting from letter to letter
                  if ( MorseCode[I] == 0 ){ digitalWrite( Morse[0], HIGH); tone(Buzzer, 200, 100);  delay(100); digitalWrite( Morse[0], LOW); }
                  if ( MorseCode[I] == 1 ){ digitalWrite( Morse[1], HIGH); tone(Buzzer, 200, 300);  delay(300); digitalWrite( Morse[1], LOW); }
                  if ( MorseCode[I] == 2 ){ digitalWrite( Morse[2], HIGH ); delay(700); digitalWrite( Morse[2], LOW ); } } } break; //Numri 7
        case '8': { int MorseCode[] = {1, 1, 1, 0, 0, 2};
             for ( int I = 0; I < 6; I++) { delay(100); //Time of waiting from letter to letter
                  if ( MorseCode[I] == 0 ){ digitalWrite( Morse[0], HIGH); tone(Buzzer, 200, 100);  delay(100); digitalWrite( Morse[0], LOW); }
                  if ( MorseCode[I] == 1 ){ digitalWrite( Morse[1], HIGH); tone(Buzzer, 200, 300);  delay(300); digitalWrite( Morse[1], LOW); }
                  if ( MorseCode[I] == 2 ){ digitalWrite( Morse[2], HIGH ); delay(700); digitalWrite( Morse[2], LOW ); } } } break; //Numri 8
        case '9': { int MorseCode[] = {1, 1, 1, 1, 0, 2}; 
             for ( int I = 0; I < 6; I++) { delay(100); //Time of waiting from letter to letter
                  if ( MorseCode[I] == 0 ){ digitalWrite( Morse[0], HIGH); tone(Buzzer, 200, 100);  delay(100); digitalWrite( Morse[0], LOW); }
                  if ( MorseCode[I] == 1 ){ digitalWrite( Morse[1], HIGH); tone(Buzzer, 200, 300);  delay(300); digitalWrite( Morse[1], LOW); }
                  if ( MorseCode[I] == 2 ){ digitalWrite( Morse[2], HIGH ); delay(700); digitalWrite( Morse[2], LOW ); } } } break; //Numri 9
        
        default : { tone(Buzzer, 2000, 1000);  delay(1000); } break; //Fundi Fjalise
      }
}
