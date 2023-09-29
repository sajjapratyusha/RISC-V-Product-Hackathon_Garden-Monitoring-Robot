#include <SoftwareSerial.h>
#include <Servo.h>

// Constants
#define LEFT_PIN 7
#define RIGHT_PIN 6
#define TRIGGER_PIN 9
#define ECHO_PIN 8

// Variables
Servo servo;
int distance = 0;

// Setup function
void setup() {
Serial.begin(9600);
servo.attach(10);

pinMode(LEFT_PIN, OUTPUT);
pinMode(RIGHT_PIN, OUTPUT);

pinMode(TRIGGER_PIN, OUTPUT);
pinMode(ECHO_PIN, INPUT);
}

// Loop function
void loop() {
// Ultrasonic distance measurement
digitalWrite(TRIGGER_PIN, LOW);
delayMicroseconds(2);
digitalWrite(TRIGGER_PIN, HIGH);
delayMicroseconds(10);
digitalWrite(TRIGGER_PIN, LOW);

distance = pulseIn(ECHO_PIN, HIGH) / 58.2;

// Checking if the distance is less than a threshold value (indicating an obstacle)
if (distance < 30) {
// Turn right
digitalWrite(LEFT_PIN, LOW);
digitalWrite(RIGHT_PIN, HIGH);
servo.write(140);
delay(1000);

// Reverse for 2 seconds
digitalWrite(LEFT_PIN, HIGH);
digitalWrite(RIGHT_PIN, HIGH);
servo.write(90);
delay(2000);

// Turn left
digitalWrite(LEFT_PIN, HIGH);
digitalWrite(RIGHT_PIN, LOW);
servo.write(40);
delay(1000);

// Move forward for 2 seconds
digitalWrite(LEFT_PIN, HIGH);
digitalWrite(RIGHT_PIN, HIGH);
servo.write(90);
delay(2000);
}
else {
// Move forward
digitalWrite(LEFT_PIN, HIGH);
digitalWrite(RIGHT_PIN, HIGH);
servo.write(90);
delay(200);
}
}
