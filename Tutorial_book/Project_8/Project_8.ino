const int switchPin = 8;
int switchState = 0, prevSwitchState = 0;

int nextLed = 2;
unsigned long previousTime = 0;

// interval between each LED turning on in milliseconds
long interval = 2000;

void setAllLeds(int status) {
  for (int i=2; i<5; i++) {
    digitalWrite(i, status);
  }
}

void setup() {
  Serial.begin(9600);
  for (int i=2; i<5; i++) {
    pinMode(i, OUTPUT);
  }
  pinMode(switchPin, INPUT);
}

void loop() {
  unsigned long currentTime = millis();

  if (currentTime - previousTime > interval) {
    // if all the pins are already HIGH, make them blink
    if (nextLed > 4) {
      setAllLeds(LOW);
      delay(250);
      setAllLeds(HIGH);
    }

    previousTime = currentTime;
    digitalWrite(nextLed, HIGH);
    nextLed++;

    switchState = digitalRead(switchPin);
    Serial.println(switchState);

    if (switchState != prevSwitchState) {
      setAllLeds(LOW);
      nextLed = 2;
      previousTime = currentTime;
    }

    prevSwitchState = switchState;
  }
}
