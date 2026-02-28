#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

int recursion(vector<int>& nums, int index, int target) {
    // Base Cases
    if (target == 0) return 1; // Found a valid subset
    if (index == 0) return (nums[0] == target) ? 1 : 0; // Only one element to consider

    // Exclude the current element
    int notTake = recursion(nums, index - 1, target);

    // Include the current element (if it does not exceed the target)
    int take = 0;
    if (nums[index] <= target) {
        take = recursion(nums, index - 1, target - nums[index]);
    }

    return take + notTake;
}

int countSubsetsWithSumKRecursion(vector<int>& nums, int K) {
    int n = nums.size();
    return recursion(nums, n-1, K);
}

int memoization(vector<int>& nums, int index, int target, vector<vector<int>>& dp) {
    // Base Cases
    if (target == 0) return 1; // Found a valid subset
    if (index == 0) return (nums[0] == target) ? 1 : 0; // Only one element to consider

    // Check if already computed
    if (dp[index][target] != -1) return dp[index][target];

    // Exclude the current element
    int notTake = memoization(nums, index - 1, target, dp);

    // Include the current element (if it does not exceed the target)
    int take = 0;
    if (nums[index] <= target) {
        take = memoization(nums, index - 1, target - nums[index], dp);
    }

    dp[index][target] = take + notTake;
    return dp[index][target];
}

int countSubsetsWithSumKMemoization(vector<int>& nums, int K) {
    int n = nums.size();
    vector<vector<int>> dp(n, vector<int>(K + 1, -1));
    return memoization(nums, n-1, K, dp);
}

int countSubsetsWithSumKTabulation(vector<int>& nums, int K) {
    int n = nums.size();
    vector<vector<int>> dp(n, vector<int>(K + 1, 0));

    // Base case initialization
    for (int i = 0; i < n; i++) {
        dp[i][0] = 1; // There's always one way to make sum 0 (empty subset)
    }
    if (nums[0] <= K) {
        dp[0][nums[0]] = 1; // If the first element is less than or equal to K
    }

    // Fill the dp table
    for (int i = 1; i < n; i++) {
        for (int target = 0; target <= K; target++) {
            int notTake = dp[i - 1][target];
            int take = 0;
            if (nums[i] <= target) {
                take = dp[i - 1][target - nums[i]];
            }
            dp[i][target] = take + notTake;
        }
    }

    return dp[n - 1][K];
}

int countSubsetsWithSumKSpaceOptimized(vector<int>& nums, int K) {
    int n = nums.size();
    vector<int> prev(K + 1, 0);
    vector<int> curr(K + 1, 0);

    // Base case initialization
    prev[0] = 1; // There's always one way to make sum 0 (empty subset)
    if (nums[0] <= K) {
        prev[nums[0]] = 1; // If the first element is less than or equal to K
    }

    // Fill the dp table using space optimization
    for (int i = 1; i < n; i++) {
        curr[0] = 1; // There's always one way to make sum 0 (empty subset)
        for (int target = 0; target <= K; target++) {
            int notTake = prev[target];
            int take = 0;
            if (nums[i] <= target) {
                take = prev[target - nums[i]];
            }
            curr[target] = take + notTake;
        }
        prev = curr;
    }

    return prev[K];
}

int main() {
    vector<int> nums = {1, 2, 3, 3};
    int K = 6;

    cout << "Count of subsets with sum " << K << " using Recursion: " 
         << countSubsetsWithSumKRecursion(nums, K) << endl;

    cout << "Count of subsets with sum " << K << " using Memoization: " 
         << countSubsetsWithSumKMemoization(nums, K) << endl;

    cout << "Count of subsets with sum " << K << " using Tabulation: " 
         << countSubsetsWithSumKTabulation(nums, K) << endl;

    cout << "Count of subsets with sum " << K << " using Space Optimization: " 
         << countSubsetsWithSumKSpaceOptimized(nums, K) << endl;

    return 0;
}