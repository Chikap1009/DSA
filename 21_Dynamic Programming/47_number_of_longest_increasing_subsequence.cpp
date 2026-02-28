#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

int findNumberOfLIS(vector<int>& nums) {
    int n = nums.size();

    vector<int> dp(n, 1);      // dp[i] will be the length of LIS ending at index i
    vector<int> count(n, 1);   // count[i] will be the number of LIS ending at index i

    int maxi = 1; // Length of the longest increasing subsequence found so far

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (nums[i] > nums[j]) {
                if (dp[j] + 1 > dp[i]) {
                    dp[i] = dp[j] + 1;
                    count[i] = count[j];
                } else if (dp[j] + 1 == dp[i]) {
                    count[i] += count[j];
                }
            }
        }
        maxi = max(maxi, dp[i]);
    }

    int totalCount = 0;
    for (int i = 0; i < n; i++) {
        if (dp[i] == maxi) {
            totalCount += count[i];
        }
    }
    return totalCount;
}

int main() {
    vector<int> nums = {1, 3, 5, 4, 7};
    int result = findNumberOfLIS(nums);
    cout << "Number of Longest Increasing Subsequences: " << result << endl;
    return 0;
}