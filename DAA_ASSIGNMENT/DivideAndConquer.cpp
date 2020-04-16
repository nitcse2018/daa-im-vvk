// Author: Vivek Kumar
// Roll no.: 181210060
// Branch: CSE 2nd Year(Group2)
// Topic: Divide and Concquer

/*
Given a function f(x) on floating number x and two numbers ‘a’ and ‘b’ such that
f(a)*f(b) < 0 and f(x) is continuous in [a, b]. Here f(x) represents algebraic 
or transcendental equation. Find root of function in interval [a, b] (Or find a value of x such that f(x) is 0).
*/

#include <bits/stdc++.h>
using namespace std;
#define EPSILON 0.01

// An example function whose solution is determined using
// Bisection Method. The function is x^2 + x - 6
double func(double x)
{
    return x * x + x - 6;
}

void bisection(double a, double b)
{
    if (func(a) * func(b) >= 0)
    {
        cout << "You have not provided right a and b\n";
        return;
    }

    double c = a;
    while ((b - a) >= EPSILON)
    {
        c = (a + b) / 2;

        if (func(c) == 0.0)
            break;

        else if (func(c) * func(a) < 0)
            b = c;
        else
            a = c;
    }
    cout << "The value of root is : " << c;
}

int main()
{
    // Initial values assumed
    double a = 0, b = 10;
    bisection(a, b);
    return 0;
}