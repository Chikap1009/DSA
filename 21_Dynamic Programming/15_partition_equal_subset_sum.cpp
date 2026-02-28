#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

bool subsetSumToKSpaceOptimized(vector<int> &arr, int k) {
    int n = arr.size();
    vector<bool> prev(k + 1, false);

    // Base case: target 0 can always be achieved with empty subset
    prev[0] = true;

    // Base case: only first element
    if (arr[0] <= k) {
        prev[arr[0]] = true;
    }

    for (int index = 1; index < n; index++) {
        vector<bool> curr(k + 1, false);
        curr[0] = true; // target 0 can always be achieved
        for (int target = 1; target <= k; target++) {
            // Not take the element
            bool notTake = prev[target];
            // Take the element
            bool take = false;
            if (arr[index] <= target) {
                take = prev[target - arr[index]];
            }
            curr[target] = take || notTake;
        }
        prev = curr;
    }

    return prev[k];
}

bool canPartition(vector<int>& nums) {
    int sum = accumulate(nums.begin(),nums.end(),0);
    if (sum%2 != 0) return false;
    return subsetSumToKSpaceOptimized(nums, sum/2);
}

int main() {
    vector<int> partitionArr = {1, 5, 11, 5};
    if (canPartition(partitionArr)) {
        cout << "The array can be partitioned into two subsets with equal sum." << endl;
    } else {
        cout << "The array cannot be partitioned into two subsets with equal sum." << endl;
    }

    return 0;
}