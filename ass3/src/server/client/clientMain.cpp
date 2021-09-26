#include "clientTcpSocket.hpp"
#include "../../classifier/stringIO.hpp"
#include <thread>

void runDownload(clientTcpSocket TCPClient, std::string path, std::string message)
{
    TCPClient.stringToFile(path, message);
}

//Builds the client side and runs it.
int main()
{
    //Creates the tcp client socket.
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0)
    {
        perror("error creating socket");
    }
    //Creates the IO of the client.
    stringIO serverIO;
    //Builds the tcp client object.
    clientTcpSocket TCPClient(sock, &serverIO);
    //Tries to connect to the tcp server.
    TCPClient.connectToServer();
    std::string input, menuString, message = "";
    menuString = TCPClient.receive();
    std::cout << menuString;
    getline(std::cin, input);
    while (true)
    {
        TCPClient.send(input);
        if (input == "1")
        {
            message = TCPClient.receive();
            std::cout << message;
            std::string path;
            getline(std::cin, path);
            input = TCPClient.fileToString(path);
            std::cout << "";
            TCPClient.send(input);
            message = TCPClient.receive();
            std::cout << message;
            message = TCPClient.receive();
            std::cout << message;
            getline(std::cin, path);
            input = TCPClient.fileToString(path);
            std::cout << "";
            TCPClient.send(input);
            message = TCPClient.receive();
            std::cout << message;
            while (input.size() != 0)
                getline(std::cin, input);
            TCPClient.send("\n");
            message = TCPClient.receive();
            std::cout << message;
        }
        else if (input == "2")
        {
            message = TCPClient.receive();
            std::cout << message;
            do
            {
                getline(std::cin, input);
                if (input.size() == 0)
                    TCPClient.send("\n");
                else
                    TCPClient.send(input);
                message = TCPClient.receive();
                std::cout << message;
            } while (message != menuString);
        }
        else if (input == "3" || input == "4" || input == "6")
        {
            message = TCPClient.receive();
            std::cout << message;
            while (input.size() != 0)
                getline(std::cin, input);
            TCPClient.send("\n");
            message = TCPClient.receive();
            std::cout << message;
        }
        else if (input == "5")
        {
            message = TCPClient.receive();
            if (message != "Please upload data and classify it before downloading.\n")
            {
                std::cout << "Enter a path to download results" << std::endl;
                std::string path;
                getline(std::cin, path);
                std::thread th(runDownload, TCPClient, path + "/results.txt", message);
                th.detach();
            }
            else
            {
                std::cout << message;
            }
            while (input.size() != 0)
                getline(std::cin, input);
            TCPClient.send("\n");
            message = TCPClient.receive();
            std::cout << message;
        }
        else if (input == "7")
        {
            break;
        }
        getline(std::cin, input);
    }
    TCPClient.closeSocket();
    return 0;
}