#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    // Declaration of variables
    int i, j, k, n, maxiter;
    float A[10][10], x[10], sum, e, big_e, error, temp;

    // Getting the Matrix
    // Getting the order of the matrix
    cout << "Enter the Order of Matrix : ";
    cin >> n;
    // Getting the elements of the matrix
    cout << "\nEnter the elements : " << endl;
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n + 1; j++)
        {
            cout << "A[" << i << "][" << j << "] : ";
            cin >> A[i][j];
        }
    }

    // Getting the max iteration and error
    cout << "\nEnter the maximum iteration : ";
    cin >> maxiter;
    // cout << "\nEnter the error (e) : ";
    // cin >> e;

    // Initialising the value of x1,x2,x3,...,xn;
    for (int i = 1; i <= n; i++)
        x[i] = 0;

    // Algorithm for JACOBI ITERATION METHOD
    for (k = 1; k <= maxiter; k++)
    {
        big_e = 0;
        for (i = 1; i <= n; i++)
        {
            // Initialising sum to 0
            sum = 0.0;
            for (j = 1; j <= n; j++)
            {
                // Calculating the { aixi + (ai+1)x(i+1) }
                if (i != j)
                    sum += A[i][j] * x[j];
            }
            // Calculating the x array { xi = (an - sum) / ai }
            temp = (A[i][n + 1] - sum) / A[i][i];

            // Updating the x column
            x[i] = temp;

            error = abs((temp - x[i]) / temp);
            // cout << "Error : (" << temp << " - " << x[i] << ") / " << temp << " = " << error;
            if (error > big_e)
                big_e = error;
        }

        // Printing the value as x
        // cout << "\n\nThe values in " << k << " iteration is -" << endl;
        // for (j = 1; j <= n; j++)
        // {
        //     cout << "x[" << j << "] : " << x[j] << endl;
        // }

        if (big_e <= e)
        {
            cout << "\nSolution is convergent, it converges in " << k;
            for (i = 1; i <= n; i++)
                cout << "\nx[" << i << "] = " << x[i];
        }
    }

    cout << "\nSolution doesn't converges in " << maxiter << " iterations";

    return 0;
}