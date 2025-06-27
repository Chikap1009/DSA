#include <bits/stdc++.h>
using namespace std;

int findPlatform(vector<int>& arr, vector<int>& dep) {
    sort(arr.begin(),arr.end());
    sort(dep.begin(),dep.end());
    
    int l=0, r=0, count=0, maxCount=0;
    
    while(l<arr.size() && r<dep.size()) {
        if (arr[l]<=dep[r]) {
            l++;
            count++;
        }
        else {
            r++;
            count--;
        }
        
        maxCount = max(maxCount, count);
    }
    
    return maxCount;
}

int main() {
    vector<int> arr = {2148,2334,338,25,2121,2353,1125,2358,1023}, dep = {2238,2349,1518,939,2147,2355,2233,2359,2200};

    cout << findPlatform(arr, dep) << endl;

    return 0;
}