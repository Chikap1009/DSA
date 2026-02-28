#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

int recursion(vector<int>& weights, vector<int>& values, int index, int capacity) {
    if (index == 0) {
        return (capacity / weights[0]) * values[0];
    }

    int notTake = recursion(weights, values, index-1, capacity);
    int take = INT_MIN;
    if (weights[index] <= capacity) 
        take = values[index] + recursion(weights, values, index, capacity - weights[index]);
    return max(take, notTake);
}

int unboundedKnapsackRecursion(vector<int>& weights, vector<int>& values, int capacity) {
    int n = weights.size();
    return recursion(weights, values, n-1, capacity);
}

int memoization(vector<int>& weights, vector<int>& values, int index, int capacity, vector<vector<int>>& dp) {
    if (index == 0) {
        return (capacity / weights[0]) * values[0];
    }
    if (dp[index][capacity] != -1) return dp[index][capacity];

    int notTake = memoization(weights, values, index-1, capacity, dp);
    int take = INT_MIN;
    if (weights[index] <= capacity) 
        take = values[index] + memoization(weights, values, index, capacity - weights[index], dp);
    return dp[index][capacity] = max(take, notTake);
}

int unboundedKnapsackMemoization(vector<int>& weights, vector<int>& values, int capacity) {
    int n = weights.size();
    vector<vector<int>> dp(n, vector<int>(capacity+1, -1));
    return memoization(weights, values, n-1, capacity, dp);
}

int unboundedKnapsackTabulation(vector<int>& weights, vector<int>& values, int capacity) {
    int n = weights.size();
    vector<vector<int>> dp(n, vector<int>(capacity+1, 0));
    for (int cap = 0 ; cap <= capacity ; cap++) {
        dp[0][cap] = (cap / weights[0]) * values[0];
    }
    for (int index = 1 ; index < n ; index++) {
        for (int cap = 0 ; cap <= capacity ; cap++) {
            int notTake = dp[index-1][cap];
            int take = INT_MIN;
            if (weights[index] <= cap) 
                take = values[index] + dp[index][cap - weights[index]];
            dp[index][cap] = max(take, notTake);
        }
    }
    return dp[n-1][capacity];
}

int unboundedKnapsackSpaceOptimized(vector<int>& weights, vector<int>& values, int capacity) {
    int n = weights.size();
    vector<int> prev(capacity+1, 0);
    for (int cap = 0 ; cap <= capacity ; cap++) {
        prev[cap] = (cap / weights[0]) * values[0];
    }
    for (int index = 1 ; index < n ; index++) {
        vector<int> curr(capacity+1, 0);
        for (int cap = 0 ; cap <= capacity ; cap++) {
            int notTake = prev[cap];
            int take = INT_MIN;
            if (weights[index] <= cap) 
                take = values[index] + curr[cap - weights[index]];
            curr[cap] = max(take, notTake);
        }
        prev = curr;
    }
    return prev[capacity];
}

int unboundedKnapsackFinalSpaceOptimized(vector<int>& weights, vector<int>& values, int capacity) {
    int n = weights.size();
    vector<int> dp(capacity+1, 0);
    for (int cap = 0 ; cap <= capacity ; cap++) {
        dp[cap] = (cap / weights[0]) * values[0];
    }
    for (int index = 1 ; index < n ; index++) {
        for (int cap = 0 ; cap <= capacity ; cap++) {
            int notTake = dp[cap];
            int take = INT_MIN;
            if (weights[index] <= cap) 
                take = values[index] + dp[cap - weights[index]];
            dp[cap] = max(take, notTake);
        }
    }
    return dp[capacity];
}

int main() {
    vector<int> weights = {1, 2, 3};
    vector<int> values = {10, 15, 40};
    int capacity = 7;

    cout << "Unbounded Knapsack (Recursion): " << unboundedKnapsackRecursion(weights, values, capacity) << endl;
    cout << "Unbounded Knapsack (Memoization): " << unboundedKnapsackMemoization(weights, values, capacity) << endl;
    cout << "Unbounded Knapsack (Tabulation): " << unboundedKnapsackTabulation(weights, values, capacity) << endl;
    cout << "Unbounded Knapsack (Space Optimized): " << unboundedKnapsackSpaceOptimized(weights, values, capacity) << endl;
    cout << "Unbounded Knapsack (Final Space Optimized): " << unboundedKnapsackFinalSpaceOptimized(weights, values, capacity) << endl;

    return 0;
}