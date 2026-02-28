#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

int lengthOfLIS(vector<int>& nums) {
    if (nums.empty()) return 0;
    int n = nums.size();
    vector<int> dp(n, 1);
    int maxLength = 1;

    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (nums[i] > nums[j]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        maxLength = max(maxLength, dp[i]);
    }

    return maxLength;
}

vector<int> printingLIS(vector<int>& nums) {
    if (nums.empty()) return {};
    int n = nums.size();
    vector<int> dp(n, 1);
    vector<int> prev(n, -1);
    int maxLength = 1;
    int maxIndex = 0;

    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (nums[i] > nums[j] && dp[i] < dp[j] + 1) {
                dp[i] = dp[j] + 1;
                prev[i] = j;
            }
        }
        if (dp[i] > maxLength) {
            maxLength = dp[i];
            maxIndex = i;
        }
    }

    vector<int> lis;
    for (int i = maxIndex; i >= 0; i = prev[i]) {
        lis.push_back(nums[i]);
        if (prev[i] == -1) break;
    }
    reverse(lis.begin(), lis.end());
    return lis;
}

int main() {
    vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};

    int length = lengthOfLIS(nums);
    cout << "Length of Longest Increasing Subsequence: " << length << endl;

    vector<int> lis = printingLIS(nums);
    cout << "Longest Increasing Subsequence: ";
    for (int num : lis) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}