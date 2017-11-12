// 24 V - 24V Supply
// GND - Supply GND & Arduino GND
// StartStop - Pin 6 (PWM)
// CwCCw     - Pin 5
// CLK - Not connected
// H/D - Not connected
// LD  - Not connected

char Zgjedhja;    // Variabla per ruajtje te vlerave te pranuara nga SerialMonitor
int CwCCw = 5;     // Pini per kontrollimin e kahjes se rrotullimit
int StartStop = 6; // Pini per ndezjen dhe ndaljen e motorrit
int SpEn = 3; int SpVlera = 0;
int SpDir = 4; int DirVlera = 0;

void setup() { //Serial.begin(9600); // Starto serial
    pinMode(CwCCw, OUTPUT);       // Deklarimi i pinit si dales
    pinMode(StartStop, OUTPUT);   // Deklarimi i pinit si dales
}

void loop() {
    //Zgjedhja = Serial.read(); // Lexo dhe ruaj ne variabel

     SpVlera = digitalRead(SpEn );
    DirVlera = digitalRead(SpDir);
    
    
         if (Zgjedhja == 'D') { digitalWrite(CwCCw, LOW);    } // Djathtas
    else if (Zgjedhja == 'M') { digitalWrite(CwCCw, HIGH);   } // Majtas
    else if (Zgjedhja == 'S') { analogWrite(StartStop, 64);  } // Ndize
    else if (Zgjedhja == 'N') { analogWrite(StartStop, 255); } // Ndale
    else if (Zgjedhja == 'T') { analogWrite(StartStop, 255);delay(10);analogWrite(StartStop, 0);delay(10); } // Ndale
        else if (Zgjedhja == 'R') { analogWrite(StartStop, 255);analogWrite(StartStop, 0); } // Ndale
            else if (Zgjedhja == 'E') { analogWrite(StartStop, 255);delay(10);analogWrite(StartStop, 64);delay(10); } // Ndale
}
