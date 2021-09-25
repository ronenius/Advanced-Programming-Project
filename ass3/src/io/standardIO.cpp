#include "standardIO.hpp"
#include "../classifier/stringIO.hpp"

standardIO::standardIO() : is1(false), is12(false), is5(false){};

std::string standardIO::read()
{
    /*if (is1)
    {
        is1 = false;
        is12 = true;
        std::string path, message;
        stringIO io;
        std::cin >> path;
        message = io.importFileToString(path);
        return message;
    }
    else if (is12)
    {
        is12 = false;
        std::string path, message;
        stringIO io;
        std::cin >> path;
        message = io.importFileToString(path);
        return message;
    }
    else
    {
        std::string input;
        getline(std::cin, input);
        if (input.compare("1") == 0)
        {
            is1 = true;
        }
        if (input.compare("5") == 0)
        {
            is5 = true;
        }
        return input;
    }*/
    std::string input;
    getline(std::cin, input);
    return input;
}

void standardIO::write(std::string output)
{
    /*if (is5)
    {
        if (output[0] == '1')
        {
            std::string path;
            stringIO io;
            std::cin >> path;
            io.exportStringToFile(path, output);
        }
        else
        {
            std::cout << output;
        }
        is5 = false;
    }
    else
    {
        std::cout << output;
    }*/
    std::cout << output;
}