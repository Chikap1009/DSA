#include <bits/stdc++.h>
using namespace std;

int minEnergyTillInd(vector<int>& heights, vector<int>& dp, int ind, int k) {
    if (ind == 0) return 0;
    if (dp[ind] != -1) return dp[ind];

    int minEnergy = INT_MAX;
    for (int j=1 ; j<=k ; j++) {
        if (ind - j < 0) break;
        int energy = minEnergyTillInd(heights, dp, ind - j, k) + abs(heights[ind] - heights[ind - j]);
        minEnergy = min(minEnergy, energy);
    }

    return dp[ind] = minEnergy;
}

int frogJump_memoization(vector<int>& heights, int k) {
    int n = heights.size();
    vector<int> dp(n, -1);

    return minEnergyTillInd(heights, dp, n-1, k);
}

int frogJump_tabulation(vector<int>& heights, int k) {
    int n = heights.size();
    vector<int> dp(n, 0);
    
    for (int i = 1 ; i < n ; i++) {
        int minEnergy = INT_MAX;
        for (int j = 1 ; j <= k ; j++) {
            if (i - j < 0) break;
            int energy = dp[i - j] + abs(heights[i] - heights[i - j]);
            minEnergy = min(minEnergy, energy);
        }
        dp[i] = minEnergy;
    }
    
    return dp[n-1];
}

int main() {
    vector<int> heights = {10, 30, 40, 20, 50};
    int k = 2; // Maximum distance the frog can jump
    cout << "Minimum energy required (Memoization): " << frogJump_memoization(heights, k) << endl;
    cout << "Minimum energy required (Tabulation): " << frogJump_tabulation(heights, k) << endl;
    return 0;
}