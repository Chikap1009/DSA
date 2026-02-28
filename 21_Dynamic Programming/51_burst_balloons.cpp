#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

int recursion(vector<int> nums, int i, int j) {
    if (i > j) return 0;

    int maxi = INT_MIN;

    for (int k = i ; k <= j ; k++) {
        int coins = (nums[i-1] * nums[k] * nums[j+1]) + recursion(nums, i, k-1) + recursion(nums, k+1, j);
        maxi = max(maxi, coins);
    }

    return maxi;
}

int maxCoinsRecursion(vector<int> nums) {
    int n = nums.size();

    nums.insert(nums.begin(), 1);
    nums.push_back(1);

    return recursion(nums, 1, n);
}

int memoization(vector<int> nums, int i, int j, vector<vector<int>>& dp) {
    if (i > j) return 0;

    if (dp[i][j] != -1) return dp[i][j];

    int maxi = INT_MIN;

    for (int k = i ; k <= j ; k++) {
        int coins = (nums[i-1] * nums[k] * nums[j+1]) + memoization(nums, i, k-1, dp) + memoization(nums, k+1, j, dp);
        maxi = max(maxi, coins);
    }

    return dp[i][j] = maxi;
}

int maxCoinsMemoization(vector<int> nums) {
    int n = nums.size();

    nums.insert(nums.begin(), 1);
    nums.push_back(1);

    vector<vector<int>> dp(n+1, vector<int>(n+1, -1));

    return memoization(nums, 1, n, dp);
}

int maxCoinsTabulation(vector<int> nums) {
    int n = nums.size();

    nums.insert(nums.begin(), 1);
    nums.push_back(1);

    vector<vector<int>> dp(n+2, vector<int> (n+2, 0));

    for (int i = n; i >= 1 ; i--) {
        for (int j = i ; j <= n ; j++) {
            int maxi = INT_MIN;
            for (int k = i ; k <= j ; k++) {
                int coins = (nums[i-1] * nums[k] * nums[j+1]) +
                            dp[i][k-1] +
                            dp[k+1][j];
                
                maxi = max(maxi, coins);
            }
            dp[i][j] = maxi;
        }
    }

    return dp[1][n];
}

int main() {
    vector<int> nums = {3, 1, 5, 8};

    cout << "Maximum coins (Recursion): " << maxCoinsRecursion(nums) << endl;
    cout << "Maximum coins (Memoization): " << maxCoinsMemoization(nums) << endl;
    cout << "Maximum coins (Tabulation): " << maxCoinsTabulation(nums) << endl;

    return 0;
}