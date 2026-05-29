#include <iostream>
#include <string>
#include <vector>

struct MARSH
{
    std::string begname;
    std::string endname;
    int num;
};

int main()
{
    int n = 8;

    std::vector<MARSH> marshvec;

    // std::string sinp[n] = {"scity_1", "scity_2", "scity_3", "scity_4", "scity_5", "scity_6", "scity_7", "scity_8"};
    // std::string einp[n] = {"ecity_1", "ecity_2", "ecity_3", "ecity_4", "ecity_5", "ecity_6", "ecity_7", "ecity_8"};

    std::string sinp[n];
    std::string einp[n];

    std::string input;
    for (int i = 0; i < n; i++)
    {
        std::cout << "Введите название начального пункта маршрута: ";
        std::cin >> input;
        sinp[i] = input;

        std::cout << "Введите название конечного пункта маршрута: ";
        std::cin >> input;
        einp[i] = input;
    }

    for (int i = 0; i < n; i++)
    {
        MARSH mr;
        mr.begname = sinp[i];
        mr.endname = einp[i];
        mr.num = i;
        marshvec.push_back(mr);
    }

    int exit_code = 0;
    while (exit_code == 0)
    {
        int eror = 0;
        std::string test;
        std::cout << "Введите 'название' для вывода информации. \n'0'Для выхода из программы: ";
        std::cin >> test;
        for (int i = 0; i < n; i++)
        {
            if (test == marshvec[i].begname || test == marshvec[i].endname)
            {
                std::cout << "\n"
                          << marshvec[i].num + 1 << std::endl;
                std::cout << "Начало: " << marshvec[i].begname << std::endl;
                std::cout << "Конец: " << marshvec[i].endname << std::endl;
                eror = 1;
            }
        }

        if (eror == 0)
        {
            std::cout << "\nВведённого маршрута не существует.\n"
                      << std::endl;
            if (test == "0")
            {
                exit_code = 1;
                break;
            }
        }
    }

    return 0;
}

// 1. Описать структуру с именем MARSH, содержащую следующие поля:
// • название начального пункта маршрута;
// • название конечного пункта маршрута;
// • номер маршрута.
// 2. Написать программу, выполняющую следующие действия:
// • ввод с клавиатуры данных в массив, состоящий из восьми элементов типа
// MARSH; записи должны быть упорядочены по номерам маршрутов;
// • вывод на экран информации о маршрутах, которые начинаются или кончаются в пункте, название которого введено с клавиатуры;
// • если таких маршрутов нет, выдать на дисплей соответствующее сообщение.
