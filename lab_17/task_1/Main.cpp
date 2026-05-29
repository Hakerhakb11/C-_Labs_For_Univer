#include <iostream>
#include <random>
#include <algorithm>
#include <valarray>

int n = 10;

std::valarray<double> arr(n);
std::random_device rd;
std::uniform_real_distribution<> dist(-10.0, 10.0);

std::valarray<double> arr2(n);

int main()
{
    for (int i = 0; i < n; i++)
    {
        arr[i] = std::round(dist(rd) * 100) / 100;
    }

    std::cout << "Создан массив: " << std::endl;
    for (int i = 0; i < n; i++)
    {
        std::cout << arr[i] << std::endl;
    }

    double a = -2;
    double b = 5;

    double check = fabs(arr[0]);
    double sum_fabs = 0;

    int number = 0;
    int exit_code = 0;
    int num_min_elem = 1;

    for (int i = 0; i < n; i++)
    {
        number++;
        if (fabs(arr[i]) < check)
        {
            check = fabs(arr[i]);
            num_min_elem = number;
        }

        if (exit_code == 0)
        {
            if (arr[i] < 0)
            {
                exit_code = 1;
            }
        }
        else
        {
            sum_fabs += fabs(arr[i]);
        }
    }

    std::cout << "\nНомер минимального по модулю элемента: num_min_elem " << num_min_elem << std::endl;
    std::cout << "\nСумма модулей после первого отрицательного элемента: sum_fabs " << sum_fabs << std::endl;
    int num_back = 0;
    int j = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > a && arr[i] < b)
        {
            num_back++;
        }
        else
        {
            arr2[j] = arr[i];
            j++;
        }
    }

    std::cout << "\nСжатый массив:" << std::endl;
    arr2[std::slice(1, 10, 1)];
    for (int i : arr2)
    {
        std::cout << "(" << i << "), ";
    }
    return 0;
}
// в одномерном массиве, состоящем из n вещественных элементов, вычислить:
// 1) номер минимального по модулю элемента массива;
// 2) сумму модулей элементов массива,
// расположенных после первогоотрицательного элемента.
// Сжать массив, удалив из него все элементы, величина которых находится в
// интервале [а,Ь]. Освободившиеся в конце массива элементы заполнить нулями.
