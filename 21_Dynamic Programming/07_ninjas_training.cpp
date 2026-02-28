#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int recursion(int day, int last, vector<vector<int>> &points) {
    if (day == 0) {
        int maxi = 0;
        for (int task = 0; task < 3; task++) {
            if (task != last) {
                maxi = max(maxi, points[0][task]);
            }
        }
        return maxi;
    }

    int maxi = 0;
    for (int task = 0; task < 3; task++) {
        if (task != last) {
            int point = points[day][task] + recursion(day - 1, task, points);
            maxi = max(maxi, point);
        }
    }
    return maxi;
}

int ninjaTrainingRecursion(vector<vector<int>> &points) {
    int n = points.size();
    return recursion(n-1, 3, points);
}

int recursionMemoization(int day, int last, vector<vector<int>> &points, vector<vector<int>> &dp) {
    if (day == 0) {
        int maxi = 0;
        for (int task = 0; task < 3; task++) {
            if (task != last) {
                maxi = max(maxi, points[0][task]);
            }
        }
        return maxi;
    }

    if (dp[day][last] != -1) {
        return dp[day][last];
    }

    int maxi = 0;
    for (int task = 0; task < 3; task++) {
        if (task != last) {
            int point = points[day][task] + recursionMemoization(day - 1, task, points, dp);
            maxi = max(maxi, point);
        }
    }
    return dp[day][last] = maxi;
}

int ninjaTrainingMemoization(vector<vector<int>> &points) {
    int n = points.size();
    vector<vector<int>> dp(n, vector<int>(4, -1));
    return recursionMemoization(n-1, 3, points, dp);
}

int ninjaTrainingTabulation(vector<vector<int>> &points) {
    int n = points.size();
    vector<vector<int>> dp(n, vector<int>(4, 0));

    // Base case
    dp[0][0] = max(points[0][1], points[0][2]);
    dp[0][1] = max(points[0][0], points[0][2]);
    dp[0][2] = max(points[0][0], points[0][1]);
    dp[0][3] = max(points[0][0], max(points[0][1], points[0][2]));

    for (int day = 1; day < n; day++) {
        for (int last = 0; last < 4; last++) {
            dp[day][last] = 0;
            for (int task = 0; task < 3; task++) {
                if (task != last) {
                    int point = points[day][task] + dp[day - 1][task];
                    dp[day][last] = max(dp[day][last], point);
                }
            }
        }
    }

    return dp[n - 1][3];
}

int ninjaTrainingSpaceOptimization(vector<vector<int>> &points) {
    int n = points.size();
    vector<int> prev(4, 0);

    // Base case
    prev[0] = max(points[0][1], points[0][2]);
    prev[1] = max(points[0][0], points[0][2]);
    prev[2] = max(points[0][0], points[0][1]);
    prev[3] = max(points[0][0], max(points[0][1], points[0][2]));

    for (int day = 1; day < n; day++) {
        vector<int> curr(4, 0);
        for (int last = 0; last < 4; last++) {
            curr[last] = 0;
            for (int task = 0; task < 3; task++) {
                if (task != last) {
                    int point = points[day][task] + prev[task];
                    curr[last] = max(curr[last], point);
                }
            }
        }
        prev = curr;
    }

    return prev[3];
}

int main() {
    vector<vector<int>> points = {
        {10, 40, 70},
        {20, 50, 80},
        {30, 60, 90}
    };

    cout << "Maximum points (Recursion): " << ninjaTrainingRecursion(points) << endl;
    cout << "Maximum points (Memoization): " << ninjaTrainingMemoization(points) << endl;
    cout << "Maximum points (Tabulation): " << ninjaTrainingTabulation(points) << endl;
    cout << "Maximum points (Space Optimization): " << ninjaTrainingSpaceOptimization(points) << endl;

    return 0;
}