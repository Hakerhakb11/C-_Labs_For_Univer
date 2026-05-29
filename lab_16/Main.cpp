#include <iostream>
#include <random>
#include <vector>
#include <algorithm>

std::vector<double> arr;
std::random_device rd;
std::uniform_real_distribution<> dist(-10, 10);

int n = 10;

int main()
{
    for (int i = 0; i < n; i++)
    {
        arr.push_back(std::round(dist(rd) * 100) / 100);
    }

    std::cout << "Создан массив:" << std::endl;
    for (auto it = arr.begin(); it != arr.end(); it++)
    {
        std::cout << *it << std::endl;
    }

    double a = -2;
    double b = 5;

    auto min_val = std::min_element(arr.begin(), arr.end(), [](double x, double y)
                                    { return fabs(x) < fabs(y); });

    int num_min_elem = std::distance(arr.begin(), min_val);

    auto first_neg = std::find_if(arr.begin(), arr.end(), [](double x)
                                  { return x < 0; });

    double sum_fabs = std::accumulate(first_neg + 1, arr.end(), 0.0, [](double x, double y)
                                      { return fabs(x) + fabs(y); });

    arr.erase(std::remove_if(arr.begin(), arr.end(), [a, b](double x)
                             { return x > a && x < b; }),
              arr.end());

    while (arr.size() < n)
    {
        arr.push_back(0);
    }

    std::cout << "\nНомер минимального по модулю элемента: num_min_elem " << num_min_elem + 1 << std::endl;
    std::cout << "\nСумма модулей после первого отрицательного элемента: sum_fabs " << sum_fabs << std::endl;

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
// интервале [а,Ь]. Освободившиеся в конце массива элементы заполнить нулями.1
