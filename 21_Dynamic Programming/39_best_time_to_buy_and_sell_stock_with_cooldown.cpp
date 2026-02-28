#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

int recursion(vector<int>& prices, int index, bool canBuy) {
    if (index >= prices.size()) {
        return 0;
    }

    int profit = 0;
    if (canBuy) {
        int buy = -prices[index] + recursion(prices, index + 1, false);
        int skip = recursion(prices, index + 1, true);
        profit = max(buy, skip);
    } else {
        int sell = prices[index] + recursion(prices, index + 2, true);
        int skip = recursion(prices, index + 1, false);
        profit = max(sell, skip);
    }
    return profit;
}

int maxProfitRecursion(vector<int>& prices) {
    int n = prices.size();
    return recursion(prices, 0, true);
}

int memoization(vector<int>& prices, int index, bool canBuy, vector<vector<int>>& dp) {
    if (index >= prices.size()) {
        return 0;
    }

    if (dp[index][canBuy] != -1) {
        return dp[index][canBuy];
    }

    int profit = 0;
    if (canBuy) {
        int buy = -prices[index] + memoization(prices, index + 1, false, dp);
        int skip = memoization(prices, index + 1, true, dp);
        profit = max(buy, skip);
    } else {
        int sell = prices[index] + memoization(prices, index + 2, true, dp);
        int skip = memoization(prices, index + 1, false, dp);
        profit = max(sell, skip);
    }
    dp[index][canBuy] = profit;
    return profit;
}

int maxProfitMemoization(vector<int>& prices) {
    int n = prices.size();
    vector<vector<int>> dp(n, vector<int>(2, -1));
    return memoization(prices, 0, true, dp);
}

int maxProfitTabulation(vector<int>& prices) {
    int n = prices.size();
    vector<vector<int>> dp(n + 2, vector<int>(2, 0));

    for (int index = n - 1; index >= 0; --index) {
        for (int canBuy = 0; canBuy <= 1; ++canBuy) {
            int profit = 0;
            if (canBuy) {
                int buy = -prices[index] + dp[index + 1][0];
                int skip = dp[index + 1][1];
                profit = max(buy, skip);
            } else {
                int sell = prices[index] + dp[index + 2][1];
                int skip = dp[index + 1][0];
                profit = max(sell, skip);
            }
            dp[index][canBuy] = profit;
        }
    }

    return dp[0][1];
}

int maxProfitSpaceOptimized(vector<int>& prices) {
    int n = prices.size();
    vector<int> ahead2(2, 0);
    vector<int> ahead1(2, 0);

    for (int index = n - 1; index >= 0; --index) {
        vector<int> curr(2, 0);
        for (int canBuy = 0; canBuy <= 1; ++canBuy) {
            int profit = 0;
            if (canBuy) {
                int buy = -prices[index] + ahead1[0];
                int skip = ahead1[1];
                profit = max(buy, skip);
            } else {
                int sell = prices[index] + ahead2[1];
                int skip = ahead1[0];
                profit = max(sell, skip);
            }
            curr[canBuy] = profit;
        }
        ahead2 = ahead1;
        ahead1 = curr;
    }

    return ahead1[1];
}

int main() {
    vector<int> prices = {1, 2, 3, 0, 2};

    cout << "Max Profit (Recursion): " << maxProfitRecursion(prices) << endl;
    cout << "Max Profit (Memoization): " << maxProfitMemoization(prices) << endl;
    cout << "Max Profit (Tabulation): " << maxProfitTabulation(prices) << endl;
    cout << "Max Profit (Space Optimized): " << maxProfitSpaceOptimized(prices) << endl;

    return 0;
}