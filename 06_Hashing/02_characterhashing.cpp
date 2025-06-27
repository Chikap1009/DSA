#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin >> s;

    int arr[26] = {0};

    for (int i=0 ; i<s.length() ; i++)
    {
        arr[(int)s[i]-97]++;
    }

    int t;
    cin >> t;

    for (int i=0 ; i<t ; i++)
    {
        char c;
        cin >> c;
        cout << arr[(int)c-97] << endl;
    }

    return 0;
}