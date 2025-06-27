#include <bits/stdc++.h>
using namespace std;

int maxDepth(string s) {
    int maxNo = 0;
    int counter = 0;

    int n = s.length();

    for (int i=0 ; i<n ; i++)
    {
        if (s[i] == '(')
        {
            counter++;
            maxNo = max(maxNo, counter);
        }
        else if (s[i] == ')')
        {
            counter--;
        }
    }
    
    return maxNo;
}

int main()
{
    cout << maxDepth("(1+(2*3)+((8)/4))+1") << endl;

    return 0;
}