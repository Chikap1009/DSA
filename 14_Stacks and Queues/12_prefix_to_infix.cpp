#include <bits/stdc++.h>
using namespace std;

bool isOperand(char c)
{
    if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || (c >= '0' && c <= '9')) return true;
    return false;
}

string preToInfix(string pre_exp) {
    
    int i=pre_exp.size()-1;
    stack<string> st;
    
    while(i>=0) {
        if (isOperand(pre_exp[i])) {
            string temp;
            temp.push_back(pre_exp[i]);
            st.push(temp);
        }
        else {
            string t1 = st.top();
            st.pop();
            string t2 = st.top();
            st.pop();
            st.push("(" + t1 + pre_exp[i] + t2 + ")");
        }
        i--;
    }
    
    return st.top();
}

int main() {

    cout << preToInfix("-+a*b^-^cde+f*ghi") << endl;

    return 0;
}