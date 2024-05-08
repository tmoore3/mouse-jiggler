#include <fcntl.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MOUSE_GADGET "/dev/hidg1" // Replace with your actual device file path

typedef struct __attribute__((packed)) {
    uint8_t buttons;
    int8_t x;
    int8_t y;
} mouse_report_t;

int main( void ) {
    int fd_mouse_gadget;
    mouse_report_t report = {0};

    fd_mouse_gadget = open(MOUSE_GADGET, O_WRONLY);
    if (fd_mouse_gadget < 0) {
        perror("Failed to open the device file");
        return EXIT_FAILURE;
    }

    report.buttons = 0;
    report.y = 0;
    report.x = 1;

    while(1) {
        for(int i = 0; i < 2; i++) {
            if(write(fd_mouse_gadget, (unsigned char*)&report, sizeof(report)) < 0) {
                perror("Failed to write to the device file");
                close(fd_mouse_gadget);
                return EXIT_FAILURE;
            }
            report.x = -report.x;
        }
        sleep(30);
    }

    close(fd_mouse_gadget);

    return EXIT_SUCCESS;
}