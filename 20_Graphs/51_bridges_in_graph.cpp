#include <bits/stdc++.h>
using namespace std;

void dfs(int node, int parent, vector<vector<int>>& graph, vector<int>& visited, vector<int>& timeToReach, vector<int>& leastTime, int& timer, vector<vector<int>>& bridges) {
    visited[node] = 1;
    timeToReach[node] = leastTime[node] = timer;
    timer++;

    for (auto adjNode : graph[node]) {
        if (adjNode == parent) continue;

        if (!visited[adjNode]) {
            dfs(adjNode, node, graph, visited, timeToReach, leastTime, timer, bridges);
            leastTime[node] = min(leastTime[node], leastTime[adjNode]);

            if (leastTime[adjNode] > timeToReach[node]) bridges.push_back({node,adjNode});
        }
        else {
            leastTime[node] = min(leastTime[node], leastTime[adjNode]);
        }
    }
}
vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
    vector<vector<int>> graph (n);
    for (auto it : connections) {
        graph[it[0]].push_back(it[1]);
        graph[it[1]].push_back(it[0]);
    }

    vector<int> visited (n,0);

    vector<int> timeToReach(n);
    vector<int> leastTime(n);

    int timer = 1;

    vector<vector<int>> bridges;

    dfs(0, -1, graph, visited, timeToReach, leastTime, timer, bridges);

    return bridges;
}

int main() {
    int n = 4;
    vector<vector<int>> connections = {{0,1},{1,2},{2,0},{1,3}};
    vector<vector<int>> result = criticalConnections(n, connections);
    
    for (const auto& bridge : result) {
        cout << "[" << bridge[0] << ", " << bridge[1] << "]" << endl;
    }
    
    return 0;
}