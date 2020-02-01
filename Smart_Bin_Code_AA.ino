#define TRIGGER 13
#define ECHO    15

#include <ESP8266WiFi.h>
#include <Servo.h> // including servo library.

Servo servo_1; // Giving name to servo.

void setup (){
  servo_1.attach(0); // Attaching Servo to D3
  pinMode(TRIGGER, OUTPUT);
  pinMode(ECHO, INPUT);
}

void loop(){

  long duration, distance;
  digitalWrite(TRIGGER, LOW);  
  delayMicroseconds(2); 
  
  digitalWrite(TRIGGER, HIGH);
  delayMicroseconds(10); 
  
  digitalWrite(TRIGGER, LOW);
  duration = pulseIn(ECHO, HIGH);
  distance = (duration/2) / 29.1;

  if(distance<40){
  servo_1.write (170); // Servo will move to 45 degree angle.
  delay (4000);
  }
  else{
  servo_1.write (0);  // servo will move to 90 degree angle.
  }
}
