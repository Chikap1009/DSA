#include <bits/stdc++.h>
using namespace std;

bool isOperand(char c)
{
    if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || (c >= '0' && c <= '9')) return true;
    return false;
}

string postToInfix(string exp) {
    stack<string> st;
    int i=0;
    
    while(i<exp.size()) {
        if (isOperand(exp[i])) {
            string temp;
            temp.push_back(exp[i]);
            st.push(temp);
        }
        else {
            string t1 = st.top();
            st.pop();
            string t2 = st.top();
            st.pop();
            st.push("(" + t2 + exp[i] + t1 + ")");
        }
        i++;
    }
    
    return st.top();
}

int main() {
    
    cout << postToInfix("abcd^e-fgh*+^*+i-") << endl;

    return 0;
}