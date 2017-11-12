import processing.serial.*; // Therret librarine per komunikimin Serik
import java.awt.event.KeyEvent; // Therret librarine per leximin e vlerave nga Porti Serik
import java.io.IOException;

Serial myPort; // Definon Objektin Serial [Per komunikim Serik]
// Paraqitja e Variablave
String angle="";
String distance="";
String data="";
String noObject;
String Paralajmerimi;
String Armatimi;
float pixsDistance;
int iAngle, iDistance;
int index1=0;
int index2=0;
PFont orcFont;

void setup() {
  
 size (1000, 600); // ***Caktimi i madhesise se dritares vizualizuese***
 smooth();
 myPort = new Serial(this,"COM3", 9600); // Fillon komunikimin serik me paisjen
 myPort.bufferUntil('.'); // Lexon vlerat e derguara nga senzori dhe e kupton me simbolin '.' qe te dhenat u lexuan.
 orcFont = loadFont("Consolas.vlw"); //Cakton se qfare shkronja te perdoren gjate vizualizimit
}

void serialEvent (Serial myPort) { // Fillon leximin e te dhenave nga Porti Serik
  // Lexon vlerat deri te karakteri '.' dhe i vendose ne nje variabel "data".
  data = myPort.readStringUntil('.');
  data = data.substring(0,data.length()-1);
  
  // E gjen karakterin ',' dhe i ndan dy vlerat e ruajtura me heret ne nje variabel ne dy variabla
  index1 = data.indexOf(","); 
  angle= data.substring(0, index1); //Fillon prej 0, deri te ','
  distance= data.substring(index1+1, data.length()); //Fillon prej ',' deri ne fund
  
  // Vlerat i konverton nga String ne Integer [Numer]
  iAngle = int(angle);
  iDistance = int(distance);
}

void draw() {
  
  fill(98,245,31);
  textFont(orcFont);
  // Simulimi i hijezimeve te detektimit te radarit
  noStroke();
  fill(0,4); 
  rect(0, 0, width, height-height*0.065); 
  
  fill(98,245,31); // Ngjyra e gjelber
  // Therret funksionet per vizatimin e Radarit
  drawRadar(); 
  drawLine();
  drawObject();
  drawText();
}

void drawRadar() {
  pushMatrix();
  translate(width/2,height-height*0.074); // Levizja e koordinatave fillestare ne lokacionin e ri
  noFill();
  strokeWeight(2);
  stroke(98,245,31);
  // draws the arc lines
  arc(0,0,(width-width*0.0625),(width-width*0.0625),PI,TWO_PI);
  arc(0,0,(width-width*0.27),(width-width*0.27),PI,TWO_PI);
  arc(0,0,(width-width*0.479),(width-width*0.479),PI,TWO_PI);
  arc(0,0,(width-width*0.687),(width-width*0.687),PI,TWO_PI);
  // draws the angle lines
  line(-width/2,0,width/2,0);
  line(0,0,(-width/2)*cos(radians(30)),(-width/2)*sin(radians(30)));
  line(0,0,(-width/2)*cos(radians(60)),(-width/2)*sin(radians(60)));
  line(0,0,(-width/2)*cos(radians(90)),(-width/2)*sin(radians(90)));
  line(0,0,(-width/2)*cos(radians(120)),(-width/2)*sin(radians(120)));
  line(0,0,(-width/2)*cos(radians(150)),(-width/2)*sin(radians(150)));
  line((-width/2)*cos(radians(30)),0,width/2,0);
  popMatrix();
}

