#include <iostream>
#include <vector>
#include <iomanip>
#include <numeric>
#include <algorithm>

int main()
{
    std::vector<std::vector<double>> matrix = {
        {6, 3, 9},
        {4, 4, 44},
        {6, 8, 34}};

    int line = matrix.size();
    int stolb = matrix[0].size();

    std::cout << "Исходная матрица: " << std::endl;
    for (int i = 0; i < line; i++)
    {
        for (int j = 0; j < stolb; j++)
        {
            std::cout << " " << matrix[i][j];
        }
        std::cout << std::endl;
    }

    for (int i = 0; i < std::min(line, stolb); i++)
    {
        int maxval = i;
        for (int k = i + 1; k < line; k++)
        {
            if (matrix[maxval][i] < matrix[k][i])
            {
                maxval = k;
            }
        }
        std::swap(matrix[i], matrix[maxval]);

        if (matrix[i][i] == 0)
        {
            continue;
        }

        for (int k = i + 1; k < line; k++)
        {
            double value = matrix[k][i] / matrix[i][i];
            for (int j = i; j < stolb; j++)
            {
                matrix[k][j] -= value * matrix[i][j];
            }
        }
    }

    std::cout << std::fixed << std::setprecision(2) << "\nне Исходная матрица: " << std::endl;
    for (int i = 0; i < line; i++)
    {
        for (int j = 0; j < stolb; j++)
        {
            std::cout << " " << matrix[i][j];
        }
        std::cout << std::endl;
    }

    double number;
    // std::cout << "\nВведите значение для среднего арифметического: ";
    // std::cin >> number;
    number = 9;
    int count = 0;

    for (const auto &i : matrix)
    {
        double sum = std::accumulate(i.begin(), i.end(), 0.0);
        double avg = sum / i.size();
        if (avg < number)
        {
            count++;
        }
    }

    std::cout << "Количество строк, среднее арифметическое которых меньше " << number << ": " << count << std::endl;

    return 0;
}
