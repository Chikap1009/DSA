#include <bits/stdc++.h>
using namespace std;

int subarraysWithMaxKDistinct(vector<int>& nums, int k) {
    if (k==0) return 0;
    int l=0, r=0, ans=0;
    unordered_map<int,int> mp;

    while(r<nums.size()) {
        mp[nums[r]]++;
        while(l<=r && mp.size()>k) {
            mp[nums[l]]--;
            if (mp[nums[l]] == 0) mp.erase(nums[l]);
            l++;
        }
        if (mp.size()<=k) ans += (r-l+1);
        r++;
    }

    return ans;
}

int subarraysWithKDistinct(vector<int>& nums, int k) {
    return subarraysWithMaxKDistinct(nums,k) - subarraysWithMaxKDistinct(nums,k-1);
}

int main() {

    vector<int> nums = {1,2,1,2,3};

    cout << subarraysWithKDistinct(nums, 2) << endl;

    return 0;
}