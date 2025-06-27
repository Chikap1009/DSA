#include <bits/stdc++.h>
using namespace std;

bool removingLastSetBit(int num)
{
    return ((num&(num-1)) == 0);
}

int main()
{
    cout << removingLastSetBit(16) << endl;

    return 0;
}