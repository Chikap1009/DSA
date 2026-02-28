#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

int recursion(string& word1, string& word2, int i, int j) {
    if (i < 0) return j + 1; // If word1 is empty, we need to insert all characters of word2
    if (j < 0) return i + 1; // If word2 is empty, we need to delete all characters of word1

    if (word1[i] == word2[j]) {
        return recursion(word1, word2, i - 1, j - 1); // Characters match, move both pointers
    } else {
        int insertOp = 1 + recursion(word1, word2, i, j - 1);    // Insert character
        int deleteOp = 1 + recursion(word1, word2, i - 1, j);    // Delete character
        int replaceOp = 1 + recursion(word1, word2, i - 1, j - 1); // Replace character
        return min({insertOp, deleteOp, replaceOp});
    }
}

int minDistanceRecursion(string word1, string word2) {
    int n = word1.size();
    int m = word2.size();
    return recursion(word1, word2, n - 1, m - 1);
}

int memoization(string& word1, string& word2, int i, int j, vector<vector<int>>& dp) {
    if (i < 0) return j + 1; // If word1 is empty, we need to insert all characters of word2
    if (j < 0) return i + 1; // If word2 is empty, we need to delete all characters of word1

    if (dp[i][j] != -1) return dp[i][j];

    if (word1[i] == word2[j]) {
        dp[i][j] = memoization(word1, word2, i - 1, j - 1, dp); // Characters match, move both pointers
    } else {
        int insertOp = 1 + memoization(word1, word2, i, j - 1, dp);    // Insert character
        int deleteOp = 1 + memoization(word1, word2, i - 1, j, dp);    // Delete character
        int replaceOp = 1 + memoization(word1, word2, i - 1, j - 1, dp); // Replace character
        dp[i][j] = min({insertOp, deleteOp, replaceOp});
    }
    return dp[i][j];
}

int minDistanceMemoization(string word1, string word2) {
    int n = word1.size();
    int m = word2.size();
    vector<vector<int>> dp(n, vector<int>(m, -1));
    return memoization(word1, word2, n - 1, m - 1, dp);
}

int minDistanceTabulation(string word1, string word2) {
    int n = word1.size();
    int m = word2.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    // If word2 is empty, we need to delete all characters of word1
    for (int i = 0; i <= n; i++) {
        dp[i][0] = i;
    }
    // If word1 is empty, we need to insert all characters of word2
    for (int j = 0; j <= m; j++) {
        dp[0][j] = j;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (word1[i - 1] == word2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1]; // Characters match, move both pointers
            } else {
                int insertOp = 1 + dp[i][j - 1];    // Insert character
                int deleteOp = 1 + dp[i - 1][j];    // Delete character
                int replaceOp = 1 + dp[i - 1][j - 1]; // Replace character
                dp[i][j] = min({insertOp, deleteOp, replaceOp});
            }
        }
    }
    return dp[n][m];
}

int minDistanceSpaceOptimized(string word1, string word2) {
    int n = word1.size();
    int m = word2.size();
    vector<int> prev(m + 1, 0);

    // If word1 is empty, we need to insert all characters of word2
    for (int j = 0; j <= m; j++) {
        prev[j] = j;
    }

    for (int i = 1; i <= n; i++) {
        vector<int> curr(m + 1, 0);
        curr[0] = i; // If word2 is empty, we need to delete all characters of word1
        for (int j = 1; j <= m; j++) {
            if (word1[i - 1] == word2[j - 1]) {
                curr[j] = prev[j - 1]; // Characters match, move both pointers
            } else {
                int insertOp = 1 + curr[j - 1];    // Insert character
                int deleteOp = 1 + prev[j];        // Delete character
                int replaceOp = 1 + prev[j - 1];   // Replace character
                curr[j] = min({insertOp, deleteOp, replaceOp});
            }
        }
        prev = curr;
    }
    return prev[m];
}

int main() {
    string word1 = "intention";
    string word2 = "execution";

    cout << "Edit Distance (Recursion): " << minDistanceRecursion(word1, word2) << endl;
    cout << "Edit Distance (Memoization): " << minDistanceMemoization(word1, word2) << endl;
    cout << "Edit Distance (Tabulation): " << minDistanceTabulation(word1, word2) << endl;
    cout << "Edit Distance (Space Optimized): " << minDistanceSpaceOptimized(word1, word2) << endl;

    return 0;
}