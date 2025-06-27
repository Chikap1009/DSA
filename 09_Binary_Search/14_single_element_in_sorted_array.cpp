#include <bits/stdc++.h>
using namespace std;

int singleNonDuplicate(vector<int>& nums)
{
    int n = nums.size();

    if (n==1) return nums[0];
    if (nums[0] != nums[1]) return nums[0];
    if (nums[n-1] != nums[n-2]) return nums[n-1];

    int low = 1;
    int high = n-2;

    while (low <= high)
    {
        int mid = (low + high)/2;

        if (nums[mid] != nums[mid-1] && nums[mid] != nums[mid+1]) return nums[mid];

        if (mid % 2 == 1)
        {
            if (nums[mid] == nums[mid-1])
            {
                low = mid+1;
            }
            else if (nums[mid] == nums[mid+1])
            {
                high = mid-1;
            }
        }
        else
        {
            if (nums[mid] == nums[mid+1])
            {
                low = mid+1;
            }
            else if (nums[mid] == nums[mid-1])
            {
                high = mid-1;
            }
        }
    }
    return -1;
}

int main()
{
    vector<int> v = {1,1,2,2,3,3,4,5,5,6,6,7,7,8,8,9,9,10,10};

    cout << singleNonDuplicate(v) << endl;

    return 0;
}