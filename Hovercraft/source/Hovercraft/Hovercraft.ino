//Kodi per kontrollin e HoverCraft, RF 433 Mhz ASK Modulation, Mërgim Halimi.

#include <VirtualWire.h>
#include <SoftwareServo.h> //Libraria per Servo Motorrin

SoftwareServo servo; //Objekti i Servo Motorrit

int Motorri2 = 2;  // Pini ku lidhet aktivizimi i motorrit te pare
int Motorri1 = 3;  // Pini ku lidhet aktivizimi i motorrit te dyte
int Majtas = 0; // Variabla per kthimin majtas
int Djathtas = 0; // Variabla per kthimin djathtas
int Ndizu = 0; // Variabla per ndezjen e motorrit per ngritje

void setup() {

  Serial.begin(9600);
  vw_setup(2000); 
  vw_set_rx_pin(A4);
  vw_rx_start(); 
  
  servo.attach(5);  // E lidh PIN'in nr. 5 me objektin e Servos
  pinMode(Motorri1, OUTPUT); //Deklarimi i PIN'it te motorrit te pare si dales
  pinMode(Motorri2, OUTPUT); //Deklarimi i PIN'it te motorrit te dyte si dales
}

void loop() {
      int Permiresuesi = 0;
      byte buf[VW_MAX_MESSAGE_LEN]; 
      byte buflen = VW_MAX_MESSAGE_LEN;
      char MesazhiP [100];

         if( vw_get_message(buf, &buflen) ) {
            for (int i = 1; i < buflen - 1; i++) { Permiresuesi++;
                MesazhiP [i-1] = (char)buf[i]; }
                
                String MesazhiPstring = MesazhiP;
                String MesazhiPermiresuar = MesazhiPstring.substring(0, Permiresuesi);

                if (MesazhiPermiresuar == "Ngritu") { digitalWrite(Motorri1, HIGH); }
                else if (MesazhiPermiresuar == "Ulu") { digitalWrite(Motorri1, LOW); }
                else if (MesazhiPermiresuar == "Para") { digitalWrite(Motorri2, HIGH); }
                else if (MesazhiPermiresuar == "Ndalu") { digitalWrite(Motorri2, LOW); }
                else if (MesazhiPermiresuar == "Majtas") { Majtas++; if ( Majtas =! 0 ) { servo.write(140); } }
                else if (MesazhiPermiresuar == "Djathtas") { Djathtas++; if ( Djathtas =! 0 ) { servo.write(40); } }
                else if (MesazhiPermiresuar == "Drejt") {  Majtas = 0; Djathtas = 0; servo.write(90); } }
                SoftwareServo::refresh();
            }
