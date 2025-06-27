#include <bits/stdc++.h>
using namespace std;

vector<int> nextSmallerElement(vector<int> & nums) {
    vector<int> nse(nums.size());
    stack<int> st;

    for (int i=nums.size()-1 ; i>=0 ; i--) {
        while(!st.empty() && nums[st.top()] > nums[i]) {
            st.pop();
        }

        if (st.empty()) nse[i] = nums.size();
        else nse[i] = st.top();

        st.push(i);
    }

    return nse;
}

vector<int> previousSmallerEqualElement(vector<int> & nums) {
    vector<int> psee(nums.size());
    stack<int> st;

    for (int i=0 ; i<nums.size() ; i++) {
        while(!st.empty() && nums[st.top()] >= nums[i]) {
            st.pop();
        }

        if (st.empty()) psee[i] = -1;
        else psee[i] = st.top();

        st.push(i);
    }

    return psee;
}

vector<int> nextGreaterElement(vector<int> & nums) {
    vector<int> nge(nums.size());
    stack<int> st;

    for (int i=nums.size()-1 ; i>=0 ; i--) {
        while(!st.empty() && nums[st.top()] < nums[i]) {
            st.pop();
        }

        if (st.empty()) nge[i] = nums.size();
        else nge[i] = st.top();

        st.push(i);
    }

    return nge;
}

vector<int> previousGreaterEqualElement(vector<int> & nums) {
    vector<int> pgee(nums.size());
    stack<int> st;

    for (int i=0 ; i<nums.size() ; i++) {
        while(!st.empty() && nums[st.top()] <= nums[i]) {
            st.pop();
        }

        if (st.empty()) pgee[i] = -1;
        else pgee[i] = st.top();

        st.push(i);
    }

    return pgee;
}

long long sumOfSubArrayMinimums (vector<int>& nums) {
    vector<int> nse = nextSmallerElement(nums);
    vector<int> psee = previousSmallerEqualElement(nums);
    long long sum = 0;
    for (int i=0 ; i<nums.size() ; i++) {
        long long left = i - psee[i];
        long long right = nse[i] - i;

        sum = sum + (left*right)*nums[i]; 
    }
    return sum;
}

long long sumOfSubArrayMaximums (vector<int>& nums) {
    vector<int> nse = nextGreaterElement(nums);
    vector<int> psee = previousGreaterEqualElement(nums);
    long long sum = 0;
    for (int i=0 ; i<nums.size() ; i++) {
        long long left = i - psee[i];
        long long right = nse[i] - i;

        sum = sum + (left*right)*nums[i]; 
    }
    return sum;
}

long long subArrayRanges(vector<int>& nums) {
    return sumOfSubArrayMaximums(nums) - sumOfSubArrayMinimums(nums);
}

int main() {
    vector<int> v = {1,2,3};

    cout << subArrayRanges(v) << endl;

    return 0;
}