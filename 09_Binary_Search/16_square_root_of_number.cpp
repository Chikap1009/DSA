#include <bits/stdc++.h>
using namespace std;

int squareRoot(int n)
{
    int low = 1;
    int high = n;

    while (low <= high)
    {
        int mid = (low + high)/2;

        if (mid*mid <= n)
        {
            low = mid+1;
        }
        else
        {
            high = mid-1;
        }
    }

    return high;
}

int main()
{
    cout << squareRoot(77) << endl;

    return 0;
}