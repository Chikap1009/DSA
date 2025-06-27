#include <bits/stdc++.h>
using namespace std;

int networkDelayTime(vector<vector<int>>& times, int n, int k) {
    vector<vector<pair<int,int>>> graph(n+1);
    for (auto it : times) {
        graph[it[0]].push_back({it[1],it[2]});
    }

    vector<int> time(n+1, 1e9);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

    time[k] = 0;
    pq.push({0,k});

    while(!pq.empty()) {
        int t = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        for (auto it : graph[node]) {
            int adjNode = it.first;
            int timeTaken = it.second;

            if (t + timeTaken < time[adjNode]) {
                time[adjNode] = t + timeTaken;
                pq.push({time[adjNode], adjNode});
            }
        }
    }

    int minTime = INT_MIN;
    for (int i=1 ; i<=n ; i++) {
        if (time[i] == 1e9) return -1;
        minTime = max(minTime, time[i]);
    }
    return minTime;
}

int main() {
    vector<vector<int>> times = {{2,1,1},{2,3,1},{3,4,1}};
    int n = 4;
    int k = 2;

    int result = networkDelayTime(times, n, k);
    cout << "The time taken for all nodes to receive the signal is: " << result << endl; // Output: 2

    return 0;
}