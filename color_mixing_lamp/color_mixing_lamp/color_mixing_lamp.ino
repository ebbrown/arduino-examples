const int GREEN_LED_PIN = 9, RED_LED_PIN = 10, BLUE_LED_PIN = 11;
const int RED_SENSOR_PIN = A0, GREEN_SENSOR_PIN = A1, BLUE_SENSOR_PIN = A2;

int redValue, greenValue, blueValue;
int redSensorValue, greenSensorValue, blueSensorValue;

void setup() {
  Serial.begin(9600);

  pinMode(GREEN_LED_PIN, OUTPUT);
  pinMode(RED_LED_PIN, OUTPUT);
  pinMode(BLUE_LED_PIN, OUTPUT);
}

void loop() {
  redSensorValue = analogRead(RED_SENSOR_PIN);
  delay(5);
  greenSensorValue = analogRead(GREEN_SENSOR_PIN);
  delay(5);
  blueSensorValue = analogRead(BLUE_SENSOR_PIN);
  
  Serial.print("Raw Sensor Values \t Red: ");
  Serial.print(redSensorValue);
  Serial.print("\t Green: ");
  Serial.print(greenSensorValue);
  Serial.print("\t Blue: ");
  Serial.println(blueSensorValue);
  
  redValue = redSensorValue/4;
  greenValue = greenSensorValue/4;
  blueValue = blueSensorValue/4;
  
  Serial.print("Mapped Sensor Value \t Red: ");
  Serial.print(redValue);
  Serial.print("\t Green: ");
  Serial.print(greenValue);
  Serial.print("\t Blue: ");
  Serial.println(blueValue);

  analogWrite(RED_LED_PIN, redValue);
  analogWrite(GREEN_LED_PIN, greenValue);
  analogWrite(BLUE_LED_PIN, blueValue);
}
