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
    float X[20], fx[20], FD[20][20];

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
            fx[i] = FX(X[i]);
    }

    // Calculating the first forward difference
    for (j = 0; j < limit - 1; j++)
        FD[0][j] = fx[j + 1] - fx[j];

    // Calculating the next forward differences
    for (i = 1; i < limit - 1; i++)
    {
        for (j = 0; j < limit - 1 - i; j++)
            FD[i][j] = FD[i - 1][j + 1] - FD[i - 1][j];
    }

    // Printing the x and f(x)
    cout << "\nX =";
    for (i = 0; i < limit; i++)
        cout << " " << X[i];
    cout << "\nf(x) =";
    for (i = 0; i < limit; i++)
        cout << " " << fx[i];

    // Printing the forward differences value
    cout << endl;
    for (i = 0; i < limit - 1; i++)
    {
        cout << "\nDel-" << i + 1 << " :";
        for (j = 0; j < limit - 1 - i; j++)
            cout << " " << FD[i][j];
    }

    return 0;
}