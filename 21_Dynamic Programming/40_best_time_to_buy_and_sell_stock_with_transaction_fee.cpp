#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

int recursion(int index, vector<int>& prices, bool canBuy, int fee) {
    if (index >= prices.size()) {
        return 0;
    }

    if (canBuy) {
        int buy = -prices[index] + recursion(index + 1, prices, false, fee);
        int skip = recursion(index + 1, prices, true, fee);
        return max(buy, skip);
    } else {
        int sell = prices[index] + recursion(index + 1, prices, true, fee) - fee;
        int skip = recursion(index + 1, prices, false, fee);
        return max(sell, skip);
    }
}

int maxProfitRecursion(vector<int>& prices, int fee) {
    int n = prices.size();
    return recursion(0, prices, true, fee);
}

int memoization(int index, vector<int>& prices, bool canBuy, vector<vector<int>>& dp, int fee) {
    if (index >= prices.size()) {
        return 0;
    }

    if (dp[index][canBuy] != -1) {
        return dp[index][canBuy];
    }

    if (canBuy) {
        int buy = -prices[index] + memoization(index + 1, prices, false, dp, fee);
        int skip = memoization(index + 1, prices, true, dp, fee);
        dp[index][canBuy] = max(buy, skip);
    } else {
        int sell = prices[index] + memoization(index + 1, prices, true, dp, fee) - fee;
        int skip = memoization(index + 1, prices, false, dp, fee);
        dp[index][canBuy] = max(sell, skip);
    }

    return dp[index][canBuy];
}

int maxProfitMemoization(vector<int>& prices, int fee) {
    int n = prices.size();
    vector<vector<int>> dp(n, vector<int>(2, -1));
    return memoization(0, prices, true, dp, fee);
}

int maxProfitTabulation(vector<int>& prices, int fee) {
    int n = prices.size();
    vector<vector<int>> dp(n + 1, vector<int>(2, 0));

    for (int index = n - 1; index >= 0; --index) {
        for (int canBuy = 0; canBuy <= 1; ++canBuy) {
            if (canBuy) {
                int buy = -prices[index] + dp[index + 1][0];
                int skip = dp[index + 1][1];
                dp[index][canBuy] = max(buy, skip);
            } else {
                int sell = prices[index] + dp[index + 1][1] - fee;
                int skip = dp[index + 1][0];
                dp[index][canBuy] = max(sell, skip);
            }
        }
    }

    return dp[0][1];
}

int maxProfitSpaceOptimized(vector<int>& prices, int fee) {
    int n = prices.size();
    vector<int> ahead(2, 0), curr(2, 0);

    for (int index = n - 1; index >= 0; --index) {
        for (int canBuy = 0; canBuy <= 1; ++canBuy) {
            if (canBuy) {
                int buy = -prices[index] + ahead[0];
                int skip = ahead[1];
                curr[canBuy] = max(buy, skip);
            } else {
                int sell = prices[index] + ahead[1] - fee;
                int skip = ahead[0];
                curr[canBuy] = max(sell, skip);
            }
        }
        ahead = curr;
    }

    return ahead[1];
}

int main() {
    vector<int> prices = {1, 3, 2, 8, 4, 9};
    int fee = 2;

    cout << "Max Profit (Recursion): " << maxProfitRecursion(prices, fee) << endl;
    cout << "Max Profit (Memoization): " << maxProfitMemoization(prices, fee) << endl;
    cout << "Max Profit (Tabulation): " << maxProfitTabulation(prices, fee) << endl;
    cout << "Max Profit (Space Optimized): " << maxProfitSpaceOptimized(prices, fee) << endl;

    return 0;
}