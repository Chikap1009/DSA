#include <bits/stdc++.h>
using namespace std;

int myAtoi(string s) {
    long long myAns = 0;
    int traversal = 0;
    int sign = 1;
    for (int i=0 ; i<s.length() ; i++)
    {
        if (s[i] != ' ') break;
        traversal++;
    }
    if (s[traversal] == '-' || s[traversal] == '+')
    {
        if (s[traversal] == '-') sign = -1;
        traversal++;
    }
    for (int i=traversal ; i<s.length() ; i++)
    {
        if (myAns >= pow(2,31))
        {
            if (sign == 1) return (pow(2,31) - 1);
            else return (pow(2,31)*(-1));
        }
        if (s[i] >= '0' && s[i] <= '9')
        {
            myAns = myAns * 10 + (s[i] - '0');
        }
        else break;
    }
    if (myAns >= pow(2,31))
    {
        if (sign == 1) return (pow(2,31) - 1);
        else return (pow(2,31)*(-1));
    }
    return myAns*sign;
}

int main()
{
    cout << myAtoi("21474836460") << endl;

    cout << atoi("    -00021474836 hello") << endl;

    return 0;
}