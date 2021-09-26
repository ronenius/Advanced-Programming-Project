#include "defaultIO.hpp"
#include "../server/tcpServer/tcpSocket.hpp"

class socketIO : public defaultIO
{
private:
    tcpSocket *server;

public:
    socketIO(tcpSocket *server);
    std::string read();
    void write(std::string output);
};