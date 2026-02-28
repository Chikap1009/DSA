#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

int countSquares(vector<vector<int>>& matrix) {
    int m = matrix.size();
    int n = matrix[0].size();

    vector<vector<int>> dp(m, vector<int> (n, 0));
    int total = 0;

    for (int i=0 ; i<m ; i++) {
        dp[i][0] = matrix[i][0];
        total += dp[i][0];
    }
    for (int j=1 ; j<n ; j++) {
        dp[0][j] = matrix[0][j];
        total += dp[0][j];
    }

    for (int i=1 ; i<m ; i++) {
        for (int j=1 ; j<n ; j++) {
            if (matrix[i][j] == 1) {
                dp[i][j] = 1 + min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1]));
            }

            total += dp[i][j];
        }
    }

    return total;
}

int main() {
    vector<vector<int>> matrix = {
        {0,1,1,1},
        {1,1,1,1},
        {0,1,1,1}
    };

    cout << "Total square submatrices with all ones: " << countSquares(matrix) << endl;

    return 0;
}