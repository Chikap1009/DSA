#include <bits/stdc++.h>
using namespace std;

// For multiple queries

// vector<int> getSieve(int n)
// {
//     vector<int> prime(n+1,1);

//     for (long long i=2 ; i*i<=n; i++)
//     {
//         if (prime[i] == 1)
//         {
//             for (long long j=i*i ; j<=n ; j+=i)
//             {
//                 prime[j] = 0;
//             }
//         }
//     }
//     return prime;
// }

// int countPrimes(int l, int r)
// {
//     vector<int> primes = getSieve(1e6);
//     int count = 0;

//     for (int i=2 ; i<=1e6 ; i++)
//     {
//         count += primes[i];
//         primes[i] = count;
//     }

//     return (primes[r] - primes[l-1]);
// }

// For single query
int countPrimes(int l, int r)
{
    vector<int> primes(1e6+1,1);
    int count = 0;

    for (int i=2 ; i<=r ; i++)
    {
        count += primes[i];

        if (primes[i] == 1)
        {
            for (int j=i*i ; j<=1e6 ; j+=i)
            {
                primes[j] = 0;
            }
        }

        primes[i] = count;
    }

    return (primes[r] - primes[l-1]);
}

int main()
{
    cout << countPrimes(3,10) << endl;

    return 0;
}