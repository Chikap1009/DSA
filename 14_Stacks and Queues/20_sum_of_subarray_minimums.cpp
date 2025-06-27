#include <bits/stdc++.h>
using namespace std;

vector<int> nextSmallerElement (vector<int>& arr) {
    vector<int> nse(arr.size());
    stack<int> st;
    for (int i=arr.size()-1 ; i>=0 ; i--) {
        while(!st.empty() && arr[st.top()] >= arr[i]) {
            st.pop();
        }

        if (st.empty()) nse[i] = arr.size();
        else nse[i] = st.top();

        st.push(i);
    }

    return nse;
}

vector<int> previousSmallerEqualElement (vector<int>& arr) {
    vector<int> psee(arr.size());
    stack<int> st;
    for (int i=0 ; i<arr.size() ; i++) {
        while(!st.empty() && arr[st.top()] > arr[i]) {
            st.pop();
        }

        if (st.empty()) psee[i] = -1;
        else psee[i] = st.top();

        st.push(i);
    }

    return psee;
}

int sumSubarrayMins(vector<int>& arr) {
    vector<int> nse = nextSmallerElement(arr);
    vector<int> psee = previousSmallerEqualElement(arr);
    long long mod = 1e9 + 7;
    long long sum = 0;
    for (long long i=0 ; i<arr.size() ; i++) {
        long long left = i - psee[i];
        long long right = nse[i] - i;
        long long subarrays = (left * right);
        sum = (sum + subarrays*(long long)arr[i])%(mod);
    }
    return sum;
}

int main() {
    vector<int> v = {3,1,2,4};

    cout << sumSubarrayMins(v) << endl;

    return 0;
}