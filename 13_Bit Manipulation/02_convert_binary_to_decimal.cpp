#include <bits/stdc++.h>
using namespace std;

int convert2Decimal(string num)
{
    int n=0;
    long long p = 1;
    for (int i=num.length()-1 ; i>=0 ; i--)
    {
        if (num[i] == '1') n+=p;
        p*=2;
    }
    return n;
}

int main()
{
    cout << convert2Decimal("10101110000011000111") << endl;

    return 0;
}