#include <bits/stdc++.h>
using namespace std;

vector<long long> factorialNumbers(long long n) {
        // Write Your Code here
        vector<long long> v;
        long long i=1;
        long long fact=1;
        do
        {
            fact = fact*i;
            v.emplace_back(fact);
            i++;
        } while (fact*i <= n);
        return v;
    }

int main()
{
    for (auto x : factorialNumbers(121))
    {
        cout << x << " ";
    }

    return 0;
}