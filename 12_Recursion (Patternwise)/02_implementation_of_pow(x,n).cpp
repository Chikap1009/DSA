#include <bits/stdc++.h>
using namespace std;

double calcPow(double x, long long n)
{
    if (n==0) return 1;

    if (n<0) return 1/calcPow(x,-1*n);

    if (n%2 == 0)
    {
        return calcPow(x*x, n/2);
    }
    else
    {
        return x * calcPow(x*x, n/2);
    }
}

double myPow(double x, int n) {
    return calcPow(x,n);
}

// double myPow(double x, int n) {
//     double ans = 1;
//     long long num = n;
//     if (num < 0) num = (-1)*num;
//     while(num)
//     {
//         if (num%2 != 0) ans*=x;
//         x*=x;
//         num/=2;
//     }
//     if (n>=0) return ans;
//     return 1/ans;
// }

int main()
{
    cout << myPow(2.000,10) << endl;

    return 0;
}