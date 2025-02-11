/*
Code for ultrasonic sensor based on: https://howtomechatronics.com/tutorials/arduino/ultrasonic-sensor-hc-sr04/
Code for controlling the led inspired from: https://www.circuitbasics.com/arduino-basics-controlling-led/
*/

// define pins numbers of ultrasonic sensor
const int trigPin = 9;
const int echoPin = 10;
// define led pin
const int ledPin = 13; // (digital pin)

// define variables
long duration;
int distance;


void setup() {
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600); //initialize serial communication
}


void loop() {
  // Clears the trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  // Calculating the distance in cm
  distance = duration * 0.0343 / 2; // Distance = (Time * Speed) / 2 -- speed of sound = 34cm/ms and division by 2 cause sound waves need to travel twice the distance
  // Prints the distance on the Serial Monitor
  Serial.print("Distance: ");
  Serial.println(distance);

  // if distance small enough, then turn the led on
  if (distance < 50) {
    digitalWrite(ledPin, HIGH);
  }
  else {
    digitalWrite(ledPin, LOW);
  }
}
