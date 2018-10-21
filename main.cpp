#pragma clang diagnostic ignored "-Wdeprecated-declarations"
#include <iostream>
#include <string>
#include <boost/asio.hpp>
#include "src/serial_io.h"
#include <cctype>
// #include "src/lidar_reader.h"
#include "src/either.h"

const std::string PORT_NAME = "/dev/tty.usbmodem1411";
const int BAUD_RATE = 9600;

Either<std::string> could_error(int my_arg) {
    Either<std::string> out;

    if (my_arg == 0) {
        Error e;
        e.what = "the error message";
        out.error = &e;
    }

    out.expected = "all good";

    return out;
}

int main() {
    Either<std::string> e = could_error(0);

    if (e.error != NULL) {
        std::cout << e.error->what << std::endl;
    }

     SerialComm serial(PORT_NAME, BAUD_RATE);
     //serial.open_port();

     std::cout << "=> type H to turn on the light, L to turn it off" << std::endl;

     serial.write();

    // PointCloud pointCloud("data/lidar_point_cloud.las");

    return 0;
}
