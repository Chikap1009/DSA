#include <bits/stdc++.h>
using namespace std;

int settingLastUnsetBit(int num)
{
    return (num|(num+1));
}

int main()
{
    cout << settingLastUnsetBit(12) << endl;

    return 0;
}