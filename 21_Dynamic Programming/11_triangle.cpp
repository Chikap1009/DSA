#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int recursion(vector<vector<int>>& triangle, int r, int c) {
    if (r == triangle.size()-1) {
        return triangle[r][c];
    }

    int down1 = triangle[r][c] + recursion(triangle, r+1, c);
    int down2 = triangle[r][c] + recursion(triangle, r+1, c+1);

    return min(down1, down2);
}

int minimumTotalRecursion(vector<vector<int>>& triangle) {
    int n = triangle.size();
    return recursion(triangle, 0, 0);
}

int memoization(vector<vector<int>>& triangle, vector<vector<int>>& dp, int r, int c) {
    if (r == triangle.size()-1) {
        return triangle[r][c];
    }
    if (dp[r][c] != -1) return dp[r][c];

    int down1 = triangle[r][c] + memoization(triangle, dp, r+1, c);
    int down2 = triangle[r][c] + memoization(triangle, dp, r+1, c+1);

    return dp[r][c] = min(down1, down2);
}

int minimumTotalMemoization(vector<vector<int>>& triangle) {
    int n = triangle.size();
    vector<vector<int>> dp(n, vector<int>(n, -1));
    return memoization(triangle, dp, 0, 0);
}

int minimumTotalTabulation(vector<vector<int>>& triangle) {
    int n = triangle.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));

    for (int c = 0; c < n; c++) {
        dp[n-1][c] = triangle[n-1][c];
    }

    for (int r = n-2; r >= 0; r--) {
        for (int c = r; c >= 0; c--) {
            int down1 = triangle[r][c] + dp[r+1][c];
            int down2 = triangle[r][c] + dp[r+1][c+1];
            dp[r][c] = min(down1, down2);
        }
    }

    return dp[0][0];
}

int minimumTotalSpaceOptimized(vector<vector<int>>& triangle) {
    int n = triangle.size();
    vector<vector<int>> dp(n, vector<int> (n, 0));
    vector<int> prevRow (n, 0);
    for (int i=0 ; i<n ; i++) {
        prevRow[i] = triangle[n-1][i];
    }
    for (int i=n-2 ; i>=0 ; i--) {
        vector<int> currRow (n, 0);
        for (int j=i ; j>=0 ; j--) {
            int down = triangle[i][j] + prevRow[j];
            int diag = triangle[i][j] + prevRow[j+1];
            currRow[j] = min(down, diag);
        }
        prevRow = currRow;
    }
    return prevRow[0];
}

int main() {
    vector<vector<int>> triangle = {
        {2},
        {3,4},
        {6,5,7},
        {4,1,8,3}
    };

    cout << "Minimum Total (Recursion): " << minimumTotalRecursion(triangle) << endl;
    cout << "Minimum Total (Memoization): " << minimumTotalMemoization(triangle) << endl;
    cout << "Minimum Total (Tabulation): " << minimumTotalTabulation(triangle) << endl;
    cout << "Minimum Total (Space Optimized): " << minimumTotalSpaceOptimized(triangle) << endl;

    return 0;
}