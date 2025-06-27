#include <bits/stdc++.h>
using namespace std;

// bit indexing starts from 0
int settingithbit1(int num, int i)
{
    return (num|(1<<i));
}

// bit indexing starts from 1
int settingithbit2(int num, int i)
{
    return (num|(1<<(i-1)));
}

int main()
{
    cout << settingithbit1(13,1) << endl;
    cout << settingithbit2(13,2) << endl;

    return 0;
}