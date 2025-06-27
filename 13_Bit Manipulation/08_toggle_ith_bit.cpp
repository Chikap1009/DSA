#include <bits/stdc++.h>
using namespace std;

// bit indexing starts from 0
int togglingithbit1(int num, int i)
{
    return (num^(1<<i));
}

// bit indexing starts from 1
int togglingithbit2(int num, int i)
{
    return (num^(1<<(i-1)));
}

int main()
{
    cout << togglingithbit1(13,1) << endl;
    cout << togglingithbit2(13,2) << endl;

    return 0;
}