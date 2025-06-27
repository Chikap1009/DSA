#include <bits/stdc++.h>
using namespace std;

vector<long long int> twoOddNum(long long int Arr[], long long int N)  
{
    long long xorNums = 0;
    
    for (long long i=0 ; i<N ; i++)
    {
        xorNums ^= Arr[i];
    }
    
    long long rightMost = (xorNums&(xorNums-1))^(xorNums);
    
    long long b1 = 0, b2 = 0;
    
    for (long long i=0 ; i<N ; i++)
    {
        if ((Arr[i]&rightMost) == 0) b1 ^= Arr[i];
        else b2 ^= Arr[i];
    }
    
    if (b1 > b2) return {b1, b2};
    return {b2, b1};
}

int main()
{
    long long int arr[] = {2,4,2,5,7,7,14,5,7,14};

    vector<long long int> ans = twoOddNum(arr, 10);

    cout << ans[0] << " " << ans[1] << endl;

    return 0;
}