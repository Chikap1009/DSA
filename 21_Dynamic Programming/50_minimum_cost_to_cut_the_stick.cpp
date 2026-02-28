#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

int recursion(int i, int j, vector<int>& cuts) {
    if (i > j) return 0;

    int min_cost = INT_MAX;

    for (int ind = i; ind <= j; ind++) {
        int cost = (cuts[j + 1] - cuts[i - 1]) +
                   recursion(i, ind - 1, cuts) +
                   recursion(ind + 1, j, cuts);

        min_cost = min(min_cost, cost);
    }

    return min_cost;
}

int minCost(int n, vector<int> cuts) {
    int c = cuts.size();
    cuts.push_back(0);
    cuts.push_back(n);
    sort(cuts.begin(), cuts.end());
    return recursion(1, c, cuts);
}

int memoization(int i, int j, vector<int>& cuts, vector<vector<int>>& dp) {
    if (i > j) return 0;

    if (dp[i][j] != -1) return dp[i][j];

    int min_cost = INT_MAX;

    for (int ind = i; ind <= j; ind++) {
        int cost = (cuts[j + 1] - cuts[i - 1]) +
                   memoization(i, ind - 1, cuts, dp) +
                   memoization(ind + 1, j, cuts, dp);

        min_cost = min(min_cost, cost);
    }

    return dp[i][j] = min_cost;
}

int minCostMemoization(int n, vector<int> cuts) {
    int c = cuts.size();
    cuts.push_back(0);
    cuts.push_back(n);
    sort(cuts.begin(), cuts.end());
    vector<vector<int>> dp(c + 1, vector<int>(c + 1, -1));
    return memoization(1, c, cuts, dp);
}

int minCostTabulation(int n, vector<int> cuts) {
    int c = cuts.size();
    cuts.push_back(0);
    cuts.push_back(n);
    sort(cuts.begin(), cuts.end());
    vector<vector<int>> dp(c + 2, vector<int>(c + 2, 0));

    for (int i = c; i >= 1; i--) {
        for (int j = i; j <= c; j++) {
            int min_cost = INT_MAX;

            for (int ind = i; ind <= j; ind++) {
                int cost = (cuts[j + 1] - cuts[i - 1]) +
                           dp[i][ind - 1] +
                           dp[ind + 1][j];

                min_cost = min(min_cost, cost);
            }

            dp[i][j] = min_cost;
        }
    }

    return dp[1][c];
}

int main() {
    int n = 7;
    vector<int> cuts = {1, 3, 4, 5};

    cout << "Minimum cost using Recursion: " << minCost(n, cuts) << endl;
    cout << "Minimum cost using Memoization: " << minCostMemoization(n, cuts) << endl;
    cout << "Minimum cost using Tabulation: " << minCostTabulation(n, cuts) << endl;

    return 0;
}