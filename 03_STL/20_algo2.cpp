#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s = "123";
    cout << s << endl;
    sort(s.begin(),s.end());
    cout << s << endl;

    do
    {
        cout << s << endl;
    } while(next_permutation(s.begin(),s.end()));

    string temp = "231";
    do
    {
        cout << temp << endl;
    } while(next_permutation(temp.begin(),temp.end()));

    return 0;
}