void drawObject() {
  pushMatrix();
  translate(width/2,height-height*0.074); // Levizja e koordinatave fillestare ne lokacionin e ri
  strokeWeight(9);
  stroke(255,10,10); // red color
  pixsDistance = iDistance*((height-height*0.1666)*0.025); // Konvertimi i distances se pranuar nga senzori prej Cm ne Pixels
  // Limitimi i teritorit deri ne 40 cm
  if(iDistance<40){
    // Vizatimi i objektit duke marre parasysh kendin dhe distancen
  line(pixsDistance*cos(radians(iAngle)),-pixsDistance*sin(radians(iAngle)),(width-width*0.505)*cos(radians(iAngle)),-(width-width*0.505)*sin(radians(iAngle)));
  }
  popMatrix();
}

void drawLine() {
  pushMatrix();
  strokeWeight(9);
  stroke(30,250,60);
  translate(width/2,height-height*0.074); // Levizja e koordinatave fillestare ne lokacionin e ri
  line(0,0,(height-height*0.12)*cos(radians(iAngle)),-(height-height*0.12)*sin(radians(iAngle))); // draws the line according to the angle
  popMatrix();
}

void drawText() { // draws the texts on the screen
  
  pushMatrix();
  if ( iDistance<40 && iDistance>35 ) { Paralajmerimi = " i Pare  Dil nga teritori"; }
  if ( iDistance<35 && iDistance>30 ) { Paralajmerimi = " i dyte  Dil nga teritori"; }
  if ( iDistance<30 && iDistance>25 ) { Paralajmerimi = " i trete Dil nga teritori"; }
  if ( iDistance>=40 || (iDistance>0 && iDistance<15) ) { Paralajmerimi = " Gjendja Stabile"; }
  if ( iDistance<25 && iDistance>15 ) { Paralajmerimi = " Armiku u rrezua"; }
  if ( iDistance<25 ) { Armatimi = " Raketa u leshua"; }
  if ( iDistance>25 ) { Armatimi = " Eshte Gati"; }
  
  if(iDistance>40) {
  noObject = "Nuk ka";
  }
  else {
  noObject = "Ka";
  }
  fill(0,0,0);
  noStroke();
  rect(0, height-height*0.0648, width, height);
  fill(98,245,31);
  textSize(20);
  
  text("10cm",width-width*0.3854,height-height*0.0833);
  text("20cm",width-width*0.281,height-height*0.0833);
  text("30cm",width-width*0.177,height-height*0.0833);
  text("40cm",width-width*0.0729,height-height*0.0833);
  textSize(20);
  text("Objekt: " + noObject, width-width*0.875, height-height*0.0377);
  text("Kendi: " + iAngle +" °", width-width*0.48, height-height*0.0377);
  text("Distanca: ", width-width*0.26, height-height*0.0377);
  
  text("Paralajmerimi: " + Paralajmerimi, width-width*0.875, height-height*0.0100);
  text("Armatimi: " + Armatimi, width-width*0.35, height-height*0.0100);
  
  if(iDistance<40) {
  text("        " + iDistance +" cm", width-width*0.225, height-height*0.0377);
  }
  textSize(20);
  fill(98,245,60);
  translate((width-width*0.4994)+width/2*cos(radians(30)),(height-height*0.0907)-width/2*sin(radians(30)));
  rotate(-radians(-60));
  text("30°",0,0);
  resetMatrix();
  translate((width-width*0.503)+width/2*cos(radians(60)),(height-height*0.0888)-width/2*sin(radians(60)));
  rotate(-radians(-30));
  text("60°",0,0);
  resetMatrix();
  translate((width-width*0.507)+width/2*cos(radians(90)),(height-height*0.0833)-width/2*sin(radians(90)));
  rotate(radians(0));
  text("90°",0,0);
  resetMatrix();
  translate(width-width*0.513+width/2*cos(radians(120)),(height-height*0.07129)-width/2*sin(radians(120)));
  rotate(radians(-30));
  text("120°",0,0);
  resetMatrix();
  translate((width-width*0.5104)+width/2*cos(radians(150)),(height-height*0.0574)-width/2*sin(radians(150)));
  rotate(radians(-60));
  text("150°",0,0);
  popMatrix(); 
}