#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    // Declaration of variables
    int i, j, k, n, maxiter;
    float A[10][10], E, oldx[10], newx[10], sum, big_e;

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
    // cout << "\nEnter the error (E) : ";
    // cin >> E;

    // Initialising the value of x1,x2,x3,...,xn;
    for (int i = 1; i <= n; i++)
        oldx[i] = 0;

    // Algorithm for JACOBI ITERATION METHOD
    for (k = 1; k <= maxiter; k++)
    {
        // big_e = 0;
        for (i = 1; i <= n; i++)
        {
            // Initialising sum to 0
            sum = 0.0;
            for (j = 1; j <= n; j++)
            {   
                // Calculating the { aixi + (ai+1)x(i+1) }
                if (i != j)
                    sum += A[i][j] * oldx[j];   
            }
            // Calculating the newx array { xi = (an - sum) / ai }
            newx[i] = (A[i][n + 1] - sum) / A[i][i];
        }

        // Printing the value as newx
        cout << "\n\nThe values in " << k << " iteration is -" << endl;
        for (j = 1; j <= n; j++)
        {
            cout << "x[" << j << "] : " << newx[j] << endl;
            // Updating the oldx column
            oldx[j] = newx[j];
        }

        // E = abs((newx[1] - oldx[1]) / newx[i]);
        // if (E > big_e)
        //     big_e = E;
    }

    // if (big_e <= E)
    // {
    //     cout << "\nSolution is convergent, it converges in " << k;
    //     for (i = 1; i <= n; i++)
    //         cout << "\noldX[" << i << "] = " << oldx[i]
    //              << "\tnewx[" << i << "] = " << newx[i];
    // }

    return 0;
}