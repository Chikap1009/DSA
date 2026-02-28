#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

string printLongestCommonSubsequence(string text1, string text2) {
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
    
    int len = dp[n][m];
    string lcs(len, ' ');
    int ind = len - 1;
    int i = n, j = m;
    while (i > 0 && j > 0) {
        if (text1[i - 1] == text2[j - 1]) {
            lcs[ind] = text1[i - 1];
            i--;
            j--;
            ind--;
        } else if (dp[i - 1][j] > dp[i][j - 1]) {
            i--;
        } else {
            j--;
        }
    }
    return lcs;
}

int main() {
    string text1 = "ABCDGH";
    string text2 = "AEDFHR";
    cout << printLongestCommonSubsequence(text1, text2) << endl;

    return 0;
}