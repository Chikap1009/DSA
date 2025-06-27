#include <bits/stdc++.h>
using namespace std;

// bit indexing starts from 0
int clearingithbit1(int num, int i)
{
    return (num&(~(1<<i)));
}

// bit indexing starts from 1
int clearingithbit2(int num, int i)
{
    return (num&(~(1<<(i-1))));
}

int main()
{
    cout << clearingithbit1(13,2) << endl;
    cout << clearingithbit2(13,3) << endl;

    return 0;
}