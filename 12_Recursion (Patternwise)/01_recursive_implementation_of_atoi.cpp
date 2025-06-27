// Read most optimal solution on LC(8).

#include <bits/stdc++.h>
using namespace std;

pair<bool,long long> getAtoi(string s, int index, bool initial, bool positive, long long sum = 0)
{
    if (index == s.length()) return {positive,sum};
    if (initial)
    {
        if (s[index] == ' ') return getAtoi(s,index+1,true,true);
        else if (s[index] == '+') return getAtoi(s,index+1,false,true);
        else if (s[index] == '-') return getAtoi(s,index+1,false,false);
    }

    if (sum >= pow(2,31)) return {positive,pow(2,31)};
    else if (s[index] >= '0' && s[index] <= '9')
    {
        sum = sum*10 + (s[index]-'0');
        return getAtoi(s, index+1, false, positive, sum);
    }
    else
    {
        return {positive,sum};
    }
}

int myAtoi(string s) {
    pair<bool,long long> p = getAtoi(s,0,true,true);
    if (p.first)
    {
        if (p.second >= pow(2,31)-1) return pow(2,31)-1;
        else return p.second;
    }
    else
    {
        if (p.second >= pow(2,31)) return (-1)*pow(2,31);
        else return (-1)*p.second;
    }
    // long long myAns = 0;
    // int traversal = 0;
    // int sign = 1;
    // for (int i=0 ; i<s.length() ; i++)
    // {
    //     if (s[i] != ' ') break;
    //     traversal++;
    // }
    // if (s[traversal] == '-' || s[traversal] == '+')
    // {
    //     if (s[traversal] == '-') sign = -1;
    //     traversal++;
    // }
    // for (int i=traversal ; i<s.length() ; i++)
    // {
    //     if (myAns >= pow(2,31))
    //     {
    //         if (sign == 1) return (pow(2,31) - 1);
    //         else return (pow(2,31)*(-1));
    //     }
    //     if (s[i] >= '0' && s[i] <= '9')
    //     {
    //         myAns = myAns * 10 + (s[i] - '0');
    //     }
    //     else break;
    // }
    // if (myAns >= pow(2,31))
    // {
    //     if (sign == 1) return (pow(2,31) - 1);
    //     else return (pow(2,31)*(-1));
    // }
    // return myAns*sign;
}

int main()
{
    cout << myAtoi("42") << endl;
    cout << myAtoi("-042") << endl;
    cout << myAtoi("1337c0d3") << endl;
    cout << myAtoi("words and 987") << endl;

    return 0;
}