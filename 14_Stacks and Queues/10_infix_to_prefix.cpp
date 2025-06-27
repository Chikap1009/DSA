#include <bits/stdc++.h>
using namespace std;

int priority(char c) {
    if (c=='^') return 3;
    else if (c=='*' || c=='/') return 2;
    else if (c=='+' || c=='-') return 1;
    return -1;
}

bool isOperator(char c)
{
    if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || (c >= '0' && c <= '9')) return true;
    return false;
}

string infixToPrefix(string s) {
    reverse(s.begin(),s.end());
    for (auto &x : s)
    {
        if (x == '(') x = ')';
        else if (x == ')') x = '(';
    }
    int i=0;
    stack<char> st;
    string ans = "";
    while(i<s.size())
    {
        if (isOperator(s[i])) ans += s[i];
        else if (s[i] == '(') st.push('(');
        else if (s[i] == ')') {
            while(st.top() != '(') {
                ans += st.top();
                st.pop();
            }
            st.pop();
        }
        else {
            if (s[i] == '^') {
                while(!st.empty() && priority(st.top()) >= priority(s[i])) {
                    ans += st.top();
                    st.pop();
                }
            }
            else {
                while(!st.empty() && priority(st.top()) > priority(s[i])) {
                    ans += st.top();
                    st.pop();
                }
            }
            st.push(s[i]);
        }
        i++;
    }
    while(!st.empty()) {
        ans += st.top();
        st.pop();
    }
    reverse(ans.begin(),ans.end());
    return ans;
}

int main() {
    
    cout << infixToPrefix("a+b*(c^d-e)^(f+g*h)-i") << endl;

    return 0;
}