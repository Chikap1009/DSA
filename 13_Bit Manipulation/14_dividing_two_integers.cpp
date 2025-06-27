#include <bits/stdc++.h>
using namespace std;

int divide(int dividend, int divisor) {
    if (dividend == INT_MIN && divisor == -1) return INT_MAX;
    long long ans = 0;
    int sign = 1;
    if ((dividend<0 && divisor>0) || (dividend>0 && divisor<0)) sign = -1;
    long long num = abs((long long)dividend);
    long long den = abs((long long)divisor);
    while(num >= den)
    {
        long long n = 0;
        while((den<<(n+1)) <= num)
        {
            n++;
        }
        if (n==31) ans += num;
        else ans += (1<<n);
        num -= (den<<n);
    }
    if (sign == -1) ans = -ans;
    if (ans >= INT_MAX) return INT_MAX;
    if (ans <= INT_MIN) return INT_MIN;
    return ans;
}

int main()
{
    cout << divide(22,3) << endl;

    return 0;
}