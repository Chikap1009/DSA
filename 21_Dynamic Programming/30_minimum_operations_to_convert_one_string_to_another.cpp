#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

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

int minDistance(string word1, string word2) {
    int lcs = longestCommonSubsequenceSpaceOptimization(word1, word2);
    int deletions1 = word1.size() - lcs;
    int deletions2 = word2.size() - lcs;
    return deletions1 + deletions2;
}

int main() {
    string word1 = "sea";
    string word2 = "eat";
    cout << minDistance(word1, word2) << endl;

    return 0;
}