#include <iostream>

template <class T>
class Complex
{
private:
    T real;
    T imag;

public:
    Complex(T r, T i) : real(r), imag(i) {}

    void show()
    {
        std::cout << real << " + " << imag << "i" << std::endl;
    }

    Complex operator+(const Complex &other)
    {
        return Complex(real + other.real, imag + other.imag);
    }

    Complex operator-(const Complex &other)
    {
        return Complex(real - other.real, imag - other.imag);
    }

    Complex operator*(const Complex &other)
    {
        return Complex(real * other.real - imag * other.imag, real * other.imag + imag * other.real);
    }
};

int main()
{
    int choice = 0;
    while (choice != 1 && choice != 2)
    {
        std::cout << "Выберите тип для чисел:" << std::endl;
        std::cout << " <1. int> <2. double>, " << std::endl;
        std::cin >> choice;
        if (choice == 1)
        {
            Complex x1(0, 0);
            Complex x2(0, 0);
            int n1, n2;

            int exit_code = 1;
            while (exit_code != 0)
            {
                std::cout << "---------------------------------------------" << std::endl;
                std::cout << "1. Создать число 1" << std::endl;
                std::cout << "2. Создать число 2" << std::endl;
                std::cout << "3. Сумма" << std::endl;
                std::cout << "4. Разность" << std::endl;
                std::cout << "5. Умножение" << std::endl;
                std::cout << "0. Выход" << std::endl;
                std::cout << "Выберите действие: ";
                std::cin >> exit_code;

                if (exit_code == 1)
                {
                    std::cout << "Введите значение для действительного числа: ";
                    std::cin >> n1;
                    std::cout << "Введите значение для мнимого числа: ";
                    std::cin >> n2;
                    x1 = Complex(n1, n2);
                }
                if (exit_code == 2)
                {
                    std::cout << "Введите значение для действительного числа: ";
                    std::cin >> n1;
                    std::cout << "Введите значение для мнимого числа: ";
                    std::cin >> n2;
                    x2 = Complex(n1, n2);
                }
                if (exit_code == 3)
                {
                    Complex plus = x1 + x2;
                    plus.show();
                }
                if (exit_code == 4)
                {
                    Complex minus = x1 - x2;
                    minus.show();
                }

                if (exit_code == 5)
                {
                    Complex qwer = x1 * x2;
                    qwer.show();
                }
            }
        }
        else if (choice == 2)
        {
            Complex x1(0.0, 0.0);
            Complex x2(0.0, 0.0);
            double n1, n2;

            int exit_code = 1;
            while (exit_code != 0)
            {
                std::cout << "---------------------------------------------" << std::endl;
                std::cout << "1. Создать число 1" << std::endl;
                std::cout << "2. Создать число 2" << std::endl;
                std::cout << "3. Сумма" << std::endl;
                std::cout << "4. Разность" << std::endl;
                std::cout << "5. Умножение" << std::endl;
                std::cout << "0. Выход" << std::endl;
                std::cout << "Выберите действие: ";
                std::cin >> exit_code;

                if (exit_code == 1)
                {
                    std::cout << "Введите значение для действительного числа: ";
                    std::cin >> n1;
                    std::cout << "Введите значение для мнимого числа: ";
                    std::cin >> n2;
                    x1 = Complex(n1, n2);
                }
                if (exit_code == 2)
                {
                    std::cout << "Введите значение для действительного числа: ";
                    std::cin >> n1;
                    std::cout << "Введите значение для мнимого числа: ";
                    std::cin >> n2;
                    x2 = Complex(n1, n2);
                }
                if (exit_code == 3)
                {
                    Complex plus = x1 + x2;
                    plus.show();
                }
                if (exit_code == 4)
                {
                    Complex minus = x1 - x2;
                    minus.show();
                }

                if (exit_code == 5)
                {
                    Complex qwer = x1 * x2;
                    qwer.show();
                }
            }
        }
        else
        {
            std::cout << "Ошибка, повторите ввод.." << std::endl;
        }
    }

    return 0;
}
