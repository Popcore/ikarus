//
// Created by Marco on 03/10/2018.
//
#include <string>
#include <iostream>
#include "serial_io.h"

void AsioSerial::set_port() {
    port = new boost::asio::serial_port(io);
}

Either<bool> AsioSerial::open_port(std::string port_name) {
    Error err;
    boost::system::error_code error_code;

    port->open(port_name, error_code);

    if (error_code) {
        err.what = error_code.message();

        connected.expected = false;
        connected.error = &err;
        return connected;
    }

    connected.expected = true;
    return connected;
}

void AsioSerial::write_to_port(std::string input) {
    // TODO check if port is open
    // port->is_open()
    boost::asio::write(*port, boost::asio::buffer(input));
}

// ArduinoSerial class constructor
ArduinoSerial::ArduinoSerial(std::string port_n, int baud_r, SerialPortOps *serial_ops) {
    port_name = port_n;
    baud_rate = baud_r;
    serial = serial_ops;
}

Error* ArduinoSerial::connect() {
    Either<bool> connection;

    serial->set_port();
    connection = serial->open_port(port_name);

    if (connection.error) {
        return connection.error;
    }

    return NULL;
}

// write listens to messages from cin and writes them to
// the open port.
void ArduinoSerial::write() {
    std::string input;

    while (true) {
        getline(std::cin, input);
        serial->write_to_port(input);
    }
}

void ArduinoSerial::read() {
    return;
}