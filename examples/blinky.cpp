#include "mbed-drivers/mbed.h"

static void blinky(void) {
    static DigitalOut led(BACKLIGHT);
    led = !led;
    printf("LED = %d \r\n",led.read());
}

void app_start(int, char**) {
    minar::Scheduler::postCallback(blinky).period(minar::milliseconds(500));
}
