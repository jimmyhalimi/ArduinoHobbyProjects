const int stepPin = A5;
const int dirPin = A4; 
int Majtas = A2; int VleraM = 0;
int Djathtas = A1; int VleraD = 0;

double customdelayMicroseconds;
double customdelayMicrosecondsMapped; // Defines variables
 
void setup() { Serial.begin(9600);
  // Sets the two pins as Outputs
  pinMode(stepPin,OUTPUT);
  pinMode(dirPin,OUTPUT);
  pinMode(Majtas,INPUT_PULLUP);
  pinMode(Djathtas,INPUT_PULLUP);
 

}
void loop() { LexoButonat ();
              
              if (VleraM == LOW) {
                  digitalWrite(dirPin,HIGH); //Enables the motor to move in a particular direction
                    for (int i = 1; i <= 200; i++) {
                          digitalWrite(stepPin, HIGH);
                          delayMicroseconds((customdelayMicrosecondsMapped+35000)-i*7);
                          digitalWrite(stepPin, LOW);
                          delayMicroseconds((customdelayMicrosecondsMapped+35000)-i*7);
                          if (((customdelayMicrosecondsMapped+35000)-i*7) <= customdelayMicrosecondsMapped) break;
                          }
                  Rotullo ();
              }
              
              else if (VleraD == LOW) {
                  digitalWrite(dirPin,LOW); //Enables the motor to move in a particular direction
                    for (int i = 0; i <= 300; i++) {
                          digitalWrite(stepPin, HIGH);
                          delayMicroseconds((customdelayMicrosecondsMapped+35000)-i*7);
                          digitalWrite(stepPin, LOW);
                          delayMicroseconds((customdelayMicrosecondsMapped+35000)-i*7);
                          if (((customdelayMicrosecondsMapped+35000)-i*7) <= customdelayMicrosecondsMapped) break;
                          }
                  Rotullo ();
              }

              else if (VleraD == LOW && VleraM == LOW) {
                //Do Nothing
              }
}

void Rotullo () {
  while (VleraM != HIGH || VleraD != HIGH) {
  customdelayMicrosecondsMapped = speedUp(); // Gets custom delayMicroseconds values from the custom speedUp function
  digitalWrite(stepPin, HIGH);
  delayMicroseconds(customdelayMicrosecondsMapped);
  digitalWrite(stepPin, LOW);
  delayMicroseconds(customdelayMicrosecondsMapped); 
  LexoButonat () ;
  }
                      for (int i = 1; i <= 300; i++) {
                          digitalWrite(stepPin, HIGH);
                          delayMicroseconds(customdelayMicrosecondsMapped+i*7);
                          digitalWrite(stepPin, LOW);
                          delayMicroseconds(customdelayMicrosecondsMapped+i*7); 
                          }
}

void LexoButonat () {
  VleraM = digitalRead(Majtas);
  VleraD = digitalRead(Djathtas);
}

int speedUp() {
  int customdelayMicroseconds = analogRead(A0); // Reads the potentiometer
  int newCustom = map(customdelayMicroseconds, 0, 1023, 400, 2000); // Convrests the read values of the potentiometer from 0 to 1023 into desireded delayMicroseconds values (300 to 4000)
  return newCustom;
}
