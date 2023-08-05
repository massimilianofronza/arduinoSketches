const int sensorPin = A0;
float baselineTemp = -1;

float getTemperature() {
  // Read ADC sensor value
  int sensorVal = analogRead(sensorPin);
  Serial.print("Sensor value(ADC): " + (String)sensorVal);
  
  // convert the ADC reading to voltage
  float voltage = (sensorVal/1024.0) * 5.0;
  Serial.print(", Volts: " + (String)voltage);
  
  // Convert from voltage to Celsius temperature
  float temperature = (voltage - 0.5) *100;
  
  return temperature;
}

void setup() {
  Serial.begin(9600);

  for (int pinNumber=3; pinNumber<6; pinNumber++) {
    pinMode(pinNumber, OUTPUT);
    digitalWrite(pinNumber, LOW);
  }

  baselineTemp = getTemperature();
}

void loop() {
  float temperature = getTemperature();
  Serial.println(", Sensor degrees C: " + (String)temperature + ", Baseline: " + baselineTemp);

  if (temperature < baselineTemp+1) {
    digitalWrite(3, LOW);  // yellow led
    digitalWrite(4, LOW);  // green led
    digitalWrite(5, LOW);  // red led
  }
  else if (temperature >= baselineTemp+2 && temperature < baselineTemp+4) {
    digitalWrite(3, HIGH);
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
  }
  else if (temperature >= baselineTemp+4 && temperature < baselineTemp+6) {
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
    digitalWrite(5, LOW);
  }
  else if (temperature >= baselineTemp+4) {
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
    digitalWrite(5, HIGH);
  }
  
  delay(1500);
}
