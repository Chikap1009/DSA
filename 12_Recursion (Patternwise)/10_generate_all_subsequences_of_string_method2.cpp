#include <bits/stdc++.h>
using namespace std;

vector<string> subsets(string s) {
    vector<string> ans;
    int n = s.length();
    int maxi = pow(2,n) - 1; // 1<<n - 1
    for (int num=0 ; num<=maxi ; num++)
    {
        string temp = "";
        for (int i=0 ; i<n ; i++)
        {
            if ((num&(1<<i)) != 0)
            {
                temp += s[i];
            }
        }
        ans.push_back(temp);
    }
    return ans;
}

int main()
{
    string s = "abcd";

    vector<string> ans = subsets(s);

    for (auto x : ans)
    {
        cout << x << " ";
    }
    cout << endl;
    
    return 0;
}