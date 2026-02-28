#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

int recursion(vector<int>& weights, vector<int>& values, int index, int capacity) {
    if (index == 0) {
        if (weights[0] <= capacity) {
            return values[0];
        } else {
            return 0;
        }
    }

    int notTake = recursion(weights, values, index - 1, capacity);
    int take = INT_MIN;
    if (weights[index] <= capacity) {
        take = values[index] + recursion(weights, values, index - 1, capacity - weights[index]);
    }
    return max(take, notTake); 
}

int knapsackRecursion(vector<int>& weights, vector<int>& values, int capacity) {
    int n = weights.size();
    return recursion(weights, values, n - 1, capacity);
}

int memoization(vector<int>& weights, vector<int>& values, int index, int capacity, vector<vector<int>>& dp) {
    if (index == 0) {
        if (weights[0] <= capacity) {
            return values[0];
        } else {
            return 0;
        }
    }

    if (dp[index][capacity] != -1) {
        return dp[index][capacity];
    }

    int notTake = memoization(weights, values, index - 1, capacity, dp);
    int take = INT_MIN;
    if (weights[index] <= capacity) {
        take = values[index] + memoization(weights, values, index - 1, capacity - weights[index], dp);
    }
    dp[index][capacity] = max(take, notTake);
    return dp[index][capacity];
}

int knapsackMemoization(vector<int>& weights, vector<int>& values, int capacity) {
    int n = weights.size();
    vector<vector<int>> dp(n, vector<int>(capacity + 1, -1));
    return memoization(weights, values, n - 1, capacity, dp);
}

int knapsackTabulation(vector<int>& weights, vector<int>& values, int capacity) {
    int n = weights.size();
    vector<vector<int>> dp(n, vector<int>(capacity + 1, 0));

    for (int w = weights[0]; w <= capacity; ++w) {
        dp[0][w] = values[0];
    }

    for (int index = 1; index < n; ++index) {
        for (int cap = 0; cap <= capacity; ++cap) {
            int notTake = dp[index - 1][cap];
            int take = INT_MIN;
            if (weights[index] <= cap) {
                take = values[index] + dp[index - 1][cap - weights[index]];
            }
            dp[index][cap] = max(take, notTake);
        }
    }
    return dp[n - 1][capacity];
}

int knapsackSpaceOptimized(vector<int>& weights, vector<int>& values, int capacity) {
    int n = weights.size();
    vector<int> prev(capacity + 1, 0);

    for (int w = weights[0]; w <= capacity; ++w) {
        prev[w] = values[0];
    }

    for (int index = 1; index < n; ++index) {
        vector<int> curr(capacity + 1, 0);
        for (int cap = 0; cap <= capacity; ++cap) {
            int notTake = prev[cap];
            int take = INT_MIN;
            if (weights[index] <= cap) {
                take = values[index] + prev[cap - weights[index]];
            }
            curr[cap] = max(take, notTake);
        }
        prev = curr;
    }
    return prev[capacity];
}

int knapsackFinalSpaceOptimized(vector<int>& weights, vector<int>& values, int capacity) {
    int n = weights.size();
    vector<int> dp(capacity + 1, 0);

    for (int w = weights[0]; w <= capacity; ++w) {
        dp[w] = values[0];
    }

    for (int index = 1; index < n; ++index) {
        for (int cap = capacity; cap >= 0; --cap) {
            int notTake = dp[cap];
            int take = INT_MIN;
            if (weights[index] <= cap) {
                take = values[index] + dp[cap - weights[index]];
            }
            dp[cap] = max(take, notTake);
        }
    }
    return dp[capacity];
}

int main() {
    vector<int> weights = {1, 2, 3};
    vector<int> values = {10, 15, 40};
    int capacity = 6;

    cout << "Recursion: " << knapsackRecursion(weights, values, capacity) << endl;
    cout << "Memoization: " << knapsackMemoization(weights, values, capacity) << endl;
    cout << "Tabulation: " << knapsackTabulation(weights, values, capacity) << endl;
    cout << "Space Optimized: " << knapsackSpaceOptimized(weights, values, capacity) << endl;
    cout << "Final Space Optimized: " << knapsackFinalSpaceOptimized(weights, values, capacity) << endl;

    return 0;
}