#include "command.hpp"

command::command(defaultIO *dio, std::string description) : dio(dio), description(description){};

//Retuerns the description of the command.
std::string command::getDescription()
{
    return description;
}

//Returns the defaultIO the command uses to communicate.
defaultIO *command::getIO()
{
    return dio;
}