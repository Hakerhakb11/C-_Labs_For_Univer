#include <iostream>
#include <sstream>
#include <fstream>

int main()
{
    std::string test = "text.dat";
    std::ifstream file(test);
    if (!file)
    {
        std::cout << "Ошибка открытия" << std::endl;
        return 0;
    }
    std::string line;
    std::cout << "Содержимое файла:";
    while (std::getline(file, line))
    {
        std::cout << line << std::endl;
    }

    auto it = line.rbegin();
    while (it != line.rend() && isspace(*it) || ispunct(*it))
    {
        it++;
    }

    auto words = it;

    while (it != line.rend() && !isspace(*it) && !ispunct(*it))
    {
        it++;
    }

    std::string endword(it.base(), words.base());
    std::cout << "Последнее слово: (" << endword << ")" << std::endl;

    char c = 'a';
    int count;
    for (auto it = endword.begin(); it < endword.end(); it++)
    {
        if (*it == c)
        {
            count++;
        }
    }
    std::cout << "Количество букв 'а': " << count << std::endl;

    std::string any;
    std::cout << "Нажмите клавишу для выделения последнего слова" << std::endl;
    std::cin >> any;
    std::cout << "\033[31m" << endword << "\033[0m" << std::endl;

    int quantity = 0;
    int exit_code = 1;
    while (exit_code <= count)
    {
        std::cout << "Нажмите клавишу для выделения буквы" << std::endl;
        std::cin >> any;
        quantity = exit_code;
        for (auto it = endword.begin(); it < endword.end(); it++)
        {
            if (*it == c)
            {
                if (quantity)
                {
                    std::cout << "\033[32m" << *it << "\033[0m";
                    quantity--;
                }
                else
                {
                    std::cout << *it;
                }
            }
            else
            {
                std::cout << *it;
            }
        }
        exit_code++;
        std::cout << std::endl;
    }
    return 0;
}
