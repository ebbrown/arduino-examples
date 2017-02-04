const int SWITCH_PIN = 8;

unsigned long previousTime = 0;
int switchState = 0, prevSwitchState = 0;
int led = 2;
long interval = 50;
bool ascending = true; // Keep track of light direction

void setup() {
  // Initialize pins
  for (int x = 2; x < 8; x++) {
    pinMode(x, OUTPUT);
  }
  pinMode(SWITCH_PIN, INPUT);
}

void loop() {
  unsigned long currentTime = millis();
  
  if (currentTime - previousTime > interval) {
    // Apply or remove lights depending on set interval
    if (ascending) {
      previousTime = currentTime;
      digitalWrite(led, HIGH);
      led++;
      
      if (led > 7) {
        ascending = false;
      }
    } else {
      previousTime = currentTime;
      digitalWrite(led, LOW);
      led--;

      if (led < 2) {
        ascending = true;  
      }
    }
  }
  
  switchState = digitalRead(SWITCH_PIN);

  // Reset configuration on tilt switch changes
  if (switchState != prevSwitchState) {
    for (int x = 2;x < 8; x++) {
      digitalWrite(x, LOW); 
    }
    led = 2;
    previousTime = currentTime;
    ascending = true;
  }
  
  prevSwitchState = switchState;
}
