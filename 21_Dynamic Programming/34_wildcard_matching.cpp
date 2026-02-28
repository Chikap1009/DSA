#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

bool recursion(string &s, string &p, int i, int j) {
    // Base Cases
    if (i < 0 && j < 0) return true; // Both strings are fully matched
    if (j < 0) return false;          // Pattern is exhausted but string is not
    if (i < 0) {
        // String is exhausted, check if remaining pattern characters are all '*'
        for (int k = 0; k <= j; k++) {
            if (p[k] != '*') return false;
        }
        return true;
    }

    if (s[i] == p[j] || p[j] == '?') {
        // Characters match or pattern has '?', move both pointers
        return recursion(s, p, i - 1, j - 1);
    } else if (p[j] == '*') {
        // '*' can match zero characters (move pattern pointer) or one/more characters (move string pointer)
        return recursion(s, p, i, j - 1) || recursion(s, p, i - 1, j);
    } 
    else return false; // Characters do not match
}

bool isMatchRecursion(string s, string p) {
    int n = s.size();
    int m = p.size();
    return recursion(s, p, n - 1, m - 1);
}

bool memoization(string &s, string &p, int i, int j, vector<vector<int>> &dp) {
    // Base Cases
    if (i < 0 && j < 0) return true; // Both strings are fully matched
    if (j < 0) return false;          // Pattern is exhausted but string is not
    if (i < 0) {
        // String is exhausted, check if remaining pattern characters are all '*'
        for (int k = 0; k <= j; k++) {
            if (p[k] != '*') return false;
        }
        return true;
    }

    if (dp[i][j] != -1) return dp[i][j];

    if (s[i] == p[j] || p[j] == '?') {
        // Characters match or pattern has '?', move both pointers
        dp[i][j] = memoization(s, p, i - 1, j - 1, dp);
    } else if (p[j] == '*') {
        // '*' can match zero characters (move pattern pointer) or one/more characters (move string pointer)
        dp[i][j] = memoization(s, p, i, j - 1, dp) || memoization(s, p, i - 1, j, dp);
    } else {
        dp[i][j] = false; // Characters do not match
    }
    return dp[i][j];
}

bool isMatchMemoization(string s, string p) {
    int n = s.size();
    int m = p.size();
    vector<vector<int>> dp(n, vector<int>(m, -1));
    return memoization(s, p, n - 1, m - 1, dp);
}

bool isMatchTabulation(string s, string p) {
    int n = s.size();
    int m = p.size();
    vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));

    dp[0][0] = true; // Both strings are empty

    // Initialize first row (s is empty)
    for (int j = 1; j <= m; j++) {
        if (p[j - 1] == '*') {
            dp[0][j] = true;
        }
        else {
            break; // Once a non-* character is found, rest are false
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (s[i - 1] == p[j - 1] || p[j - 1] == '?') {
                dp[i][j] = dp[i - 1][j - 1];
            } else if (p[j - 1] == '*') {
                dp[i][j] = dp[i][j - 1] || dp[i - 1][j];
            } else {
                dp[i][j] = false;
            }
        }
    }
    return dp[n][m];
}

bool isMatchSpaceOptimized(string s, string p) {
    int n = s.size();
    int m = p.size();
    vector<bool> prev(m + 1, false);

    prev[0] = true; // Both strings are empty

    // Initialize first row (s is empty)
    for (int j = 1; j <= m; j++) {
        if (p[j - 1] == '*') {
            prev[j] = true;
        }
        else {
            break; // Once a non-* character is found, rest are false
        }
    }

    for (int i = 1; i <= n; i++) {
        vector<bool> curr(m + 1, false);
        curr[0] = false; // If pattern is empty but string is not
        for (int j = 1; j <= m; j++) {
            if (s[i - 1] == p[j - 1] || p[j - 1] == '?') {
                curr[j] = prev[j - 1];
            } else if (p[j - 1] == '*') {
                curr[j] = curr[j - 1] || prev[j];
            } else {
                curr[j] = false;
            }
        }
        prev = curr;
    }
    return prev[m];
}

int main() {
    string s = "adceb";
    string p = "*a*b";

    cout << boolalpha; // Print boolean values as true/false

    cout << "Recursion: " << isMatchRecursion(s, p) << endl;
    cout << "Memoization: " << isMatchMemoization(s, p) << endl;
    cout << "Tabulation: " << isMatchTabulation(s, p) << endl;
    cout << "Space Optimized: " << isMatchSpaceOptimized(s, p) << endl;

    return 0;
}