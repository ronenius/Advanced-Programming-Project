#include "defaultIO.hpp"
#include "../server/tcpServer/tcpSocket.hpp"
#ifndef SOCKET_IO_HPP
#define SOCKET_IO_HPP
class socketIO : public defaultIO
{
private:
    tcpSocket *server;

public:
    socketIO(tcpSocket *server);
    std::string read();
    void write(std::string output);
};
#endif