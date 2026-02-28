#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

int recursion(vector<int>& coins, int index, int amount) {
    if (index == 0) {
        if (amount % coins[0] == 0) return 1;
        return 0;
    }

    int notTake = recursion(coins, index-1, amount);
    int take = 0;
    if (coins[index] <= amount) take = recursion(coins, index, amount - coins[index]);
    return take + notTake;
}

int changeRecursion(int amount, vector<int>& coins) {
    int n = coins.size();
    return recursion(coins, n-1, amount);
}

int memoization(vector<int>& coins, int index, int amount, vector<vector<int>>& dp) {
    if (index == 0) {
        if (amount % coins[0] == 0) return 1;
        return 0;
    }
    if (dp[index][amount] != -1) return dp[index][amount];

    int notTake = memoization(coins, index-1, amount, dp);
    int take = 0;
    if (coins[index] <= amount) take = memoization(coins, index, amount - coins[index], dp);
    return dp[index][amount] = take + notTake;
}

int changeMemoization(int amount, vector<int>& coins) {
    int n = coins.size();
    vector<vector<int>> dp(n, vector<int>(amount+1, -1));
    return memoization(coins, n-1, amount, dp);
}

int changeTabulation(int amount, vector<int>& coins) {
    int n = coins.size();
    vector<vector<unsigned int>> dp(n, vector<unsigned int>(amount+1, 0));
    for (int amt = 0 ; amt <= amount ; amt++) {
        if (amt % coins[0] == 0) dp[0][amt] = 1;
    }
    for (int index = 1 ; index < n ; index++) {
        for (int amt = 0 ; amt <= amount ; amt++) {
            unsigned int notTake = dp[index-1][amt];
            unsigned int take = 0;
            if (coins[index] <= amt) take = dp[index][amt - coins[index]];
            dp[index][amt] = notTake + take;
        }
    }
    return dp[n-1][amount];
}

int changeSpaceOptimized(int amount, vector<int>& coins) {
    int n = coins.size();
    vector<unsigned int> prev(amount+1, 0);
    for (int amt = 0 ; amt <= amount ; amt++) {
        if (amt % coins[0] == 0) prev[amt] = 1;
    }
    for (int index = 1 ; index < n ; index++) {
        vector<unsigned int> curr(amount+1, 0);
        for (int amt = 0 ; amt <= amount ; amt++) {
            unsigned int notTake = prev[amt];
            unsigned int take = 0;
            if (coins[index] <= amt) take = curr[amt - coins[index]];
            curr[amt] = notTake + take;
        }
        prev = curr;
    }
    return prev[amount];
}

int main() {
    int amount = 5;
    vector<int> coins = {1, 2, 5};

    cout << "Number of combinations (Recursion): " << changeRecursion(amount, coins) << endl;
    cout << "Number of combinations (Memoization): " << changeMemoization(amount, coins) << endl;
    cout << "Number of combinations (Tabulation): " << changeTabulation(amount, coins) << endl;
    cout << "Number of combinations (Space Optimized): " << changeSpaceOptimized(amount, coins) << endl;

    return 0;
}