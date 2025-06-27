#include <bits/stdc++.h>
using namespace std;

bool isCycle(vector<vector<int>>& graph) {
    int n = graph.size();
    vector<int> indegree(n,0);
    for (int i=0 ; i<n ; i++) {
        for (auto it : graph[i]) {
            indegree[it]++;
        }
    }

    queue<int> q;
    for (int i=0 ; i<n ; i++) {
        if (indegree[i] == 0) q.push(i);
    }

    int count = 0;
    while(!q.empty()) {
        int node = q.front();
        q.pop();
        count++;

        for (auto it : graph[node]) {
            indegree[it]--;
            if (indegree[it] == 0) q.push(it);
        }
    }

    return !(count == n); // If count equals number of nodes, no cycle exists
}

int main() {
    vector<vector<int>> graph = {
        {1, 2}, // Node 0 points to Nodes 1 and 2
        {3},    // Node 1 points to Node 3
        {3},    // Node 2 also points to Node 3
        {},     // Node 3 has no outgoing edges
        {5},    // Node 4 points to Node 5
        {}      // Node 5 has no outgoing edges
    };

    bool result = isCycle(graph);

    if (result) {
        cout << "Graph has no cycle, topological sort possible." << endl;
    }
    else {
        cout << "Graph has a cycle, topological sort not possible." << endl;
    }

    return 0;
}