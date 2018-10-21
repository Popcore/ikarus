#pragma clang diagnostic ignored "-Wdeprecated-declarations"
#include <iostream>
#include <string>
#include "src/serial_io.h"
// #include "src/lidar_reader.h"

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

    std::cout << "=> type H to turn on the light, L to turn it off" << std::endl;

    serial.write();

    // PointCloud pointCloud("data/lidar_point_cloud.las");

    return 0;
}
