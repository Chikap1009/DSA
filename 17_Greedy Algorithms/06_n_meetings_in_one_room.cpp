#include <bits/stdc++.h>
using namespace std;

// int maxMeetings(vector<int>& start, vector<int>& end) {
//     vector<pair<int,int>> meetings;
//     for (int i=0 ; i<start.size() ; i++) {
//         meetings.push_back({end[i],start[i]});
//     }
    
//     sort(meetings.begin(),meetings.end());
    
//     int count = 1;
//     int freeTime = meetings[0].first;
    
//     for (int i=1 ; i<start.size() ; i++) {
//         if (meetings[i].second > freeTime) {
//             count++;
//             freeTime = meetings[i].first;
//         }
//     }
    
//     return count;
// }

struct Meeting {
    int start;
    int end;
    int position; // 0-based
};

bool comp(Meeting m1, Meeting m2) {
    if (m1.end <= m2.end) return true;
    return false;
}

int maxMeetings(vector<int>& start, vector<int>& end) {

    int n = start.size();
    Meeting arr[n];

    for (int i=0 ; i<n ; i++) {
        arr[i].start = start[i];
        arr[i].end = end[i];
        arr[i].position = i;
    }
    
    sort(arr,arr+n,comp);
    
    int count = 1;
    int freeTime = arr[0].end;

    vector<int> positions = {arr[0].position};
    
    for (int i=1 ; i<n ; i++) {
        if (arr[i].start > freeTime) {
            count++;
            freeTime = arr[i].end;
            positions.push_back(arr[i].position);
        }
    }
    
    return count;
}

int main() {

    vector<int> start = {7,18,24}, end = {30,26,28};

    cout << maxMeetings(start, end) << endl;

    return 0;
}