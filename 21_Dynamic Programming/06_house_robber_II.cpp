#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int rob(vector<int>& nums) {
    if (nums.size() == 1) return nums[0];
    
    int n = nums.size();
    int prev2 = 0;
    int prev = nums[0];
    for (int i=1 ; i<n-1 ; i++) {
        int pick = nums[i];
        if (i>1) pick += prev2;
        int notPick = 0 + prev;

        int curr = max(pick, notPick);
        prev2 = prev;
        prev = curr;
    }
    int ans1 = prev;

    prev2 = 0;
    prev = nums[1];
    for (int i=2 ; i<n ; i++) {
        int pick = nums[i];
        if (i>1) pick += prev2;
        int notPick = 0 + prev;

        int curr = max(pick, notPick);
        prev2 = prev;
        prev = curr;
    }
    int ans2 = prev;

    return max(ans1, ans2);
}

int main() {
    vector<int> nums = {2,3,2};
    cout << rob(nums) << endl; // Output: 3
    return 0;
}