#include <Servo.h> //E therret librarine e Servo

const int trigPin = 9;// Pin'i Trigg per senzorin US HC-SR04
const int echoPin = 10;// Pin'i Echo  per senzorin US HC-SR04

long Kohezgjatja;// Variabla per ruajtjen e kohezgjatjes
int Distanca;// Variabla per ruajtjen e Distancas

Servo myServo; // Krijon objektin per kontrollimin e Servo

void setup() { 
  pinMode(trigPin, OUTPUT); // Definon Pin'in Trigg si dales
  pinMode(echoPin, INPUT); // Definon Pin'in Echo si hyres
  pinMode(A0, OUTPUT); // Definon Pin'in e Armeve si dales

  Serial.begin(9600);
  myServo.attach(11); // Definon Pin'in ku eshte lidhur Servo
}
void loop() { 
  // Rotullon Servon prej 15 Shkalle deri ne 165 Shkalle
  for(int i=15;i<=165;i++){  
  myServo.write(i);
  delay(30);
  Distanca = LlogaritDistancen();// Therret funksionin i cili do ta kalkuloje Distancan e pranuar nga senzori
  
  Serial.print(i); // Dergon shkallen e detektuar nga senzori per tu vizualizuar
  Serial.print(","); // Dergon nje simbol qe ti tregoje Processing se Shkalla u pranua dhe pregaditu per vleren tjeter
  Serial.print(Distanca); // Dergon Distancan e detektuar nga senzori per tu vizualizuar
  Serial.print("."); // Dergon nje simbol qe ti tregoje Processing se Distaca u pranua dhe nuk ka vlere tjeter qe duhet pranuar
  if ( Distanca<25 && Distanca> 0 ) { analogWrite(A1, 255); } //Sherben si interrapt me Prioritet
  if ( Distanca>25 ) { analogWrite(A1, 0); } //Sherben si interrapt me Prioritet
  }
  // Rotullon Servon prej 165 Shkalle deri ne 15 Shkalle
  for(int i=165;i>15;i--){  
  myServo.write(i);
  delay(30);
  Distanca = LlogaritDistancen();
  Serial.print(i);
  Serial.print(",");
  Serial.print(Distanca);
  Serial.print(".");
  if ( Distanca<25 && Distanca> 0 ) { digitalWrite(A1, HIGH); }
  if ( Distanca>25 ) { digitalWrite(A1, LOW); }

} }
// Funksioni per llogaritjen e distances se pranuar nga senzori Ultrasonic
int LlogaritDistancen(){ 
  
  digitalWrite(trigPin, LOW); 
  delayMicroseconds(2);
  // Dergon sinjal te Pin'i Trigg per 10 micro seconda
  digitalWrite(trigPin, HIGH); 
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  Kohezgjatja = pulseIn(echoPin, HIGH); // Lexon Pin'in Echo dhe e kthen valen e tingullit ne micro seconda
  Distanca= Kohezgjatja*0.034/2;
  return Distanca;
}
