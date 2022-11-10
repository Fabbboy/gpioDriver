#pragma once

//arduino .ino lib for raspberry pi alternative to wiringpi

#define INPUT 0x00
#define OUTPUT 0x01

#define LOW 0x00
#define HIGH 0x01



//base
void pinMode(unsigned int pin, int mode);
void delay(unsigned int ms);

//digital
void digitalWrite(unsigned int pin, int value);
int digitalRead(unsigned int pin);

