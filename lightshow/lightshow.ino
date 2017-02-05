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
  mainUpdate();
}
