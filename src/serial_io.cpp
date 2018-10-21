//
// Created by Marco on 03/10/2018.
//

#pragma clang diagnostic ignored "-Wdeprecated-declarations"

#include <boost/asio/serial_port.hpp>
#include <boost/asio.hpp>
#include <string>
#include <iostream>
#include "serial_io.h"
#include "either.h"

// ArduinoSerial class constructor
ArduinoSerial::ArduinoSerial(std::string port_n, int baud_r) {
    boost::asio::io_context io;
    port_name = port_n;
    baud_rate = baud_r;
}

void ArduinoSerial::connect() {
    std::cout << port_name << std::endl;

    try {
        port = new boost::asio::serial_port(io, port_name);
    }
    catch (boost::system::system_error &e) {
        std::cout << "=> Error: cannot open port. Info: " << e.what() << "\n";
        exit(EXIT_FAILURE);
    }
}

// write listens to messages from cin and writes them to
// the open port.
void ArduinoSerial::write() {
    std::string input;

    std::cout << port->is_open() <<  std::endl;

    while (true) {
        getline(std::cin, input);
        boost::asio::write(*port, boost::asio::buffer(input));
    }
}

void ArduinoSerial::read() {
    return;
}
