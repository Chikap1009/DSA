#include <bits/stdc++.h>
using namespace std;

int bruteCharacterReplacement(string s, int k) {
    //  changes = length of substring - max frequency among all numbers in substring

    int longest = 0;
    for (int i=0 ; i<s.length() ; i++) {
        vector<int> hash(26,0);
        int maxfrequency = 0;
        for (int j=i ; j<s.length() ; j++) {
            hash[s[j]-'A']++;
            maxfrequency = max(maxfrequency, hash[s[j]-'A']);
            int changes = (j-i+1) - maxfrequency;
            if (changes > k) break;
            longest = max(longest, j-i+1);
        }
    }
    return longest;
}

int betterCharacterReplacement(string s, int k) {
    //  changes = length of substring - max frequency among all numbers in substring

    int l=0, r=0, longest=0, maxfrequency=0;
    vector<int> hash(26,0);

    while(r < s.length()) {
        hash[s[r]-'A']++;
        maxfrequency = max(maxfrequency, hash[s[r]-'A']);
        int changes = (r-l+1) - maxfrequency;
        while (l<=r && changes > k) {
            hash[s[l]-'A']--;
            l++;
            maxfrequency = 0;
            for (auto x : hash) {
                maxfrequency = max(maxfrequency, x);
            }
            changes = (r-l+1) - maxfrequency;
        } 
        if (changes <= k) longest = max(longest, r-l+1);
        r++;
    }
    return longest;
}

int optimalCharacterReplacement(string s, int k) {
    //  changes = length of substring - max frequency among all numbers in substring

    int l=0, r=0, longest=0, maxfrequency=0;
    vector<int> hash(26,0);

    while(r < s.length()) {
        hash[s[r]-'A']++;
        maxfrequency = max(maxfrequency, hash[s[r]-'A']);
        int changes = (r-l+1) - maxfrequency;
        if (changes > k) {
            hash[s[l]-'A']--;
            l++;
            changes = (r-l+1) - maxfrequency; // changes--;
        } 
        if (changes <= k) longest = max(longest, r-l+1);
        r++;
    }
    return longest;
}

int main() {
    
    cout << bruteCharacterReplacement("AABABBA", 1) << endl;
    cout << betterCharacterReplacement("AABABBA", 1) << endl;
    cout << optimalCharacterReplacement("AABABBA", 1) << endl;

    return 0;
}