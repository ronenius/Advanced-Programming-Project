#include "io.hpp"
std::vector<iris> importData(std::string path)
{
    std::vector<iris> data;
    std::fstream fin;
    fin.open(path);
    std::vector<std::string> row;
    std::vector<double> properties;
    std::string line, word;
    while (getline(fin, line, '\n'))
    {
        row.clear();
        properties.clear();
        std::stringstream s(line);
        while (getline(s, word, ','))
        {
            row.push_back(word);
        }
        for (int i = 0; i < 4; i++)
        {
            properties.push_back(stod(row[i]));
        }
        if (row.size() < 5)
        {
            data.push_back(iris(iris::UNDEFINED, properties));
        }
        else if (row[4] == "Iris-setosa")
        {
            data.push_back(iris(iris::SETOSA, properties));
        }
        else if (row[4] == "Iris-virginica")
        {
            data.push_back(iris(iris::VIRGINICA, properties));
        }
        else
        {
            data.push_back(iris(iris::VERSICOLOR, properties));
        }
    }
    fin.close();
    return data;
}
void exportData(std::vector<iris> data, std::string path)
{
    std::ofstream fout(path);
    for (int i = 0; i < data.size(); i++)
    {
        iris currIris = data[i];
        fout << "Iris-" << currIris.getName() << std::endl;
    }
    fout.close();
}