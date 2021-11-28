#include <iostream>
using namespace std;

float f(float x)
{
    return ((x * x * x) - (4 * x) + 1);
}

int main()
{
    int i = 1; // To keep track on iteration
    float a, b, m, e = 0.0001;
    cout << "Enter a and b :";
    cin >> a >> b;

    cout << ".......................................................................................";
    cout << "\n\ti \t    a \t\t    b \t\t   m \t\t  f(m)\n";
    if (f(a) * f(b) < 0)
    {
        m = (a * f(b) - b * f(a)) / (f(b) - f(a));
        while (abs(f(m)) > e)
        {
            printf("\t%d \t%0.6f \t%0.6f \t%0.6f \t%0.6f\n", i++, a, b, m, f(m));
            if (f(m) < 0)
                a = m;
            else
                b = m;
            m = (a * f(b) - b * f(a)) / (f(b) - f(a));
        }
        printf("\t%d \t%0.6f \t%0.6f \t%0.6f \t%0.6f\n", i++, a, b, m, f(m));
    }
    else
    {
        cout << "\nInvalid Interval !!";
    }
    cout << "\nRoot = " << m << "\t\t\tError : " << abs(f(m) - e);

    return 0;
}