#include "command.hpp"
command::command(defaultIO* dio, std::string description) : dio(dio), description(description) { }
std::string command::getDescription() {
    return description;
}