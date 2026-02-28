#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

int recursion(vector<int>& prices, int index, int length) {
    if (index == 0) {
        return length * prices[0];
    }

    int notTake = recursion(prices, index - 1, length);
    int take = INT_MIN;
    int rodLength = index + 1;
    if (rodLength <= length) {
        take = prices[index] + recursion(prices, index, length - rodLength);
    }

    return max(take, notTake);
}

int rodCuttingProblemRecursion(vector<int>& prices) {
    int n = prices.size();
    return recursion(prices, n-1, n);
}

int memoization(vector<int>& prices, int index, int length, vector<vector<int>>& dp) {
    if (index == 0) {
        return length * prices[0];
    }

    if (dp[index][length] != -1) {
        return dp[index][length];
    }

    int notTake = memoization(prices, index - 1, length, dp);
    int take = INT_MIN;
    int rodLength = index + 1;
    if (rodLength <= length) {
        take = prices[index] + memoization(prices, index, length - rodLength, dp);
    }

    return dp[index][length] = max(take, notTake);
}

int rodCuttingProblemMemoization(vector<int>& prices) {
    int n = prices.size();
    vector<vector<int>> dp(n, vector<int>(n + 1, -1));
    return memoization(prices, n - 1, n, dp);
}

int rodCuttingProblemTabulation(vector<int>& prices) {
    int n = prices.size();
    vector<vector<int>> dp(n, vector<int>(n + 1, 0));

    for (int length = 0; length <= n; length++) {
        dp[0][length] = length * prices[0];
    }

    for (int index = 1; index < n; index++) {
        for (int length = 0; length <= n; length++) {
            int notTake = dp[index - 1][length];
            int take = INT_MIN;
            int rodLength = index + 1;
            if (rodLength <= length) {
                take = prices[index] + dp[index][length - rodLength];
            }
            dp[index][length] = max(take, notTake);
        }
    }

    return dp[n - 1][n];
}

int rodCuttingProblemSpaceOptimization(vector<int>& prices) {
    int n = prices.size();
    vector<int> prev(n + 1, 0);

    for (int length = 0; length <= n; length++) {
        prev[length] = length * prices[0];
    }

    for (int index = 1; index < n; index++) {
        vector<int> curr(n + 1, 0);
        for (int length = 0; length <= n; length++) {
            int notTake = prev[length];
            int take = INT_MIN;
            int rodLength = index + 1;
            if (rodLength <= length) {
                take = prices[index] + curr[length - rodLength];
            }
            curr[length] = max(take, notTake);
        }
        prev = curr;
    }

    return prev[n];
}

int rodCuttingProblemFinalSpaceOptimization(vector<int>& prices) {
    int n = prices.size();
    vector<int> dp(n + 1, 0);

    for (int length = 0; length <= n; length++) {
        dp[length] = length * prices[0];
    }

    for (int index = 1; index < n; index++) {
        for (int length = 0; length <= n; length++) {
            int notTake = dp[length];
            int take = INT_MIN;
            int rodLength = index + 1;
            if (rodLength <= length) {
                take = prices[index] + dp[length - rodLength];
            }
            dp[length] = max(take, notTake);
        }
    }

    return dp[n];
}

int main() {
    vector<int> prices = {1, 5, 8, 9, 10, 17, 17, 20};

    cout << "Recursion: " << rodCuttingProblemRecursion(prices) << endl;
    cout << "Memoization: " << rodCuttingProblemMemoization(prices) << endl;
    cout << "Tabulation: " << rodCuttingProblemTabulation(prices) << endl;
    cout << "Space Optimization: " << rodCuttingProblemSpaceOptimization(prices) << endl;
    cout << "Final Space Optimization: " << rodCuttingProblemFinalSpaceOptimization(prices) << endl;

    return 0;
}