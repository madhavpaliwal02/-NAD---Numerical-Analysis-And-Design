#include <iostream>
#include <math.h>
using namespace std;

float F(float x)
{
    // return 1 / (1 + (x * x));
    return (sqrt(x));
}

int main()
{
    // Declaration of variables
    int n, i;
    float X[20], fx[20], a, b, h, sum = 0.0, integral;

    // Getting the value of a and b
    cout << "Enter the value of a and b : ";
    cin >> a >> b;

    // Getting the no of iteration
    cout << "\nEnter the no of iterations : ";
    cin >> n;

    // Calculating the interval value
    h = (b - a) / n;
    cout << "\nh : " << h;

    // Calculating the X column
    X[0] = a;
    X[n] = b;
    for (i = 1; i < n; i++)
        X[i] = X[i - 1] + h;

    // Calculating the fx column
    for (i = 0; i <= n; i++)
        fx[i] = F(a + X[i]);

    // Printing the x and f(x)
    cout << endl;
    cout << "\nX =";
    for (i = 0; i <= n; i++)
        cout << "\t" << X[i];
    cout << "\nf(x) =";
    for (i = 0; i <= n; i++)
        cout << " " << fx[i];

    // Calculating the inner terms
    sum = fx[0] + fx[n];
    for (i = 1; i < n; i++)
        if (i % 3 == 0)
            sum += 2 * fx[i];
        else
            sum += 3 * fx[i];
    cout << "\nSum : " << sum;

    // Dividing by outer terms
    integral = (sum * 3 * h) / 8;

    // Printing the final answer
    cout << "\n\nInteegral : " << integral;

    return 0;
}