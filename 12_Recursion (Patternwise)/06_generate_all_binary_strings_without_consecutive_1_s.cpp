#include <bits/stdc++.h>
using namespace std;

// If the last character is '0', next character can be both '0' and '1'.
// If the last character is '1', next character has to be '0'.

void generateBinary(int n)
{
    if (s.length() == n)
    {
        cout << s << " ";
        return;
    }

    if (s.length() == 0)
    {
        helperFunction(n,"0");
        helperFunction(n,"1");
    }

    if (s[s.length()-1] == '0')
    {
        helperFunction(n,s+"0");
        helperFunction(n,s+"1");
    }
    else if (s[s.length()-1] == '1')
    {
        helperFunction(n,s+"0");
    }
}

int main()
{
    generateBinary(4);

    return 0;
}