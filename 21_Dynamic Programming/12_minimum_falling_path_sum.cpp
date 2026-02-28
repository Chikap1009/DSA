#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int recursion(vector<vector<int>>& matrix, int r, int c) {
    if (r == 0) {
        return matrix[0][c];
    }

    int left = INT_MAX, up = INT_MAX, right = INT_MAX;
    if (c-1 >= 0) left = matrix[r][c] + recursion(matrix, r-1, c-1);
    up = matrix[r][c] + recursion(matrix, r-1, c);
    if (c+1 < matrix.size()) right = matrix[r][c] + recursion(matrix, r-1, c+1);

    return min(up, min(left, right));
}

int minFallingPathSumTRecursion(vector<vector<int>>& matrix) {
    int n = matrix.size();
    int mini = INT_MAX;
    for (int j = 0 ; j < n ; j++) {
        mini = min(mini, recursion(matrix, n-1, j));
    }
    return mini;
}

int memoization(vector<vector<int>>& matrix, vector<vector<int>> &dp, int r, int c) {
    if (r == 0) {
        return matrix[0][c];
    }
    if (dp[r][c] != -1) return dp[r][c];

    int left = INT_MAX, up = INT_MAX, right = INT_MAX;
    if (c-1 >= 0) left = matrix[r][c] + memoization(matrix, dp, r-1, c-1);
    up = matrix[r][c] + memoization(matrix, dp, r-1, c);
    if (c+1 < matrix.size()) right = matrix[r][c] + memoization(matrix, dp, r-1, c+1);

    return dp[r][c] = min(up, min(left, right));
}

int minFallingPathSumMemoization(vector<vector<int>>& matrix) {
    int n = matrix.size();
    vector<vector<int>> dp(n, vector<int> (n,-1));
    int mini = INT_MAX;
    for (int j = 0 ; j < n ; j++) {
        mini = min(mini, memoization(matrix, dp, n-1, j));
    }
    return mini;
}

int minFallingPathSumTabulation(vector<vector<int>>& matrix) {
    int n = matrix.size();
    vector<vector<int>> dp(n, vector<int> (n,0));
    for (int i=0 ; i<n ; i++) {
        dp[0][i] = matrix[0][i];
    }
    for (int r=1 ; r<n ; r++) {
        for (int c=0 ; c<n ; c++) {
            int left = INT_MAX, up = INT_MAX, right = INT_MAX;
            if (c-1 >= 0) left = matrix[r][c] + dp[r-1][c-1];
            up = matrix[r][c] + dp[r-1][c];
            if (c+1 < matrix.size()) right = matrix[r][c] + dp[r-1][c+1];
            dp[r][c] = min(up, min(left, right));
        }
    }
    
    return *min_element(dp[n-1].begin(), dp[n-1].end());
}

int minFallingPathSumSpaceOptimized(vector<vector<int>>& matrix) {
    int n = matrix.size();
    vector<int> prevRow(n, 0);
    for (int i=0 ; i<n ; i++) {
        prevRow[i] = matrix[0][i];
    }
    for (int r=1 ; r<n ; r++) {
        vector<int> currRow (n, 0);
        for (int c=0 ; c<n ; c++) {
            int left = INT_MAX, up = INT_MAX, right = INT_MAX;
            if (c-1 >= 0) left = matrix[r][c] + prevRow[c-1];
            up = matrix[r][c] + prevRow[c];
            if (c+1 < matrix.size()) right = matrix[r][c] + prevRow[c+1];
            currRow[c] = min(up, min(left, right));
        }
        prevRow = currRow;
    }
    
    return *min_element(prevRow.begin(), prevRow.end());
}

int main() {
    vector<vector<int>> matrix = {
        {2,1,3},
        {6,5,4},
        {7,8,9}
    };

    cout << "Minimum Falling Path Sum (Recursion): " << minFallingPathSumTRecursion(matrix) << endl;
    cout << "Minimum Falling Path Sum (Memoization): " << minFallingPathSumMemoization(matrix) << endl;
    cout << "Minimum Falling Path Sum (Tabulation): " << minFallingPathSumTabulation(matrix) << endl;
    cout << "Minimum Falling Path Sum (Space Optimized): " << minFallingPathSumSpaceOptimized(matrix) << endl;

    return 0;
}