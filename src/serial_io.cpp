//
// Created by Marco on 03/10/2018.
//

#pragma clang diagnostic ignored "-Wdeprecated-declarations"

#include <boost/asio/serial_port.hpp>
#include <string>
#include <iostream>
#include <boost/asio.hpp>
#include "serial_io.h"
#include "either.h"

boost::asio::io_context io;
boost::asio::serial_port *port;

class SerialCommunicator {
public:
    virtual void connect() = 0;


};
/*
struct Serial {
    SerialCommunicator communicator;

    Error write(std::string input) {
        return communicator.write(input);
    };

    Either<std::byte> read() {
        return communicator.read();
    }
};
 */

// class constructor
SerialComm::SerialComm(std::string port_name, int baud_rate) {

    try {
        port = new boost::asio::serial_port(io, port_name);
    }
    catch (boost::system::system_error &e) {
        std::cout << "=> Error: cannot open port. Info: " << e.what() << "\n";
        exit(EXIT_FAILURE);
    }

    port_name = port_name;
    baud_rate = baud_rate;
}

// open_port creates a new io context and opens the USB
// serial port using the specified port name and baud rate
// (the) speed of communication over the date channel).
void SerialComm::open_port() {
    port->set_option(boost::asio::serial_port_base::baud_rate(baud_rate));
}

// write listens to messages from cin and writes them to
// the open port.
void SerialComm::write() {
    std::string input;

    std::cout << port->is_open() <<  std::endl;

    while (true) {
        getline(std::cin, input);
        boost::asio::write(*port, boost::asio::buffer(input));
    }
}
