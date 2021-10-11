#include "socketIO.hpp"

socketIO::socketIO(socketInterface *server) : server(server){};

//Reads the input from the user.
std::string socketIO::read()
{
    return server->receive();
}

//Writes the output for the user.
void socketIO::write(std::string output)
{
    server->send(output);
}