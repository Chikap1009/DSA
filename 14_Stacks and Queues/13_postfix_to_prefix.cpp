#include <bits/stdc++.h>
using namespace std;

bool isOperand(char c)
{
    if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || (c >= '0' && c <= '9')) return true;
    return false;
}

string postToPre(string post_exp) {
    int i=0;
    stack<string> st;
    
    while(i<post_exp.length()) {
        if (isOperand(post_exp[i])) {
            string temp;
            temp.push_back(post_exp[i]);
            st.push(temp);
        }
        else {
            string t1 = st.top();
            st.pop();
            string t2 = st.top();
            st.pop();
            st.push(post_exp[i] + t2 + t1);
        }
        i++;
    }
    
    return st.top();
}

int main() {

    cout << postToPre("abcd^e-fgh*+^*+i-") << endl;

    return 0;
}