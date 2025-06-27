#include <bits/stdc++.h>
using namespace std;

vector<int> topoSort(vector<vector<int>>& graph) {
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

    vector<int> ans;
    while(!q.empty()) {
        int node = q.front();
        q.pop();
        ans.push_back(node);

        for (auto it : graph[node]) {
            indegree[it]--;
            if (indegree[it] == 0) q.push(it);
        }
    }

    return ans;
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

    vector<int> result = topoSort(graph);

    cout << "Topological Sort Order: ";
    for (int node : result) {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}