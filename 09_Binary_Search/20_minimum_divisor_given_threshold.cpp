#include <bits/stdc++.h>
using namespace std;

bool checkPossible(vector<int>& nums, int threshold, int checkValue){
    int total = 0;
    for (auto x : nums)
    {
        total += ceil((double)x/checkValue);
    }
    if (total <= threshold) return true;
    return false;
}

int MaxElement(vector<int>& nums){
    int maxi = INT_MIN;

    for (int x : nums)
    {
        maxi = max(maxi, x);
    }
    return maxi;
}

int smallestDivisor(vector<int>& nums, int threshold) {
    int low = 1;
    int high = MaxElement(nums);

    while (low <= high)
    {
        int mid = (low + high)/2;

        if (checkPossible(nums, threshold, mid))
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
    vector<int> nums = {1,2,5,9};

    cout << smallestDivisor(nums, 6) << endl;

    return 0;
}