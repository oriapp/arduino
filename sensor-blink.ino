const int out=12;
const int in=13;
void setup() {
  Serial.begin(9700);
  pinMode(out,OUTPUT);
  pinMode(in,INPUT);
  pinMode(8, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(6, OUTPUT);
}
void loop() {
  long durs;
  digitalWrite(out,LOW);
  delayMicroseconds(2);
  digitalWrite(out,HIGH);
  delayMicroseconds(10);
  digitalWrite(out,LOW);
  durs = pulseIn(in,HIGH);
  Serial.println(String(durs));
  digitalWrite(6, LOW);
  if(durs <= 800){
    Serial.println("buzz " + String(durs));
    digitalWrite(6, LOW);
    digitalWrite(8, HIGH);
    digitalWrite(7, HIGH);
  } else {
    digitalWrite(8, LOW);
    digitalWrite(7, LOW);
    digitalWrite(6, HIGH);
  }
  delay(10);
}
