#include "standardIO.hpp"
#include "../classifier/stringIO.hpp"

standardIO::standardIO(CLI *cli) : is1(false), is5(false), cli(cli){};

std::string standardIO::read()
{
    if (is1)
    {
        is1 = false;
        std::string path, message;
        stringIO io;
        std::cin >> path;
        message = io.importFileToString(path);
        return message;
    }
    else
    {
        std::string input;
        std::cin >> input;
        if (input.compare("1") == 0)
        {
            is1 = true;
        }
        if (input.compare("5") == 0)
        {
            is5 = true;
        }
        return input;
    }
}

void standardIO::write(std::string output)
{
    if (is5 && cli->dataClassified())
    {
        is5 = false;
        std::string path;
        stringIO io;
        std::cin >> path;
        io.exportStringToFile(path, output);
    }
    else
    {
        std::cout << output;
    }
}