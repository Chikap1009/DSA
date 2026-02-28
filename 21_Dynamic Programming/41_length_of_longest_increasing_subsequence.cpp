#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

int recursion(vector<int>& nums, int index, int prevIndex) {
    if (index == nums.size()) {
        return 0;
    }

    int notTake = recursion(nums, index + 1, prevIndex);
    int take = 0;
    if (prevIndex == -1 || nums[index] > nums[prevIndex]) {
        take = 1 + recursion(nums, index + 1, index);
    }

    return max(take, notTake);
}

int lengthOfLISRecursion(vector<int>& nums) {
    int n = nums.size();
    return recursion(nums, 0, -1);
}

int memoization(vector<int>& nums, int index, int prevIndex, vector<vector<int>>& dp) {
    if (index == nums.size()) {
        return 0;
    }

    if (dp[index][prevIndex + 1] != -1) {
        return dp[index][prevIndex + 1];
    }

    int notTake = memoization(nums, index + 1, prevIndex, dp);
    int take = 0;
    if (prevIndex == -1 || nums[index] > nums[prevIndex]) {
        take = 1 + memoization(nums, index + 1, index, dp);
    }

    dp[index][prevIndex + 1] = max(take, notTake);
    return dp[index][prevIndex + 1];
}

int lengthOfLISMemoization(vector<int>& nums) {
    int n = nums.size();
    vector<vector<int>> dp(n, vector<int>(n + 1, -1));
    return memoization(nums, 0, -1, dp);
}

int lengthOfLISTabulation(vector<int>& nums) {
    int n = nums.size();
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

    for (int index = n - 1; index >= 0; index--) {
        for (int prevIndex = index - 1; prevIndex >= -1; prevIndex--) {
            int notTake = dp[index + 1][prevIndex + 1];
            int take = 0;
            if (prevIndex == -1 || nums[index] > nums[prevIndex]) {
                take = 1 + dp[index + 1][index + 1];
            }
            dp[index][prevIndex + 1] = max(take, notTake);
        }
    }

    return dp[0][0];
}

int lengthOfLISSpaceOptimized(vector<int>& nums) {
    int n = nums.size();
    vector<int> next(n + 1, 0);

    for (int index = n - 1; index >= 0; index--) {
        vector<int> curr(n + 1, 0);
        for (int prevIndex = index - 1; prevIndex >= -1; prevIndex--) {
            int notTake = next[prevIndex + 1];
            int take = 0;
            if (prevIndex == -1 || nums[index] > nums[prevIndex]) {
                take = 1 + next[index + 1];
            }
            curr[prevIndex + 1] = max(take, notTake);
        }
        next = curr;
    }

    return next[0];
}

int main() {
    vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};

    cout << "Length of Longest Increasing Subsequence (Recursion): "
         << lengthOfLISRecursion(nums) << endl;

    cout << "Length of Longest Increasing Subsequence (Memoization): "
         << lengthOfLISMemoization(nums) << endl;

    cout << "Length of Longest Increasing Subsequence (Tabulation): "
         << lengthOfLISTabulation(nums) << endl;

    cout << "Length of Longest Increasing Subsequence (Space Optimized): "
         << lengthOfLISSpaceOptimized(nums) << endl;

    return 0;
}