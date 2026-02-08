// Coded in C++ by Lorenzo J Munguia
#include <Adafruit_LiquidCrystal.h>

const int sensorPin = 2;   // Sensor output connected to digital pin 2
const int ledPin = 13;     // Built-in LED
const int exled = 3;       // Green external LED
const int exspeak = 4;     // Piezo speaker
const int exled2 = 5;      // Red external LED

Adafruit_LiquidCrystal lcd_1(0);  // I2C address 0x20 (Adafruit backpack default)

void setup() {
  pinMode(sensorPin, INPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(exled, OUTPUT);
  pinMode(exspeak, OUTPUT);
  pinMode(exled2, OUTPUT);

  Serial.begin(9600);
  Serial.println("LLabs OS V0.1");
  Serial.println("Proximity Sensor Booting...");

  lcd_1.begin(16, 2);

  // Boot animation
  lcd_1.print("LLabs Industries");
  lcd_1.setCursor(0, 1);
  lcd_1.print("Est 2011");
  delay(1000);

  lcd_1.clear();
  lcd_1.print("PBC Engineering");
  lcd_1.setCursor(0, 1);
  lcd_1.print("Est 2003");
  delay(1000);

  lcd_1.clear();
  lcd_1.print("By Mr");
  lcd_1.setCursor(0, 1);
  lcd_1.print("Bluesky");
  delay(1000);

  lcd_1.clear();
}

void loop() {
  static int lastProximity = -1;   // Track previous state
  int proximity = digitalRead(sensorPin);

  // Only update LCD + outputs when the state changes
  if (proximity != lastProximity) {
    lcd_1.clear();

    if (proximity == HIGH) {
      // Motion detected
      digitalWrite(ledPin, HIGH);
      digitalWrite(exled2, LOW);
      digitalWrite(exled, HIGH);
      digitalWrite(exspeak, HIGH);

      Serial.println("Motion Detected");
      lcd_1.print("Motion Detected");

    } else {
      // No motion
      digitalWrite(ledPin, LOW);
      digitalWrite(exled2, HIGH);
      digitalWrite(exled, LOW);
      digitalWrite(exspeak, LOW);

      Serial.println("No Motion");
      lcd_1.print("   No Motion");
    }

    lastProximity = proximity;  // Update stored state
  }

  delay(1);
}
