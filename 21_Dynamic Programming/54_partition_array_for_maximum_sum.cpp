#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

int recursion(vector<int>& arr, int index, int k) {
    int n = arr.size();
    if (index >= n) return 0;

    int maxSum = 0;
    int currentMax = 0;

    for (int j = index; j < min(n, index + k); ++j) {
        currentMax = max(currentMax, arr[j]);
        int length = j - index + 1;
        int total = length * currentMax + recursion(arr, j + 1, k);
        maxSum = max(maxSum, total);
    }

    return maxSum;
}

int maxSumAfterPartitioningRecursion(vector<int>& arr, int k) {
    return recursion(arr, 0, k);
}

int memoization(vector<int>& arr, int index, int k, vector<int>& dp) {
    int n = arr.size();
    if (index >= n) return 0;
    if (dp[index] != -1) return dp[index];

    int maxSum = 0;
    int currentMax = 0;

    for (int j = index; j < min(n, index + k); ++j) {
        currentMax = max(currentMax, arr[j]);
        int length = j - index + 1;
        int total = length * currentMax + memoization(arr, j + 1, k, dp);
        maxSum = max(maxSum, total);
    }

    dp[index] = maxSum;
    return dp[index];
}

int maxSumAfterPartitioningMemoization(vector<int>& arr, int k) {
    int n = arr.size();
    vector<int> dp(n, -1);
    return memoization(arr, 0, k, dp);
}

int maxSumAfterPartitioningTabulation(vector<int>& arr, int k) {
    int n = arr.size();
    vector<int> dp(n + 1, 0);
    dp[n] = 0;

    for (int index = n - 1; index >= 0; --index) {
        int maxSum = 0;
        int currentMax = 0;

        for (int j = index; j < min(n, index + k); ++j) {
            currentMax = max(currentMax, arr[j]);
            int length = j - index + 1;
            int total = length * currentMax + dp[j + 1];
            maxSum = max(maxSum, total);
        }

        dp[index] = maxSum;
    }

    return dp[0];
}

int main() {
    vector<int> arr = {1, 15, 7, 9, 2, 5, 10};
    int k = 3;

    cout << "Recursion: " << maxSumAfterPartitioningRecursion(arr, k) << endl;
    cout << "Memoization: " << maxSumAfterPartitioningMemoization(arr, k) << endl;
    cout << "Tabulation: " << maxSumAfterPartitioningTabulation(arr, k) << endl;

    return 0;
}