#include "clientTcpSocket.hpp"
#include "../../classifier/stringIO.hpp"
#include <thread>

void saveClassifications(clientTcpSocket TCPClient, std::string message, std::string path)
{
    TCPClient.stringToFile(path, message);
}

void sendEnter(clientTcpSocket TCPClient)
{
    std::string input = "1";
    while (input.size() != 0)
        getline(std::cin, input);
    TCPClient.send("\n");
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
            std::string path1;
            getline(std::cin, path1);
            std::string file1 = TCPClient.fileToString(path1);
            TCPClient.send(file1);
            message = TCPClient.receive();
            std::cout << message;
            std::string path2;
            getline(std::cin, path2);
            std::string file2 = TCPClient.fileToString(path2);
            TCPClient.send(file2);
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
            std::cout << "Enter a path to download results" << std::endl;
            std::string path;
            getline(std::cin, path);
            std::thread enterThread(sendEnter, TCPClient);
            enterThread.detach();
            std::string message = TCPClient.receive();
            if (message == menuString)
            {
                std::cout << message;
                message = TCPClient.receive();
                if (message != "Please upload data and classify it before downloading.\n")
                {
                    std::thread saveThread(saveClassifications, TCPClient, message, path + "/results.txt");
                    saveThread.detach();
                }
                else
                {
                    std::cout << message;
                }
            }
            else
            {
                if (message != "Please upload data and classify it before downloading.\n")
                {
                    std::thread saveThread(saveClassifications, TCPClient, message, path + "/results.txt");
                    saveThread.detach();
                }
                else
                {
                    std::cout << message;
                }
                message = TCPClient.receive();
                std::cout << message;
            }
        }
        else if (input == "7")
        {
            break;
        }
        else
        {
            std::cout << "Wrong option" << std::endl;
        }
        getline(std::cin, input);
    }
    TCPClient.closeSocket();
    return 0;
}