#include <bits/stdc++.h>
using namespace std;

int numSubarraysWithLessThanEqualToSum(vector<int>& nums, int goal) {
    if (goal < 0) return 0;
    int l=0, r=0, sum=0, count=0;

    while(r<nums.size()) {
        sum += nums[r];
        while(l<=r && sum==goal+1) {
            sum -= nums[l];
            l++;
        }
        count += (r-l+1);
        r++;
    }
    return count;
}

int numSubarraysWithSum(vector<int>& nums, int goal) {
    return numSubarraysWithLessThanEqualToSum(nums, goal) - numSubarraysWithLessThanEqualToSum(nums, goal-1);
}

int main() {
    vector<int> nums = {1,0,1,0,1};

    cout << numSubarraysWithSum(nums, 2) << endl;

    return 0;
}