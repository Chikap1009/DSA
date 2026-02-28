#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

int recursion(int index, vector<int>& prices, bool canBuy) {
    if (index >= prices.size()) {
        return 0;
    }

    if (canBuy) {
        int buy = -prices[index] + recursion(index + 1, prices, false);
        int skip = recursion(index + 1, prices, true);
        return max(buy, skip);
    } else {
        int sell = prices[index] + recursion(index + 1, prices, true);
        int skip = recursion(index + 1, prices, false);
        return max(sell, skip);
    }
}

int maxProfitRecursion(vector<int>& prices) {
    int n = prices.size();
    return recursion(0, prices, true);
}

int memoization(int index, vector<int>& prices, bool canBuy, vector<vector<int>>& dp) {
    if (index >= prices.size()) {
        return 0;
    }

    if (dp[index][canBuy] != -1) {
        return dp[index][canBuy];
    }

    if (canBuy) {
        int buy = -prices[index] + memoization(index + 1, prices, false, dp);
        int skip = memoization(index + 1, prices, true, dp);
        dp[index][canBuy] = max(buy, skip);
    } else {
        int sell = prices[index] + memoization(index + 1, prices, true, dp);
        int skip = memoization(index + 1, prices, false, dp);
        dp[index][canBuy] = max(sell, skip);
    }

    return dp[index][canBuy];
}

int maxProfitMemoization(vector<int>& prices) {
    int n = prices.size();
    vector<vector<int>> dp(n, vector<int>(2, -1));
    return memoization(0, prices, true, dp);
}

int maxProfitTabulation(vector<int>& prices) {
    int n = prices.size();
    vector<vector<int>> dp(n + 1, vector<int>(2, 0));

    for (int index = n - 1; index >= 0; --index) {
        for (int canBuy = 0; canBuy <= 1; ++canBuy) {
            if (canBuy) {
                int buy = -prices[index] + dp[index + 1][0];
                int skip = dp[index + 1][1];
                dp[index][canBuy] = max(buy, skip);
            } else {
                int sell = prices[index] + dp[index + 1][1];
                int skip = dp[index + 1][0];
                dp[index][canBuy] = max(sell, skip);
            }
        }
    }

    return dp[0][1];
}

int maxProfitSpaceOptimized(vector<int>& prices) {
    int n = prices.size();
    vector<int> ahead(2, 0), curr(2, 0);

    for (int index = n - 1; index >= 0; --index) {
        for (int canBuy = 0; canBuy <= 1; ++canBuy) {
            if (canBuy) {
                int buy = -prices[index] + ahead[0];
                int skip = ahead[1];
                curr[canBuy] = max(buy, skip);
            } else {
                int sell = prices[index] + ahead[1];
                int skip = ahead[0];
                curr[canBuy] = max(sell, skip);
            }
        }
        ahead = curr;
    }

    return ahead[1];
}

int main() {
    vector<int> prices = {7, 1, 5, 3, 6, 4};

    cout << "Max Profit (Recursion): " << maxProfitRecursion(prices) << endl;
    cout << "Max Profit (Memoization): " << maxProfitMemoization(prices) << endl;
    cout << "Max Profit (Tabulation): " << maxProfitTabulation(prices) << endl;
    cout << "Max Profit (Space Optimized): " << maxProfitSpaceOptimized(prices) << endl;

    return 0;
}