# target-OSHChip-gcc
Official Yotta target for OSHChip using gcc

####Getting Started With Yotta and OSHChip

#####Installing Yotta
Install the latest version of Yotta from [the official mbed website](https://docs.mbed.com/docs/getting-started-mbed-os/en/latest/installation/#installers) for your operating system. you can run yotta in the command line with either `yotta` or `yt`

#####Creating your Project
Create a new directory and navigate to it in your command line using `cd`, then run `yotta init` to create a new project. answer the questions it asks, or hit enter to use the default. When it asks if you want to create an executable, say yes

#####Downloading Dependencies
To target the OSHChip run `yotta target oshchip-gcc`. Yotta will automatically download the latest version of this repository and set it as your target. Then, install the mbed environment with `yotta install mbed-drivers`

#####Writing your Code
Write your code in the `Source` directory of your project. Instead of the usual "main" function familiar to C and C++ programmers, mbed runs a function called `app_start`, which takes one int and an array of chars as arguments. You can find the full mbed docs [here](https://docs.mbed.com/), or the source [here](https://github.com/ARMmbed/mbed-os).

For the OSHChip, you can use different pins either by their pin number `OSHChip_Pin_1` or by an arduino-style IO name such as `D0` or `A0`. The LEDs can be used with `LED1`, `LED2`, and `LED3`.

```
       |----------|
TX/D0 -| 1     16 |- VCC
RX/D1 -| 2     15 |- D8
   D2 -| 3     14 |- D7
   D3 -| 4     13 |- A0
   D4 -| 5     12 |- A1
   D5 -| 6     11 |- AREF
   D4 -| 7     10 |- A2
  GND -| 8  ::  9 |- A3
       |----------|
```

below is an example project that blinks LED1 and outputs the LED's status over UART on D0 and D1
```C++
#include "mbed-drivers/mbed.h"

static void blinky(void) {
    static DigitalOut led(LED1);
    led = !led;
    printf("LED = %d \r\n",led.read());
}

void app_start(int, char**) {
    minar::Scheduler::postCallback(blinky).period(minar::milliseconds(500));
}
```
