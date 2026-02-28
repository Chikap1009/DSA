#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

int recursion(vector<int>& dimensions, int i, int j) {
    if (i >= j) {
        return 0; // No cost if there's one or no matrix
    }

    int minCost = INT_MAX;

    for (int k = i; k < j; k++) {
        int costLeft = recursion(dimensions, i, k);
        int costRight = recursion(dimensions, k + 1, j);
        int costMultiply = dimensions[i - 1] * dimensions[k] * dimensions[j];
        int totalCost = costLeft + costRight + costMultiply;

        minCost = min(minCost, totalCost);
    }

    return minCost;
}

int matrixMultiplicationTopDown(vector<int>& dimensions) {
    int n = dimensions.size();
    return recursion(dimensions, 1, n-1);
}

int memoization(vector<int>& dimensions, int i, int j, vector<vector<int>>& dp) {
    if (i >= j) {
        return 0; // No cost if there's one or no matrix
    }

    if (dp[i][j] != -1) {
        return dp[i][j];
    }

    int minCost = INT_MAX;

    for (int k = i; k < j; k++) {
        int costLeft = memoization(dimensions, i, k, dp);
        int costRight = memoization(dimensions, k + 1, j, dp);
        int costMultiply = dimensions[i - 1] * dimensions[k] * dimensions[j];
        int totalCost = costLeft + costRight + costMultiply;

        minCost = min(minCost, totalCost);
    }

    dp[i][j] = minCost;
    return minCost;
}

int matrixMultiplicationMemoization(vector<int>& dimensions) {
    int n = dimensions.size();
    vector<vector<int>> dp(n, vector<int>(n, -1));
    return memoization(dimensions, 1, n-1, dp);
}

int main() {
    vector<int> dimensions = {10, 20, 30, 40, 30};

    int resultTopDown = matrixMultiplicationTopDown(dimensions);
    cout << "Minimum number of multiplications (Top-Down): " << resultTopDown << endl;

    int resultMemoization = matrixMultiplicationMemoization(dimensions);
    cout << "Minimum number of multiplications (Memoization): " << resultMemoization << endl;

    return 0;
}