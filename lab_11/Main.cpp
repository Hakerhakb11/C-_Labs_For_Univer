#include <iostream>
#include <cmath>
#include <iomanip>

int main()
{
    double a, b, c, x_start, x_end, dx;

    std::cout << "Введите a, b, c: ";
    std::cin >> a >> b >> c;
    std::cout << "Введите Xнач, Xкон, dX: ";
    std::cin >> x_start >> x_end >> dx;

    // a = 3;
    // b = 2;
    // c = 2;
    // x_start = -5;
    // x_end = 5;
    // dx = 0.5;

    int Ac = (a);
    int Bc = (b);
    int Cc = (c);

    std::cout << "------------------------------------" << std::endl;
    std::cout << "|   x   |     F(x)     |    Тип    |" << std::endl;
    std::cout << "------------------------------------" << std::endl;

    for (double x = x_start; x <= x_end; x += dx)
    {
        double F = 0;

        if (x < 1 && c != 0)
        {
            F = a * x * x + (b / c);
        }
        else if (x > 1.5 && c == 0)
        {
            F = (x - a) / ((x - c) * (x - c));
        }
        else
        {
            F = (x * x) / (c * c);
        }

        if (((Ac & Bc) % 2 * Cc) != 0) // ?
        {
            std::cout << "|" << std::setw(6) << x << " | " << std::setw(12) << F << " |  double   |" << std::endl;
        }
        else
        {
            std::cout << "|" << std::setw(6) << x << " | " << std::setw(12) << int(F) << " | int       |" << std::endl;
        }
    }

    std::cout << "------------------------------------" << std::endl;
    return 0;
}
