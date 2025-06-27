#include <bits/stdc++.h>
using namespace std;

int removingLastSetBit(int num)
{
    return (num&(num-1));
}

int main()
{
    cout << removingLastSetBit(13) << endl;

    return 0;
}