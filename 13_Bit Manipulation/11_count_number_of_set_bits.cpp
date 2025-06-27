#include <bits/stdc++.h>
using namespace std;

int countSetBits1(int num)
{
    int count = 0;

    while(num>1)
    {
        count += (num&1);
        num >>= 1; // num = num>>1;
    }

    return count+1;
}

int countSetBits2(int num)
{
    int count = 0;

    while(num>0)
    {
        num &= (num-1); // num = num&(num-1);
        count++;
    }

    return count;
}

int main()
{
    cout << countSetBits1(12) << endl;
    cout << countSetBits2(12) << endl;

    return 0;
}