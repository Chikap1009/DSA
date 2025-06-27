#include <bits/stdc++.h>
using namespace std;

vector<char> getChar(char num)
{
    switch(num)
    {
        case '2':
        return {'a','b','c'};

        case '3':
        return {'d','e','f'};

        case '4':
        return {'g','h','i'};

        case '5':
        return {'j','k','l'};

        case '6':
        return {'m','n','o'};

        case '7':
        return {'p','q','r','s'};

        case '8':
        return {'t','u','v'};

        case '9':
        return {'w','x','y','z'};
    }
    return {};
}

void getCombos(string digits, vector<string>& ans, string str = "", int index = 0)
{
    if (index == digits.length())
    {
        ans.push_back(str);
        return;
    }

    vector<char> v = getChar(digits[index]);

    for (auto x : v)
    {
        str.push_back(x);
        getCombos(digits,ans,str,index+1);
        str.pop_back();
    }
}

// void getCombos(string digits, vector<string>& ans, string str = "", int index = 0)
// {
//     if (index == digits.length())
//     {
//         ans.push_back(str);
//         return;
//     }

//     if (digits[index] == '2')
//     {
//         for (char i='a' ; i<= 'c' ; i++)
//         {
//             str.push_back(i);
//             getCombos(digits,ans,str,index+1);
//             str.pop_back();
//         }
//     }
//     else if (digits[index] == '3')
//     {
//         for (char i='d' ; i<= 'f' ; i++)
//         {
//             str.push_back(i);
//             getCombos(digits,ans,str,index+1);
//             str.pop_back();
//         }
//     }
//     else if (digits[index] == '4')
//     {
//         for (char i='g' ; i<= 'i' ; i++)
//         {
//             str.push_back(i);
//             getCombos(digits,ans,str,index+1);
//             str.pop_back();
//         }
//     }
//     else if (digits[index] == '5')
//     {
//         for (char i='j' ; i<= 'l' ; i++)
//         {
//             str.push_back(i);
//             getCombos(digits,ans,str,index+1);
//             str.pop_back();
//         }
//     }
//     else if (digits[index] == '6')
//     {
//         for (char i='m' ; i<= 'o' ; i++)
//         {
//             str.push_back(i);
//             getCombos(digits,ans,str,index+1);
//             str.pop_back();
//         }
//     }
//     else if (digits[index] == '7')
//     {
//         for (char i='p' ; i<= 's' ; i++)
//         {
//             str.push_back(i);
//             getCombos(digits,ans,str,index+1);
//             str.pop_back();
//         }
//     }
//     else if (digits[index] == '8')
//     {
//         for (char i='t' ; i<= 'v' ; i++)
//         {
//             str.push_back(i);
//             getCombos(digits,ans,str,index+1);
//             str.pop_back();
//         }
//     }
//     else if (digits[index] == '9')
//     {
//         for (char i='w' ; i<= 'z' ; i++)
//         {
//             str.push_back(i);
//             getCombos(digits,ans,str,index+1);
//             str.pop_back();
//         }
//     }
// }

vector<string> letterCombinations(string digits) {
    vector<string> ans;
    getCombos(digits, ans);
    if (digits.empty()) return {};
    return ans;
}

int main()
{
    vector<string> ans = letterCombinations("23");

    for (auto x : ans)
    {
        cout << x << " ";
    }
    cout << endl;
    
    return 0;
}