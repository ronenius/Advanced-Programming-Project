#include "stringIO.hpp"

//Constructor of the class.
stringIO::stringIO(instanceBuilder *builder) : builder(builder){};

//Copies a file to a string.
std::string stringIO::importFileToString(std::string path)
{
    //Resets the data string.
    std::string data = "", line;
    //Opens the input stream.
    std::fstream fin;
    fin.open(path);
    if (getline(fin, line, '\n'))
    {
        data = data + line;
    }
    //Goes through all of the lines in the file.
    while (getline(fin, line, '\n'))
    {
        //Adds the line to the string and new line.
        data = data + '\n' + line;
    }
    //Closes the stream.
    fin.close();
    //Returns the new string.
    return data;
}

//Processes the string and build a vector of classifiables out of it.
std::vector<classifiable *> stringIO::importStringToVector(std::string data, int numProperties)
{
    //The new vector of classifiables.
    std::vector<classifiable *> vecData;
    std::vector<std::string> row;
    std::vector<double> properties;
    std::string line, word;
    std::stringstream s1(data);
    //Goes through all of the lines in the string.
    while (getline(s1, line, '\n'))
    {
        // Clears the vectors of data to avoid duplications.
        row.clear();
        properties.clear();
        // Creates a stream for the curren line.
        std::stringstream s2(line);
        // Parses the current line by ',' and inserts the parameters to the vector.
        while (getline(s2, word, ','))
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
            vecData.push_back(builder->createInstance("undefined", properties));
        }
        // Else adds the name to the knnables vector.
        else
        {
            vecData.push_back(builder->createInstance(row[numProperties], properties));
        }
    }
    return vecData;
}

//Copies the categories of the vector to a string.
std::string stringIO::exportVectorToString(std::vector<classifiable *> data)
{
    //Resets the string.
    std::string strData = "";
    //Goes through all of the data.
    strData = strData + data[0]->getCategory();
    for (int i = 1; i < data.size(); i++)
    {
        //Adds the current category name to the string and new line.
        strData = strData + '\n' + data[i]->getCategory();
    }
    //Returns the string.
    return strData;
}

//Copies the string to a file in the path.
void stringIO::exportStringToFile(std::string path, std::string data)
{
    //Opens the output stream.
    std::ofstream fout(path);
    std::stringstream s(data);
    std::string line;
    //Goes through all of the lines.
    while (getline(s, line, '\n'))
    {
        //Copies the line to the file.
        fout << line << std::endl;
    }
    //Closes the stream.
    fout.close();
}