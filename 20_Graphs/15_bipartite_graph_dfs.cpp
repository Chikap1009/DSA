#include <bits/stdc++.h>
using namespace std;

bool dfs(int node, vector<vector<int>>& graph, vector<int>& marked, int mark) {
    marked[node] = mark;
    
    for (auto adjNode : graph[node]) {
        if (marked[adjNode] == -1) {
            if (!dfs(adjNode, graph, marked, !mark)) return false;
        }
        else {
            if (marked[adjNode] == mark) return false;
        }
    }

    return true;
}

bool isBipartite(vector<vector<int>>& graph) {
    int n = graph.size();
    vector<int> marked(n,-1);

    for (int i=0 ; i<n ; i++) {
        if (marked[i] == -1) {
            if (!dfs(i,graph,marked,0)) return false;
        }
    }

    return true;
}

int main() {
    vector<vector<int>> graph = {{1,3},{0,2},{1,3},{0,2}};
    cout << (isBipartite(graph) ? "true" : "false") << endl; // Output: true

    graph = {{1,2,3},{0,2},{0,1,3},{0,2}};
    cout << (isBipartite(graph) ? "true" : "false") << endl; // Output: false

    return 0;
}