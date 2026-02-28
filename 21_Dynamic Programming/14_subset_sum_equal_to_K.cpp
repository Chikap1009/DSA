#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool recursion(vector<int> &arr, int index, int target) {
    if (target == 0) {
        return true; // Subset found
    }
    if (index == 0) {
        return (arr[0] == target) ? true : false;
    }

    // Not take the element
    bool notTake = recursion(arr, index - 1, target);
    // Take the element
    bool take = false;
    if (arr[index] <= target) {
        take = recursion(arr, index - 1, target - arr[index]);
    }

    return take || notTake;
}

bool subsetSumToKRecursion(vector<int> &arr, int k) {
    int n = arr.size();
    return recursion(arr, n-1, k);
}

bool memoization(vector<int> &arr, int index, int target, vector<vector<int>> &dp) {
    if (target == 0) {
        return true; // Subset found
    }
    if (index == 0) {
        return (arr[0] == target) ? true : false;
    }

    if (dp[index][target] != -1) {
        return dp[index][target];
    }

    // Not take the element
    bool notTake = memoization(arr, index - 1, target, dp);
    // Take the element
    bool take = false;
    if (arr[index] <= target) {
        take = memoization(arr, index - 1, target - arr[index], dp);
    }

    return dp[index][target] = take || notTake;
}

bool subsetSumToKMemoization(vector<int> &arr, int k) {
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int>(k + 1, -1));
    return memoization(arr, n-1, k, dp);
}

bool subsetSumToKTabulation(vector<int> &arr, int k) {
    int n = arr.size();
    vector<vector<bool>> dp(n, vector<bool>(k + 1, false));

    // Base case: target 0 can always be achieved with empty subset
    for (int i = 0; i < n; i++) {
        dp[i][0] = true;
    }

    // Base case: only first element
    if (arr[0] <= k) {
        dp[0][arr[0]] = true;
    }

    for (int index = 1; index < n; index++) {
        for (int target = 1; target <= k; target++) {
            // Not take the element
            bool notTake = dp[index - 1][target];
            // Take the element
            bool take = false;
            if (arr[index] <= target) {
                take = dp[index - 1][target - arr[index]];
            }
            dp[index][target] = take || notTake;
        }
    }

    return dp[n - 1][k];
}

bool subsetSumToKSpaceOptimized(vector<int> &arr, int k) {
    int n = arr.size();
    vector<bool> prev(k + 1, false);

    // Base case: target 0 can always be achieved with empty subset
    prev[0] = true;

    // Base case: only first element
    if (arr[0] <= k) {
        prev[arr[0]] = true;
    }

    for (int index = 1; index < n; index++) {
        vector<bool> curr(k + 1, false);
        curr[0] = true; // target 0 can always be achieved
        for (int target = 1; target <= k; target++) {
            // Not take the element
            bool notTake = prev[target];
            // Take the element
            bool take = false;
            if (arr[index] <= target) {
                take = prev[target - arr[index]];
            }
            curr[target] = take || notTake;
        }
        prev = curr;
    }

    return prev[k];
}

int main() {
    vector<int> arr = {3, 34, 4, 12, 5, 2};
    int k = 9;

    cout << "Using Recursion: " << (subsetSumToKRecursion(arr, k) ? "Found" : "Not Found") << endl;
    cout << "Using Memoization: " << (subsetSumToKMemoization(arr, k) ? "Found" : "Not Found") << endl;
    cout << "Using Tabulation: " << (subsetSumToKTabulation(arr, k) ? "Found" : "Not Found") << endl;
    cout << "Using Space Optimized: " << (subsetSumToKSpaceOptimized(arr, k) ? "Found" : "Not Found") << endl;

    return 0;
}