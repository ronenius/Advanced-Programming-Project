#include "defaultIO.hpp"
#include "../server/tcpServer/tcpSocket.hpp"
#ifndef SOCKET_IO_HPP
#define SOCKET_IO_HPP
//Socket IO for the CLI (with tcp socket).
class socketIO : public defaultIO
{
private:
    //The socket.
    socketInterface *server;

public:
    socketIO(socketInterface *server);
    //Reads the input from the user.
    std::string read();
    //Writes the output for the user.
    void write(std::string output);
};
#endif