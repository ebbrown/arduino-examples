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
    mode = (mode + 1) % 4;
    resetDisplay();
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
    case 3:
      spiralGlow();
      break;
  }
}

/*
   Helpers
*/

void resetDisplay () {
  clearLights();
  resetLEDIndex();
  resetInterval();
  spiralAscending = true;  
}

int resetLEDIndex () {
  switch (mode) {
    case 0:
      currentLED = 2;
      break;
    case 1: 
      currentLED = 7;
      break;
    case 2:
    case 3:
      spiralIndex = 0;
      break;
  }
}

int resetInterval () {
  switch (mode) {
    case 0:
    case 1:
    case 2:
      interval = 50;
      break;
    case 3: 
      interval = 100;
      break;
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
