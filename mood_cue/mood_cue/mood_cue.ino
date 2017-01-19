#include <Servo.h>
Servo myServo;

const int POT_PIN = A0;
int potVal, angle;

void setup() {
  myServo.attach(9);
  Serial.begin(9600);
}

void loop() {
  potVal = analogRead(POT_PIN);
  Serial.print("potVal: ");
  Serial.print(potVal);

  // Scale values from the potentiometer to an angle for the motor
  angle = map(potVal, 0, 1023, 0, 179);
  Serial.print(", angle: ");
  Serial.println(angle);

  myServo.write(angle);
  delay(15);
}
