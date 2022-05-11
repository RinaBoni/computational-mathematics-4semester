#include <iostream>

using namespace std;

//Интерполяция по Лагранжу
float lagrange(float x, float* xi, float* yi);
//Интерполяция по Ньютону
float newtone(float x, float* xi, float* yi);

int main()
{
    float x = -0.5;
    float xi[6] = { -1.4, -0.4, 0.2, 1.3, 2, 3.3 };
    float yi[6] = { 6.50496, -4.43904, 4.13952, 28.51563, 24, 6.76863 };

    cout << "Newtone: " << newtone(x, xi, yi) << endl;
    cout << "Lagranje: " << lagrange(x, xi, yi) << endl;
}



//Интерполяция по Лагранжу
float lagrange(float x, float* xi, float* yi)
{
    float lag = 0;
    int n = 6;
    float chis = 0, zman = 0;

    for (int k = 0; k < n; k++)
    {
        chis = 1;

        for (int i = 0; i < n; i++)
        {
            if (i != k)
                chis = chis * (x - xi[i]);
        }

        zman = 1;
        for (int j = 0; j < n; j++)
        {
            if (j != k)
                zman = zman * (xi[k] - xi[j]);
        }

        lag = lag + yi[k] * chis * zman;
    }
    return lag;
}


//Интерполяция по Ньютону
float newtone(float x, float* xi, float* yi)
{
    float newt = 0;

    int n = 6;
    int prod = 1;

    for (int k = 0; k < n; k++)
    {
        prod = prod * (x - xi[n - k + 1]);
        newt = newt + yi[n - k, k] * prod;
    }

    return newt;
}