#include <bits/stdc++.h>
using namespace std;

long long getPow(long long x, long long n)
{
    int mod = 1e9 + 7;
    if (n==0) return 1;

    if (n%2 == 0)
    {
        return (getPow((x*x)%mod, n/2)%mod);
    }
    else
    {
        return ((x%mod) * getPow((x*x)%mod, n/2)%mod);
    }
}

int countGoodNumbers(long long n) {
    int num = pow(10,9)+7;
    if (n%2 == 0)
    {
        long long ans = getPow(20,n/2);
        return ans % num;
    }
    else
    {
        long long ans = 5 * getPow(20,n/2);
        return ans % num;
    }
}

int main()
{
    cout << countGoodNumbers(1) << endl;
    cout << countGoodNumbers(4) << endl;
    cout << countGoodNumbers(1000) << endl;
}