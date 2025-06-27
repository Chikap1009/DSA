#include <bits/stdc++.h>
using namespace std;

// void subsequences(string str, unordered_set<string> &unique, int index = 0, string s = "")
// {
//     if (index == str.length())
//     {
//         unique.insert(s);
//         return;
//     }
//     s.push_back(str[index]);
//     subsequences(str,unique,index+1,s);
//     s.pop_back();
//     subsequences(str,unique,index+1,s);
// }

// string betterString(string str1, string str2) {
//     unordered_set<string> s1, s2;
//     subsequences(str1, s1);
//     subsequences(str2, s2);
//     if (s1.size() >= s2.size()) return str1;
//     return str2;
// }

string betterString(string str1, string str2) {
    unordered_set<string> s1, s2;
    int n = str1.length();
    int maxi = (1<<n) - 1;
    for (int i=0 ; i<=maxi ; i++)
    {
        string temp1 = "";
        string temp2 = "";
        for (int j=0 ; j<n ; j++)
        {
            if ((i&(1<<j)) != 0)
            {
                temp1 += str1[j];
                temp2 += str2[j];
            }
        }
        s1.insert(temp1);
        s2.insert(temp2);
    }
    if (s1.size() >= s2.size()) return str1;
    return str2;
}

int main()
{
    cout << betterString("gfg","ggg") << endl;

    return 0;
}