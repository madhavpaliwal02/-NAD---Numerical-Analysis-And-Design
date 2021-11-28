#include <iostream>
#include <math.h>
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

/*int main()
{
    // Declaration of variables
    float x1, x2, x;
    int e1, e2, e, ee = 0;

    // Getting values of variables from user
    cout << "Enter the value of x1 and x2 :";
    cin >> x1 >> x2;
    cout << "\nEnter the value of e1 and e2 :";
    cin >> e1 >> e2;

    // Addition of FPNs
    if (e1 == e2) // CHecking condition that the exponents are equal or not , if yes then
    {
        x = x1 + x2; // Adding mantissa part of FPN
        e = e1;
        if (x >= 10000) // CHecking whether the mantissa is not exceeded upto 10000
        {
            // Normalising the mantissa part
            while (x > 10000)
            {
                x /= 10; // Dividing, untill we get the value less than 10000
                ee++;
            }
            e = e + ee;                         // Updating the exponent value
            if (checking_exp_range(e) == false) // Checking range of exponent
            {
                return 0; // If exceeds the renge, then main function termintes
            }
        }
        cout << "\nThe Sum is :- \nMantissa : " << x << "\nExponent : " << e;
    }
    else
    {
        if (e1 > e2 && e1 < 100) // Comparing the exponents
        {
            while (e2 < e1) // Incrementing the exponent until, they becomes equal
            {
                x2 /= 10;
                e2++;
            }
            x = x1 + x2;
            e = e1;
        }
        if (e1 < e2 && e2 < 100) // Comparing the exponents
        {
            while (e2 > e1) // Incrementing the exponent until, they becomes equal
            {
                x1 /= 10;
                e1++;
            }
            e = e1;
            x = x1 + x2;
        }
        cout << "\nThe Sum is :- \nMantissa : " << x << "\nExponent : " << e;
    }
    return 0;
}*/

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

    // Getting the difference of exponent terms
    e = abs(e1 - e2);

    // 
    if (e1 > e2)
    {
        x2 /= pow(10, e);
        e = e1;
    }
    else
    {
        x1 /= pow(10, e);
        e = e2;
    }

    x = x1 + x2;
    if (x >= 1.0)
    {
        while (x > 1)
        {
            x /= 10;
            e++;
        }
    }

    if (e > 99)
    {
        cout << "\nOverflow !!!";
    }
    else
    {
        cout << "\nThe Sum is :- \nMantissa : " << x << "\nExponent : " << e;
    }
}