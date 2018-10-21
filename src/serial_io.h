//
// Created by Marco on 03/10/2018.
//

#ifndef IKARUS_SERIAL_IO_H
#define IKARUS_SERIAL_IO_H

#include <string>
#include <boost/asio.hpp>
#include <boost/asio/serial_port.hpp>
#include "either.h"

// SerialPortOps is an interface used to wrap low level serial communication
// operations. Useful to hide complexity and to mock for testing.
class SerialPortOps {
public:
    virtual ~SerialPortOps() = 0;
    virtual void set_port() = 0;
    virtual Either<bool> open_port(std::string port_name) = 0;
    virtual void write_to_port(std::string input) = 0;
};

// AsioSerial is a concrete implementation of SerialPortOps using the
// boost asio library.
class AsioSerial: public SerialPortOps {
private:
    Either<bool> connected;
    boost::asio::io_context io;
    boost::asio::serial_port* port;
    boost::system::error_code error_code;
public:
    void set_port() override;
    Either<bool> open_port(std::string port_name) override;
    void write_to_port(std::string input) override;
};

// SerialCommunicator is the interface describing the functionalities
// a class dealing with serial communication (i.e. USB) must implement.
class SerialCommunicator {
public:
    virtual ~SerialCommunicator() = 0;
    virtual Error* connect() = 0;
    virtual void write() = 0;
    virtual void read() = 0;
};

// ArduinoSerial is a concrete implementation of SerialCommunicator.
class ArduinoSerial: public SerialCommunicator {
public:
    ArduinoSerial(std::string port_name, int baud_rate, SerialPortOps *serial_ops);
    Error* connect() override;
    void write () override;
    void read() override;

private:
    int baud_rate;
    std::string port_name;
    SerialPortOps *serial;
};

#endif //IKARUS_SERIAL_IO_H


