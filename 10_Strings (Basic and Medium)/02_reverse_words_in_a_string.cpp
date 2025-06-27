#include <bits/stdc++.h>
using namespace std;

string reverseWords(string s) {
    reverse(s.begin(), s.end());
    string ans = "";
    string word = "";

    for (int i=0 ; i<s.length() ; i++)
    {
        if (s[i] != ' ')
        {
            word += s[i];
        }
        else
        {
            if (i==0 || s[i-1] == ' ')
            {
                continue;
            }
            reverse(word.begin(), word.end());
            ans += word + " ";
            word = "";
        }
    }

    if (word != "")
    {
        reverse(word.begin(), word.end());
        ans += word;
    }

    if (ans[ans.size()-1] == ' ')
    {
        ans.pop_back();
    }

    return ans;
}

// string reverseWords(string s) {
    
//     string ans = "";
//     vector<string> words;
//     string word = "";

//     for (int i=0 ; i<s.length() ; i++)
//     {
//         if (s[i] != ' ')
//         {
//             word += s[i];
//         }
//         else if (s[i] == ' ')
//         {
//             if (i==0 || (i>0 && s[i-1] == ' '))
//             {
//                 continue;
//             }
//             words.push_back(word);
//             word = "";
//         }
//     }

//     if (word != "")
//     {
//         words.push_back(word);
//     }

//     for (int i=words.size()-1 ; i>=0 ; i--)
//     {
//         ans += words[i] + " ";
//     }
//     ans.pop_back();

//     return ans;
// }

int main()
{
    cout << reverseWords("      the sky is     blue  ") << endl;

    return 0;
}