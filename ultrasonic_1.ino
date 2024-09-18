#define SOUND_VELOCITY 0.034
#include <Servo.h>
const int trig = 12; //d06
const int echo = 14; //d5

Servo myservo;
int duration = 0;
int distance = 0;
int deg=0;

void setup() {
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  myservo.attach(16);  

  Serial.begin(9600);
}

void loop() {
  digitalWrite(trig, HIGH);
  
  digitalWrite(trig, LOW);

  duration = pulseIn(echo, HIGH);
  distance = duration * SOUND_VELOCITY/2;
  Serial.println(distance);
 Serial.print("Distance (cm): ");
  Serial.println(distance);
  if (distance <= 5) 
  {
    deg=30;
    myservo.write(deg);
    delay(2000);
  } 
  else if (distance <= 10) 
  {
    deg=60;
    myservo.write(deg);
    delay(2000);
  }
else if (distance <= 15) 
 {
  deg=90;
    myservo.write(deg);
    delay(2000);
 }
 else if (distance <= 20) 
 {
  deg=120;
    myservo.write(deg);
    delay(2000);
 }
  
}