const int OUT = 2;          // IR Proximity Sensor pin
const int ledPin = 13;      // LED pin

int Number_of_Object = 0;   // Counter for objects
int SensorState = 0;        // Current sensor reading
int lastSensorState = HIGH; // Previous sensor reading to track state changes

void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  pinMode(OUT, INPUT);
}

void loop() {
  SensorState = digitalRead(OUT);


  if (SensorState == LOW && lastSensorState == HIGH) {
    Number_of_Object++;
    digitalWrite(ledPin, HIGH);
    Serial.print("Object detected! Total: ");
    Serial.println(Number_of_Object);
    delay(200); 
  } else if (SensorState == HIGH) {
    digitalWrite(ledPin, LOW);
  }

  lastSensorState = SensorState;
}