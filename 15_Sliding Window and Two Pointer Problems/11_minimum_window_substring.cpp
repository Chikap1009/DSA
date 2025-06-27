#include <bits/stdc++.h>
using namespace std;

string minWindow(string s, string t) {
    if (s.length() < t.length()) return "";
    vector<int> v (256,0);
    int l=0, r=0, count=0;
    for (int i=0 ; i<t.length() ; i++) {
        v[t[i]]++;
    }
    int minLength = INT_MAX, startIndex = -1;

    while(r<s.length()){
        if (v[s[r]] > 0) count++;
        v[s[r]]--;

        while (count == t.length()) {
            if (r-l+1 < minLength) {
                minLength = r-l+1;
                startIndex = l;
            }

            v[s[l]]++;
            if (v[s[l]] > 0) count--;
            l++;
        }

        r++;
    }

    if (startIndex == -1) return "";
    
    string ans = "";
    for (int i=0 ; i<minLength ; i++) {
        ans += s[startIndex+i];
    }

    return ans;
}

int main() {

    cout << minWindow("ADOBECODEBANC","ABC") << endl;

    return 0;
}