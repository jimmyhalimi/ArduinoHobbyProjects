// 24 V - 24V Supply
// GND - Supply GND & Arduino GND
// Start - Pin 6 (PWM)
// Cw     - Pin 5
// CLK - Not connected
// H/D - Not connected
// LD  - Not connected

//char Zgjedhja;    // Variabla per ruajtje te vlerave te pranuara nga SerialMonitor
int Cw = 5;     // Pini per kontrollimin e kahjes se rrotullimit
int Start = 6; // Pini per ndezjen dhe ndaljen e motorrit
int Spen = 3; int Spvlera = 0;
int Spdir = 4; int Dirvlera = 0;

void setup () { //Serial.begin(9600); // Starto serial
    pinMode(Cw, OUTPUT);       // Deklarimi i pinit si dales
    pinMode(Start, OUTPUT);   // Deklarimi i pinit si dales
    pinMode(Spen, INPUT_PULLUP);  
    pinMode(Spdir, INPUT_PULLUP); 
}

void loop() {

     Spvlera = digitalRead(Spen );
    Dirvlera = digitalRead(Spdir);
    
    
         if (Dirvlera == HIGH) { digitalWrite(Cw, LOW);    } // Djathtas
    else if (Dirvlera == LOW) { digitalWrite(Cw, HIGH);   } // Majtas
    else if (Spvlera == HIGH) { analogWrite(Start, 64);  } // Ndize
    else if (Spvlera == LOW) { digitalWrite(Start, HIGH); } // Ndale
    
}
