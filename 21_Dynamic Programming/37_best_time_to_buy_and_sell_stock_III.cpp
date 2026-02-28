#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

int recursion(int i, vector<int>& prices, int k, int buy) {
    if (i >= prices.size() || k == 0) {
        return 0;
    }

    if (buy) {
        int buyStock = -prices[i] + recursion(i + 1, prices, k, 0);
        int skip = recursion(i + 1, prices, k, 1);
        return max(buyStock, skip);
    } else {
        int sellStock = prices[i] + recursion(i + 1, prices, k - 1, 1);
        int skip = recursion(i + 1, prices, k, 0);
        return max(sellStock, skip);
    }
}

int maxProfitRecursion(vector<int>& prices) {
    int n = prices.size();
    return recursion(0, prices, 2, 1);
}

int memoization(int i, vector<int>& prices, int k, int buy, vector<vector<vector<int>>>& dp) {
    if (i >= prices.size() || k == 0) {
        return 0;
    }

    if (dp[i][k][buy] != -1) {
        return dp[i][k][buy];
    }

    if (buy) {
        int buyStock = -prices[i] + memoization(i + 1, prices, k, 0, dp);
        int skip = memoization(i + 1, prices, k, 1, dp);
        dp[i][k][buy] = max(buyStock, skip);
    } else {
        int sellStock = prices[i] + memoization(i + 1, prices, k - 1, 1, dp);
        int skip = memoization(i + 1, prices, k, 0, dp);
        dp[i][k][buy] = max(sellStock, skip);
    }

    return dp[i][k][buy];
}

int maxProfitMemoization(vector<int>& prices) {
    int n = prices.size();
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(3, vector<int>(2, -1)));
    return memoization(0, prices, 2, 1, dp);
}

int maxProfitTabulation(vector<int>& prices) {
    int n = prices.size();
    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(3, vector<int>(2, 0)));

    for (int i = n - 1; i >= 0; --i) {
        for (int k = 1; k <= 2; ++k) {
            for (int buy = 0; buy <= 1; ++buy) {
                if (buy) {
                    int buyStock = -prices[i] + dp[i + 1][k][0];
                    int skip = dp[i + 1][k][1];
                    dp[i][k][buy] = max(buyStock, skip);
                } else {
                    int sellStock = prices[i] + dp[i + 1][k - 1][1];
                    int skip = dp[i + 1][k][0];
                    dp[i][k][buy] = max(sellStock, skip);
                }
            }
        }
    }

    return dp[0][2][1];
}

int maxProfitSpaceOptimized(vector<int>& prices) {
    int n = prices.size();
    vector<vector<int>> ahead(3, vector<int>(2, 0));

    for (int i = n - 1; i >= 0; --i) {
        vector<vector<int>> curr(3, vector<int>(2, 0));
        for (int k = 1; k <= 2; ++k) {
            for (int buy = 0; buy <= 1; ++buy) {
                if (buy) {
                    int buyStock = -prices[i] + ahead[k][0];
                    int skip = ahead[k][1];
                    curr[k][buy] = max(buyStock, skip);
                } else {
                    int sellStock = prices[i] + ahead[k - 1][1];
                    int skip = ahead[k][0];
                    curr[k][buy] = max(sellStock, skip);
                }
            }
        }
        ahead = curr;
    }

    return ahead[2][1];
}

int main() {
    vector<int> prices = {3, 3, 5, 0, 0, 3, 1, 4};

    cout << "Max Profit (Recursion): " << maxProfitRecursion(prices) << endl;
    cout << "Max Profit (Memoization): " << maxProfitMemoization(prices) << endl;
    cout << "Max Profit (Tabulation): " << maxProfitTabulation(prices) << endl;
    cout << "Max Profit (Space Optimized): " << maxProfitSpaceOptimized(prices) << endl;

    return 0;
}