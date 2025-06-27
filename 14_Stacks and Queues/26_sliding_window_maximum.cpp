#include <bits/stdc++.h>
using namespace std;

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    vector<int> ans;
    deque<int> dq;

    for (int i=0 ; i<nums.size() ; i++) {
        if (!dq.empty() && dq.front() == i-k) {
            dq.pop_front();
        }

        while(!dq.empty() && nums[dq.back()] <= nums[i]) {
            dq.pop_back();
        }

        dq.push_back(i);

        if (i>=k-1) {
            ans.push_back(nums[dq.front()]);
        }
    }
    return ans;
}

int main() {
    vector<int> arr = {1,3,-1,-3,5,3,6,7};

    vector<int> ans = maxSlidingWindow(arr, 3);

    for (auto x : ans) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}