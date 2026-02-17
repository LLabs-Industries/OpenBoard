// Coded in C++ by Lorenzo J Munguia

const int sensorPin = 2;  // Sensor output

void setup() {
  Serial.begin(9600);
  pinMode(sensorPin, INPUT);
}

void loop() {
  int proximity = digitalRead(sensorPin);

  if (proximity == HIGH) {
    Serial.println("Motion Detected");
  } else {
    Serial.println("No Motion");
  }

  delay(50); // keeps serial output readable
}
