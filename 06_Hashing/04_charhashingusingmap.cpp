#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin >> s;

    unordered_map<char,int> mp;

    for (int i=0 ; i<s.length() ; i++)
    {
        mp[s[i]]++;
    }

    for (auto x : mp)
    {
        cout << x.first << "->" << x.second << endl;
    }

    int q;
    cin >> q;

    for (int i=0 ; i<q ; i++)
    {
        char c;
        cin >> c;

        cout << mp[c] << endl;
    }

    return 0;
}