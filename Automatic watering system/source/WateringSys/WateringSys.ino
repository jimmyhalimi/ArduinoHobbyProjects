/*  

Kodi per ujitjen automatike me Arduino Uno

Pjestarët :
  Msc.  Jakup Berisha  ( jakup.berisha@gmail.com, +377 (0) 44 122 270 )
  Student. Mërgim Halimi  ( m.halimi@live.com, +377 (0) 45 590 509 )
 
*/

#include <Wire.h> //Deklarimi i librarise per komunikimin e I2C
#include <LiquidCrystal_I2C.h> //Deklarimi i LCD me I2C

LiquidCrystal_I2C lcd(0x20,16,2); //Deklarimi i PIN'ave te Display ne adresen 0x20, 16x2 LCD, Pin SDA SCL

#include <NewPing.h> //Deklarimi i librarise se senzorit US HC-SR04

//Deklarimi fiks i PIN'ave te senzorit dhe niveleve Min/Max
#define trigPin 12 // Definimi i Pin'it Trig te HC-SR04
#define echoPin 13 // Definimi i Pin'it Echo te HC-SR04
#define DistancaMaksimale 500 // Distanca maksimale qe deshirojme qe te matet nga senzori. Distanca maksimale eshte 400-500 Cm per HC-SR04
#define NiveliMin 23 // Mat distancen[cm] e rezervuarit prej senzorit deri ne nivelin minimal  te deshiruar, ndrysho vleren vartesisht nga rezervuari
#define NiveliMax 6  // Mat distancen[cm] e rezervuarit prej senzorit deri ne nivelin maksimal te deshiruar, ndrysho vleren vartesisht nga rezervuari
                       // Kodi eshte permiresuar me 14-01-2016 nga J.Berisha ne rreshtin 22 dhe 23  me vlera te sakta te niveleve Max dhe Min
NewPing sonar(trigPin, echoPin, DistancaMaksimale); // Thirrja e nenprogramit Newping per llogaritje nga senzori HC-SR04

//Deklarimi fleksibil i PIN'ave te butonave dhe senzorave ne portet Analoge
int ButonatP = A0; 
        int Butonat = 0; //Deklarimi i PIN'it te butonit dhe ruajtja e vleres se butonit ne nje variabel

int SensLageshtise1 = A1; //Deklarimi i PIN'it te sensorit te lageshtise P1
           int VSL1 = 0; //Ruajtja e vleres se sensorit ne nje variabel
           
int SensLageshtise2 = A2; 
           int VSL2 = 0; //Deklarimi i PIN'it te sensorit te lageshtise P2 dhe ruajtja e vleres se sensorit ne nje variabel
           
int SensLageshtise3 = A3; 
           int VSL3 = 0; //Deklarimi i PIN'it te sensorit te lageshtise P3 dhe ruajtja e vleres se sensorit ne nje variabel
           
int SensLageshtise4 = A6; 
           int VSL4 = 0;  //Deklarimi i PIN'it te sensorit te lageshtise P4 dhe ruajtja e vleres se sensorit ne nje variabel

int VleraDistances  = 0;  //Deklarimi i variables per ruajtjen e vleres se distances se senzorit US HC-SR04
int SasiaRezervuarit = 0; //Deklarimi i variables per ruatjen e vleres se sasise se ujit ne rezervuar [Ne perqindje]

//Deklarimi fleksibil i PIN'ave te ElektroV. dhe rezervuarit (Pompa per mbushje dhe zbrazje)
int Elektrovalvula_1 = 2; 
int Elektrovalvula_2 = 3; 
int Elektrovalvula_3 = 4; 
int Elektrovalvula_4 = 5; //PIN'at e Releve, Moduli 1

int Rezervuari = 6; //Pompa In
int RezervuariZbrazja = 7;//Pompa Out //PIN'at e Releve, Moduli 2

int B1_EV1 = 0;
int B2_EV2 = 0;
int B3_EV3 = 0;
int B4_EV4 = 0;
int B5_REZERVUARI = 0;
int B6_REZERVUARIZBRAZJA = 0; //Vlerat e Butonave fillimisht jane zero, kur te klikohen butonat ndryshon vlera ne 1

