// Smart Irrigation System using Arduino
// Components: Soil Moisture Sensor, Relay Module, Water Pump

// Pin connections
int soilMoisturePin = A0;   // Soil moisture sensor connected to Analog pin A0
int pumpPin = 7;            // Relay module controlling pump on Digital pin 7

// Threshold (adjust based on your sensor calibration)
int threshold = 400;        // Below this → soil is dry

void setup() {
  pinMode(pumpPin, OUTPUT);
  digitalWrite(pumpPin, LOW);   // Pump OFF initially
  Serial.begin(9600);
}

void loop() {
  int moistureValue = analogRead(soilMoisturePin);  // Read sensor value

  Serial.print("Soil Moisture Value: ");
  Serial.println(moistureValue);

  if (moistureValue < threshold) {
    // Soil is dry → Turn ON Pump
    digitalWrite(pumpPin, HIGH);
    Serial.println("Soil is DRY → Pump ON");
  } else {
    // Soil is wet enough → Turn OFF Pump
    digitalWrite(pumpPin, LOW);
    Serial.println("Soil is WET → Pump OFF");
  }

  delay(2000);  // Wait 2 sec before next reading
}
