#include <bits/stdc++.h>
using namespace std;

string removeOuterParentheses(string s) {
    string ans = "";
    int count = 0;
    
    for (int i=0 ; i<s.length() ; i++)
    {
        if (s[i] == '(')
        {
            if (count > 0)
            {
                ans += s[i];
            }
            count++;
        }
        else if (s[i] == ')')
        {
            count--;
            if (count > 0)
            {
                ans += s[i];
            }
        }
    }
    
    return ans;
}

int main()
{
    cout << removeOuterParentheses("(()())(())") << endl;

    return 0;
}