#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

int recursion(int i, vector<int>& prices, int transactionNo, int k) {
    if (i >= prices.size() || transactionNo == 2 * k) {
        return 0;
    }

    if (transactionNo % 2 == 0) {
        int buyStock = -prices[i] + recursion(i + 1, prices, transactionNo + 1, k);
        int skip = recursion(i + 1, prices, transactionNo, k);
        return max(buyStock, skip);
    } else {
        int sellStock = prices[i] + recursion(i + 1, prices, transactionNo + 1, k);
        int skip = recursion(i + 1, prices, transactionNo, k);
        return max(sellStock, skip);
    }

}

int maxProfitRecursion(vector<int>& prices, int k) {
    int n = prices.size();
    return recursion(0, prices, 0, k);
}

int memoization(int i, vector<int>& prices, int transactionNo, int k, vector<vector<int>>& dp) {
    if (i >= prices.size() || transactionNo == 2 * k) {
        return 0;
    }

    if (dp[i][transactionNo] != -1) {
        return dp[i][transactionNo];
    }

    if (transactionNo % 2 == 0) {
        int buyStock = -prices[i] + memoization(i + 1, prices, transactionNo + 1, k, dp);
        int skip = memoization(i + 1, prices, transactionNo, k, dp);
        dp[i][transactionNo] = max(buyStock, skip);
    } else {
        int sellStock = prices[i] + memoization(i + 1, prices, transactionNo + 1, k, dp);
        int skip = memoization(i + 1, prices, transactionNo, k, dp);
        dp[i][transactionNo] = max(sellStock, skip);
    }

    return dp[i][transactionNo];
}

int maxProfitMemoization(vector<int>& prices, int k) {
    int n = prices.size();
    vector<vector<int>> dp(n, vector<int>(2 * k, -1));
    return memoization(0, prices, 0, k, dp);
}

int maxProfitTabulation(vector<int>& prices, int k) {
    int n = prices.size();
    vector<vector<int>> dp(n + 1, vector<int>(2 * k + 1, 0));

    for (int i = n - 1; i >= 0; --i) {
        for (int transactionNo = 0; transactionNo < 2 * k; ++transactionNo) {
            if (transactionNo % 2 == 0) {
                int buyStock = -prices[i] + dp[i + 1][transactionNo + 1];
                int skip = dp[i + 1][transactionNo];
                dp[i][transactionNo] = max(buyStock, skip);
            } else {
                int sellStock = prices[i] + dp[i + 1][transactionNo + 1];
                int skip = dp[i + 1][transactionNo];
                dp[i][transactionNo] = max(sellStock, skip);
            }
        }
    }

    return dp[0][0];
}

int maxProfitSpaceOptimized(vector<int>& prices, int k) {
    int n = prices.size();
    vector<int> next(2 * k + 1, 0);

    for (int i = n - 1; i >= 0; --i) {
        vector<int> curr(2 * k + 1, 0);
        for (int transactionNo = 0; transactionNo < 2 * k; ++transactionNo) {
            if (transactionNo % 2 == 0) {
                int buyStock = -prices[i] + next[transactionNo + 1];
                int skip = next[transactionNo];
                curr[transactionNo] = max(buyStock, skip);
            } else {
                int sellStock = prices[i] + next[transactionNo + 1];
                int skip = next[transactionNo];
                curr[transactionNo] = max(sellStock, skip);
            }
        }
        next = curr;
    }

    return next[0];
}

int main() {
    vector<int> prices = {3, 2, 6, 5, 0, 3};
    int k = 2;

    cout << "Max Profit (Recursion): " << maxProfitRecursion(prices, k) << endl;
    cout << "Max Profit (Memoization): " << maxProfitMemoization(prices, k) << endl;
    cout << "Max Profit (Tabulation): " << maxProfitTabulation(prices, k) << endl;
    cout << "Max Profit (Space Optimized): " << maxProfitSpaceOptimized(prices, k) << endl;

    return 0;
}