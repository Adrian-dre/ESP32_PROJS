/*============================================
            Midterm Practical Exam
  ============================================
  Description:
    This program counts up/down once a object is detected
    by an IR sensor.
    sw1  ||  sw2   
     0        0    =  +1
     0        1    =  -1
     1        0    =  +2
     1        1    =  -2
    
  Programmer:
    Caberoy, Adrian Miko A.
    
  Date:
   28 October, 2026
   ------------------------------------------*/
const int sensorPin = 34;
uint8_t const sw1 = 12;
uint8_t const sw2 = 35;
const int tensPins[7] = {13, 14, 27, 26, 25, 33, 32};
const int onesPins[7] = {23, 22, 21, 19, 18, 17, 16};

int count = 0;
int lastState = HIGH;

#include "decoder.h"

void setup() {
  Serial.begin(115200);
  pinMode(sw1, INPUT);
  pinMode(sw2, INPUT);
  pinMode(sensorPin, INPUT);
  for (int i = 0; i < 7; i++) {
    pinMode(tensPins[i], OUTPUT);
    pinMode(onesPins[i], OUTPUT);
  }
  decoder(count);
}

void loop() {
  int state = digitalRead(sensorPin);
  int s1    = digitalRead(sw1);
  int s2    = digitalRead(sw2);

  if (state == LOW && lastState == HIGH) {
    if (!s1 && !s2){
    count = (count + 1) % 100;
    decoder(count);
    Serial.println(count);
    delay(500);
    }
    else if (!s1 && s2){
    count = (count + 99) % 100;
    decoder(count);
    Serial.println(count);
    delay(500); 
    }else if (s1 && !s2){
    count = (count + 2) % 100;
    decoder(count);
    Serial.println(count);
    delay(500);
    }else if (s1 && s2){
    count = (count + 98) % 100;
    decoder(count);
    Serial.println(count);
    delay(500);
    }
  }

  lastState = state;
}