void setup()  { //Pjesa ku kodi ekzekutohet vetem njehere
      //Serial.begin(9600); //Aktivizimi i Serial Monitorit****************************

      lcd.backlight(); //Ndezja e drites se LCD
      lcd.init(); //Startimi i LCD Display
      
      Hyrje (); //Thirrja e nenprogramit per paraqitjen e mesazhit hyres
      
      pinMode(trigPin,OUTPUT);
      pinMode(echoPin,INPUT);
	  
      pinMode(Elektrovalvula_1, OUTPUT); 
      pinMode(Elektrovalvula_2, OUTPUT); 
      pinMode(Elektrovalvula_3, OUTPUT); 
      pinMode(Elektrovalvula_4, OUTPUT);
	 
      pinMode(Rezervuari, OUTPUT); 
      pinMode(RezervuariZbrazja, OUTPUT); //Deklarimi i PIN'ave si OUTPUT

      lcd.setCursor(0,0); //Pozicionimi i kursorit per shkruarje ne Display
      lcd.print("Ujitja "); //Shkruarja e fjales Ujitja
}

void loop() { //Pjesa ku kodi ekzekutohet pa nderprere
   VleraDistances = MatjaNivelit(); //Leximi i vleres se senzorit
   SasiaRezervuarit = 100 - ((( VleraDistances - NiveliMax )*100) / NiveliMin);

   Perqindja (); //Thirrja e nenprogramit per shkruarjen e perqindjes se sasise se rezervuarit ne LCD
   
   ButonatL (); //Thirrja e nenprogramit per leximin e butonave
   
   VSL1 = analogRead(SensLageshtise1); //Leximi i Sensorit te Lageshtise P1
   //delay(10);
   VSL2 = analogRead(SensLageshtise2); //Leximi i Sensorit te Lageshtise P2
   //delay(10);
   VSL3 = analogRead(SensLageshtise3); //Leximi i Sensorit te Lageshtise P3
   //delay(10);
   VSL4 = analogRead(SensLageshtise4); //Leximi i Sensorit te Lageshtise P4
   //delay(10);

      //A- po kerkon per tu ujitur, J- nuk ka nevoje per tu ujitur, nese nuk ka uje, kerkesa per tu ujitur paraqitet me A, por elektrovalvula 
      //nuk punon deri sa te mbushet rezervuari me uje.
      if (VSL1 > 700 || B1_EV1 != 0) { //Nese Vlera e Sensorit te lageshtise P1 eshte aktiv, ose eshte klikuar butoni per manualisht, kjo pjese e kodit
	        digitalWrite(Elektrovalvula_1, LOW); //Thirrja e nenprogramit per aktivizim te Relese (Elektrovalvules) 
          //delay(10);
          lcd.setCursor(8,0);
          lcd.print("A1"); 
          //delay(10);
      }
      else { //Qkyqja e Relese (Elektrovalvules)
          lcd.setCursor(8,0); 
          lcd.print("J1");
          //delay(10);
          digitalWrite(Elektrovalvula_1, HIGH);
          //delay(10);
      }
         
      if (VSL2 > 700 || B2_EV2 != 0) { //Nese Vlera e Sensorit te lageshtise P2 eshte aktiv, ose eshte klikuar butoni per manualisht, kjo pjese e kodit
          digitalWrite(Elektrovalvula_2, LOW); //Thirrja e nenprogramit per aktivizim te Relese (Elektrovalvules)
          //delay(10);
          lcd.setCursor(10,0);
          lcd.print("A2"); 
          //delay(10);
      }
      else { //Qkyqja e Relese (Elektrovalvules)
          lcd.setCursor(10,0); 
          lcd.print("J2"); 
          //delay(10);
          digitalWrite(Elektrovalvula_2, HIGH); 
          //delay(10);
      }
       
      if (VSL3 > 700 || B3_EV3 != 0) { //Nese Vlera e Sensorit te lageshtise P3 eshte aktiv, ose eshte klikuar butoni per manualisht, kjo pjese e kodit
          digitalWrite(Elektrovalvula_3, LOW); //Thirrja e nenprogramit per aktivizim te Relese (Elektrovalvules)    
          //delay(10);
          lcd.setCursor(12,0);
          lcd.print("A3"); 
          //delay(10);
      }
      else { //Qkyqja e Relese (Elektrovalvules)
          lcd.setCursor(12,0); 
          lcd.print("J3"); 
          //delay(10);
          digitalWrite(Elektrovalvula_3, HIGH);
          //delay(10);
      }

      if (VSL4 > 700 || B4_EV4 != 0) { //Nese Vlera e Sensorit te lageshtise P4 eshte aktiv, ose eshte klikuar butoni per manualisht, kjo pjese e kodit
          digitalWrite(Elektrovalvula_4, LOW);
          //delay(10);
          lcd.setCursor(14,0);
          lcd.print("A4"); 
          //delay(10);
      }
      else { //Qkyqja e Relese (Elektrovalvules)
          lcd.setCursor(14,0); 
          lcd.print("J4"); 
          //delay(10);
          digitalWrite(Elektrovalvula_4, HIGH);
          //delay(10);
      }
      //Nese butoni per zbrazje, butonat per aktivizim te E.V. ose senzorat jane aktiv duhet te punoje pompa per zbrazje (P Out)
      if (B6_REZERVUARIZBRAZJA != 0||(VSL1>700||VSL2>700||VSL3>700||VSL4>700)||(B1_EV1!=0||B2_EV2!=0||B3_EV3!=0||B4_EV4!=0)) { //Aktivizimi i pompes per zbrazje
           digitalWrite(RezervuariZbrazja, LOW); }
      else { //Qkyqja e pompes per zbrazje
           digitalWrite(RezervuariZbrazja, HIGH);
      }
      
      if (VleraDistances > NiveliMin || B5_REZERVUARI != 0 ) { //Pjesa e kodit qe lejon mbushjen me uje te rezervuarit ne menyre automatike(Senzor) dhe manuale(Buton)
          while (VleraDistances > NiveliMax || B5_REZERVUARI != 0) { //Pjesa e kodit e cila nuk e lejon funksionimin e pompes per zbrazeje nese nuk ka uje dhe eshte duke u mbushur
          //delay(10);
          digitalWrite(Rezervuari, LOW); digitalWrite(RezervuariZbrazja, HIGH); //Aktivizo mbushjen, qaktivizo zbrazjen
          digitalWrite(Elektrovalvula_1, HIGH); digitalWrite(Elektrovalvula_2, HIGH); //Qaktivizo elektrovalvulat 1 dhe 2
          digitalWrite(Elektrovalvula_3, HIGH); digitalWrite(Elektrovalvula_4, HIGH); //Qaktivizo elektrovalvulat 3 dhe 4
          if (VleraDistances <= NiveliMax){ B5_REZERVUARI = 0; }
          VleraDistances = MatjaNivelit(); 
          SasiaRezervuarit = 100 - ((( VleraDistances - NiveliMax )*100) / NiveliMin); //Rikalkulimi i nivelit brenda unazes While
          Perqindja (); //Thirrja e nenprogramit per paraqitjen e perqindjes brenda unazes While
          ButonatL (); //Thirrja e nenprogramit per leximin e butonave brenda unazes While
          /* Brenda unazes While duhet ti thirrim nenprogramet edhe njehere per shkak se nese kodi fillon te ekzekutohet brenda kesaj unaze
             nuk ka qasje ne asnje pjese tjeter te kodit, kshtu qe rrjetha e punes bllokohet per shkak se informatat nuk mund te perditesohen(Update) per shkak se 
             nuk ekzekutohen pjeset e kodit ku behet marrja e informatave nga leximi i senzorave */
          } 
      }
      else if ( VleraDistances < NiveliMax || B5_REZERVUARI == 0 ) { //Pjesa e kodit qe ndalon mbushjen me uje te rezervuarit ne menyre automatike(Senzor) dhe manuale(Buton)
          //delay(10);
          digitalWrite(Rezervuari, HIGH); B5_REZERVUARI = 0;
      }
      
      //teDhanat (); //Bej koment rreshtin nese ke perfunduar me azhurimin e vlerave te senzorave, Sherben per paraqitjen e te dhenave ne SerialMonitor********************
}

