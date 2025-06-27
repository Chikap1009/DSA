#include <bits/stdc++.h>
using namespace std;

vector<int> bruteNextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
    vector<int> ans;

    for (int i=0 ; i<nums1.size() ; i++)
    {
        auto pos = find(nums2.begin(), nums2.end(), nums1[i]);
        for (auto it = pos ; it != nums2.end() ; it++)
        {
            if (*it > nums1[i]) {
                ans.push_back(*it);
                break;
            }
        }
        if (ans.size() == i) ans.push_back(-1);
    }
    return ans;
}

vector<int> optimalNextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
    vector<int> ans;

    stack<int> st;
    unordered_map<int,int> nge;

    for (int i=nums2.size()-1 ; i>=0 ; i--) {

        while(!st.empty() && st.top() <= nums2[i]) {
            st.pop();
        }

        if (st.empty()) nge[nums2[i]] = -1;
        else nge[nums2[i]] = st.top();

        st.push(nums2[i]);
    }

    for (int i=0 ; i<nums1.size() ; i++) {
        ans.push_back(nge[nums1[i]]);
    }

    return ans;
}

int main() {

    vector<int> v1 = {4,1,2}, v2 = {1,3,4,2};

    vector<int> ans1 = bruteNextGreaterElement(v1,v2);
    vector<int> ans2 = optimalNextGreaterElement(v1,v2);

    for (auto x : ans1) {cout << x << " ";}
    cout << endl;

    for (auto x : ans2) {cout << x << " ";}
    cout << endl;

    return 0;
}