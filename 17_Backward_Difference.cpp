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
    float X[20], fx[20], BD[20][20];

    // Getting the no of args
    cout << "Enter the limit : ";
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

    // Calculating the first backward difference
    for (j = 1; j < limit; j++)
    {
        BD[0][j] = fx[j] - fx[j - 1];
        BD[0][j - 1] = BD[0][j];
    }

    // Calculating the next backward differences
    for (i = 0; i < limit - 2; i++)
        for (j = 1; j < limit - 1 - i; j++)
            BD[i + 1][j - 1] = BD[i][j] - BD[i][j - 1];

    // Printing the x and f(x)
    cout << "\nX =";
    for (i = 0; i < limit; i++)
        cout << " " << X[i];
    cout << "\nf(x) =";
    for (i = 0; i < limit; i++)
        cout << " " << fx[i];

    // Printing the backward difference values
    cout << endl;
    for (i = 0; i < limit - 1; i++)
    {
        cout << "\nNabla-" << i + 1 << " :";
        for (j = 0; j < limit - 1 - i; j++)
            cout << " " << BD[i][j];
    }

    return 0;
}