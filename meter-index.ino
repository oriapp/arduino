# include <LiquidCrystal.h>

const int trigPin = 7; //  Blonk Blue
const int echoPin = 8; // Blink red

LiquidCrystal lcd(12, 11, 5, 4, 3, 2); // LCD parameters

void setup(){
  lcd.begin(16, 2); // Shhot up the LCD (;
  Serial.begin(9600);
  
}

void loop(){
  lcd.clear(); // clear all inputs before printing anythign 
  long duration, inches, cm, mm;
  pinMode(trigPin, OUTPUT); 
  digitalWrite(trigPin, LOW); 
delayMicroseconds(2000); 
digitalWrite(trigPin, HIGH); 
delayMicroseconds(1000); 
digitalWrite(trigPin, LOW);
pinMode(echoPin, INPUT); 
duration = pulseIn(echoPin, HIGH);
inches = microsecondsToInches(duration); 
cm = microsecondsToCentimeters(duration);
mm = microsecondsToMillimeters(duration);
lcd.print(cm);
lcd.print("cm, ");
lcd.print(mm);
lcd.print(" mm");
delay(250);
 //lcd.cursor();
 //lcd.scrollDisplayLeft();
 //delay(200);
 //lcd.noCursor();
 //delay(500);
}


long microsecondsToInches(long microseconds)
{return microseconds / 74 / 2;}
long microsecondsToCentimeters(long microseconds)
{return microseconds / 29 / 2;}
long microsecondsToMillimeters(long microseconds)
{return microseconds / 2.9 / 2;}
