#include "Servo.h"

Servo myservo;

void setup() {
  myservo.attach(12);
}

void loop() {
  myservo.write(90);
  delay(1000);
  myservo.write(0);
  delay(400);
  myservo.write(45);
  delay(400);
  myservo.write(0);
  delay(400);
  myservo.write(60);
  delay(400);
  myservo.write(0);
  delay(400);
  myservo.write(45);
  delay(400);
  myservo.write(0);
  delay(400);
  myservo.write(90);
  delay(400);
  myservo.write(0);
  delay(400);
  myservo.write(45);
  delay(400);
  myservo.write(0);
  delay(400);
  myservo.write(60);
  delay(400);
  myservo.write(0);
  delay(400);
  myservo.write(45);
  delay(400);
  myservo.write(0);
  delay(400);
}
