/*=========================================
              PWM DEMO
===========================================
Description:
 This program changes brightness of the LED.
Programmer:
 Caberoy, Adrian Miko A.
 Vigilar, Franz Louis G.

Date:
 9 Sept. 2026
 ------------------------------------------*/
// GPIOs
 const uint8_t LED =32;

// PWM parameters
 const uint16_t FREQ = 5000;
 const uint8_t RES  = 8;
 int bright = 0;
 int t_delay =10;
 int fade =5;

void setup() {
 ledcAttach(LED,FREQ,RES);
}

void loop() {
  ledcWrite(LED,bright);
  bright += fade;
  delay(t_delay);

  if(bright >= 255 || bright <= 0){
    fade = -fade;
  }
}
