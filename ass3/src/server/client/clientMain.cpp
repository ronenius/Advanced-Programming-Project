#include "clientTcpSocket.hpp"
#include "../../classifier/stringIO.hpp"
#include <thread>

//Saves the classifications file that the server sends to the client to the given path.
void saveClassifications(clientTcpSocket TCPClient, std::string message, std::string path)
{
    TCPClient.stringToFile(path, message);
}

//Waits until the client pressed enter and sends it to the server.
void sendEnter(clientTcpSocket TCPClient)
{
    std::string input = "1";
    while (input.size() != 0)
        getline(std::cin, input);
    TCPClient.send("\n");
}

//Builds the client side and runs it to work with the cli.
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
    //Gets the menu string (the first one).
    menuString = TCPClient.receive();
    //Prints the menu.
    std::cout << menuString;
    //Gets the first input from the user (his choice).
    getline(std::cin, input);
    //Runs until breaks (if user chooses 7).
    while (true)
    {
        //Sends the choice to the server.
        TCPClient.send(input);
        //If the client chose 1.
        if (input == "1")
        {
            //The client receives the message to upload a train file.
            message = TCPClient.receive();
            std::cout << message;
            //Gets the path of the train file from the client.
            std::string path1;
            getline(std::cin, path1);
            //Converts the path to a string and sends it to the cli.
            std::string file1 = TCPClient.fileToString(path1);
            TCPClient.send(file1);
            //The client receives the message to upload a test file.
            message = TCPClient.receive();
            std::cout << message;
            //Gets the path of the test file from the client.
            std::string path2;
            getline(std::cin, path2);
            //Converts the path to a string and sends it to the cli.
            std::string file2 = TCPClient.fileToString(path2);
            TCPClient.send(file2);
            //The client receives the message that the upload was successful.
            message = TCPClient.receive();
            std::cout << message;
            //The client presses enter and sends it to the server.
            while (input.size() != 0)
                getline(std::cin, input);
            TCPClient.send("\n");
            //The client receives the menu message.
            message = TCPClient.receive();
            std::cout << message;
        }
        //If the client chose 2.
        else if (input == "2")
        {
            //The client receives a message from the server and prints it.
            message = TCPClient.receive();
            std::cout << message;
            //The client tries to choose valid variables for command 2 until it's valid.
            do
            {
                //Gets the parametrs from the client or an enter to continue to menu.
                getline(std::cin, input);
                //Sends the parameters.
                if (input.size() == 0)
                    TCPClient.send("\n");
                else
                    TCPClient.send(input);
                //Receives a message from the server (an error message or the menu if successful).
                message = TCPClient.receive();
                std::cout << message;
            } while (message != menuString);
        }
        //If the user chose 3, 4 or 6.
        else if (input == "3" || input == "4" || input == "6")
        {
            //The client receives a message from the server and prints it.
            message = TCPClient.receive();
            std::cout << message;
            //The client presses enter and sends it to the server.
            while (input.size() != 0)
                getline(std::cin, input);
            TCPClient.send("\n");
            //The client receives the menu message.
            message = TCPClient.receive();
            std::cout << message;
        }
        //If the user chose 5.
        else if (input == "5")
        {
            //Gets the path to download the classifications to from the user.
            std::cout << "Enter a path to download results" << std::endl;
            std::string path;
            getline(std::cin, path);
            //Creates a thread that waits until the client presses enter in order for the menu to show up.
            std::thread enterThread(sendEnter, TCPClient);
            enterThread.detach();
            //The client receives a message (the results or the menu).
            std::string message = TCPClient.receive();
            //If the message is the menu.
            if (message == menuString)
            {
                //Prints it.
                std::cout << message;
                //Waits to receive the results.
                message = TCPClient.receive();
                //If there wasn't an error.
                if (message != "Please upload data and classify it before downloading.\n")
                {
                    //Runs a new thread to save the contents of the results in the given path.
                    std::thread saveThread(saveClassifications, TCPClient, message, path + "/results.txt");
                    saveThread.detach();
                }
                else
                {
                    //Else there was an error and prints it.
                    std::cout << message;
                }
            }
            //Else the message was an error or the results.
            else
            {
                //If there wasn't an error.
                if (message != "Please upload data and classify it before downloading.\n")
                {
                    //Runs a new thread to save the contents of the results in the given path.
                    std::thread saveThread(saveClassifications, TCPClient, message, path + "/results.txt");
                    saveThread.detach();
                }
                else
                {
                    //Else there was an error and prints it.
                    std::cout << message;
                }
                //Receives the menu from the server and prints it.
                message = TCPClient.receive();
                std::cout << message;
            }
        }
        //If user chooses 7 then finish and close the socket.
        else if (input == "7")
        {
            break;
        }
        //Else it's a wrong option.
        else
        {
            std::cout << "Wrong option" << std::endl;
        }
        //gets the next choice from the user.
        getline(std::cin, input);
    }
    //Closes socket.
    TCPClient.closeSocket();
    return 0;
}