void teDhanat () { //Paraqitja e vlerave ne Serial Monitor
  Serial.print("Lageshtia1  : "); 
  Serial.println(VSL1);
  
  Serial.print("Lageshtia2 : "); 
  Serial.println(VSL2);
  
  Serial.print("Lageshtia3 : "); 
  Serial.println(VSL3);
  
  Serial.print("Lageshtia4 : "); 
  Serial.println(VSL4);

  Serial.print("Distanca : ");
  Serial.println(VleraDistances);
}

void Hyrje () { //Paraqitja e mesazhit hyres ne momentin kur te behet ndezja e sistemit 
      lcd.setCursor(0,0);
      lcd.print("**Pershendetje**");
      lcd.setCursor(0,1);
      lcd.print("UjitjaAutomatike");
      delay(2000);
      lcd.setCursor(0,0);
      lcd.print(" me Arduino Uno ");
      lcd.setCursor(0,1);
      lcd.print("  Punuar nga :  ");
      delay(2000);
      lcd.setCursor(0,0);
      lcd.print("- Jakup Berisha ");
      lcd.setCursor(0,1);
      lcd.print("- Mergim Halimi ");
      delay(2000); //Mesazhi hyres kur te ndizet sistemi
}

void Perqindja () { //Paraqitja e perqindjes se nivelit te ujit ne LCD
      lcd.setCursor(0,1); //Pozicionimi i kursorit per shkruarje ne Display
      lcd.print("Rezervuari: "); //Shkruarja e fjales Rezervuari
      lcd.setCursor(14,1);
      lcd.print(" ");
      lcd.setCursor(12,1); //Pozicionimi i kursorit per shkruarje ne Display
      lcd.print(SasiaRezervuarit); //Shkruarja e vleres se nivelit ne perqindje
      lcd.setCursor(15,1); //Pozicionimi i kursorit per shkruarje ne Display
      lcd.print("%"); //Shkruarja e karakterit te perqindjes
}

