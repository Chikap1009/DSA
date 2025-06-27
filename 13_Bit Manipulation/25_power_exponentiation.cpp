#include <bits/stdc++.h>
using namespace std;

double myPow(double x, int n) {
    double ans = 1;
    long long num = n;
    if (num < 0) num = (-1)*num;
    while(num > 0)
    {
        if (num%2 != 0) ans*=x;
        x*=x;
        num/=2;
    }
    if (n>=0) return ans;
    return 1.0/ans;
}

int main()
{
    cout << myPow(2.7, 8) << endl;

    return 0;
}