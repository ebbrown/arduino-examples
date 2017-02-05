unsigned long previousTime = 0;
int currentLED = 2;
long interval = 50;
int switchState, prevSwitchState, mode = 0;

int spiralPattern[] = {2, 7, 3, 6, 4, 5};
int spiralIndex = 0;
bool spiralAscending = true;

void setup() {
  // Initialize pins
  for (int x = 2; x < 8; x++) {
    pinMode(x, OUTPUT);
  }
  pinMode(8, INPUT);
}

void loop() {
  unsigned long currentTime = millis();
  toggleLightModeOnKeyUp(digitalRead(8));
  
  if (currentTime - previousTime > interval)
    showLights(currentTime);
}

void toggleLightModeOnKeyUp (int switchState) {
  // Listen for changes in button  
  bool toggled = false;

  while (switchState == 1) {
    toggled = true;
    switchState = digitalRead(8);
  }

  if (toggled) {
    clearLights();
    mode = (mode + 1) % 3;
    resetLED();
  }

}

void showLights (unsigned long currentTime) {
  previousTime = currentTime;
  switch (mode) {
    case 0:
      linearGlow(true);
      break;
    case 1:
      linearGlow(false);
      break;
    case 2:
      if (spiralAscending) {
        spiralGlow(HIGH);
        if (spiralIndex > 8) spiralAscending = false;
      } else {
        spiralGlow(LOW);
        if (spiralIndex < 0) spiralAscending = true;
      }
      break;
  }
}

/*
 * Light Types
 */

void linearGlow (bool ascending) {
  digitalWrite(currentLED, HIGH);

  if (ascending) {
    currentLED++;
    if (currentLED > 8) loopLights(0);
  } else {
    currentLED--;
    if (currentLED < 0) loopLights(7);
  }
}

void spiralGlow (int input) {
  digitalWrite(spiralPattern[spiralIndex], input);
  input > 0 ? spiralIndex++ : spiralIndex--;
}

/*
 * Helpers
 */

int resetLED () {
  switch (mode) {
    case 0: currentLED = 2;
    case 1: currentLED = 7;
    case 2: spiralIndex = 0;
  }
}

void clearLights () {
  for (int i = 2; i < 8; i++) {
    digitalWrite(i, LOW);
  }
}

void loopLights (int led) {
  clearLights();
  currentLED = led;
}
