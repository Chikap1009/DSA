#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

int recursion(string& expression, int i, int j, bool isTrue) {
    if (i > j) return 0;
    if (i == j) {
        if (isTrue) return expression[i] == 'T' ? 1 : 0;
        else return expression[i] == 'F' ? 1 : 0;
    }

    int ways = 0;
    for (int k = i + 1; k <= j - 1; k += 2) {
        char op = expression[k];

        int leftTrue = recursion(expression, i, k - 1, true);
        int leftFalse = recursion(expression, i, k - 1, false);
        int rightTrue = recursion(expression, k + 1, j, true);
        int rightFalse = recursion(expression, k + 1, j, false);

        if (op == '&') {
            if (isTrue) {
                ways += leftTrue * rightTrue;
            } else {
                ways += leftFalse * rightFalse + leftTrue * rightFalse + leftFalse * rightTrue;
            }
        } else if (op == '|') {
            if (isTrue) {
                ways += leftTrue * rightTrue + leftTrue * rightFalse + leftFalse * rightTrue;
            } else {
                ways += leftFalse * rightFalse;
            }
        } else if (op == '^') {
            if (isTrue) {
                ways += leftTrue * rightFalse + leftFalse * rightTrue;
            } else {
                ways += leftTrue * rightTrue + leftFalse * rightFalse;
            }
        }
    }
    return ways;
}

int evaluateExpRecursion(string& expression) {
    int s = expression.size();
    return recursion(expression, 0, s - 1, true);
}

int memoization(string& expression, int i, int j, bool isTrue, vector<vector<vector<int>>>& dp) {
    if (i > j) return 0;
    if (i == j) {
        if (isTrue) return expression[i] == 'T' ? 1 : 0;
        else return expression[i] == 'F' ? 1 : 0;
    }

    if (dp[i][j][isTrue] != -1) return dp[i][j][isTrue];

    int ways = 0;
    for (int k = i + 1; k <= j - 1; k += 2) {
        char op = expression[k];

        int leftTrue = memoization(expression, i, k - 1, true, dp);
        int leftFalse = memoization(expression, i, k - 1, false, dp);
        int rightTrue = memoization(expression, k + 1, j, true, dp);
        int rightFalse = memoization(expression, k + 1, j, false, dp);

        if (op == '&') {
            if (isTrue) {
                ways += leftTrue * rightTrue;
            } else {
                ways += leftFalse * rightFalse + leftTrue * rightFalse + leftFalse * rightTrue;
            }
        } else if (op == '|') {
            if (isTrue) {
                ways += leftTrue * rightTrue + leftTrue * rightFalse + leftFalse * rightTrue;
            } else {
                ways += leftFalse * rightFalse;
            }
        } else if (op == '^') {
            if (isTrue) {
                ways += leftTrue * rightFalse + leftFalse * rightTrue;
            } else {
                ways += leftTrue * rightTrue + leftFalse * rightFalse;
            }
        }
    }
    return dp[i][j][isTrue] = ways;
}

int evaluteExpMemoization(string& expression) {
    int s = expression.size();
    vector<vector<vector<int>>> dp(s, vector<vector<int>>(s, vector<int>(2, -1)));
    return memoization(expression, 0, s - 1, true, dp);
}

int evaluateExpTabulation(string& expression) {
    int n = expression.size();
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(2, 0)));

    for (int i = 0; i < n; i += 2) {
        dp[i][i][1] = (expression[i] == 'T') ? 1 : 0;
        dp[i][i][0] = (expression[i] == 'F') ? 1 : 0;
    }

    for (int i = n - 1; i >= 0; i -= 2) {
        for (int j = i + 2; j < n; j += 2) {
            for (int isTrue = 0; isTrue <= 1; isTrue++) {
                int ways = 0;
                for (int k = i + 1; k <= j - 1; k += 2) {
                    char op = expression[k];

                    int leftTrue = dp[i][k - 1][1];
                    int leftFalse = dp[i][k - 1][0];
                    int rightTrue = dp[k + 1][j][1];
                    int rightFalse = dp[k + 1][j][0];

                    if (op == '&') {
                        if (isTrue) {
                            ways += leftTrue * rightTrue;
                        } else {
                            ways += leftFalse * rightFalse + leftTrue * rightFalse + leftFalse * rightTrue;
                        }
                    } else if (op == '|') {
                        if (isTrue) {
                            ways += leftTrue * rightTrue + leftTrue * rightFalse + leftFalse * rightTrue;
                        } else {
                            ways += leftFalse * rightFalse;
                        }
                    } else if (op == '^') {
                        if (isTrue) {
                            ways += leftTrue * rightFalse + leftFalse * rightTrue;
                        } else {
                            ways += leftTrue * rightTrue + leftFalse * rightFalse;
                        }
                    }
                }
                dp[i][j][isTrue] = ways;
            }
        }
    }

    return dp[0][n - 1][1];
}

int main() {
    string expression = "T|F&T^F";

    cout << "Number of ways (Recursion): " << evaluateExpRecursion(expression) << endl;
    cout << "Number of ways (Memoization): " << evaluteExpMemoization(expression) << endl;
    cout << "Number of ways (Tabulation): " << evaluateExpTabulation(expression) << endl;

    return 0;
}