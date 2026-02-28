#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int recursion(vector<int>& nums, int index) {
    if (index < 0) return 0;

    int pick = nums[index] + recursion(nums, index-2);
    int notPick = 0 + recursion(nums, index-1);

    return max(pick, notPick);
}

int rob(vector<int>& nums) {
    int n = nums.size();
    return recursion(nums, n-1);
}

int recursion(vector<int>& nums, vector<int>& dp, int index) {
    if (index < 0) return 0;

    if (dp[index] != -1) return dp[index];

    int pick = nums[index] + recursion(nums, dp, index-2);
    int notPick = 0 + recursion(nums, dp, index-1);

    return dp[index] = max(pick, notPick);
}

int rob_memoization(vector<int>& nums) {
    int n = nums.size();
    vector<int> dp(n, -1);
    return recursion(nums, dp, n-1);
}

int rob_tabulation(vector<int>& nums) {
    int n = nums.size();
    vector<int> dp(n, -1);
    dp[0] = nums[0];
    for (int i=1 ; i<n ; i++) {
        int pick = nums[i];
        if (i>1) pick += dp[i-2];
        int notPick = 0 + dp[i-1];

        dp[i] = max(pick, notPick);
    }
    return dp[n-1];
}

int rob_spaceOptimized(vector<int>& nums) {
    int n = nums.size();
    int prev2 = 0;
    int prev = nums[0];
    for (int i=1 ; i<n ; i++) {
        int pick = nums[i];
        if (i>1) pick += prev2;
        int notPick = 0 + prev;

        int curr = max(pick, notPick);
        prev2 = prev;
        prev = curr;
    }
    return prev;
}

int main() {
    vector<int> nums = {2,7,9,3,1};
    cout << "Maximum amount that can be robbed (Recursion): " << rob(nums) << endl;
    cout << "Maximum amount that can be robbed (Memoization): " << rob_memoization(nums) << endl;
    cout << "Maximum amount that can be robbed (Tabulation): " << rob_tabulation(nums) << endl;
    cout << "Maximum amount that can be robbed (Space Optimized): " << rob_spaceOptimized(nums) << endl;
    return 0;
}