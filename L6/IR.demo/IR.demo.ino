const int OUT = 2;          
const int ledPin = 13;     

int Number_of_Object = 0;  
int SensorState = 0;        
int lastSensorState = HIGH; 

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
