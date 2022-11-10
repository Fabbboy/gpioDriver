#include "../Driver.h"
#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>



void pinMode(unsigned int pin, int mode){
    int fd;
    char buf[64];
    fd = open("/sys/class/gpio/export", O_WRONLY);
    if (fd < 0) {
        perror("open");
        exit(1);
    }

    sprintf(buf, "%d", pin);
    write(fd, buf, strlen(buf));
    close(fd);

    sprintf(buf, "/sys/class/gpio/gpio%d/direction", pin);
    fd = open(buf, O_WRONLY);
    if (fd < 0) {
        perror("open");
        exit(1);
    }

    if (mode == 0) {
        write(fd, "in", 2);
    } else {
        write(fd, "out", 3);
    }

    close(fd);
};

void delay(unsigned int ms){
    usleep(ms * 1000);
};


void digitalWrite(unsigned int pin, int value){
    int fd;
    char buf[64];
    sprintf(buf, "/sys/class/gpio/gpio%d/value", pin);
    fd = open(buf, O_WRONLY);
    if (fd < 0) {
        perror("open");
        exit(1);
    }

    if (value == 0) {
        write(fd, "0", 1);
    } else {
        write(fd, "1", 1);
    }

    close(fd);
};


int digitalRead(unsigned int pin){
    int fd;
    char buf[64];
    char ch;
    sprintf(buf, "/sys/class/gpio/gpio%d/value", pin);
    fd = open(buf, O_RDONLY);
    if (fd < 0) {
        perror("open");
        exit(1);
    }

    read(fd, &ch, 1);

    if (ch != '0') {
        return 1;
    } else {
        return 0;
    }

    close(fd);
};


void analogWrite(unsigned int pin, int value){
    //TODO
};

int analogRead(unsigned int pin){
    //TODO
    return 0;
};

