//
// Created by Marco on 03/10/2018.
//

#ifndef IKARUS_SERIAL_IO_H
#define IKARUS_SERIAL_IO_H

// SerialComm is responsible for handling serial communication
// via USB with the Arduino controller.
class SerialComm {
    std::string port_name;
    int baud_rate;
    boost::asio::serial_port* port;

public:
    SerialComm(std::string port_name, int baud_rate);
    void open_port();
    void write();
};

#endif //IKARUS_SERIAL_IO_H