void ButonatL () { //Leximi i butonave per perdorim manual te sistemit
     Butonat = analogRead(ButonatP); //Leximi i butonave
     
          if (Butonat > 990 && Butonat < 1000)   B1_EV1++; //Nese klikohet butoni pare
     else if (Butonat > 970 && Butonat < 980)    B2_EV2++; //Nese klikohet butoni dyte
     else if (Butonat > 825 && Butonat < 855)    B3_EV3++; //Nese klikohet butoni trete
     else if (Butonat > 800 && Butonat < 820)    B4_EV4++; //Nese klikohet butoni katert
     else if (Butonat > 750 && Butonat < 770)    B5_REZERVUARI++; //Nese klikohet butoni peste (P In)
     else if (Butonat > 680 && Butonat < 700)    B6_REZERVUARIZBRAZJA++; //Nese klikohet butoni gjashte (P Out)
     else if (Butonat > 1005 && Butonat < 1024) {
                                                 B1_EV1 = 0; 
                                                 B2_EV2 = 0; 
                                                 B3_EV3 = 0; 
                                                 B4_EV4 = 0; 
                                                 B5_REZERVUARI = 0;
                                                 B6_REZERVUARIZBRAZJA = 0; } //Nese klikohet butoni shtate (Butoni per reset)
}

int MatjaNivelit() { //metoda per matjen e distances nivelit te rezervuarit permes senzorit  HC-SR04 ne menyre direkte dhe kalkulative
      unsigned int uS = sonar.ping(); // Dergo ping, prano kohen e ping ne mikrosekonda (uS).
      return (uS / US_ROUNDTRIP_CM); //kthe si rezultat distancen permes metodes
}
