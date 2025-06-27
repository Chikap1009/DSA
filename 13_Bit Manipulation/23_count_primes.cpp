#include <bits/stdc++.h>
using namespace std;

int countPrimes(int n) {
    int count = 0;
    vector<int> prime(n,1);
    for (long long i=2 ; i<n ; i++)
    {
        if (prime[i] == 1)
        {
            count++;
            for (long long j=i*i ; j<n ; j+=i)
            {
                prime[j] = 0;
            }
        }
    }
    return count;
}

int main()
{
    cout << countPrimes(30) << endl;

    return 0;
}