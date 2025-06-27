#include <bits/stdc++.h>
using namespace std;

int numberOfSubstrings(string s) {
    vector<int> hash = {-1,-1,-1};
    int ans = 0;

    for (int i=0 ; i<s.length() ; i++) {
        hash[s[i]-'a'] = i;
        ans += *min_element(hash.begin(),hash.end()) + 1;
    }

    return ans;
}

int main() {
    
    cout << numberOfSubstrings("abcabc") << endl;

    return 0;
}