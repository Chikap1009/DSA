#include <bits/stdc++.h>
using namespace std;

int countSubstr(string s, int k) {
    set<char> tally;
    int count = 0;
    int initial = 0;
    for (int i=0 ; i<s.length() ; i++)
    {
        for (int j=i ; j<s.length() ; j++)
        {
            tally.insert(s[j]);
            if (tally.size() == k) count++;
            else if (tally.size() > k)
            {
                tally.erase(s[initial]);
                initial++;
                while (initial < s.length() && s[initial-1]==s[initial])
                {
                    initial++;
                }
            }
        }
    }
    return count;
}

int main()
{
    cout << countSubstr("aba",2) << endl;

    return 0;
}