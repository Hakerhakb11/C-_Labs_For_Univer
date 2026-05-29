#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <cstring>
#include <string>

struct NOTEBOOK
{
    char model[21]; // наименование
    struct size     // габаритные размеры
    {
        float x;
        float y;
        float z;
    } size;
    float w;   // вес
    int price; // цена
};

std::vector<NOTEBOOK> read_file(const std::string filename)
{
    std::vector<NOTEBOOK> notebooks;
    std::ifstream file(filename);
    if (file.fail())
    {
        std::cerr << "Ошибка открытия файла." << std::endl;
        return notebooks;
    }
    std::string line;
    while (std::getline(file, line))
    {
        NOTEBOOK nb;
        std::strcpy(nb.model, line.substr(0, 20).c_str());
        nb.price = std::stoi(line.substr(20, 4));
        nb.w = std::stof(line.substr(25, 3));

        std::string sstr = line.substr(29, 14);
        std::replace(sstr.begin(), sstr.end(), 'x', ' ');
        std::istringstream result(sstr);
        result >> nb.size.x >> nb.size.y >> nb.size.z;

        float shdd = std::stof(line.substr(71, 5));
        if (shdd < 1)
        {
            notebooks.push_back(nb);
            // std::cout << nb.model << std::endl;
        }
    }
    file.close();
    return notebooks;
}

void binary_write(const std::string filename, std::vector<NOTEBOOK> notebook)
{
    std::ofstream file2(filename, std::ios::binary | std::ios::trunc);
    if (file2.fail())
    {
        std::cerr << "Ошибка открытия файла..2" << std::endl;
    }

    int count = notebook.size();
    file2.write(reinterpret_cast<char *>(&count), sizeof(count));
    for (int i = 0; i < notebook.size(); i++)
    {
        file2.write(reinterpret_cast<char *>(&notebook[i]), sizeof(NOTEBOOK));
    }
    file2.close();
}

int main()
{
    std::string name_in_file = "node.txt";
    std::string name_out_file = "binary_notebooks.bin";

    std::vector<NOTEBOOK> notebooks = read_file(name_in_file);

    std::sort(notebooks.begin(), notebooks.end(), [](NOTEBOOK &a, NOTEBOOK &b)
              { return (std::string(a.model) < std::string(b.model)); });

    binary_write(name_out_file, notebooks);

    return 0;
}
