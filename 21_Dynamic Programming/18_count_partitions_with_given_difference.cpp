#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

int countSubsetsWithSumKSpaceOptimized(vector<int>& nums, int K) {
    int n = nums.size();
    vector<int> prev(K + 1, 0);
    vector<int> curr(K + 1, 0);

    // Base case initialization
    prev[0] = 1; // There's always one way to make sum 0 (empty subset)
    if (nums[0] <= K) {
        prev[nums[0]] += 1; // If the first element is less than or equal to K
    }

    // Fill the dp table using space optimization
    for (int i = 1; i < n; i++) {
        curr[0] = 1; // There's always one way to make sum 0 (empty subset)
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

int countPartitionsWithGivenDifference(vector<int>& nums, int diff) {
    int totalSum = accumulate(nums.begin(), nums.end(), 0);
    int targetSum = (totalSum - diff) / 2;

    if (targetSum < 0) {
        return 0; // No valid partitions possible
    }
    
    // Check if (totalSum + diff) is even
    if ((totalSum - diff) % 2 != 0) {
        return 0; // No valid partitions possible
    }
    
    return countSubsetsWithSumKSpaceOptimized(nums, targetSum);
}

int main() {
    vector<int> nums = {1, 1, 2, 3};
    int diff = 1;
    cout << "Number of partitions with given difference: " 
         << countPartitionsWithGivenDifference(nums, diff) << endl;
    return 0;
}