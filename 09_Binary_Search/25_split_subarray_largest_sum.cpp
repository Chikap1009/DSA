#include <bits/stdc++.h>
using namespace std;

bool canWeSplit(vector<int>& nums, int k, int limit)
{
    int noOfSubarrays = 0;
    int sum = 0;
    for (int i=0 ; i<nums.size() ; i++)
    {
        sum += nums[i];
        if (sum > limit)
        {
            noOfSubarrays++;
            sum = nums[i];
        }
        else if (sum == limit)
        {
            noOfSubarrays++;
            sum = 0;
        }
    }
    if (sum != 0) noOfSubarrays++;
    if (noOfSubarrays > k)  return false;
    return true;
}

int splitArray(vector<int>& nums, int k) {
    if (nums.size() < k) return -1;

    int low = *max_element(nums.begin(), nums.end());
    int high = accumulate(nums.begin(), nums.end(), 0);

    while (low <= high)
    {
        int mid = (low + high)/2;
        if (canWeSplit(nums, k, mid))
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
    vector<int> v = {7,2,5,10,8};

    cout << splitArray(v, 2) << endl;

    return 0;
}