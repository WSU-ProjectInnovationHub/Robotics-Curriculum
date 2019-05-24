#include <Servo.h>

Servo myServo;
const int servoPin = 13;

void setup() {
  myServo.attach(servoPin);
}

void loop() {
  myServo.write(30);
  delay(1000);
  myServo.write(90);
  delay(1000);  
  myServo.write(145);
  delay(1000);
}
