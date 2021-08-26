#include "csvIO.hpp"

//Creates an instance of the csvIO with the given builder.
csvIO::csvIO(instanceBuilder *builder) : builder(builder){};

/**
 * The function gets a path to a csv file, opens it
 * and copies all the data about the knnables from the file
 * to a vector of knnables.
 */
std::vector<classifiable *> csvIO::importData(std::string path, int numProperties)
{
    // The new vector of knnables.
    std::vector<classifiable *> data;
    // Creates and opens a new input stream from the file in the path.
    std::fstream fin;
    fin.open(path);
    // The vector of the parameters in each row.
    std::vector<std::string> row;
    // The vector of the properties of each new knnable.
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
        for (int i = 0; i < numProperties; i++)
        {
            properties.push_back(stod(row[i]));
        }
        // If there are less than 'numProperties' parameters then there is no name and it's undefined.
        if (row.size() < numProperties + 1)
        {
            data.push_back(builder->createInstance("undefined", properties));
        }
        // Else adds the name to the knnables vector.
        else
        {
            data.push_back(builder->createInstance(row[numProperties], properties));
        }
    }
    // Closes the input stream.
    fin.close();
    // Returns the new knnables vector.
    return data;
}

/**
 * The function gets a vector of knnables and a path,
 * opens a csv file in the path and copies the data of the knnables
 * from the vector to the file.
 */
void csvIO::exportData(std::vector<classifiable *> data, std::string path)
{
    // Opens a new output stream to a file in the path.
    std::ofstream fout(path);
    // Runs through all of the knnables in the data.
    for (int i = 0; i < data.size(); i++)
    {
        // Gets and prints the current knnable name to the output file.
        classifiable *currClassifiable = data[i];
        fout << currClassifiable->getCategory() << std::endl;
    }
    // Closes the output stream.
    fout.close();
}