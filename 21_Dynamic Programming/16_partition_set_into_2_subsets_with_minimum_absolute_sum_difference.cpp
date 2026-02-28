#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

int minSubsetSumDifference(vector<int>& nums) {
    int n = nums.size();
    int totalSum = accumulate(nums.begin(), nums.end(), 0);
    vector<bool> prev(totalSum + 1, false);
    prev[0] = true;
    if (nums[0] <= totalSum) {
        prev[nums[0]] = true;
    }
    for (int index = 1; index < n; index++) {
        vector<bool> curr(totalSum + 1, false);
        curr[0] = true;
        for (int target = 1; target <= totalSum; target++) {
            bool notTake = prev[target];
            bool take = false;
            if (nums[index] <= target) {
                take = prev[target - nums[index]];
            }
            curr[target] = take || notTake;
        }
        prev = curr;
    }

    int minDiff = INT_MAX;
    for (int s1 = 0; s1 <= totalSum / 2; s1++) {
        if (prev[s1]) {
            int s2 = totalSum - s1;
            minDiff = min(minDiff, abs(s2 - s1));
        }
    }
    return minDiff;
}

int main() {
    vector<int> partitionArr = {1, 6, 11, 5};
    int result = minSubsetSumDifference(partitionArr);
    cout << "The minimum absolute sum difference between two subsets is: " << result << endl;
    return 0;
}