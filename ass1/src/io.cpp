#include "io.hpp"

/**
 * The function gets a path to a csv file, opens it
 * and copies all the data about the irises from the file
 * to a vector of irises.
 */
std::vector<iris> importData(std::string path)
{
    // The new vector of irises.
    std::vector<iris> data;
    // Creates and opens a new input stream from the file in the path.
    std::fstream fin;
    fin.open(path);
    // The vector of the parameters in each row.
    std::vector<std::string> row;
    // The vector of the properties of each new iris.
    std::vector<double> properties;
    // The current line and word.
    std::string line, word;
    // Gets the next line and copies it to line variable.
    while (getline(fin, line, '\n'))
    {
        // Clears the vectors of data to avoid duplications.
        row.clear();
        properties.clear();
        // Creates a stream for the curren line.
        std::stringstream s(line);
        // Parses the current line by ',' and inserts the parameters to the vector.
        while (getline(s, word, ','))
        {
            row.push_back(word);
        }
        // Copies the numerical parameters to the properties vector.
        for (int i = 0; i < NUMBER_OF_PROPERTIES; i++)
        {
            properties.push_back(stod(row[i]));
        }
        // If there are less than 5 parameters then there is no name and it's undefined.
        if (row.size() < NUMBER_OF_PROPERTIES + 1)
        {
            data.push_back(iris(iris::UNDEFINED, properties));
        }
        // Else the name of the iris is setosa then adds it to the irises vector.
        else if (row[NUMBER_OF_PROPERTIES] == "Iris-setosa")
        {
            data.push_back(iris(iris::SETOSA, properties));
        }
        // Else the name of the iris is virginica then adds it to the irises vector.
        else if (row[NUMBER_OF_PROPERTIES] == "Iris-virginica")
        {
            data.push_back(iris(iris::VIRGINICA, properties));
        }
        // Else the name of the iris is versicolor then adds it to the irises vector.
        else
        {
            data.push_back(iris(iris::VERSICOLOR, properties));
        }
    }
    // Closes the input stream.
    fin.close();
    // Returns the new irises vector.
    return data;
}

/**
 * The function gets a vector of irises and a path,
 * opens a csv file in the path and copies the data of the irises
 * from the vector to the file.
 */
void exportData(std::vector<iris> data, std::string path)
{
    // Opens a new output stream to a file in the path.
    std::ofstream fout(path);
    // Runs through all of the irises in the data.
    for (int i = 0; i < data.size(); i++)
    {
        // Gets and prints the current iris name to the output file.
        iris currIris = data[i];
        fout << "Iris-" << currIris.getName() << std::endl;
    }
    // Closes the output stream.
    fout.close();
}