#include <bits/stdc++.h>
using namespace std;

vector<int> brutePreviousSmallerElement(vector<int>& nums) {

    vector<int> ans (nums.size(), -1);

    for (int i=0 ; i<nums.size() ; i++)
    {
        for (int j=i-1 ; j>=0 ; j--) {
            if (nums[j] < nums[i]) {
                ans[i] = nums[j];
                break;
            }
        }
    }
    return ans;
}

vector<int> optimalPreviousSmallerElement(vector<int>& nums) {

    vector<int> ans (nums.size(),-1);
    stack<int> st;

    for (int i=0 ; i<nums.size() ; i++) {

        while(!st.empty() && st.top() >= nums[i]) {
            st.pop();
        }

        if (!st.empty()) ans[i] = st.top();

        st.push(nums[i]);
    }

    return ans;
}

int main() {

    vector<int> v = {5,7,9,6,7,4,5,1,3,7};

    vector<int> ans1 = brutePreviousSmallerElement(v);
    vector<int> ans2 = optimalPreviousSmallerElement(v);

    for (auto x : ans1) {cout << x << " ";}
    cout << endl;

    for (auto x : ans2) {cout << x << " ";}
    cout << endl;

    return 0;
}