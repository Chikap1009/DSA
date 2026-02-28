#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

int recursion(vector<int>& coins, int index, int amount) {
    if (index == 0) {
        if (amount % coins[0] == 0) {
            return amount / coins[0];
        } else {
            return 1e9;
        }
    }

    int notTake = recursion(coins, index - 1, amount);
    int take = 1e9;
    if (coins[index] <= amount) {
        take = 1 + recursion(coins, index, amount - coins[index]);
    }
    return min(take, notTake);
}

int coinChangeRecursion(vector<int>& coins, int amount) {
    int n = coins.size();
    int result = recursion(coins, n - 1, amount);
    if (result >= 1e9) {
        return -1;
    }
    return result; 
}

int memoization(vector<int>& coins, int index, int amount, vector<vector<int>>& dp) {
    if (index == 0) {
        if (amount % coins[0] == 0) {
            return amount / coins[0];
        } else {
            return 1e9;
        }
    }

    if (dp[index][amount] != -1) {
        return dp[index][amount];
    }

    int notTake = memoization(coins, index - 1, amount, dp);
    int take = 1e9;
    if (coins[index] <= amount) {
        take = 1 + memoization(coins, index, amount - coins[index], dp);
    }
    dp[index][amount] = min(take, notTake);
    return dp[index][amount];
}

int coinChangeMemoization(vector<int>& coins, int amount) {
    int n = coins.size();
    vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
    int result = memoization(coins, n - 1, amount, dp);
    if (result >= 1e9) {
        return -1;
    }
    return result;
}

int coinChangeTabulation(vector<int>& coins, int amount) {
    int n = coins.size();
    vector<vector<int>> dp(n, vector<int>(amount + 1, 0));

    for (int amt = 0; amt <= amount; ++amt) {
        if (amt % coins[0] == 0) {
            dp[0][amt] = amt / coins[0];
        } else {
            dp[0][amt] = 1e9;
        }
    }

    for (int index = 1; index < n; ++index) {
        for (int amt = 0; amt <= amount; ++amt) {
            int notTake = dp[index - 1][amt];
            int take = 1e9;
            if (coins[index] <= amt) {
                take = 1 + dp[index][amt - coins[index]];
            }
            dp[index][amt] = min(take, notTake);
        }
    }
    int result = dp[n - 1][amount];
    if (result >= 1e9) {
        return -1;
    }
    return result;
}

int coinChangeSpaceOptimized(vector<int>& coins, int amount) {
    int n = coins.size();
    vector<int> prev(amount + 1, 0);

    for (int amt = 0; amt <= amount; ++amt) {
        if (amt % coins[0] == 0) {
            prev[amt] = amt / coins[0];
        } else {
            prev[amt] = 1e9;
        }
    }

    for (int index = 1; index < n; ++index) {
        vector<int> curr(amount + 1, 0);
        for (int amt = 0; amt <= amount; ++amt) {
            int notTake = prev[amt];
            int take = 1e9;
            if (coins[index] <= amt) {
                take = 1 + curr[amt - coins[index]];
            }
            curr[amt] = min(take, notTake);
        }
        prev = curr;
    }
    int result = prev[amount];
    if (result >= 1e9) {
        return -1;
    }
    return result;
}

int main() {
    vector<int> coins = {1, 2, 5};
    int amount = 11;

    cout << "Minimum coins (Recursion): " << coinChangeRecursion(coins, amount) << endl;
    cout << "Minimum coins (Memoization): " << coinChangeMemoization(coins, amount) << endl;
    cout << "Minimum coins (Tabulation): " << coinChangeTabulation(coins, amount) << endl;
    cout << "Minimum coins (Space Optimized): " << coinChangeSpaceOptimized(coins, amount) << endl;

    return 0;
}