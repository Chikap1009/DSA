#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

int recursion(string &text1, string &text2, int i, int j) {
    if (i < 0 || j < 0) {
        return 0;
    }
    if (text1[i] == text2[j]) {
        return 1 + recursion(text1, text2, i - 1, j - 1);
    } else {
        return max(recursion(text1, text2, i - 1, j), recursion(text1, text2, i, j - 1));
    }
}

int longestCommonSubsequenceRecursion(string text1, string text2) {
    int n = text1.size();
    int m = text2.size();
    return recursion(text1, text2, n - 1, m - 1);
}

int memoization(string &text1, string &text2, int i, int j, vector<vector<int>> &dp) {
    if (i < 0 || j < 0) {
        return 0;
    }
    if (dp[i][j] != -1) {
        return dp[i][j];
    }
    if (text1[i] == text2[j]) {
        dp[i][j] = 1 + memoization(text1, text2, i - 1, j - 1, dp);
    } else {
        dp[i][j] = max(memoization(text1, text2, i - 1, j, dp), memoization(text1, text2, i, j - 1, dp));
    }
    return dp[i][j];
}

int longestCommonSubsequenceMemoization(string text1, string text2) {
    int n = text1.size();
    int m = text2.size();
    vector<vector<int>> dp(n, vector<int>(m, -1));
    return memoization(text1, text2, n - 1, m - 1, dp);
}

int longestCommonSubsequenceTabulation(string text1, string text2) {
    int n = text1.size();
    int m = text2.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (text1[i - 1] == text2[j - 1]) {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[n][m];
}

int longestCommonSubsequenceSpaceOptimization(string text1, string text2) {
    int n = text1.size();
    int m = text2.size();
    vector<int> prev(m + 1, 0);
    for (int i = 1; i <= n; i++) {
        vector<int> curr(m + 1, 0);
        for (int j = 1; j <= m; j++) {
            if (text1[i - 1] == text2[j - 1]) {
                curr[j] = 1 + prev[j - 1];
            } else {
                curr[j] = max(prev[j], curr[j - 1]);
            }
        }
        prev = curr;
    }
    return prev[m];
}

int main() {
    string text1 = "abcde";
    string text2 = "ace";

    cout << "Length of Longest Common Subsequence (Recursion): " 
         << longestCommonSubsequenceRecursion(text1, text2) << endl;

    cout << "Length of Longest Common Subsequence (Memoization): " 
         << longestCommonSubsequenceMemoization(text1, text2) << endl;

    cout << "Length of Longest Common Subsequence (Tabulation): " 
         << longestCommonSubsequenceTabulation(text1, text2) << endl;

    cout << "Length of Longest Common Subsequence (Space Optimization): " 
         << longestCommonSubsequenceSpaceOptimization(text1, text2) << endl;

    return 0;
}