# GPIO Driver
GPIO driver is a C library that is inspired by wiringPi library. It is designed to be used on Raspberry Pi and other ARM based boards.

## Features
* GPIO pin mode (input/output)
* GPIO pin digital (read/write)
* Delay milliseconds

## Installation
* Clone the repository
* Create folder called build 
```
mkdir build
```
* Go to build folder
```
cd build
```
* Run build
```
cmake .. && make
```

## Examples
* Blink LED
```c
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
```