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
