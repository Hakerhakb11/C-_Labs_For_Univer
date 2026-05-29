#include <iostream>
#include <fstream>
#include <vector>

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

int main()
{
    std::string name_file = "binary_notebooks.bin";

    std::ifstream binfile(name_file, std::ios::binary);
    if (!binfile)
    {
        std::cout << "Ошибка открытия файла..2" << std::endl;
        return 1;
    }

    binfile.seekg(0, std::ios::end);
    size_t filesize = binfile.tellg();
    binfile.seekg(0, std::ios::beg);

    int count1;
    binfile.read(reinterpret_cast<char *>(&count1), sizeof(int));
    std::cout << "All = " << count1 << std::endl;

    std::vector<NOTEBOOK> nb(count1);
    for (int i = 0; i < count1; i++)
    {
        binfile.read(reinterpret_cast<char *>(&nb[i]), sizeof(NOTEBOOK));
        std::cout << " (" << i + 1 << ") " << nb[i].model << std::endl;
    }
    binfile.close();

    return 0;
}
