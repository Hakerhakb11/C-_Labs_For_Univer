#include <iostream>
#include <cstring>
#include <vector>
#include <string>
typedef struct node
{
    std::string data;
    struct node *next;
} Node;

int n = 0;
int exit_code = 1;
int k;

class Book
{
private:
    static int count_list;
    int n_qty;

public:
    std::string listName;
    Node *pbeg = NULL, *pend = NULL, *temp;

    Book() {}

    friend std::ostream &operator<<(std::ostream &os, Book &b)
    {
        os << b.listName << "\n";

        if (b.n_qty != 0)
        {
            Node *pcur = b.pbeg;
            while (pcur != NULL)
            {
                std::cout << pcur->data << " ";
                pcur = pcur->next;
            }
            std::cout << "\n"
                      << std::endl;
        }

        else
        {
            std::cout << "Список пуст.." << std::endl;
        }

        return os;
    }

    friend std::istream &operator>>(std::istream &is, Book &b)
    {
        std::cout << "Введите имя списка: ";
        is >> b.listName;
        std::cout << "Введите количество элементов: ";
        is >> b.n_qty;

        if (b.n_qty > 0)
        {
            std::string string;
            std::cout << "Введите строку:" << std::endl;
            std::cin >> string;
            b.pend = b.pbeg = new (Node);
            b.pbeg->data = string;
            for (int i = 1; i < b.n_qty; i++)
            {
                std::cout << "Введите строку:" << std::endl;
                std::cin >> string;
                b.pend = b.pend->next = new (Node);
                b.pend->data = string;
            }
            b.pend->next = NULL;
        }
        Book::count_list += 1;
        std::cout << "Список '" << b.listName << "' на '" << b.n_qty << "' элементов был создан:\n";
        std::cout << b;

        return is;
    }

    int search_by_num()
    {
        if (count_list <= 0)
        {
            std::cout << "Список ешё не создан.\n";
            return 0;
        }
        int j;
        temp = pbeg;
        std::cout << "Введите номер элемента:";
        std::cin >> j;
        if (j > n_qty || j <= 0)
        {
            std::cout << "\nЧисло (" << j << "), выходит за пределы списка в (" << n_qty << ").\n";
            return 0;
        }
        for (int i = 1; i < j; i++)
        {
            temp = temp->next;
        }
        std::cout << "\nЭлемент (" << j << ") = '" << temp->data << "'\n";
        return 0;
    }

    void copled(Book *other, std::vector<Book *> &lists)
    {
        std::cout << "Первый" << std::endl;
        std::cout << *this;
        std::cout << "Второй" << std::endl;
        std::cout << *other;
        Book *x = new Book;
        lists.push_back(x);
        std::cout << "Введите имя для нового списка:" << std::endl;
        std::string temp = listName;
        std::cin >> lists.back()->listName;

        std::cout << "Процесс создания списка..." << std::endl;
        Node *temp1 = pbeg, *temp2 = other->pbeg;

        lists.back()->pbeg = lists.back()->pend = new (Node);
        lists.back()->pend->data = temp1->data;
        lists.back()->n_qty += 1;
        temp1 = temp1->next;

        lists.back()->pend = lists.back()->pend->next = new (Node);
        lists.back()->pend->data = temp2->data;
        lists.back()->n_qty += 1;
        temp2 = temp2->next;
        lists.back()->pend->next = NULL;

        while (temp1 != NULL && temp2 != NULL)
        {
            lists.back()->pend = lists.back()->pend->next = new (Node);
            lists.back()->pend->data = temp1->data;
            lists.back()->pend->next = NULL;
            lists.back()->n_qty += 1;
            temp1 = temp1->next;

            lists.back()->pend = lists.back()->pend->next = new (Node);
            lists.back()->pend->data = temp2->data;
            lists.back()->pend->next = NULL;
            lists.back()->n_qty += 1;
            temp2 = temp2->next;
        }
        lists.back()->pend->next = NULL;
        listName = temp;
        std::cout << "Успешно!" << std::endl;
    }

