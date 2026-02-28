#include <bits/stdc++.h>
using namespace std;

int minEnergy(vector<int>& heights, vector<int>& dp, int ind) {
    if (ind == 0) return 0;
    if (dp[ind] != -1) return dp[ind];

    int left = minEnergy(heights, dp, ind-1) + abs(heights[ind] - heights[ind-1]);
    int right = INT_MAX;
    if (ind > 1) {
        right = minEnergy(heights, dp, ind-2) + abs(heights[ind] - heights[ind-2]);
    }

    return dp[ind] = min(left, right);
}

int frogJump_memoization(vector<int>& heights) {
    int n = heights.size();
    vector<int> dp(n, -1);

    return minEnergy(heights, dp, n-1);
}

int frogJump_tabulation(vector<int>& heights) {
    int n = heights.size();
    vector<int> dp(n, 0);
    
    for (int i = 1 ; i < n ; i++) {
        int left = dp[i-1] + abs(heights[i] - heights[i-1]);
        int right = INT_MAX;
        if (i > 1) {
            right = dp[i-2] + abs(heights[i] - heights[i-2]);
        }
        dp[i] = min(left, right);
    }
    
    return dp[n-1];
}

int frogJump_space_optimized(vector<int>& heights) {
    int n = heights.size();
    int prev2 = 0, prev1 = 0;

    for (int i = 1 ; i < n ; i++) {
        int left = prev1 + abs(heights[i] - heights[i-1]);
        int right = INT_MAX;
        if (i > 1) {
            right = prev2 + abs(heights[i] - heights[i-2]);
        }
        int curr = min(left, right);
        prev2 = prev1;
        prev1 = curr;
    }

    return prev1;
}

int main() {
    vector<int> heights = {10, 30, 40, 20, 50};
    cout << "Minimum energy required (Memoization): " << frogJump_memoization(heights) << endl;
    cout << "Minimum energy required (Tabulation): " << frogJump_tabulation(heights) << endl;
    cout << "Minimum energy required (Space Optimized): " << frogJump_space_optimized(heights) << endl;
    return 0;
}