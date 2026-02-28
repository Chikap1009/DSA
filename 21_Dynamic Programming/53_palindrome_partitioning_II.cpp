#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

bool isPalindrome(string& s, int left, int right) {
    while (left < right) {
        if (s[left] != s[right]) return false;
        ++left;
        --right;
    }
    return true;
}

int recursion(string& s, int start) {
    int n = s.size();
    if (start >= n) return 0;

    int minCuts = INT_MAX;
    for (int end = start; end < n; ++end) {
        if (isPalindrome(s, start, end)) {
            int cuts = 1 + recursion(s, end + 1);
            minCuts = min(minCuts, cuts);
        }
    }
    return minCuts;
}

int minCutsRecursion(string s) {
    int n = s.size();
    return recursion(s, 0) - 1;
}

int memoization(string& s, int start, vector<int>& dp) {
    int n = s.size();
    if (start >= n) return 0;
    if (dp[start] != -1) return dp[start];

    int minCuts = INT_MAX;
    for (int end = start; end < n; ++end) {
        if (isPalindrome(s, start, end)) {
            int cuts = 1 + memoization(s, end + 1, dp);
            minCuts = min(minCuts, cuts);
        }
    }
    dp[start] = minCuts;
    return dp[start];
}

int minCutsMemoization(string& s) {
    int n = s.size();
    vector<int> dp(n, -1);
    return memoization(s, 0, dp) - 1;
}

int minCutsTabulation(string& s) {
    int n = s.size();
    vector<int> dp(n + 1, 0);
    dp[n] = 0;

    for (int start = n - 1; start >= 0; --start) {
        int minCuts = INT_MAX;
        for (int end = start; end < n; ++end) {
            if (isPalindrome(s, start, end)) {
                int cuts = 1 + dp[end + 1];
                minCuts = min(minCuts, cuts);
            }
        }
        dp[start] = minCuts;
    }
    return dp[0] - 1;
}

int main() {
    string s = "aab";
    cout << "Minimum cuts (Recursion): " << minCutsRecursion(s) << endl;
    cout << "Minimum cuts (Memoization): " << minCutsMemoization(s) << endl;
    cout << "Minimum cuts (Tabulation): " << minCutsTabulation(s) << endl;
    return 0;
}