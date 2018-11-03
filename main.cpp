#pragma clang diagnostic ignored "-Wdeprecated-declarations"
#include <iostream>
#include <string>
#include "src/serial_io.h"

const std::string PORT_NAME = "/dev/tty.usbmodem1411";
const int BAUD_RATE = 9600;

int main() {
    SerialPortOps *serial_ops = new AsioSerial();

    ArduinoSerial serial(PORT_NAME, BAUD_RATE, serial_ops);

    Error *err = serial.connect();

    if (err) {
        std::cout << err->what << std::endl;
        return 0;
    }

    std::cout << "=> type 'w' to move forward. \n 's' to go backwards. \n 'a' to go left. \n 'd' to go right. \n 'h' to go stop." << std::endl;

    serial.write();

    return 0;
}
