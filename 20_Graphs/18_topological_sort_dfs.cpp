#include <bits/stdc++.h>
using namespace std;

void dfs(int node, vector<vector<int>>& graph, vector<int> &visited, stack<int> &st) {
    visited[node] = 1;

    for (auto it : graph[node]) {
        if (!visited[it]) {
            dfs(it, graph, visited, st);
        }
    }

    st.push(node);
}

vector<int> topoSort(vector<vector<int>>& graph) {
    int n = graph.size();
    vector<int> visited(n,0);
    stack<int> st;

    for (int i=0 ; i<n ; i++) {
        if (!visited[i]) {
            dfs(i, graph, visited, st);
        }
    }

    vector<int> ans;
    while(!st.empty()) {
        ans.push_back(st.top());
        st.pop();
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