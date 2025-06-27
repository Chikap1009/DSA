#include <bits/stdc++.h>
using namespace std;

vector<int> primeFactorisation1(int n)
{
    vector<int> ans;
    for (int i=2 ; i*i <= n ; i++)
    {
        while(n%i == 0)
        {
            ans.push_back(i);
            n/=i;
        }
    }
    if (n>1) ans.push_back(n);
    return ans;
}

vector<int> primeFactorisation2(int n)
{
    vector<int> ans;
    vector<int> prime(n+1,1);
    for (long long i=2 ; i <= n ; i++)
    {
        if (prime[i] == 1)
        {
            int temp = n;
            while(temp%i == 0)
            {
                ans.push_back(i);
                temp/=i;
            }

            for (long long j=i*i ; j<=n ; j+=i)
            {
                prime[j] = 0;
            }
        }
    }
    return ans;
}

vector<int> primeFactorisation3(int n)
{
    vector<int> ans;
    vector<int> spf(1e5+1);
    for (int i=0 ; i<=1e5 ; i++)
    {
        spf[i] = i;
    }

    for (long long i=2 ; i<=1e5 ; i++)
    {
        if (spf[i] == i)
        {
            for (long long j =i*i ; j<=1e5 ; j+=i)
            {
                if (spf[j] == j) spf[j] = i;
            }
        }
    }

    while(n > 1)
    {
        ans.push_back(spf[n]);
        n /= spf[n];
    }

    return ans;
}

void print(vector<int> v)
{
    for (auto x : v)
    {
        cout << x << " ";
    }
    cout << endl;
}

int main()
{
    vector<int> pf1 = primeFactorisation1(780);
    vector<int> pf2 = primeFactorisation2(780);
    vector<int> pf3 = primeFactorisation3(780);

    print(pf1);
    print(pf2);
    print(pf3);

    return 0;
}