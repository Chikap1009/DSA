#include <bits/stdc++.h>
using namespace std;

int hoursTaken(vector<int>& piles, int k)
{
    int total = 0;

    for (auto x : piles)
    {
        total += ceil((double)x/k);
    }

    return total;
}

int maxElement(vector<int>& piles)
{
    int maxi = 0;
    for (auto x : piles)
    {
        maxi = max(maxi, x);
    }
    return maxi;
}

int eatingSpeed(vector<int>& piles, int h)
{
    int low = 1;
    int high = maxElement(piles);

    while (low <= high)
    {
        int mid = (low + high)/2;

        if (hoursTaken(piles, mid) <= h)
        {
            high = mid-1;
        }
        else
        {
            low = mid+1;
        }
    }
    
    return low;
}

int main()
{
    vector<int> piles = {3,4,7,11};

    cout << eatingSpeed(piles, 8) << endl;

    return 0;
}