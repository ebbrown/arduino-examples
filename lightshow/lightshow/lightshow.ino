unsigned long previousTime = 0;
int ledIndex = 0;
int ledPattern[6] = {2, 7, 3, 6, 4, 5};
long interval = 50;
bool ascending = true; // Keep track of light direction

void setup() {
  // Initialize pins
  for (int x = 2; x < 8; x++) {
    pinMode(x, OUTPUT);
  }
}

void loop() {
  unsigned long currentTime = millis();

  if (currentTime - previousTime > interval) {
    if (ascending && changeLightStatus(HIGH, currentTime) > 6) {
      ascending = false;
    } else if (!ascending && changeLightStatus(LOW, currentTime) < 0) {
      ascending = true;
    }
  }
}

int changeLightStatus (int output, unsigned long currentTime) {
  previousTime = currentTime;
  digitalWrite(ledPattern[ledIndex], output);
  return ascending ? ++ledIndex : --ledIndex;
}
