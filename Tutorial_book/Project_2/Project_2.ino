int switchState = 0;

void setup() {
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(2, INPUT);

  Serial.begin(9600);
}

void loop() {
  switchState = digitalRead(2);
  Serial.println("Switch state: " + (String)switchState);

  if (switchState == LOW) {
    // button is not pressed

    digitalWrite(3, HIGH); // yellow led
    digitalWrite(4, LOW);  // green led
    digitalWrite(5, LOW);  // red led
  }
  
  else {
    digitalWrite(3, LOW);  // yellow led
    digitalWrite(4, LOW); // green led
    digitalWrite(5, HIGH); // red led

    delay(250);
    digitalWrite(4, HIGH); // green led
    digitalWrite(5, LOW); // red led
    delay(250);
  }
}
