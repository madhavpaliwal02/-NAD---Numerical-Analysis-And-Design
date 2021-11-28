#include <iostream>
using namespace std;

bool checking_exp_range(int e)
{
    if (e < -99)
    {
        cout << "\nUnderflow !!!";
        return false;
    }
    else if (e > 99)
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
    int e1, e2, e, ee = 0; // ee is declared to keep tracking on e

    // Getting values of variables from user
    cout << "Enter the value of x1 and x2 :";
    cin >> x1 >> x2;
    cout << "\nEnter the value of e1 and e2 :";
    cin >> e1 >> e2;

    // Addition of FPNs
    if (e1 == e2) // CHecking condition that the exponents are equal or not , if yes then
    {
        x = x1 - x2; // Substracting mantissa part of FPN
        e = e1;

        if (x >= 1)
        {
            while (x >= 1)
            {
                x /= 10;
                ee++;
            }
        }
        if (x <= -1)
        {
            while (x < -1)
            {
                x *= 10;
                ee++;
            }
        }

        /*if (x < 0) // CHecking whether the mantissa is not preceeded upto 1
        {
            // Normalising the mantissa part
            while (x < 0)
            {
                x = x * 10; // Multiplying, untill we get the value greater than 1
                ee++;
            }
            e -= ee;                            // Updating the exponent value
            if (checking_exp_range(e) == false) // Checking range of exponent
            {
                return 0; // If preceeds the range, then main function termintes
            }
        }*/
        // cout << "\nThe Difference is :- \nMantissa : " << x << "\nExponent : " << e;
    }
    else
    {
        while (e1 > e2) // Incrementing the exponent until, they becomes equal
        {
            x2 /= 10;
            e2++;
        }
        while (e1 < e2) // Incrementing the exponent until, they becomes equal
        {
            x1 /= 10;
            e1++;
        }
        if (e1 == e2)
        {
            x = x1 - x2;
            e = e1;
        }
    }
    cout << "\nThe Difference is :- \nMantissa : " << x << "\nExponent : " << e;
    return 0;
}