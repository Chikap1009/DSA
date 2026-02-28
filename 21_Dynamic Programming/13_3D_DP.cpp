#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int recursion(vector<vector<int>>& grid, int r, int c1, int c2) {
    if (r == grid.size() - 1) {
        if (c1 == c2) {
            return grid[r][c1];
        } else {
            return grid[r][c1] + grid[r][c2];
        }
    }

    int maxChocolates = INT_MIN;
    for (int dc1 = -1; dc1 <= 1; dc1++) {
        for (int dc2 = -1; dc2 <= 1; dc2++) {
            int newC1 = c1 + dc1;
            int newC2 = c2 + dc2;

            if (newC1 >= 0 && newC1 < grid[0].size() && newC2 >= 0 && newC2 < grid[0].size()) {
                int chocolates = 0;
                if (c1 == c2) {
                    chocolates += grid[r][c1];
                } else {
                    chocolates += grid[r][c1] + grid[r][c2];
                }
                chocolates += recursion(grid, r + 1, newC1, newC2);
                maxChocolates = max(maxChocolates, chocolates);
            }
        }
    }
    return maxChocolates;
}

int ninjaAndHisFriendsRecursion(vector<vector<int>> &grid) {
    int n = grid.size();
    int m = grid[0].size();
    return recursion(grid, 0, 0, m - 1);
}

int memoization(vector<vector<int>>& grid, int r, int c1, int c2, vector<vector<vector<int>>>& dp) {
    if (r == grid.size() - 1) {
        if (c1 == c2) {
            return grid[r][c1];
        } else {
            return grid[r][c1] + grid[r][c2];
        }
    }

    if (dp[r][c1][c2] != -1) {
        return dp[r][c1][c2];
    }

    int maxChocolates = INT_MIN;
    for (int dc1 = -1; dc1 <= 1; dc1++) {
        for (int dc2 = -1; dc2 <= 1; dc2++) {
            int newC1 = c1 + dc1;
            int newC2 = c2 + dc2;

            if (newC1 >= 0 && newC1 < grid[0].size() && newC2 >= 0 && newC2 < grid[0].size()) {
                int chocolates = 0;
                if (c1 == c2) {
                    chocolates += grid[r][c1];
                } else {
                    chocolates += grid[r][c1] + grid[r][c2];
                }
                chocolates += memoization(grid, r + 1, newC1, newC2, dp);
                maxChocolates = max(maxChocolates, chocolates);
            }
        }
    }
    return dp[r][c1][c2] = maxChocolates;
}

int ninjaAndHisFriendsMemoization(vector<vector<int>> &grid) {
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, -1)));
    return memoization(grid, 0, 0, m - 1, dp);
}

int ninjaAndHisFriendsTabulation(vector<vector<int>> &grid) {
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, 0)));

    for (int c1 = 0; c1 < m; c1++) {
        for (int c2 = 0; c2 < m; c2++) {
            if (c1 == c2) {
                dp[n - 1][c1][c2] = grid[n - 1][c1];
            } else {
                dp[n - 1][c1][c2] = grid[n - 1][c1] + grid[n - 1][c2];
            }
        }
    }

    for (int r = n - 2; r >= 0; r--) {
        for (int c1 = 0; c1 < m; c1++) {
            for (int c2 = 0; c2 < m; c2++) {
                int maxChocolates = INT_MIN;
                for (int dc1 = -1; dc1 <= 1; dc1++) {
                    for (int dc2 = -1; dc2 <= 1; dc2++) {
                        int newC1 = c1 + dc1;
                        int newC2 = c2 + dc2;

                        if (newC1 >= 0 && newC1 < m && newC2 >= 0 && newC2 < m) {
                            int chocolates = 0;
                            if (c1 == c2) {
                                chocolates += grid[r][c1];
                            } else {
                                chocolates += grid[r][c1] + grid[r][c2];
                            }
                            chocolates += dp[r + 1][newC1][newC2];
                            maxChocolates = max(maxChocolates, chocolates);
                        }
                    }
                }
                dp[r][c1][c2] = maxChocolates;
            }
        }
    }

    return dp[0][0][m - 1];
}

int ninjaAndHisFriendsSpaceOptimized(vector<vector<int>> &grid) {
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> front(m, vector<int>(m, 0));

    for (int c1 = 0; c1 < m; c1++) {
        for (int c2 = 0; c2 < m; c2++) {
            if (c1 == c2) {
                front[c1][c2] = grid[n - 1][c1];
            } else {
                front[c1][c2] = grid[n - 1][c1] + grid[n - 1][c2];
            }
        }
    }

    for (int r = n - 2; r >= 0; r--) {
        vector<vector<int>> curr(m, vector<int>(m, 0));
        for (int c1 = 0; c1 < m; c1++) {
            for (int c2 = 0; c2 < m; c2++) {
                int maxChocolates = INT_MIN;
                for (int dc1 = -1; dc1 <= 1; dc1++) {
                    for (int dc2 = -1; dc2 <= 1; dc2++) {
                        int newC1 = c1 + dc1;
                        int newC2 = c2 + dc2;

                        if (newC1 >= 0 && newC1 < m && newC2 >= 0 && newC2 < m) {
                            int chocolates = 0;
                            if (c1 == c2) {
                                chocolates += grid[r][c1];
                            } else {
                                chocolates += grid[r][c1] + grid[r][c2];
                            }
                            chocolates += front[newC1][newC2];
                            maxChocolates = max(maxChocolates, chocolates);
                        }
                    }
                }
                curr[c1][c2] = maxChocolates;
            }
        }
        front = curr;
    }

    return front[0][m - 1];
}

int main() {
    vector<vector<int>> grid = {
        {2, 3, 1, 2},
        {3, 4, 2, 2},
        {5, 6, 3, 5}
    };

    cout << "Recursion: " << ninjaAndHisFriendsRecursion(grid) << endl;
    cout << "Memoization: " << ninjaAndHisFriendsMemoization(grid) << endl;
    cout << "Tabulation: " << ninjaAndHisFriendsTabulation(grid) << endl;
    cout << "Space Optimized: " << ninjaAndHisFriendsSpaceOptimized(grid) << endl;

    return 0;
}