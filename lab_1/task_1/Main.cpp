#include <stdio.h>
#include <math.h>
#include <clocale>

int main()
{
    std::setlocale(LC_ALL, ".UTF8"); 
    double x1 = 1, x2 = 10, x3 = 15, x0 = 10, y1 = 1, y2 = 10, y3 = 15, y0 = 5;
    double a, b, c, a1, b1, c1, S, S1, S2, S3, s, s1, s2, s3, Ssum, p, e, t, i;

    a = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
    b = sqrt(pow(x3 - x2, 2) + pow(y3 - y2, 2));
    c = sqrt(pow(x3 - x1, 2) + pow(y3 - y1, 2));
    a1 = sqrt(pow(x0 - x1, 2) + pow(y0 - y1, 2));
    b1 = sqrt(pow(x0 - x2, 2) + pow(y0 - y2, 2));
    c1 = sqrt(pow(x3 - x0, 2) + pow(y3 - y0, 2));
    p = (a + b + c) / 2;
    t = (a1 + a + b1) / 2;
    e = (c1 + c + a1) / 2;
    i = (b1 + b + c1) / 2;
    S1 = sqrt(t * (t - a1) * (t - a) * (t - b1));
    S2 = sqrt(i * (i - b1) * (i - b) * (i - c1));
    S3 = sqrt(e * (e - c1) * (e - c) * (e - a1));
    S = sqrt(p * (p - a) * (p - b) * (p - c));

    s1 = 0.5 * fabs(x1 * y2 + x2 * y3 + x3 * y1 - x1 * y3 - x2 * y1 - x3 * y2);
    s2 = 0.5 * fabs(x1 * y2 + x2 * y0 + x0 * y1 - x1 * y0 - x2 * y1 - x0 * y2);
    s3 = 0.5 * fabs(x2 * y3 + x3 * y0 + x0 * y2 - x2 * y0 - x3 * y2 - x0 * y3);
    s = 0.5 * fabs(x1 * y0 + x0 * y3 + x3 * y1 - x1 * y3 - x0 * y1 - x3 * y0);
    printf("%s, %f, %f, %f, %f, %s", "Площадя по формуле гауса:", s, s1, s2, s3, "Сравнивая, видно что наибольший треугольник ABC");
    Ssum = (S1 + S2 + S3);
    printf("%s, %f, %f, %f, %f, %s", "\nПлощадя по формуле герона:", S, S1, S2, S3, "Сравнивая, видно что наибольший треугольник ABC");
    if (Ssum > S) {
        printf("\n хорошая работа сумма площадей больше треуголинька ABC, значит точка P принадлежит треугольнику. А это сумма площадей: %f", Ssum);
    }
    else {
        printf("\n Dosent work %f, %s", Ssum, "Что-то пошло не так");
    }

    return 0;
}
