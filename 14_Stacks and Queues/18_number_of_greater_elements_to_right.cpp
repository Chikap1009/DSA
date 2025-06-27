#include <bits/stdc++.h>
using namespace std;

vector<int> count_NGE(int n, vector<int> &arr, int queries, vector<int> &indices){
    stack<int> st;
    vector<int> ans(n);
    for (int i=arr.size()-1 ; i>=0 ; i--) {
        stack<int> temp;
        int cnt = 0;
        while(!st.empty() && st.top() > arr[i]) {
            temp.push(st.top());
            st.pop();
            cnt++;
        }
        st.push(arr[i]);
        while(!temp.empty()) {
            st.push(temp.top());
            temp.pop();
        }
        ans[i] = cnt;
    }
    vector<int> final;
    for (int i=0 ; i<queries ; i++) {
        final.push_back(ans[indices[i]]);
    }
    return final;
}

int main() {
    vector<int> arr = {3, 4, 2, 7, 5, 8, 10, 6}, indices = {0, 5};
    int queries = 2;

    vector<int> ans = count_NGE(arr.size(), arr, queries, indices);

    for (auto x : ans) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}