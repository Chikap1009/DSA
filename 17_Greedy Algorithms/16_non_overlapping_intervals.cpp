#include <bits/stdc++.h>
using namespace std;

int eraseOverlapIntervals(vector<vector<int>>& intervals) {
    vector<pair<int,int>> interval;
    for (int i=0 ; i<intervals.size() ; i++) {
        interval.push_back({intervals[i][1],intervals[i][0]});
    }
    sort(interval.begin(), interval.end());
    int count = 1;
    int last = interval[0].first;
    for (int i=1 ; i<interval.size() ; i++) {
        if (interval[i].second >= last) {
            count++;
            last = interval[i].first;
        }
    }
    return (interval.size()-count);
}

int main() {
    vector<vector<int>> intervals = {{1,2},{2,3},{3,4},{1,3}};

    cout << eraseOverlapIntervals(intervals) << endl;

    return 0;
}