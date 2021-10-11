#include "command.hpp"
#include "cli.hpp"
#ifndef CONFUSION_MATRIX_COMMAND_HPP
#define CONFUSION_MATRIX_COMMAND_HPP
//a command that calculates and prints the confusion matrix.
class confusionMatrix : public command
{
private:
    CLI *cli;

public:
    confusionMatrix(defaultIO *dio, CLI *cli);
    //checks if the files are uploaded and classified. if they aren't classified, it will classify them,
    //and if they are classified, 
    //will calculate the confusion matrix according to the classification in the test file provided.
    void execute();
};
#endif