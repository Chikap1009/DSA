#include <bits/stdc++.h>
using namespace std;

void helperFunction(int n, vector<string>& v, int countOpen = 0, int countClosed = 0, string s = "")
{
    if (s.length() == n*2)
    {
        v.push_back(s);
        return;
    }

    if (countOpen < n)
    {
        helperFunction(n, v, countOpen+1, countClosed, s+"(");
    }
    if (countClosed < countOpen)
    {
        helperFunction(n, v, countOpen, countClosed+1, s+")");
    }
}

vector<string> generateParenthesis(int n) {
    vector<string> ans;
    helperFunction(n, ans);
    return ans;
}

int main()
{
    vector<string> ans = generateParenthesis(4);

    for (auto x : ans)
    {
        cout << x << "  ";
    }
    cout << endl;

    return 0;
}