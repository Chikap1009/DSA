#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

int matrixMultiplicationBottomUp(vector<int>& dimensions) {
    int n = dimensions.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));

    for (int i = n - 1; i >= 1; i--) {
        for (int j = i + 1; j < n; j++) {
            dp[i][j] = INT_MAX;
            for (int k = i; k < j; k++) {
                int costLeft = dp[i][k];
                int costRight = dp[k + 1][j];
                int costMultiply = dimensions[i - 1] * dimensions[k] * dimensions[j];
                int totalCost = costLeft + costRight + costMultiply;

                dp[i][j] = min(dp[i][j], totalCost);
            }
        }
    }

    return dp[1][n - 1];
}

int main() {
    vector<int> dimensions = {10, 20, 30, 40, 30};
    cout << "Minimum number of multiplications (Bottom-Up): "
         << matrixMultiplicationBottomUp(dimensions) << endl;
    return 0;
}