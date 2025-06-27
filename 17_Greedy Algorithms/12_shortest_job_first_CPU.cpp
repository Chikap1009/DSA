#include <bits/stdc++.h>
using namespace std;

long long solve(vector<int>& bt) {
    long long totalWaitingTime = 0;
    long long waitingTime = 0;
    sort(bt.begin(),bt.end());
    
    for (int i=0 ; i<bt.size() ; i++) {
        totalWaitingTime += waitingTime;
        waitingTime += bt[i];
    }
    
    return totalWaitingTime/bt.size();
}

int main() {
    vector<int> bt = {4,3,7,1,2};

    cout << solve(bt) << endl;

    return 0;
}