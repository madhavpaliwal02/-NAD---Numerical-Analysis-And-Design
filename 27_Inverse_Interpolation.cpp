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
    float X[20], fx[20], II[15][10];

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

    // Calculation of Inverse Interpolation Formula
    // 1. Num terms - (y-y1)(y-y2)(y-y3)...
    // 2. Denum terms - (y0-y1)(y0-y2)(y0-y3)...
    // 3. Finding value column - for calculation for num
    float num[20], denum[20], sum = 0, find;
    int iter = 1;

    while (iter != 0)
    {
        // Gettiing the finding value
        cout << "\n\nEnter the finding value : ";
        cin >> find;

        // Initailising the value of num and denominator
        for (i = 0; i < 20; i++)
        {
            num[i] = 1;
            denum[i] = 1;
        }

        for (i = 0; i < limit; i++)
        {
            for (j = 0; j < limit; j++)
            {
                if (i == j)
                    continue;
                num[i] *= find - fx[j];
                denum[i] *= fx[i] - fx[j];
            }
            sum += (num[i] * X[i]) / denum[i];
        }

        // Printing the final result
        cout << "\n\nThe result is : " << sum;

        // Restart to find another value
        cout << "\n\nPress 1 to find another value"
             << "\nPress 0 to exit"
             << "\nEnter your choice : ";
        cin >> iter;
        sum = 0;
    }

    return 0;
}