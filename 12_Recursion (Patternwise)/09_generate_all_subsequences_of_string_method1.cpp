#include <bits/stdc++.h>
using namespace std;

void getSubsets(string s, vector<string>& ans, string substring = "", int index = 0)
{
    if (index == s.length())
    {
        ans.push_back(substring);
        return;
    }

    substring.push_back(s[index]);
    getSubsets(s,ans,substring,index+1);
    substring.pop_back();
    getSubsets(s,ans,substring,index+1);
}

vector<string> subsets(string s) {
    vector<string> ans;
    getSubsets(s,ans);
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