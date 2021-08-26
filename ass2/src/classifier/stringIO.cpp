#include "stringIO.hpp"

stringIO::stringIO(instanceBuilder *builder) : builder(builder){};

std::string stringIO::importFileToString(std::string path)
{
    std::string data = "", line;
    std::fstream fin;
    fin.open(path);
    while (getline(fin, line, '\n'))
    {
        data = data + line + '\n';
    }
    fin.close();
    return data;
}

std::vector<classifiable *> stringIO::importStringToVector(std::string data, int numProperties)
{
    std::vector<classifiable *> vecData;
    std::vector<std::string> row;
    std::vector<double> properties;
    std::string line, word;
    std::stringstream s1(data);
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

std::string stringIO::exportVectorToString(std::vector<classifiable *> data)
{
    std::string strData = "";
    for (int i = 0; i < data.size(); i++)
    {
        strData = strData + data[i]->getCategory() + '\n';
    }
    return strData;
}

void stringIO::exportStringToFile(std::string path, std::string data)
{
    std::ofstream fout(path);
    std::stringstream s(data);
    std::string line;
    while (getline(s, line, '\n'))
    {
        fout << line << std::endl;
    }
    fout.close();
}