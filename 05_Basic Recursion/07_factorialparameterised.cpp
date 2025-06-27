#include <bits/stdc++.h>
using namespace std;

int factorial(int n, int fact = 1)
{
    if (n<1) return fact;
    return factorial(n-1, fact*n);
}

int main()
{
    cout << factorial(5) << endl;

    return 0;
}