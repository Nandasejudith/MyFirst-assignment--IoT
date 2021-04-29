#include <Servo.h>
Servo myServo;
int potpin=0;
int Red = 4;
int Blue = 2;
int Green=3;
int val;
Servo servo1;
int trigpin=5;
int echopin=6;
long distance;
long duration;
 
void setup()
{
 pinMode(Red, OUTPUT);
 pinMode(Blue, OUTPUT);
  pinMode(Green,OUTPUT);
  myServo.attach(9);
  pinMode(trigpin,OUTPUT);
  pinMode(echopin,INPUT);
}
 
void loop() {
  
 ultra();
  myServo.write(0);
  val=analogRead(potpin);
  val = map(val, 0,1023,0,100);
  myServo.write(val);
   delay(15);
  
  if(distance <=9){
  digitalWrite(Red,HIGH);
  delay(2000);
  digitalWrite(Red, LOW);
  delay(1000);
   myServo.write(60);
  }
   else  { myServo.write(0);}
  if (distance<=9){
  digitalWrite(Blue, HIGH);
  delay(3000);
  digitalWrite(Blue,LOW);
  delay(3000);  
   myServo.write(120);
 }
 
  else { myServo.write(0);}
   if (distance<=9){
  digitalWrite(Green,HIGH);
  delay(3000);
  digitalWrite(Green,LOW);
  delayMicroseconds(3000);
  myServo.write(180);
    }
 
   
  else{ myServo.write(0);}
}
void ultra(){
  digitalWrite(trigpin,LOW);
  delayMicroseconds(10);
  digitalWrite(trigpin,HIGH);
  delayMicroseconds(20);
  digitalWrite(trigpin,LOW);
  duration = pulseIn(echopin, HIGH);
  //distance=duration*0.343/2;
}

/*WHERE SERVO MOTORS ARE USED IN MY ENVIRONMENT.

->Home electric devices like DVD and blu-ray disc players
use servos to extract and retrct disc trays
->Automobiles also use servo motors.In modern cars,servo motors
are used to control their speed.
->Servos are also most-suited for electrically operated pieces of machinery
such as elevators, rudders, walking robots, and operating grippers.*/

