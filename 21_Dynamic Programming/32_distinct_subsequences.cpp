#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

int recursion(string& s, string& t, int i, int j) {
    if (j < 0) return 1; // An empty t can be formed from any s
    if (i < 0) return 0; // Non-empty t cannot be formed from an empty s

    // If characters match, we have two choices:
    // 1. Include this character from s
    // 2. Exclude this character from s
    if (s[i] == t[j]) {
        return recursion(s, t, i - 1, j - 1) + recursion(s, t, i - 1, j);
    }
    // If characters do not match, we can only exclude the character from s
    return recursion(s, t, i - 1, j);
}

int numDistinctRecursion(string s, string t) {
    int n = s.size();
    int m = t.size();
    return recursion(s, t, n - 1, m - 1);
}

int memoization(string& s, string& t, int i, int j, vector<vector<unsigned int>>& dp) {
    if (j < 0) return 1; // An empty t can be formed from any s
    if (i < 0) return 0; // Non-empty t cannot be formed from an empty s

    if (dp[i][j] != -1) return dp[i][j];

    if (s[i] == t[j]) {
        dp[i][j] = memoization(s, t, i - 1, j - 1, dp) + memoization(s, t, i - 1, j, dp);
    } else {
        dp[i][j] = memoization(s, t, i - 1, j, dp);
    }
    return dp[i][j];
}

int numDistinctMemoization(string s, string t) {
    int n = s.size();
    int m = t.size();
    vector<vector<unsigned int>> dp(n, vector<unsigned int>(m, -1));
    return memoization(s, t, n - 1, m - 1, dp);
}

int numDistinctTabulation(string s, string t) {
    int n = s.size();
    int m = t.size();
    vector<vector<unsigned int>> dp(n + 1, vector<unsigned int>(m + 1, 0));

    // An empty t can be formed from any prefix of s
    for (int i = 0; i <= n; i++) {
        dp[i][0] = 1;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (s[i - 1] == t[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    return dp[n][m];
}

int numDistinctSpaceOptimized(string s, string t) {
    int n = s.size();
    int m = t.size();
    vector<int> prev(m + 1, 0);
    prev[0] = 1; // An empty t can be formed from any prefix of s

    for (int i = 1; i <= n; i++) {
        vector<int> curr(m + 1, 0);
        curr[0] = 1; // An empty t can be formed from any prefix of s
        for (int j = 1; j <= m; j++) {
            if (s[i - 1] == t[j - 1]) {
                curr[j] = prev[j - 1] + prev[j];
            } else {
                curr[j] = prev[j];
            }
        }
        prev = curr;
    }
    return prev[m];
}

int numDistinctFinalSpaceOptimized(string s, string t) {
    int n = s.size();
    int m = t.size();
    vector<unsigned int> dp(m + 1, 0);
    dp[0] = 1; // An empty t can be formed from any prefix of s

    for (int i = 1; i <= n; i++) {
        for (int j = m; j >= 1; j--) {
            if (s[i - 1] == t[j - 1]) {
                dp[j] += dp[j - 1];
            }
        }
    }
    return dp[m];
}

int main() {
    string s = "babgbag";
    string t = "bag";

    cout << "Recursion: " << numDistinctRecursion(s, t) << endl;
    cout << "Memoization: " << numDistinctMemoization(s, t) << endl;
    cout << "Tabulation: " << numDistinctTabulation(s, t) << endl;
    cout << "Space Optimized: " << numDistinctSpaceOptimized(s, t) << endl;
    cout << "Final Space Optimized: " << numDistinctFinalSpaceOptimized(s, t) << endl;

    return 0;
}