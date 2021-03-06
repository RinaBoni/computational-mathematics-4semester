#include <iostream>
#include <vector>

using namespace std;

float xi[6] = { -1.4, -0.4, 0.2, 1.3, 2, 3.3 };
float yi[6] = { 6.50496, -4.43904, 4.13952, 28.51563, 24, 6.76863 };

float x = -0.5;

//Интерполяция по Лагранжу
float lagrange(float x, float* xi, float* yi);

//Интерполяция по Ньютону1
float newtone1(float x, float* xi, float* yi);

//Интерполяция по Ньютону2
float newtone2(float x, float* xi, float* yi);

//разделённые разности
vector<vector<float>> razdelen();

int main()
{


    cout << "Newtone1: " << newtone2(x, xi, yi) << endl;
    cout << "Newtone2: " << newtone2(x, xi, yi) << endl;
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

        lag = lag + yi[k] * chis / zman;
    }
    return lag;
}

//разделённые разности
vector<vector<float>> razdelen()
{
    int n = 6;

    vector<vector<float>> a(n, vector<float>(n + 1));

    for (int i = 0; i < a.size(); i++)
    {
        a[i][0] = xi[i];
        a[i][1] = yi[i];
    }

    int k = 0;

    for (int j = 2; j < a[0].size(); j++)
    {
        for (int i = 0; i < a.size() - 1; i++)
        {
            if (i + 1 + k >= a.size())
            {
                break;
            }
            else
            {
                a[i][j] = (a[i + 1][j - 1] - a[i][j - 1]) / (a[i + 1 + k][0] - a[i][0]);
            }

        }
        k++;
    }
    return a;
}

//Интерполяция по Ньютону2
float newtone2(float x, float* xi, float* yi)
{
   

    int n = 6;
    float newt = yi[n];
    float prod = 1;

    vector<vector<float>> raz = razdelen();

    for (int k = 0; k < n; k++)
    {
        prod = prod * (x - xi[n - k + 1]);
        newt = newt + raz[n - k, k] * prod;
    }

    return newt;
}

//Интерполяция по Ньютону1
float newtone1(float x, float* xi, float* yi)
{
    int n = 6;
    float newt = yi[0];
    float prod = 1;

    vector<vector<float>> raz = razdelen();

    for (int k = 1; k < n; k++)
    {
        prod = prod * (x - xi[k - 1]);
        newt = newt + raz[0, k] * prod;
    }
    
    return newt;
}
