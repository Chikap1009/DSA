#include <bits/stdc++.h>
using namespace std;

bool rotateString(string s, string goal) {
    if (s.length() != goal.length()) return false;

    string newStr = s + s;
    if (newStr.find(goal) < newStr.length()) return true;
    return false;
}

int main()
{
    cout << rotateString("abcde","cdeab") << endl;

    return 0;
}