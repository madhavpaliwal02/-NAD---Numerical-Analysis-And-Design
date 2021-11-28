#include <iostream>
using namespace std;

bool checking_exp_range(int e)
{
    if (e > 99)
    {
        cout << "\nOverflow !!!";
        return false;
    }
    else
    {
        return true;
    }
}

int main()
{
    // Declaration of variables
    float x1, x2, x;
    int e1, e2, e, ee = 0;

    // Getting values of variables from user
    cout << "Enter the value of x1 and x2 :";
    cin >> x1 >> x2;
    cout << "\nEnter the value of e1 and e2 :";
    cin >> e1 >> e2;

    e = e1 + e2;
    x = x1 * x2;

    // Checking high range of mantissa
    if (x > 1.0)
    {
        while (x > 1.0)
        {
            x /= 10; //Dividing, untill we get the value less than 10000
            e++;
        }
        // e = e + ee;
    }

    // Checking low range of mantissa
    if (x < 0.1)
    {
        while (x < 0.1)
        {
            x *= 10; //Dividing, untill we get the value less than 10000
            e--;
        }
        // e = e - ee;
    }

    // Checking range of exponent
    if (e > 99)
    {
        cout << "Overflow !!!";
    }
    else
    {
        cout << "\nThe Multiplication is :- \nMantissa : " << x << "\nExponent : " << e;
        cout << "\nThe term is : " << x << " x "
             << " 10^" << e;
    }
    return 0;
}