#include <bits/stdc++.h>
using namespace std;

void dfs(int node, vector<int>& visited, vector<vector<int>>& graph, stack<int>& st) {
    visited[node] = 1;
    for (int it : graph[node]) {
        if (!visited[it]) {
            dfs(it, visited, graph, st);
        }
    }
    st.push(node);
}

void dfs1(int node, vector<int>& visited, vector<vector<int>>& transposed) {
    visited[node] = 1;
    for (int it : transposed[node]) {
        if (!visited[it]) {
            dfs1(it, visited, transposed);
        }
    }
}

int kosaraju(vector<vector<int>>& graph) {
    int n = graph.size();
    
    vector<int> visited(n,0);
    stack<int> st;
    // Step 1: Fill vertices in stack according to their finishing times
    for (int i=0 ; i<n ; i++) {
        if (!visited[i]) {
            dfs(i, visited, graph, st);
        }
    }

    // Step 2: Create the transposed graph
    vector<vector<int>> transposed(n);
    for (int i = 0; i < n; i++) {
        for (int it : graph[i]) {
            transposed[it].push_back(i);
        }
        visited[i] = 0; // Reset visited for the next DFS
    }

    // Step 3: Process all vertices in order defined by stack
    int scc = 0;
    while(!st.empty()) {
        int node = st.top();
        st.pop();
        if (!visited[node]) {
            scc++;
            dfs1(node, visited, transposed);
        }
    }

    return scc;
}

int main() {
    // Example usage
    vector<vector<int>> graph = {
        {1},        // 0 -> 1
        {2},        // 1 -> 2
        {0},        // 2 -> 0
        {1, 4},     // 3 -> 1, 4
        {5},        // 4 -> 5
        {3}         // 5 -> 3
    };

    int sccCount = kosaraju(graph);
    cout << "Number of strongly connected components: " << sccCount << endl;

    return 0;
}