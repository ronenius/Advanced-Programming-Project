#include "io.hpp"
std::vector<iris> importData(std::string path)
{
    std::vector<iris> data;
    std::fstream fin;
    fin.open(path, std::ios::in);
    std::vector<std::string> row;
    std::vector<double> properties;
    std::string line, word, temp;
    while (fin >> temp)
    {
        row.clear();
        getline(fin, line);
        std::stringstream s(line);
        while (getline(s, word, ','))
        {
            row.push_back(word);
        }
        for (int i = 0; i < row.size(); i++)
        {
            properties.push_back(stod(row[i]));
        }
        if (row[4].find("setosa"))
        {
            data.push_back(iris("setosa", properties));
        }
        if (row[4].find("virginica"))
        {
            data.push_back(iris("virginica", properties));
        }
        if (row[4].find("versicolor"))
        {
            data.push_back(iris("versicolor", properties));
        }
    }
    return data;
}
void exportData(std::vector<iris> data)
{
    std::fstream fout;
    fout.open("output.csv", std::ios::out | std::ios::app);
    for (int i = 0; i < data.size(); i++)
    {
        iris currIris = data[i];
        fout << "Iris-" << currIris.getName() << std::endl;
    }
}