#include <bits/stdc++.h>
using namespace std;

int totalElements(vector<int> &arr) {
    unordered_map<int, int> mp;
    int l=0, r=0, longest = 0;
    while(r < arr.size()) {
        mp[arr[r]]++;
        if (mp.size() > 2) {
            mp[arr[l]]--;
            if (mp[arr[l]] == 0) mp.erase(arr[l]);
            l++;
        }
        if (mp.size() <= 2) longest = max(longest, r-l+1);
        r++;
    }
    return longest;
}

int main() {
    vector<int> v = {13,3,10,2,8,9,10,9,4,16,3,2,11,1,9,17,10};

    cout << totalElements(v) << endl;

    return 0;
}