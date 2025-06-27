#include <bits/stdc++.h>
using namespace std;

// USING LEFT SHIFT

// bit indexing starts from 0
bool checkithbit1(int num, int i)
{
    if ((num&(1<<i)) != 0) return true;
    return false;
}

// bit indexing starts from 1
bool checkithbit2(int num, int i)
{
    if ((num&(1<<(i-1))) != 0) return true;
    return false;
}

// USING RIGHT SHIFT

// bit indexing starts from 0
bool checkithbit3(int num, int i)
{
    if ((1&(num>>i)) == 1) return true;
    return false;
}

// bit indexing starts from 1
bool checkithbit4(int num, int i)
{
    if ((1&(num>>(i-1))) == 1) return true;
    return false;
}

int main()
{
    cout << checkithbit1(13,2) << endl;
    cout << checkithbit2(13,2) << endl;

    cout << checkithbit3(13,2) << endl;
    cout << checkithbit4(13,2) << endl;

    return 0;
}