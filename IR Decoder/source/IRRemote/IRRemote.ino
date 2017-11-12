#include <IRremote.h> 

int recvLED = 11;
int recvPin = 10;

IRrecv irReciver(recvPin);
decode_results results;

// Definimi i PIN'ave te diodes 7Seg.
byte s7segment[] = { 2, 3, 4, 5, 6, 7, 8, 9 };

// Initializing the digits array
byte digits[][20] = {
   { 0, 0, 0, 0, 0, 0, 1, 1}, // Numri 0
   { 1, 0, 0, 1, 1, 1, 1, 1}, // Numri 1
   { 0, 0, 1, 0, 0, 1, 0, 1}, // Numri 2
   { 0, 0, 0, 0, 1, 1, 0, 1}, // Numri 3
   { 1, 0, 0, 1, 1, 0, 0, 1}, // Numri 4
   { 0, 1, 0, 0, 1, 0, 0, 1}, // Numri 5
   { 0, 1, 0, 0, 0, 0, 0, 1}, // Numri 6
   { 0, 0, 0, 1, 1, 1, 1, 1}, // Numri 7
   { 0, 0, 0, 0, 0, 0, 0, 1}, // Numri 8
   { 0, 0, 0, 0, 1, 0, 0, 1}, // Numri 9
   { 0, 0, 1, 1, 0, 0, 0, 1}, // Butoni POWER
   { 0, 0, 0, 1, 0, 0, 1, 1}, // Zeri larte
   { 1, 0, 0, 0, 0, 0, 1, 1}, // zeri poshte
   { 0, 1, 1, 0, 0, 0, 1, 1}, // Majtas
   { 0, 0, 0, 0, 1, 1, 1, 1}, // Djathtas
   { 0, 1, 1, 0, 0, 0, 0, 1}, // CH -
   { 1, 0, 0, 1, 0, 0, 0, 1}, // CH
   { 0, 0, 0, 0, 1, 1, 0, 1}, // CH +
   { 0, 1, 1, 1, 0, 0, 0, 1}, // F +
   { 0, 0, 0, 1, 1, 1, 0, 1}  // F -
};

const unsigned long decodeHASH[] = { // Dekodimi i  sinjalit te pranuar nga telekomanda
  0xFF6897, // Numri 0
  0xFF30CF, // Numri 1
  0xFF18E7, // Numri 2 
  0xFF7A85, // Numri 3
  0xFF10EF, // Numri 4
  0xFF38C7, // Numri 5
  0xFF5AA5, // Numri 6
  0xFF906F, // Numri 7
  0xFF4AB5, // Numri 8
  0xFF52AD, // Numri 9
  0xFFC23D, // Butoni POWER
  0xFFA857, // Zeri larte 
  0xFFE01F, // Zeri poshte
  0xFF22DD, // Majtas
  0xFF02FD, // Djathtas
  0xFFA25D, // CH -
  0xFF629D, // CH
  0xFFE21D, // CH +
  0xFF9867, // F +
  0xFFB04F, // F -
};
  
unsigned long lastTime = 0;
  
void setup()
{
  pinMode(recvLED, OUTPUT); //Deklarimi i PIN'it qe tregon se ka pranuar sinjal si output. (LED'i)
  digitalWrite(recvLED, LOW); //Ndalja e rrymes per LED'in
  pinMode(A0, OUTPUT); //Per shkak se 7Seg eshte me CommonAnode, A0 eshte lidhur Anoda. Deklarojme si Output
  Serial.begin(9600); // E inicializojme portin serik me shpejtesi 9600 BitPerSecond

  irReciver.enableIRIn(); // Startimi i pranuesit.
  
  for (int i=0; i<8; i++) 
  {
    pinMode(s7segment[i], OUTPUT); //Konfigurimi i te gjithe PIN'ave te 7Seg. si OUTPUT (Unaza ka per detyre ti numroje)
  }  
}

void loop()
{
  unsigned long recv_value;
  
  if (irReciver.decode(&results)) {
    recv_value = results.value; 
    
    if (  recv_value != 0xFFFFFFFF )
    {
      // Beje LED in te Blinkoje sa here qe te shtypet nje buton.
      digitalWrite(recvLED, HIGH);
      delay(10);
      digitalWrite(recvLED, LOW);  
      digitalWrite(A0,HIGH);
      // Shtype rezultatin e shtypjes se butonave (Ne Serial Monitor, Vetem per te dekoduar Hex Kodin per secilin buton te shtypur per te programuar numrat)
      Serial.println(recv_value, HEX);
      
      //Kerko neper HASH'in e pranuar se a po pershtatet me ndonje HASH qe e kemi programuar
      for (int i=0; i<20; i++)
      {
        if ( recv_value == decodeHASH[i] ) // Nese HASH'i i pranuar u pershtat me ndonje, ndize nje TIMER qe mos ta leje non stop ndezur por ta ndale.
        { 
          lastTime = millis(); // Startimi i TIMER it
          for (int j=0; j<=8; j++)
            //Ndezja e 7Seg, varesisht se cilet bita i kemi ndezur (0 ose 1) nga fillimi i programit.
            digitalWrite(s7segment[j], digits[i][j]);
            
          break; // Dil nga unaza sepse tanime perfundoi procesi i programit
        }
      }
    }
    irReciver.resume(); // Lexo vleren e ardhshme
  }
  
  // Ndali 7Seg. nese eshte arritur kuota e TIMERIT prej 5 Sekondash
  if ( millis() - lastTime >= 5000 )
  {
    for (int k=0; k<=8; k++)
      digitalWrite(s7segment[k], LOW);
      digitalWrite(A0,LOW);
    lastTime = 0; // Reseto TIMERIN ne '0'  
  }
}
