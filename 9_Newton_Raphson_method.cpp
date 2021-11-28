#include <iostream>
using namespace std;

float f(float x)
{
    return ((x * x) - 12);
}

float f2(float x)
{
    return (2 * x);
}

int main()
{
    float b;
    double value, error;

    cout << "Enter the upper limit of equation : ";
    cin >> b;
    cout << "Enter the min possible value : ";
    cin >> value;

    float m = b - (f(b) / f2(b));
    int i = 1;
    if (abs(f(m)) > 0)
    {
        while (abs(f(m)) > value)
        {
            printf("\ni= %d \t\tb= %0.6f \t\tm= %0.6f  \t\tf(m)= %0.6f", i++, b, m, f(m));
            b = m;
            m = b - (f(b) / f2(b));
        }
    }
    else
    {
        cout << "\nRoot : " << m;
    }
    error = m - value;
    printf("\nError = %.6f", error);
    return 0;
}