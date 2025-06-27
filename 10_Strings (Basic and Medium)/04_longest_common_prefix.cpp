#include <bits/stdc++.h>
using namespace std;

string bruteLongestCommonPrefix(vector<string>& strs) {
    string prefix = strs[0];
    
    for (int i=1 ; i<strs.size() ; i++)
    {
        while(prefix != "" && strs[i].find(prefix) != 0)
        {
            prefix = prefix.substr(0,prefix.length()-1);
        }
        if (prefix == "") return "";
    }

    return prefix;
}

string betterLongestCommonPrefix(vector<string>& strs) {
    string prefix = strs[0];
    for (int i=0 ; i<prefix.size() ; i++)
    {
        char c = prefix[i];
        for (int j=1 ; j<strs.size() ; j++)
        {
            if (i==strs[j].size() || strs[j][i] != c)
            {
                return prefix.substr(0,i);
            }
        }
    }
    return prefix;
}

string longestCommonPrefix(vector<string>& strs) {
    string word = strs[0];
    int n = word.length();

    if (strs.size() == 1) return word;

    while(word!="")
    {
        for (int i=1 ; i<strs.size() ; i++)
        {
            if (strs[i].length() < n || strs[i].substr(0,n) != word)
            {
                word.pop_back();
                n--;
                break;
            }
            else
            {
                if (i == strs.size()-1)
                {
                    return word;
                }
            }
        }
    }
    return word;
}

// string longestCommonPrefix(vector<string>& strs) {
//     string ans = "";
//     int index = 0;

//     int temp = 1;
//     while (temp == 1)
//     {
//         char chr = strs[0][index];
//         for (auto x : strs)
//         {
//             if (x.length() == index)
//             {
//                 temp = 0;
//                 break;
//             }
//             if (x[index] == chr)
//             {
//                 continue;
//             }
//             else
//             {
//                 temp = 0;
//                 break;
//             }
//         }
//         if (temp == 0)
//         {
//             break;
//         }
//         ans += strs[0][index];
//         index++;
//     }
//     return ans;
// }

int main()
{
    vector<string> words = {"flower","flow","flight"};

    cout << longestCommonPrefix(words) << endl;

    return 0;
}