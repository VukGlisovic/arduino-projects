/*
Code for water sensor based on: https://lastminuteengineers.com/water-level-sensor-arduino-tutorial/
*/

// define pins for water sensor
const int sensorPower = 7;
const int sensorPin = A0;
// define led pin
const int ledPin = 13; // (digital pin)

// variable for storing water level
int val = 0;
int level_threshold = 120;


void setup() {
  pinMode(sensorPower, OUTPUT); // Set D7 as an OUTPUT
  digitalWrite(sensorPower, LOW); // Set to LOW so no power flows through the sensor

  pinMode(ledPin, OUTPUT);

  Serial.begin(9600); // Initialize serial communication
}


void loop() {
  int level = readSensor();
	
	Serial.print("Water level: ");
	Serial.println(level);
	
	delay(10);

  // if water is detected, turn on the led. 
  // Note that taking out the water sensor still leaves some droplets on the sensor. Therefore, a threshold is used to turn on the led.
  if (level > level_threshold) {
    digitalWrite(ledPin, HIGH);
  }
  else {
    digitalWrite(ledPin, LOW);
  }
}


//This is a function used to get the reading
int readSensor() {
	digitalWrite(sensorPower, HIGH);	// Turn the sensor ON
	delay(10);
	val = analogRead(sensorPin);		  // Read the analog value form sensor
	digitalWrite(sensorPower, LOW);		// Turn the sensor OFF
	return val;							          // send current reading
}
