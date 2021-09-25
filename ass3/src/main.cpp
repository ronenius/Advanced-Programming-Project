#include "classifier/knnClassifier.hpp"
#include "cli/cli.hpp"
#include "io/standardIO.hpp"

int main()
{
    knnClassifier classif;
    standardIO io;
    CLI cli(&io, &classif);
    cli.start();
}