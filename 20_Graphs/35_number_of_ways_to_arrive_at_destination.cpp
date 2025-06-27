#include <bits/stdc++.h>
using namespace std;

int countPaths(int n, vector<vector<int>>& roads) {
    vector<vector<pair<long long,long long>>> graph(n);
    for (auto it : roads) {
        graph[it[0]].push_back({it[1],it[2]});
        graph[it[1]].push_back({it[0],it[2]});
    }

    priority_queue<pair<long long,long long>, vector<pair<long long,long long>>, greater<pair<long long,long long>>> pq;
    vector<long long> times(n,LLONG_MAX);
    vector<long long> ways(n,0);

    pq.push({0,0});
    times[0] = 0;
    ways[0] = 1;

    long long mod = 1e9 + 7;

    while(!pq.empty()) {
        long long time = pq.top().first;
        long long node = pq.top().second;
        pq.pop();

        for (auto it : graph[node]) {
            long long adjNode = it.first;
            long long t = it.second;

            if (time + t < times[adjNode]) {
                times[adjNode] = time + t;
                pq.push({times[adjNode],adjNode});
                ways[adjNode]=ways[node];
            }
            else if (time + t == times[adjNode]) {
                ways[adjNode] = (ways[adjNode] + ways[node]) % mod;
            }
        }
    }

    return ways[n-1] % mod;
}

int main() {
    int n = 7;
    vector<vector<int>> roads = {{0,6,7},{0,1,2},{1,2,3},{1,3,3},{6,3,3},{3,5,1},{6,5,1},{2,5,1},{0,4,5},{4,6,2}};
    cout << countPaths(n, roads) << endl; // Output: 4
    return 0;
}