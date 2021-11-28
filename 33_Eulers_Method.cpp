
#include <iostream>
using namespace std;

float f(float x, float y)
{
    return (x + y);
    // return (x + y + x * y);
}

int main()
{
    int i, n;
    float X[10], Y[10], h, xf;

    cout << "\nEnter the x0 : ";
    cin >> X[0];
    cout << "\nEnter the y0 : ";
    cin >> Y[0];
    // cout << "\nEnter the xn : ";
    // cin >> X[n];
    cout << "\nEnter the finding value : ";
    cin >> xf;
    cout << "\nEnter the limit : ";
    cin >> n;

    h = (xf - X[0]) / n;

    for (i = 1; i <= n; i++)
    {
        X[i] = X[i - 1] + h;
        cout << "\nX[" << i << "] = " << X[i];
    }

    for (i = 0; i < n; i++)
    {
        Y[i + 1] = Y[i] + h * f(X[i], Y[i]);
        cout << "\n"
             << Y[i + 1] << " = " << Y[i] << " + " << h << " * " << f(X[i], Y[i]);
    }

    cout << "\nThe result is : " << Y[n];

    return 0;
}