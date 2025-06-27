#include <bits/stdc++.h>
using namespace std;

int findContentChildren(vector<int>& g, vector<int>& s) {
    sort(g.begin(),g.end());
    sort(s.begin(),s.end());
    int happy = 0;
    int l=0, r=0;
    while(l<g.size() && r<s.size()) {
        if (g[l] <= s[r]) {
            happy++;
            l++;
        }
        r++;
    }
    return happy;
}

int main() {

    vector<int> g = {1,5,3,3,4}, s = {4,2,1,2,1,3};

    cout << findContentChildren(g, s) << endl;

    return 0;
}