#include <bits/stdc++.h>
using namespace std;

vector<int> sieveOfEratosthenes(int n) {
    vector<int> ans;
    vector<int> prime(n+1,1);
    for (long long i=2 ; i*i<=n ; i++)
    {
        if (prime[i] == 1)
        {
            for (long long j=i*i ; j<=n ; j+=i)
            {
                prime[j] = 0;
            }
        }
    }
    
    for (long long i=2 ; i<=n ; i++)
    {
        if (prime[i] == 1)
        {
            ans.push_back(i);
        }
    }

    return ans;
}

int main()
{
    vector<int> ans = sieveOfEratosthenes(30);

    for (auto x : ans)
    {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}