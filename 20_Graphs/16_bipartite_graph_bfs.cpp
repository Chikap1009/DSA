#include <bits/stdc++.h>
using namespace std;

bool isBipartite(vector<vector<int>>& graph) {
    int n = graph.size();
    queue<int> q;
    vector<int> marked(n, -1);
    q.push(0);
    marked[0] = 0;

    while(!q.empty()) {
        int node = q.front();
        q.pop();

        for (auto it : graph[node]) {
            if (marked[it] == -1) {
                marked[it] = 1 - marked[node];
                q.push(it);
            }
            else if (marked[it] == marked[node]) return false;
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