#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(string s)
{
    int n = s.length();
    for (int i=0 ; i<n/2 ; i++)
    {
        if (s[i] != s[n-i-1]) return false;
    }
    return true;
}

void palindromeSubstrings(string s, vector<vector<string>>& ans, vector<string> sub = {}, int index=0)
{
    if (index == s.length())
    {
        ans.push_back(sub);
        return;
    }
    string temp = "";
    for (int i=index ; i<s.length() ; i++)
    {
        temp.push_back(s[i]);
        if (isPalindrome(temp))
        {
            sub.push_back(temp);
            palindromeSubstrings(s, ans, sub, i+1);
            sub.pop_back();
        }
    }
}

vector<vector<string>> partition(string s) {
    vector<vector<string>> ans;
    palindromeSubstrings(s, ans);
    return ans;
}

int main()
{
    vector<vector<string>> ans = partition("aabb");

    for (auto x : ans)
    {
        for (auto y : x)
        {
            cout << y << " ";
        }
        cout << endl;
    }

    return 0;
}