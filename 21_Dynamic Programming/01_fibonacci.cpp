#include <bits/stdc++.h>
using namespace std;

int fibonacci_memoization(int n, vector<int>& dp) {
    if (n <= 1) {
        return n;
    }

    if (dp[n] != -1) return dp[n];

    return dp[n] = fibonacci_memoization(n - 1, dp) + fibonacci_memoization(n - 2, dp);
}

int fibonacci_tabulation(int n) {
    vector<int> dp(n + 1, 0);
    dp[0] = 0;
    dp[1] = 1;

    for (int i = 2; i <= n; ++i) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    return dp[n];
}

int fibonacci_space_optimized(int n) {
    if (n <= 1) return n;

    int prev2 = 0, prev1 = 1, current;
    for (int i = 2; i <= n; ++i) {
        current = prev1 + prev2;
        prev2 = prev1;
        prev1 = current;
    }

    return current;
}

int main() {

    vector<int> dp(6, -1);
    cout << fibonacci_memoization(5, dp) << endl;

    cout << fibonacci_tabulation(5) << endl;

    cout << fibonacci_space_optimized(5) << endl;

    return 0;
}