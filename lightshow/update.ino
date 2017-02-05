void mainUpdate () {
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
