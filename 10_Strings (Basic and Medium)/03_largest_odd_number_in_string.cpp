#include <bits/stdc++.h>
using namespace std;

string largestOddNumber(string num) {
    string ans = num;

    for (int i=num.length()-1 ; i>=0 ; i--)
    {
        if ((num[i] - '0')%2==0)
        {
            ans.pop_back();
        }
        else
        {
            return ans;
        }
    }

    return "";
}

int main()
{
    cout << largestOddNumber("35428") << endl;

    return 0;
}