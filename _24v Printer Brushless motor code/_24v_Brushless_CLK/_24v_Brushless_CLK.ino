// 24 V    - 24V Supply
// GND     - Supply GND & Arduino GND
// ss      - Pin 6
// CwCCw  - Pin 5
// CLK     - Pin 11 (PWM)
// H/D     - Pin 10
// LD      - Pin 9

// Ne SerialMonitor, Shtyp D - Per djathtas, M - Per majtas, S - Per me e nis, N - Per me e ndal

char Zgjedhja;    // Variabla per ruajtje te vlerave te pranuara nga SerialMonitor
int CwCCw = 5;     // Pini per kontrollimin e kahjes se rrotullimit
int ss = 6;         // Pini per aktivizimin e motorrit
int CLK = 11;       // Pini per Clockun e motorrit (PWM)

void setup() { Serial.begin(9600); // Starto serial
    pinMode(CwCCw, OUTPUT);       // Deklarimi i pinit si dales
    pinMode(ss, OUTPUT);           // Deklarimi i pinit si dales
    pinMode(CLK, OUTPUT);          // Deklarimi i pinit si dales
    digitalWrite(ss, LOW);         // Deklaro LOW per te aktivizuar motorrin (Enable), (HIGH - Disable)
}

void loop() {
    Zgjedhja = Serial.read(); // Lexo dhe ruaj ne variabel
    
         if (Zgjedhja == 'D') { digitalWrite(CwCCw, LOW);    } // Djathtas
    else if (Zgjedhja == 'M')   { digitalWrite(CwCCw, HIGH);   } // Majtas
    else if (Zgjedhja == 'S')    { analogWrite(CLK, 64);         } // Ndize Clockun per te rotulluar motorrin
    else if (Zgjedhja == 'N')    { analogWrite(CLK, 255);        } // Ndale Clockun per ta ndalur motorrin
}
