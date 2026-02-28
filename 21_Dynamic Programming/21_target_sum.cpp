#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

int countSubsetsWithSumKSpaceOptimized(vector<int>& nums, int K) {
    int n = nums.size();
    vector<int> prev(K + 1, 0);

    prev[0] = 1;
    if (nums[0] <= K) {
        prev[nums[0]] += 1;
    }

    for (int i = 1; i < n; i++) {
        vector<int> curr(K + 1, 0);
        curr[0] = 1;
        for (int target = 0; target <= K; target++) {
            int notTake = prev[target];
            int take = 0;
            if (nums[i] <= target) {
                take = prev[target - nums[i]];
            }
            curr[target] = take + notTake;
        }
        prev = curr;
    }

    return prev[K];
}
int findTargetSumWays(vector<int>& nums, int target) {
    int n = nums.size();
    int totalSum = accumulate(nums.begin(),nums.end(),0);
    if (totalSum - target < 0) return 0;
    if ((totalSum - target)%2 != 0) return 0;
    return countSubsetsWithSumKSpaceOptimized(nums, (totalSum - target)/2);
}

int main() {
    vector<int> nums = {1, 1, 1, 1, 1};
    int target = 3;
    cout << findTargetSumWays(nums, target) << endl; // Output: 5
    return 0;
}