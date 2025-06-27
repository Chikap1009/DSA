#include <bits/stdc++.h>
using namespace std;

int bruteLongestOnes(vector<int>& nums, int k) {
    // Longest subarray with number of zeroes <= k

    int longest = 0;

    for (int i=0 ; i<nums.size() ; i++) {
        int zeroes = 0;
        for (int j=i ; j<nums.size() ; j++) {
            if (nums[j] == 0) zeroes++;
            if (zeroes > k) break;

            longest = max(longest, j-i+1);
        }
    }

    return longest;
}

int betterLongestOnes(vector<int>& nums, int k) {
    // Longest subarray with number of zeroes <= k

    int l=0;
    int r=0;
    int longest = 0;
    int zeroes = 0;

    while(r < nums.size()) {
        if (nums[r] == 0) zeroes++;
        while(l<=r && zeroes > k) {
            if (nums[l] == 0) zeroes--;
            l++;
        }

        if (zeroes <= k) longest = max(longest, r-l+1);
        r++;
    }

    return longest;
}

int optimalLongestOnes(vector<int>& nums, int k) {
    // Longest subarray with number of zeroes <= k

    int l=0;
    int r=0;
    int longest = 0;
    int zeroes = 0;

    while(r < nums.size()) {
        if (nums[r] == 0) zeroes++;
        if (zeroes > k) {
            if (nums[l] == 0) zeroes--;
            l++;
        }

        if (zeroes <= k) longest = max(longest, r-l+1);
        r++;
    }

    return longest;
}

int main() {
    vector<int> v = {1,1,1,0,0,0,1,1,1,1,0};

    cout << bruteLongestOnes(v, 2) << endl;
    cout << betterLongestOnes(v, 2) << endl;
    cout << optimalLongestOnes(v, 2) << endl;

    return 0;
}