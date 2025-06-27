#include <bits/stdc++.h>
using namespace std;

bool bruteIsAnagram(string s, string t)
{
    if (s.length() != t.length()) return false;

    sort(s.begin(), s.end());
    sort(t.begin(), t.end());
    if (s == t) return true;
    return false;
}

bool OptimalIsAnagram(string s, string t) 
{
    if (s.length() != t.length()) return false;

    vector<int> hash(26,0);
    for (int i=0 ; i<s.length() ; i++)
    {
        hash[s[i] - 'a']++;
        hash[t[i] - 'a']--;
    }

    for (int x : hash)
    {
        if (x!=0) return false;
    }
    return true;
}

int main()
{
    cout << bruteIsAnagram("anagram","nagaram") << endl;
    cout << OptimalIsAnagram("anagram","nagaram") << endl;

    return 0;
}