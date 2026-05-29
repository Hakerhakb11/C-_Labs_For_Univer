#include <iostream>
#include <random>
#include <vector>
#include <cmath>

std::vector<double> arr;
std::random_device rd;
std::uniform_real_distribution<> dist(-10, 10);

int n = 10;

int main()
{
    for (int i = 0; i < n; i++)
    {
        double x = dist(rd);
        double y = std::round(x * 100) / 100;
        arr.push_back(y);
    }

    std::cout << "Создан массив:" << std::endl;
    for (auto it = arr.begin(); it != arr.end(); it++)
    {
        std::cout << *it << std::endl;
    }

    double a = -2;
    double b = 5;

    double check = fabs(*arr.begin());
    double sum_fabs = 0;

    int number = 0;
    int exit_code = 0;
    int num_min_elem = 1;

    for (auto it = arr.begin(); it != arr.end(); it++)
    {
        number++;
        if (fabs(*it) < check)
        {
            check = *it;
            num_min_elem = number;
        }

        if (exit_code == 0)
        {
            if (*it < 0)
            {
                exit_code = 1;
            }
        }
        else
        {
            sum_fabs += fabs(*it);
        }

        if (*it > a && *it < b)
        {
            arr.erase(it);
            it--;
        }
    }
    std::cout << "\nНомер минимального по модулю элемента: " << num_min_elem << std::endl;
    std::cout << "\nСумма модулей после первого отрицательного элемента: " << sum_fabs << std::endl;

    for (int i = arr.size(); i < n; i++)
    {
        arr.push_back(0);
    }

    std::cout << "\nСжатый массив:" << std::endl;
    for (auto it = arr.begin(); it != arr.end(); it++)
    {
        std::cout << *it << std::endl;
    }

    return 0;
}
// в одномерном массиве, состоящем из n вещественных элементов, вычислить:
// 1) номер минимального по модулю элемента массива;
// 2) сумму модулей элементов массива,
// расположенных после первогоотрицательного элемента.
// Сжать массив, удалив из него все элементы, величина которых находится в
// интервале [а,Ь]. Освободившиеся в конце массива элементы заполнить нулями.
