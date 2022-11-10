#include <stdio.h>
#include <stdbool.h>
#include "core/Driver.h"

//TODO analog   read/write



int main() {

    //blink led

    int pin = 17;
    pinMode(pin, OUTPUT);


    while (true) {
        digitalWrite(pin, HIGH);
        delay(1000);
        digitalWrite(pin, LOW);
        delay(1000);
    }

    return 0;
}



