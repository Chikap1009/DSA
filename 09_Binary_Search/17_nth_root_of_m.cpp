#include <bits/stdc++.h>
using namespace std;

int power(int n, int m, int mid)
{
    long long ans = 1;

    for (long long i=0 ; i<n ; i++)
    {
        ans *= mid;
        if (ans > m)
        {
            return 2;
        }
    }

    if (ans == m)
    {
        return 1;
    }

    return 0;
}

int nthRoot(int n, int m)
{
    long long low = 1;
    long long high = m;

    while (low <= high)
    {
        long long mid = (low + high)/2;

        if (power(n, m, mid) == 1) return mid;

        if (power(n, m, mid) == 2)
        {
            high = mid - 1;
        }
        else if (power(n, m, mid) == 0)
        {
            low = mid + 1;
        }
    }

    return -1;
}

int main()
{
    cout << nthRoot(3,27) << endl;

    return 0;
}