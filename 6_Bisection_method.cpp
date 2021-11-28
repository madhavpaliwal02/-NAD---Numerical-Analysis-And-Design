#include <iostream>
using namespace std;

float f(float x)
{
    return ((x * x) - 25);
}

int main()
{
    int i = 1; // To keep track on iteration
    float a, b, m, e = 0.0001;
    cout << "Enter a and b :";
    cin >> a >> b;

    cout << ".......................................................................................";
    cout << "\n\ti \t    a \t\t    b \t\tm=(a+b)/2 \t  f(m)\n";
    if (f(a) * f(b) < 0)
    {
        m = (a + b) / 2;
        while (abs(f(m)) > e)
        {
            printf("\t%d \t%0.6f \t%0.6f \t%0.6f \t%0.6f\n", i++, a, b, m, f(m));
            if (f(m) > 0)
                b = m;
            else
                a = m;
            m = (a + b) / 2;
        }
    }
    else
    {
        cout << "\nInvalid Interval !!";
    }
    cout << "\nRoot = " << m;
    cout << "\nError : " << abs(f(m) - e);

    return 0;
}