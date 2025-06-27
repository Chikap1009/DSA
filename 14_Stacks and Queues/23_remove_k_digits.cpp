#include <bits/stdc++.h>
using namespace std;

string removeKdigits(string num, int k) {
    stack<char> st;
    for (int i=0 ; i<num.length() ; i++) {

        while(k>0 && !st.empty() && st.top() > num[i]) {
            st.pop();
            k--;
        }

        st.push(num[i]);
    }

    while(k>0) {
        st.pop();
        k--;
    }

    if (st.empty()) return "0";

    string ans = "";
    while(!st.empty()) {
        ans += st.top();
        st.pop();
    }

    while(!ans.empty() && ans.back() == '0') {
        ans.pop_back();
    }

    if (ans.empty()) return "0";
    reverse(ans.begin(),ans.end());

    return ans;
}

int main() {
    
    cout << removeKdigits("43214321",4) << endl;

    return 0;
}