#include "clientUdpSocket.hpp"
#include "clientTcpSocket.hpp"
#include "irisBuilder.hpp"
int main()
{
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0)
    {
        perror("error creating socket");
    }
    irisBuilder builder;
    stringIO serverIO(&builder);
    clientTcpSocket TCPClient(sock, &serverIO);
    TCPClient.connectToServer();
    sock = socket(AF_INET, SOCK_DGRAM, 0);
    if (sock < 0)
    {
        perror("error creating socket");
    }
    clientUdpSocket UDPClient(sock, &serverIO);
    UDPClient.send("hello");
    std::string message = TCPClient.receive();
    std::cout << message << std::endl;
    std::string clientInput;
    std::cin >> clientInput;
    std::stringstream s(clientInput);
    std::string word;
    if (getline(s, word, ' '))
    {
        if (word.compare("TCP") == 0)
        {
            if (getline(s, word, ' '))
            {
                std::string data = TCPClient.fileToString(word);
                TCPClient.send(data);
                std::string newData = TCPClient.receive();
                if (getline(s, word, ' '))
                {
                    TCPClient.stringToFile(word, newData);
                }
            }
        }
        else if (word.compare("UDP") == 0)
        {
            if (getline(s, word, ' '))
            {
                std::string data = UDPClient.fileToString(word);
                UDPClient.send(data);
                std::string newData = UDPClient.receive();
                if (getline(s, word, ' '))
                {
                    UDPClient.stringToFile(word, newData);
                }
            }
        }
    }
    TCPClient.closeSocket();
    UDPClient.closeSocket();
    return 0;
}