#include <bits/stdc++.h>
using namespace std;

bool bruteIsIsomorphic(string s, string t) 
{
    vector<int> mappingstot(256,-1);
    vector<int> mappingttos(256,-1);

    for (int i=0 ; i<s.length() ; i++)
    {
        if (mappingstot[s[i]] == -1 && mappingttos[t[i]] == -1)
        {
            mappingstot[s[i]] = t[i];
            mappingttos[t[i]] = s[i];
        }
        else if (mappingstot[s[i]] != t[i] || mappingttos[t[i]] != s[i])
        {
            return false;
        }
    }
    
    return true;
}

string stringCode(string s)
{
    unordered_map<char,int> hash;
    int n = s.length();

    string final = "";

    for (int i=0 ; i<n ; i++)
    {
        if (hash.find(s[i]) == hash.end())
        {
            hash[s[i]] = i;
        }

        final += to_string(hash[s[i]]) + " ";
    }
    return final;
}

bool optimal1IsIsomorphic(string s, string t)
{
    return stringCode(s) == stringCode(t);
}

bool optimal2IsIsomorphic(string s, string t) 
{
    map<char, char> hash;

    int n = s.length();
    for (int i=0 ; i<n ; i++)
    {
        if (hash.find(s[i]) == hash.end())
        {
            for (auto x : hash)
            {
                if (x.second == t[i]) return false;
            }
            hash[s[i]] = t[i];
        }
        else if (hash[s[i]] != t[i])
        {
            return false;
        }
    }
    return true;
}

int main()
{
    cout << bruteIsIsomorphic("abcdefghijklmnopqrstuvwxyz", "nopqrstuvwxyzabcdefghijklm") << endl;

    return 0;
}