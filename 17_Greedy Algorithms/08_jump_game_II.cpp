#include <bits/stdc++.h>
using namespace std;

int jump(vector<int>& nums) {
    int l=0, r=0, minJumps = 0;

    while(r < nums.size()-1) {
        int newl = r+1, newr = r;

        for (int i=l ; i<=r ; i++) {
            newr = max(newr, i+nums[i]);
        }

        l = newl;
        r = newr;
        minJumps++;
    }

    return minJumps;
}

int main() {
    vector<int> v = {2,3,1,1,4};

    cout << jump(v) << endl;

    return 0;
}