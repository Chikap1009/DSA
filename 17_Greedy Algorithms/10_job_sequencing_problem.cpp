#include <bits/stdc++.h>
using namespace std;

vector<int> JobSequencing(vector<int> &id, vector<int> &deadline, vector<int> &profit) {
    vector<pair<int,int>> v;
    int maxTime = INT_MIN;

    for (int i=0 ; i<profit.size() ; i++) {
        maxTime = max(maxTime, deadline[i]);
        v.push_back({profit[i], deadline[i]});
    }

    sort(v.begin(),v.end());

    int totalProfit = 0;
    int totalJobs = 0;

    vector<int> booked (maxTime+1,0);

    for (int i=v.size()-1 ; i>=0 ; i--) {
        for (int j=v[i].second ; j>0 ; j--) {
            if (booked[j] == 0) {
                totalProfit += v[i].first;
                totalJobs++;
                booked[j] = 1;
                break;
            }
        }
    }

    return {totalJobs, totalProfit};
}

int main() {
    vector<int> id = {1,2,3,4}, deadline = {4,1,1,1}, profit = {20,1,40,30};

    vector<int> ans = JobSequencing(id, deadline, profit);
    cout << ans[0] << " " << ans[1] << endl;

    return 0;
}