    void merge(Book *other, std::vector<Book *> &lists, int number_for_del)
    {
        std::cout << "Первый" << std::endl;
        std::cout << *this;
        std::cout << "Второй" << std::endl;
        std::cout << *other;
        std::cout << "Введите имя для нового списка:" << std::endl;
        std::string temp = listName;
        std::cin >> listName;

        std::cout << "Процесс слияния списков..." << std::endl;
        Node *temp1 = pbeg;

        while (temp1 != NULL)
        {
            Node *temp2 = temp1;
            while (temp2->next != NULL)
            {
                if (temp2->next->data == temp1->data)
                {
                    Node *obj_del = temp2->next;
                    temp2->next = temp2->next->next;
                    delete obj_del;
                    n_qty -= 1;
                }
                else
                {
                    temp2 = temp2->next;
                }
            }
            temp1 = temp1->next;
        }

        temp1 = pbeg;
        Node *temp2 = other->pbeg;
        pend = pbeg;
        if (pend != NULL)
        {
            while (pend->next != NULL)
            {
                pend = pend->next;
            }
        }
        temp1 = pend;
        while (temp1 != NULL)
        {
            temp1 = temp1->next;
        }
        for (int i = 0; i < other->n_qty; i++)
        {
            temp1 = new Node();
            temp1->data = temp2->data;
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        temp1 = new (Node);
        temp1->next = NULL;
        n_qty += other->n_qty;
        if (pend != NULL)
        {
            while (pend->next != NULL)
            {
                pend = pend->next;
            }
        }
        temp1 = pbeg;
        while (temp1 != NULL)
        {
            temp2 = temp1;
            while (temp2->next != NULL)
            {
                if (temp2->next->data == temp1->data)
                {
                    Node *obj_del = temp2->next;
                    temp2->next = temp2->next->next;
                    delete obj_del;
                    n_qty -= 1;
                }
                else
                {
                    temp2 = temp2->next;
                }
            }
            temp1 = temp1->next;
        }
        pend = pbeg;
        if (pend != NULL)
        {
            while (pend->next != NULL)
            {
                pend = pend->next;
            }
        }

        lists.erase(lists.begin() + number_for_del - 1);
        delete (other);
        count_list -= 1;
        std::cout << "Успешно!" << std::endl;
    }
};
int Book::count_list = 0;
int main()
{
    std::vector<Book *> lists;
    std::string listName;

    while (exit_code != 0)
    {
        std::cout << "---------------------------------------------" << std::endl;
        std::cout << "1. Создать список" << std::endl;
        std::cout << "2. Выбрать список для редактирования" << std::endl;
        std::cout << "3. Вывести все списки" << std::endl;
        std::cout << "4. Вывести список" << std::endl;
        std::cout << "0. Выход" << std::endl;
        std::cout << "Выберите действие: ";
        std::cin >> exit_code;

        if (exit_code == 1)
        {
            Book *x = new Book();
            lists.push_back(x);
            std::cin >> *x;
        }

        if (lists.size() == 0)
        {
            continue;
        }

        if (exit_code == 2)
        {
            std::cout << "Доступных списков: " << lists.size() << std::endl;
            for (int i = 0; i < lists.size(); i++)
            {
                std::cout << (i + 1) << ") " << lists[i]->listName << std::endl;
            }
            int number;
            std::cin >> number;
            int exit_code2 = 1;

            while (exit_code2 != 0)
            {
                std::cout << "---------------------------------------------" << std::endl;
                std::cout << "Выберите действие над списком: " << lists[number - 1]->listName << std::endl;
                std::cout << *lists[number - 1];
                std::cout << "1. Вывести элемент по номеру" << std::endl;
                std::cout << "2. Сцепить два списка поэлементно" << std::endl;
                std::cout << "3. Соеденить два списка с исключением повторяющихся элементов" << std::endl;
                std::cout << "0. Выход" << std::endl;
                std::cin >> exit_code2;
                if (exit_code2 == 1)
                {
                    lists[number - 1]->search_by_num();
                }

                if (exit_code2 == 2)
                {
                    std::cout << "Выберите список для скрепления:" << std::endl;
                    std::cout << "Доступных списков: " << lists.size() << std::endl;
                    for (int i = 0; i < lists.size(); i++)
                    {
                        std::cout << (i + 1) << ") " << lists[i]->listName << std::endl;
                    }
                    int number2;
                    std::cin >> number2;
                    if (number2 > lists.size() || number2 <= 0)
                    {
                        std::cout << "Ошибка выхода за границы.." << std::endl;
                    }
                    else
                    {
                        lists[number - 1]->copled(lists[number2 - 1], lists);
                        exit_code2 = 0;
                    }
                }

                if (exit_code2 == 3)
                {
                    std::cout << "Выберите список для слияния:" << std::endl;
                    std::cout << "Доступных списков: " << lists.size() << std::endl;
                    for (int i = 0; i < lists.size(); i++)
                    {
                        std::cout << (i + 1) << ") " << lists[i]->listName << std::endl;
                    }
                    int number2;
                    std::cin >> number2;
                    if (number2 > lists.size() || number2 <= 0)
                    {
                        std::cout << "Ошибка выхода за границы.." << std::endl;
                    }
                    else
                    {
                        if (lists[number - 1] == lists[number2 - 1])
                        {
                            std::cout << "Списки одинаковы." << std::endl;
                        }
                        else
                        {
                            lists[number - 1]->merge(lists[number2 - 1], lists, number2);
                        }
                        exit_code2 = 0;
                    }
                }
            }
        }

        if (exit_code == 3)
        {
            std::cout << "Все списки: " << lists.size() << std::endl;
            for (int i = 0; i < lists.size(); i++)
            {
                std::cout << (i + 1) << ") " << lists[i]->listName << std::endl;
            }
        }

        if (exit_code == 4)
        {
            std::cout << "Доступных списков: " << lists.size() << std::endl;
            for (int i = 0; i < lists.size(); i++)
            {
                std::cout << (i + 1) << ") " << lists[i]->listName << std::endl;
            }
            int number;
            std::cin >> number;
            std::cout << "Имя: " << lists[number - 1]->listName << std::endl;
            std::cout << *lists[number - 1];
        }
    }
    return 0;
}
