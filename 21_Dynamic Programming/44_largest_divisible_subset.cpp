#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

vector<int> largestDivisibleSubset(vector<int>& nums) {
    int n = nums.size();

    sort(nums.begin(), nums.end());

    vector<int> dp(n, 1);
    vector<int> hash(n, -1);
    int maxi = 1;
    int maxiIndex = 0;

    for (int i=1 ; i < n ; i++) {
        for (int prev = 0 ; prev < i ; prev++) {
            if (nums[i] % nums[prev] == 0 && dp[prev] + 1 > dp[i]) {
                dp[i] = dp[prev] + 1;
                hash[i] = prev;
            }
        }
        if (dp[i] > maxi) {
            maxi = dp[i];
            maxiIndex = i;
        }
    }
    vector<int> lds(maxi);
    int ptr = maxi - 1;
    int index = maxiIndex;
    while(hash[index] != -1) {
        lds[ptr] = nums[index];
        ptr--;
        index = hash[index];
    }
    lds[ptr] = nums[index];
    return lds;
}

int main() {
    vector<int> nums = {1, 2, 4, 8};
    vector<int> result = largestDivisibleSubset(nums);
    cout << "Largest Divisible Subset: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}