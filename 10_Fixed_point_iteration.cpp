#include <iostream>
#include <math.h>
using namespace std;

// Given function - f(x) =>   x*x - x - 1 = 0

// In g(x) form -  g(x) =>   x = x*x -1
//   i.e.    y = x*x -1
//   g'(x) = 2*x

float f(float x)
{
    return ((x * x) - x - 1);
}
float g(float x)
{
    return (sqrt(x + 1));
}

int main()
{
    float b;
    double value, error;

    cout << "Enter the upper limit of equation : ";
    cin >> b;
    cout << "Enter the min possible value : ";
    cin >> value;

    float m = g(b);
    int i = 1;
    if (abs(f(m)) >= value)
    {
        while (abs(f(m)) >= value)
        {
            printf("\ni= %d \t\tb= %0.6f \t\tm= %0.6f  \t\t|m-b|= %0.6f", i++, b, m, abs(m - b));
            b = m;
            m = g(b);
        }
    }
    else
    {
        printf("\ni= %d \t\tb= %0.6f \t\tm= %0.6f  \t\t|m-b|= %0.6f", i, b, m, abs(m - b));
        cout << "\nRoot : " << m;
    }
    return 0;
}