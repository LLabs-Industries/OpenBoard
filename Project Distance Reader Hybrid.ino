#include <Adafruit_LiquidCrystal.h>
#include <LiquidCrystal.h>

// Written in C++ By Lorenzo J Munguia

// LCD instances
Adafruit_LiquidCrystal lcd_1(0);
LiquidCrystal lcd_2(8, 9, 10, 11, 12, 13);

// Ultrasonic sensor pins
const int TRIGGER_PIN = 7;
const int ECHO_PIN = 7;

// Store previous values
int prevCm = -1;
int prevInches = -1;

// Threshold for "no object" detection (in cm)
const int NO_OBJECT_THRESHOLD = 200; // Adjust as needed

long readUltrasonicDistance(int triggerPin, int echoPin) {
  pinMode(triggerPin, OUTPUT);
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT);
  return pulseIn(echoPin, HIGH);
}

void setup() {
  Serial.begin(9600);
  
  lcd_1.begin(16, 2);
  lcd_2.begin(16, 2);
  
  // Boot sequence
  lcd_1.print("LLabs OS V0.1");
  lcd_2.print("LLabs OS V0.1");
  Serial.print("LLabs OS V0.1");
  lcd_1.setCursor(0, 1);
  lcd_2.setCursor(0, 1);
  lcd_1.print("Booting");
  lcd_2.print("Booting");
  
  for (int i = 0; i < 3; i++) {
    delay(500);
    lcd_1.print(".");
    lcd_2.print(".");
  }
  
  delay(500);
  lcd_1.clear();
  lcd_2.clear();
}

void loop() {
  // Read distance
  int cm = 0.01723 * readUltrasonicDistance(TRIGGER_PIN, ECHO_PIN);
  int inches = cm / 2.54;
  
  // Check for no object
  if (cm > NO_OBJECT_THRESHOLD) {
    // Display "No object"
    lcd_1.clear();
    lcd_2.clear();
    lcd_1.setCursor(0, 0);
    lcd_2.setCursor(0, 0);
    lcd_1.print("No object detected");
    lcd_2.print("No object detected");
    Serial.print("No Object Detected");
  } else {
    // Only update if distance changed
    if (cm != prevCm || inches != prevInches) {
      // Output to Serial
      Serial.print(inches);
      Serial.print("in, ");
      Serial.print(cm);
      Serial.println("cm");
      
      // Clear and display on LCDs
      lcd_1.clear();
      lcd_2.clear();
      lcd_1.setCursor(0, 0);
      lcd_2.setCursor(0, 0);
      
      lcd_1.print(inches);
      lcd_2.print(inches);
      lcd_1.print("in, ");
      lcd_2.print("in, ");
      lcd_1.print(cm);
      lcd_2.print(cm);
      lcd_1.print("cm");
      lcd_2.print("cm");
      
      // Update previous values
      prevCm = cm;
      prevInches = inches;
    }
  }
  
  delay(100); // Small delay between readings
}
