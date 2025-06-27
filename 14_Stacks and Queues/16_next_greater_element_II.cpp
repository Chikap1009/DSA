#include <bits/stdc++.h>
using namespace std;

vector<int> bruteNextGreaterElements(vector<int>& nums) {

    vector<int> ans (nums.size(),-1);

    for (int i=0 ; i<nums.size() ; i++) {
        for (int j=i+1 ; j<nums.size()+i ; j++) {
            if (nums[j%nums.size()] > nums[i]) {
                ans[i] = nums[j%nums.size()];
                break;
            }
        } 
    }

    return ans;
}

vector<int> optimalNextGreaterElements(vector<int>& nums) {
    stack<int> st;
    vector<int> ans(nums.size(),-1);
    for (int i=nums.size()-1 ; i>=0 ; i--) {

        while(!st.empty() && st.top() <= nums[i]) {
            st.pop();
        }

        st.push(nums[i]);
    }

    for (int i=nums.size()-1 ; i>=0 ; i--) {
        
        while(!st.empty() && st.top() <= nums[i]) {
            st.pop();
        }

        if (st.empty()) ans[i] = -1;
        else ans[i] = st.top();

        st.push(nums[i]);
    }
    
    return ans;
}

int main() {

    vector<int> v = {1,2,3,4,3};

    vector<int> ans1 = bruteNextGreaterElements(v), ans2 = optimalNextGreaterElements(v);

    for (auto x : ans1) {
        cout << x << " ";
    }
    cout << endl;

    for (auto x : ans2) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}