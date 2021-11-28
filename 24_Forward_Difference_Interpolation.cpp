#include <iostream>
using namespace std;

int FX(int x)
{
    // return (x * x) - x - 1;
    return ((x * x * x) - (3 * x * x) + (5 * x) + 7);
}
int fact(int x)
{
    if (x >= 1)
        return x * fact(x - 1);
    else
        return 1;
}

int main()
{
    int i, j, limit;
    int X[20], fx[20], FD[20][15];

    // Getting the no of args
    cout << "Enter the number of arguments or limit : ";
    cin >> limit;

    // Getting the args values
    cout << "\nEnter the arguments, i.e. x !\n";
    for (i = 0; i < limit; i++)
    {
        cout << "X[" << i << "] = ";
        cin >> X[i];
    }

    // Checking that whether the function is available or not
    int condition;
    cout << "\nEnter 1, If you want to enter the f(x) column manually !!!\n";
    cin >> condition;
    if (condition == 1)
        for (i = 0; i < limit; i++)
        {
            cout << "fx[" << i << "] = ";
            cin >> fx[i];
        }
    else
    {
        // Calculating the fx column
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

    // Calculation of Forward interpolation formula components
    // 1. f(a) = fx     2. u & Fu
    // 3. FD            4. factorial

    int find[2], iter, iter2 = 1;
    float h, sum[2], Fu[20][2], diff;

    // Getting the finding value
    cout << "\n\nEnter"
         << "\n1. for finding a single value"
         << "\n2. For finding the difference between them\n";
    cin >> iter;

    // Calculating the h (diff X[1]-X[0])
    h = X[1] - X[0];

    while (iter2 != 0)
    {
        for (i = 0; i < iter; i++)
        {
            // Getting the finding value
            cout << "\nEnter the " << i + 1 << " finding value : ";
            cin >> find[i];

            // We know finding value = a + (u * h), then u is
            Fu[0][i] = (find[i] - X[0]) / h;

            // Calculation of Fu[]
            for (j = 1; j <= limit - 1; j++)
                Fu[j][i] = Fu[j - 1][i] * (Fu[0][i] - j);

            // Now we are applying newton's formula NFDIF
            sum[i] = fx[0];
            cout << "\nSum : " << sum[i] << endl
                 << "(Fu[] * FD[][]) / fact() = Sum \n";
            for (j = 0; j < limit - 1; j++)
            {
                sum[i] += (Fu[j][i] * FD[j][0]) / fact(j + 1);
                cout << Fu[j][i] << "\t" << FD[j][0] << "\t" << fact(j + 1) << "\t" << sum[i] << endl;
            }

            // Printing the final result
            cout << "\nThe final result is : " << sum[i];
        }

        // Calculating the difference between the two sums
        if (sum[1] != 0)
        {
            diff = sum[1] - sum[0];
            cout << "\n\nThe difference is : " << abs(diff);
        }

        // Restart to find another value
        cout << "\n\nPress 1 to find another value"
             << "\nPress 0 to exit"
             << "\nEnter your choice : ";
        cin >> iter2;
        sum[0] = sum[1] = diff = 0;
    }

    return 0;
}