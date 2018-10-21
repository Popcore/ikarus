//
// Created by Marco on 03/10/2018.
//

#ifndef IKARUS_SERIAL_IO_H
#define IKARUS_SERIAL_IO_H

#include <string>
#include <boost/asio.hpp>

// SerialCommunicator is the interface describing the functionalities
// a class dealing with serial communication (i.e. USB) must implement.
class SerialCommunicator {
public:
    virtual ~SerialCommunicator() {};
    virtual void connect() = 0;
    virtual void write() = 0;
    virtual void read() = 0;
};

// ArduinoSerial is a concrete implementation of SerialCommunicator.
class ArduinoSerial: public SerialCommunicator {

public:
    ArduinoSerial(std::string port_name, int baud_rate);
    void connect();
    void write();
    void read();

private:
    boost::asio::serial_port* port;
    boost::asio::io_context io;
    int baud_rate;
    std::string port_name;
};

#endif //IKARUS_SERIAL_IO_H


