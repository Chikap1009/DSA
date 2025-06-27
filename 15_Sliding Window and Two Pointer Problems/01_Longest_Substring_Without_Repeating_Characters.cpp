#include <bits/stdc++.h>
using namespace std;

int lengthOfLongestSubstring(string s) {
    int longest = 0;
    vector<int> hash(256, -1);

    int l=0, r=0;
    while(r < s.length()) {
        if (hash[s[r]] != -1) {
            if (hash[s[r]] >= l) {
                l = hash[s[r]] + 1;
            }
        }
        hash[s[r]] = r;
        longest = max(longest, r-l+1);
        r++;
    }
    return longest;
}

int main() {
    cout << lengthOfLongestSubstring("abcabcbb") << endl;

    return 0;
}