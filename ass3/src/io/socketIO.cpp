#include "socketIO.hpp"

socketIO::socketIO(tcpSocket *server) : server(server){};

std::string socketIO::read()
{
    return server->receive();
}

void socketIO::write(std::string output)
{
    server->send(output);
}