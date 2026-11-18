/*========================================================================
                  LEDs Lightning Modes + LCD + GUI
==========================================================================
Description:
  This program uses LCD and Traffic light to simulate Blink, Alt, and Run on LEDs.
  The ESP32 is connected to the shifter to stabalize the connection between them.


Programmer:
 Caberoy, Adrian Miko
 Vigilar, Franz Louis

Date:
  18 November 2026
==========================================================================*/
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// GPIOs
const uint8_t LED[] = {19,18,5,17,16,4};
const uint8_t NUM_LEDS = sizeof(LED)/sizeof(LED[0]);
const uint8_t SW1 = 12;
const uint8_t SW2 = 13;

bool SW1_state = 0;
bool SW2_state = 0;

// LCD (I2C: SDA = 21, SCL = 22)
LiquidCrystal_I2C lcd(0x27, 16, 2);

// Variables
bool display_msg = true;

void mode_msg(){
  Serial.println(
    "\nSelect Mode:\n"
    "1. Blink\n"
    "2. Alternate\n"
    "3. Running"
  );
}

// Shows the status on the LCD and tells the GUI
void show_status(const char* name){
  lcd.clear();
  lcd.setCursor(5, 0);                      
  lcd.print("STATUS");
  lcd.setCursor((16 - strlen(name)) / 2, 1); // center the mode name
  lcd.print(name);

  Serial.print("STATUS:");
  Serial.println(name);
}

void setup(){
  // Baud rate
  Serial.begin(9600);

  // LCD
  Wire.begin(21, 22);
  lcd.init();
  lcd.backlight();

  // Inputs 
  pinMode(SW1, INPUT);
  pinMode(SW2, INPUT);

  // Outputs
  for(int i = 0; i < NUM_LEDS; i++){
    pinMode(LED[i], OUTPUT);
  }
}

#include "Modes.h"

// Used by both the serial input and the switches
void run_mode(int m){
  switch (m){
    case 1:
      Serial.printf("Mode %d selected\n", m);
      show_status("BLINK");
      led_blink();
      break;

    case 2:
      Serial.printf("Mode %d selected\n", m);
      show_status("ALT");
      led_alt();
      break;

    case 3:
      Serial.printf("Mode %d selected\n", m);
      show_status("RUN");
      led_run();
      break;

    default:
      Serial.println("Invalid Input");
      break;
  }
}

void loop(){
  if(display_msg){
    mode_msg();
    display_msg = false;
  }

  // Reads serial monitor / GUI
  if(Serial.available()){
    String line = Serial.readStringUntil('\n');
    line.trim();
    if(line.length() > 0){
      run_mode(line.toInt());
      display_msg = true;
    }
  }

  // Reads switches
  SW1_state = digitalRead(SW1);
  SW2_state = digitalRead(SW2);

  if (SW1_state && SW2_state){
    run_mode(3);
    display_msg = true;
  } else if (SW1_state && !SW2_state){
    run_mode(2);
    display_msg = true;
  } else if (!SW1_state && SW2_state){
    run_mode(1);
    display_msg = true;
  }
  // both OFF: do nothing
}