void printColorValues(String, int, int, int);

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

  printColorValues("Raw", redSensorValue, greenSensorValue, blueSensorValue);
  
  redValue = redSensorValue/4;
  greenValue = greenSensorValue/4;
  blueValue = blueSensorValue/4;

  printColorValues("Mapped", redValue, greenValue, blueValue);

  analogWrite(RED_LED_PIN, redValue);
  analogWrite(GREEN_LED_PIN, greenValue);
  analogWrite(BLUE_LED_PIN, blueValue);
}

void printColorValues(String printType, int redVal, int greenVal, int blueVal) {
  Serial.print(printType);
  Serial.print(" Sensor Value \t Red: ");
  Serial.print(redVal);
  Serial.print("\t Green: ");
  Serial.print(greenVal);
  Serial.print("\t Blue: ");
  Serial.println(blueVal);
}

