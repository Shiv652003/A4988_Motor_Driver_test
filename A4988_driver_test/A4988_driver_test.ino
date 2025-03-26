// pin connections for setup/ for myself
// A4988 |Pin	|ESP32 Pin	Function
// VCC	|3.3V	|Logic power (DO NOT use 5V!)
// GND|	GND|	Common ground
// VMOT	|12V |Power Supply	Power for the stepper motor
// GND (Next to VMOT)	|12V GND|	Power ground
// STEP|	GPIO 25|	Steps signal
// DIR|	GPIO 26|	Direction signal
// ENABLE|	GND (or GPIO if used)	|Enable motor (LOW = enabled)
// MS1, MS2, MS3|	GND (or left floating)|	Microstepping (Full step)
// RESET & SLEEP|	Shorted together|	Keeps driver active

#define STEP_PIN 25 
#define DIR_PIN 26  

void setup() {
  Serial.begin(115200);
  pinMode(STEP_PIN, OUTPUT);
  pinMode(DIR_PIN, OUTPUT);
  digitalWrite(DIR_PIN, HIGH); // Seting initial direction
  Serial.println("Stepper motor initialized.");
}

void loop() {
  Serial.println("Moving Forward...");
  digitalWrite(DIR_PIN, HIGH);
  for (int i = 0; i < 200; i++) {  // 1 full rotation (200 steps for---- 1.8degree/step)
    digitalWrite(STEP_PIN, HIGH);
    delayMicroseconds(1000);
    digitalWrite(STEP_PIN, LOW);
    delayMicroseconds(1000);
  }
  Serial.println("Forward move completeddd");
  delay(1000); 

  Serial.println("Moving Backward...");
  digitalWrite(DIR_PIN, LOW);
  for (int i = 0; i < 200; i++) {
    digitalWrite(STEP_PIN, HIGH);
    delayMicroseconds(1000);
    digitalWrite(STEP_PIN, LOW);
    delayMicroseconds(1000);
  }
  Serial.println("Backward move completed.");
  delay(1000);
}
