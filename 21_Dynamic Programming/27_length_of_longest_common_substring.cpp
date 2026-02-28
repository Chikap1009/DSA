#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

int LongestCommonSubstring(string text1, string text2) {
    int n = text1.size();
    int m = text2.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (text1[i - 1] == text2[j - 1]) {
                dp[i][j] = 1 + dp[i - 1][j - 1];
                ans = max(ans, dp[i][j]);
            } else {
                dp[i][j] = 0;
            }
        }
    }
    return ans;
}

int main() {
    string text1 = "ABABC";
    string text2 = "BABCAB";
    cout << LongestCommonSubstring(text1, text2) << endl;

    return 0;
}