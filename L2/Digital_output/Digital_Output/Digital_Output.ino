/*============================================
            DIGITAL OUTPUT LED
  ============================================
  Description:
    This program blinks an LED connected to GPIO32 with
    a 1-second interval.
    
  Programmer:
    Caberoy, Adrian Miko A.
    Vigilar, Franz Louis G.

  Date:
   2 September 2026
   ------------------------------------------*/
  
 const uint8_t SW1 = 12;
const uint8_t SW2 = 13;

bool SW1_state = 0;
bool SW2_state = 0;

uint8_t const LED[] = {32, 33, 25, 26, 27, 14};
uint8_t NUM_PINS = 6;

void setup() {
  // put your setup code here, to run once:

  for(uint8_t a = 0 ; a < NUM_PINS ; a++){
    pinMode(LED[a],  OUTPUT);
    }
  pinMode(SW1, INPUT);  
  pinMode(SW2, INPUT);  
}

#include "LED_MODES.h"

void loop() {
  // put your main code here, to run repeatedly:
  
  SW1_state = digitalRead(SW1);
  SW2_state = digitalRead(SW2);
  
  if (SW1_state && SW2_state){
    clear();
    run();
  } else if(SW1_state == 1 && !SW2_state){
    clear();
    alt();
  } else if(SW1_state == 0 && SW2_state == 1){
    clear();
    blink();
  } else{
    clear();
  }
}
