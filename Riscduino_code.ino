// Define pin connections
const int sensorPin = A0; // Analog input pin for soil moisture sensor
const int waterPumpPin = 2; // Digital output pin for the water pump
const int moistureThreshold = 600; // Threshold value for moisture level

void setup() {
pinMode(waterPumpPin, OUTPUT);
Serial.begin(9600); // Initialize the serial communication
}

void loop() {
int moisture = analogRead(sensorPin); // Read the moisture level

if (moisture < moistureThreshold) {
Serial.println("Moisture level is low. Watering the plants...");
digitalWrite(waterPumpPin, HIGH); // Turn on the water pump
delay(5000); // Run the water pump for 5 seconds
digitalWrite(waterPumpPin, LOW); // Turn off the water pump
Serial.println("Watering completed.");
} else {
Serial.println("Moisture level is sufficient. No watering needed.");
}

delay(60000); // Wait for 1 minute before reading again
}
