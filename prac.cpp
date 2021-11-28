#include <iostream>
using namespace std;

float FX(float x, float y)
{
    return (x * x - y * y) * (x + y);
}

int main()
{
    // Declaration of variables
    int i, j, limit;
    float X[20], fx[20], Y[20];

    // Getting the no of args
    cout << "Enter the no of arguments or limit : ";
    cin >> limit;

    // Getting the args values
    cout << "\nEnter the argumets i.e. values of X - \n";
    for (i = 0; i < limit; i++)
    {
        cout << "X[" << i << "] = ";
        cin >> X[i];
    }

    // Calculating the fx column
    int condition;
    cout << "\nEnter 1 if you want to enter the f(x) column manually !!!\n";
    cin >> condition;
    if (condition == 1)
    {
        for (i = 0; i < limit; i++)
        {
            cout << "fx[" << i << "] = ";
            cin >> fx[i];
        }
    }
    else
    {
        for (i = 0; i < limit; i++)
            fx[i] = FX(X[i], fx[i]);
    }

    // Picard's Succusive method

    // y(n+1) = y0 + f(x,yn);
    Y[0] = 0;
    for (i = 0; i < limit; i++)
    {
        Y[i + 1] = Y[0] + FX(X[i], Y[i]);
    }

    return 0;
}