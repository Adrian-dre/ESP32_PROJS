void blink(){
    
        for(uint8_t a = 0 ; a < NUM_PINS ; a++){
            digitalWrite(LED[a], HIGH);
        }
        delay(500);

        for(uint8_t a = 0 ; a < NUM_PINS ; a++){
            digitalWrite(LED[a], LOW);
        }
        delay(500);
    
}

void alt(){
    
        for(uint8_t a = 0 ; a < NUM_PINS/2 ; a++){
            digitalWrite(LED[a], HIGH);
        }
        for(uint8_t a = 3 ; a < NUM_PINS ; a++){
            digitalWrite(LED[a], LOW);
        }
        delay(500);
        for(uint8_t a = 0 ; a < NUM_PINS/2 ; a++){
            digitalWrite(LED[a], LOW);
        }
        for(uint8_t a = 3 ; a < NUM_PINS ; a++){
            digitalWrite(LED[a], HIGH);
        }
        delay(500);
}

void run(){
    
        for(uint8_t a = 0 ; a < NUM_PINS ; a++){
            digitalWrite(LED[a], HIGH);
            delay(250);
            digitalWrite(LED[a], LOW);
            delay(250);
        }

        for(uint8_t a = NUM_PINS - 2 ; a > 0 ; a--){
            digitalWrite(LED[a], HIGH);
            delay(250);
            digitalWrite(LED[a], LOW);
            delay(250);
        }
    
}

void clear(){
    for(uint8_t a = 3 ; a < NUM_PINS ; a++){
        digitalWrite(LED[a], LOW);
    }
}