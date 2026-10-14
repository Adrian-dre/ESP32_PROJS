/*====================================
                ADC DEMO
======================================
Description:
    This program is connected to potentiometer 
    and photoresistor to change the LED lights
    based on the brightness receive by the 
    photoresistor.
    
  Programmer:
    Caberoy, Adrian Miko A.
    Vigilar, Franz Louis G.

  Date:
   16 September 2026


--------------------------------------*/

// GPIO pins
const uint8_t POT = 34;
int pot_val = 0;
// PWM config
const int PWM_FREQ = 5000;
const byte PWM_RES  = 12;


//variables
uint8_t const LED_1 = 12;
uint8_t const LED_2 = 14;
uint8_t const LED_3 = 27;


void setup() {
 //ADC pin
 Serial.begin(9600);
 ledcAttach(LED_1,PWM_FREQ,PWM_RES);
 ledcAttach(LED_2,PWM_FREQ,PWM_RES);
 ledcAttach(LED_3,PWM_FREQ,PWM_RES);

}

void loop() {
 pot_val = analogRead(POT);
  if(pot_val < 1365){
    ledcWrite(LED_1,4095);
    ledcWrite(LED_2,0);
    ledcWrite(LED_3,0);
    Serial.println("Brightness: lvl 1");
  }else if(pot_val >= 1365 && pot_val < 2048 ){
    ledcWrite(LED_1,0);
    ledcWrite(LED_2,4095);
    ledcWrite(LED_3,0);
    Serial.println("Brightness: lvl 2");
  }else{
    ledcWrite(LED_1,0);
    ledcWrite(LED_2,0);
    ledcWrite(LED_3,4095);
    Serial.println("Brightness: lvl 3");
  }
}
