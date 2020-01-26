#define red 9
#define green 10
#define blue 11
const int trigpin=3;
const int echopin=6;

long duration;
int dist;
void setup() {
  // put your setup code here, to run once:
pinMode(red,OUTPUT);
pinMode(green,OUTPUT);
pinMode(blue,OUTPUT);
pinMode(trigpin,OUTPUT);
pinMode(echopin,INPUT);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(trigpin,LOW);
delayMicroseconds(2);

digitalWrite(trigpin,HIGH);
delayMicroseconds(10);
digitalWrite(trigpin,LOW);

duration=pulseIn(echopin,HIGH);

dist=duration*0.034/2;

if(dist>=50)
{
  for(int i=0;i<=255;i+=51)
{
  analogWrite(green,i);
  delay(100);
}
for(int j=255;j>=0;j-=51)
{
  analogWrite(green,j);
  delay(100);
}
  
  Serial.println("Animal is at distance:");
  Serial.println(dist);
  Serial.println("Please move to Observatory A");
}
else if(dist>=25 && dist<50)
{
  for(int i=0;i<=255;i+=51)
{
  analogWrite(blue,i);
  delay(50);
}
for(int j=255;j>=0;j-=51)
{
  analogWrite(blue,j);
  delay(50);
}
  
  Serial.println("Animal is at distance:");
  Serial.println(dist);
  Serial.println("Please move to Observatory B");
}
else
{
  for(int i=0;i<=255;i+=51)
{
  analogWrite(red,i);
  delay(25);
}
for(int j=255;j>=0;j-=51)
{
  analogWrite(red,j);
  delay(25);
}
  
  Serial.println("Animal is at distance:");
  Serial.println(dist);
  Serial.println("Please move to Observatory C");
}
}
