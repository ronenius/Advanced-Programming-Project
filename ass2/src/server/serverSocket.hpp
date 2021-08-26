#include <sys/socket.h>
class serverSocket
{
public:
    virtual void send(std::string massage)=0;
    virtual void receive();
};