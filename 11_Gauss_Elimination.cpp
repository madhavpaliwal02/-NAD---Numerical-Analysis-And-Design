#include <iostream>
using namespace std;

int main()
{
    int i, j, k, n;
    float A[10][10], X[10], sum = 0.0, c;
    cout << "Enter the Order of Matrix : ";
    cin >> n;

    cout << "\nEnter the elements : " << endl;
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n + 1; j++)
        {
            cout << "A[" << i << "][" << j << "] : ";
            cin >> A[i][j];
        }
    }

    for (j = 1; j <= n; j++)
    {
        for (i = 1; i <= n; i++)
        {
            if (i > j)
            {
                c = A[i][j] / A[j][j];
                for (k = 1; k <= n + 1; k++)
                {
                    A[i][k] = A[i][k] - c * A[j][k];
                }
            }
        }
    }

    X[n] = A[n][n + 1] / A[n][n];

    for (i = n - 1; i >= 1; i--)
    {
        sum = 0;
        for (j = i + 1; j <= n; j++)
        {
            sum = sum + (A[i][j] * X[j]);
        }
        X[i] = (A[i][n + 1] - sum) / A[i][i];
    }

    cout << "The solution is : ";
    for (i = 1; i <= n; i++)
    {
        cout << "\nx" << i << " = " << X[i];
    }

    return 0;
}