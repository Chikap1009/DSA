#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int recursion(int r, int c) {
    if (r == 0 && c == 0) return 1;
    if (r < 0 || c < 0) return 0;
    int up = recursion(r-1,c);
    int left = recursion(r,c-1);
    return up + left;
}

int uniquePathsRecursion(int m, int n) {
    return recursion(m-1, n-1);
}

int memoization(int r, int c, vector<vector<int>>& dp) {
    if (r == 0 && c == 0) return 1;
    if (r < 0 || c < 0) return 0;
    if (dp[r][c] != -1) return dp[r][c];
    int up = memoization(r-1,c, dp);
    int left = memoization(r,c-1, dp);
    return dp[r][c] = up + left;
}

int uniquePathsMemoization(int m, int n) {
    vector<vector<int>> dp(m, vector<int>(n, -1));
    return memoization(m-1, n-1, dp);
}

int uniquePathsTabulation(int m, int n) {
    vector<vector<int>> dp(m, vector<int>(n, 0));
    for (int r = 0; r < m; r++) {
        for (int c = 0; c < n; c++) {
            if (r == 0 && c == 0) {
                dp[r][c] = 1;
            } else {
                int up = (r > 0) ? dp[r-1][c] : 0;
                int left = (c > 0) ? dp[r][c-1] : 0;
                dp[r][c] = up + left;
            }
        }
    }
    return dp[m-1][n-1];
}

int uniquePathsSpaceOptimized(int m, int n) {
    vector<int> prev(n, 0);
    for (int r = 0; r < m; r++) {
        vector<int> curr(n, 0);
        for (int c = 0; c < n; c++) {
            if (r == 0 && c == 0) {
                curr[c] = 1;
            } else {
                int up = (r > 0) ? prev[c] : 0;
                int left = (c > 0) ? curr[c-1] : 0;
                curr[c] = up + left;
            }
        }
        prev = curr;
    }
    return prev[n-1];
}

int main() {
    int m = 3, n = 7;
    cout << "Number of unique paths in a " << m << "x" << n << " grid: " << uniquePathsRecursion(m, n) << endl;
    cout << "Number of unique paths in a " << m << "x" << n << " grid (with memoization): " << uniquePathsMemoization(m, n) << endl;
    cout << "Number of unique paths in a " << m << "x" << n << " grid (with tabulation): " << uniquePathsTabulation(m, n) << endl;
    cout << "Number of unique paths in a " << m << "x" << n << " grid (space optimized): " << uniquePathsSpaceOptimized(m, n) << endl;
    return 0;
}