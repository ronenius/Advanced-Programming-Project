#include "defaultIO.hpp"
#include "../server/tcpServer/tcpSocket.hpp"
#ifndef SOCKET_IO_HPP
#define SOCKET_IO_HPP
class socketIO : public defaultIO
{
private:
    socketInterface *server;

public:
    socketIO(socketInterface *server);
    std::string read();
    void write(std::string output);
};
#endif