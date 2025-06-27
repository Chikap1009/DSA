#include <bits/stdc++.h>
using namespace std;

bool isPrime(int n)
{
    if (n==1) return false;
    for (int i=2 ; i<=sqrt(n) ; i++)
    {
        if (n%i == 0) return false;
    }
    return true;
}

vector<int> findPrimeFactors1(int n)
{
    vector<int> pf;
    for (int i=2 ; i<=n ; i++)
    {
        if (n%i == 0)
        {
            if (isPrime(i)) pf.push_back(i);
        }
    }
    return pf;
}

vector<int> findPrimeFactors2(int n)
{
    vector<int> pf;
    for (int i=2 ; i<=sqrt(n) ; i++)
    {
        if (n%i == 0)
        {
            if (isPrime(i)) pf.push_back(i);
            if (i != n/i)
            {
                if (isPrime(n/i)) pf.push_back(n/i);
            }
        }
    }
    return pf;
}

vector<int> findPrimeFactors3(int n)
{
    vector<int> pf;
    for (int i=2 ; i<=n ; i++)
    {
        if (n%i == 0)
        {
            pf.push_back(i);
            while(n%i == 0)
            {
                n /= i;
            }
        }
    }
    return pf;
}

vector<int> findPrimeFactors4(int n)
{
    vector<int> pf;
    for (int i=2 ; i<=sqrt(n) ; i++)
    {
        if (n%i == 0)
        {
            pf.push_back(i);
            while(n%i == 0)
            {
                n/=i;
            }
        }
    }
    if (n!=1) pf.push_back(n);
    return pf;
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
    vector<int> ans1 = findPrimeFactors3(780);
    vector<int> ans2 = findPrimeFactors3(780);
    vector<int> ans3 = findPrimeFactors3(780);
    vector<int> ans4 = findPrimeFactors3(780);

    print(ans1);
    print(ans2);
    print(ans3);
    print(ans4);

    return 0;
}