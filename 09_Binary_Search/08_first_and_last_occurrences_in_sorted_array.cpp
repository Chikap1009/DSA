#include <bits/stdc++.h>
using namespace std;

vector<int> searchRange1(vector<int>& nums, int target)
{
    int first = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
    if (nums.empty() || first == nums.size() || nums[first] != target) return {-1,-1};
    int last = upper_bound(nums.begin(), nums.end(), target) - nums.begin();
    return {first, last-1};
}

int firstOccurrence(vector<int>& nums, int target)
{
    int n = nums.size();

    int first = -1;

    int low = 0;
    int high = n-1;

    while (low<=high)
    {
        int mid = (low+high)/2;

        if (nums[mid] == target)
        {
            first = mid;
            high = mid-1;
        }
        else if (nums[mid] < target)
        {
            low = mid+1;
        }
        else
        {
            high = mid-1;
        }
    }
    
    return first;
}

int lastOccurrence(vector<int>& nums, int target)
{
    int n = nums.size();

    int last = -1;

    int low = 0;
    int high = n-1;

    while (low<=high)
    {
        int mid = (low+high)/2;

        if (nums[mid] == target)
        {
            last = mid;
            low = mid+1;
        }
        else if (nums[mid] < target)
        {
            low = mid+1;
        }
        else
        {
            high = mid-1;
        }
    }
    
    return last;
}

vector<int> searchRange2(vector<int>& nums, int target)
{
    int first = firstOccurrence(nums, target);
    if (first == -1) return {-1,-1};
    int last = lastOccurrence(nums, target);
    return {first, last};
}

int main()
{
    vector<int> v = {1,2,8,8,8,8,8,11,12,12};

    for (auto x : searchRange1(v,8))
    {
        cout << x << " ";
    }

    cout << endl;

    for (auto x : searchRange2(v,8))
    {
        cout << x << " ";
    }

    return 0;
}