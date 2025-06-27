#include <bits/stdc++.h>
using namespace std;

int countSetBits(int num)
{
    num++;
    int powerOf2 = 1;
    int ans = 0;
    while(num > powerOf2)
    {
        int sets = num / powerOf2;

        int setBitSets = sets/2;

        ans += setBitSets*powerOf2;

        int rem = num % powerOf2;
        
        if (sets%2 != 0) ans+=rem;

        powerOf2 *= 2;
    }
    return ans;
}

int main()
{
    cout << countTotalSetBits(14) << endl;

    return 0;
}