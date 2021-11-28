#include <iostream>
using namespace std;

int FX(int x)
{
    return (x * x * x) - (3 * x * x) + (5 * x) + 7;
}

int main()
{
    // Declaration of variables
    int i, j, limit;
    float X[20], fx[20], DD[15][10];

    // Getting the no of args
    cout << "Enter the no of arguments or limit : ";
    cin >> limit;

    // Getting the args values
    cout << "Enter the argumets i.e. values of X - \n";
    for (i = 0; i < limit; i++)
    {
        cout << "X[" << i << "] = ";
        cin >> X[i];
    }

    // Calculating the fx column
    int condition;
    cout << "Enter 1 if you want to enter the f(x) column manually !!!\n";
    cin >> condition;
    if (condition == 1)
        for (i = 0; i < limit; i++)
        {
            cout << "fx[" << i << "] = ";
            cin >> fx[i];
        }
    else
        for (i = 0; i < limit; i++)
            fx[i] = FX(X[i]);

    // Calculation of first Divided Difference
    for (i = 0; i < limit; i++)
    {
        DD[0][i] = (fx[i + 1] - fx[i]) / (X[i + 1] - X[i]);
    }

    // Calculation of next Divided Difference terms
    for (i = 1; i < limit - 1; i++)
        for (j = 0; j < limit - 1; j++)
            DD[i][j] = (DD[i - 1][j + 1] - DD[i - 1][j]) / (X[i + j + 1] - X[j]);

    // Printing the Divided Difference value
    cout << endl;
    for (i = 0; i < limit - 1; i++)
    {
        cout << "\nDD-" << i + 1 << " :";
        for (j = 0; j < limit - 1 - i; j++)
            cout << " " << DD[i][j];
    }
    return 0;
}