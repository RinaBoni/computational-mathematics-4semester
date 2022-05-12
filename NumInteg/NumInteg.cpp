#include <iostream>

using namespace std;

//функция а     (трапеция, точность 0,001)
double f(double x);
//пределы интегрирования
//левый
const double a = 2.3;
//правый
const double b = 3.3;



//функция б     (Симпсон, n = 8)
double g(double x);
//пределы интегрирования
//левый
const double c = 2.0;
//правый
const double d = 2.4;



//Вычисление интегралла по формуле трапеций
double trapezoid();

//Вычисление интегралла по формуле Симпсона
double simpson();



int main()
{
    system("chcp 1251");

    cout << "\nПервый интеграл: 1 / (sqrt(x * x - 4))" << endl;
    cout << "По формуле трапеции равен: " << trapezoid << "\n" << endl;

    cout << "\nВторой интеграл: log10(x * x + 7) / (x * x - 1)" << endl;
    cout << "По формуле Симпсона равен: " << simpson << "\n" << endl;
}


//функция а     (трапеция, точность 0,001)
double f(double x)
{
    double F = 1 / (sqrt(x * x - 4));
    return F;
}

//функция б     (Симпсон, n = 8)
double g(double x)
{
    double G = log10(x * x + 7) / (x * x - 1);
    return G;
}


//Вычисление интегралла по формуле трапеций
double trapezoid()
{
    const int n = 12;

    double h = (b - a) / n;

    double w = 0;

    double x;

    for (int k = 1; k < n - 1; k++)
    {
        x = a + k * h;
        w = w + f(x);
    }

    w = (2 * w + f(a) + f(b)) * h / 2;
    return w;
}

//Вычисление интегралла по формуле Симпсона
double simpson()
{
    const int m = 4;
    
    const int n = m * 2;

    double h = (d - c) / n;

    double s = 0;

    double s1 = 0;

    double s2 = 0;

    double x;

    for (int k = 1; k <= m; k++)
    {
        x = c + (2 * k - 1) * h;
        s1 = (4 * s1 + 2 * s2 + g(c) + g(d)) * h / 3;
    }

    for (int k = 1; k < m - 1; k++)
    {
        x = c + 2 * k * h;
        s2 = s2 + g(x);
    }

    s = (4 * s1 + 2 * s2 + g(c) + g(d)) * h / 3;

    return s;
}