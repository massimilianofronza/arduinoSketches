#include <Servo.h>

Servo myServo;

const int digitalMotorPin = 9;

const int analogPotPin = A0;
int potVal;
int angle;

int motorVal;

void setup() {
  Serial.begin(9600);

  myServo.attach(digitalMotorPin);
}

void loop() {
  potVal = analogRead(analogPotPin);
  angle = map(potVal, 0, 1023, 0, 179);

  Serial.print("Analog Potentiometer:\n");
  Serial.print("\tValue: " + (String)potVal + "\n");
  Serial.print("\tAngle: " + (String)angle + "\n");

  motorVal = digitalRead(digitalMotorPin);
  Serial.print("Digital Motor Value: " + (String)motorVal + "\n");

  myServo.write(angle);
  delay(15);
}
