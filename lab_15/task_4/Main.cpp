#include <iostream>
#include <vector>
#include <string>
#include <cstring>

struct Subj
{
    std::string word;
    std::vector<int> pages[10];
};

struct Node
{
    Subj data;
    Node *next;
};

int main()
{
    Node *pbeg = NULL, *pend = NULL;
    int n_qty;
    int exit_code = 1;
    while (exit_code != 0)
    {
        std::cout << "\n-----------------------------------------" << std::endl;
        std::cout << "1). Формирование предметного указателя" << std::endl;
        std::cout << "2). Вывод предметного указателя" << std::endl;
        std::cout << "3). Вывод номеров страниц для заданного слова" << std::endl;
        std::cout << "0). Выход из программы" << std::endl;
        std::cout << "Выберите действие: ";
        std::string choice;
        std::cin >> choice;
        std::cout << std::endl;

        if (choice == "0")
        {
            exit_code = 0;
            continue;
        }

        if (choice == "1")
        {
            Subj subj_to_node;
            int n;

            std::cout << "Задайте количество компонент в указателе: ";
            std::cin >> n;
            n_qty = n;

            if (n > 0)
            {
                pend = pbeg = new (Node);
                std::cout << "Введите слово №" << "1" << std::endl;
                Subj subj_to_node;
                std::cin >> subj_to_node.word;

                int value = 1;
                for (int i = 0; i < 10; i++)
                {
                    std::cout << "Вводите связанные страницы|либо '0' для завершения ввода" << std::endl;
                    std::cin >> value;
                    if (value == 0)
                    {
                        break;
                    }
                    subj_to_node.pages->push_back(value);
                }
                pbeg->data = subj_to_node;

                for (int i = 1; i < n; i++)
                {
                    pend = pend->next = new (Node);
                    std::cout << "Введите слово №" << i + 1 << std::endl;
                    Subj subj_to_node;
                    std::cin >> subj_to_node.word;

                    int value = 1;
                    for (int i = 0; i < 10; i++)
                    {
                        std::cout << "Вводите связанные страницы|либо '0' для завершения ввода" << std::endl;
                        std::cin >> value;
                        if (value == 0)
                        {
                            break;
                        }
                        subj_to_node.pages->push_back(value);
                    }
                    pend->data = subj_to_node;
                }
                pend->next = NULL;
            }
            continue;
        }

        if (choice == "2")
        {
            if (n_qty != 0)
            {
                Node *pcur = pbeg;
                while (pcur != NULL)
                {
                    std::cout << "Слово: " << pcur->data.word << std::endl;
                    std::cout << "Страницы где оно встречается: " << std::endl;
                    for (int i : *pcur->data.pages)
                    {
                        std::cout << i << " ";
                    }
                    pcur = pcur->next;
                    std::cout << "\n"
                              << std::endl;
                }
            }
            else
            {
                std::cout << "Список пуст.." << std::endl;
            }
            continue;
        }

        if (choice == "3")
        {
            int check = 0;
            if (n_qty != 0)
            {
                std::string word;
                std::cout << "Введите слово: ";
                std::cin >> word;

                Node *pcur = pbeg;
                while (pcur != NULL)
                {
                    if (pcur->data.word == word)
                    {
                        std::cout << "\nСлово '" << word << "' найдено на страницах: " << std::endl;
                        for (int i : *pcur->data.pages)
                        {
                            std::cout << i << " ";
                        }
                        pcur = pcur->next;
                        check = 1;
                    }
                    else
                    {
                        pcur = pcur->next;
                    }
                }
                std::cout << std::endl;
                if (check == 0)
                {
                    std::cout << "Слово '" << word << "' не найдено." << std::endl;
                    continue;
                }
            }
            else
            {
                std::cout << "Список пуст.." << std::endl;
                continue;
            }
            continue;
        }
        std::cout << "\nНеверный ввод!" << std::endl;
    }
    return 0;
}

// Предметный указатель организован как линейный список.
// Каждая компонента указателя содержит слово и номера страниц, на которых это
// слово встречается. Количество номеров страниц, относящихся к одному слову, от
// одного до десяти.
// Составить программу, которая обеспечивает:
// • начальное формирование предметного указателя;
// • вывод предметного указателя;
// • вывод номеров страниц для заданного слова.
// Программа должна обеспечивать диалог с помощью меню и контроль ошибок
// при вводе.
