#include <bits/stdc++.h>
using namespace std;

int countSubarrays(vector<int>& nums, int k) {
    int l=0, r=0, count=0, ans=0;
    while(r<nums.size()){
        if (nums[r]%2 != 0) count++;
        while (l<=r && count==k+1) {
            if (nums[l]%2 != 0) count--;
            l++;
        }
        ans += (r-l+1);
        r++;
    }
    return ans;
}

int numberOfSubarrays(vector<int>& nums, int k) {
    return countSubarrays(nums,k) - countSubarrays(nums,k-1);
}

int main() {
    vector<int> nums = {1,1,2,1,1};

    cout << numberOfSubarrays(nums, 3) << endl;

    return 0;
}