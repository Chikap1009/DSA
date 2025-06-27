#include <bits/stdc++.h>
using namespace std;

void dfs(int node, int parent, vector<int>& visited, vector<int>& timeIn, vector<int>& low, vector<int>& mark, vector<vector<int>>& graph, int& timer) {
    visited[node] = 1;
    timeIn[node] = low[node] = timer;
    timer++;

    int children = 0;

    for (auto it : graph[node]) {
        if (it == parent) continue; // Skip the edge to the parent node

        if (!visited[it]) {
            dfs(it, node, visited, timeIn, low, mark, graph, timer);
            low[node] = min(low[node], low[it]);

            if (low[it] >= timeIn[node] && parent != -1) {
                mark[node] = 1; // Node is an articulation point
            }

            children++;
        }

        else {
            low[node] = min(low[node], timeIn[it]);
        }
    }

    if (parent == -1 && children > 1) {
        mark[node] = 1; // Root node is an articulation point if it has more than one child
    }
}
vector<int> articulationsPoints (vector<vector<int>>& graph) {
    int n = graph.size();
    vector<int> visited(n,0);
    vector<int> timeIn(n);
    vector<int> low(n);
    vector<int> mark(n,0);
    vector<int> articulationPoints;

    int timer = 0;

    for (int i=0  ; i<n ; i++) {
        if (!visited[i]) {
            dfs(i, -1, visited, timeIn, low, mark, graph, timer);
        }
    }

    for (int i=0; i<n; i++) {
        if (mark[i]) {
            articulationPoints.push_back(i);
        }
    }

    return articulationPoints;
}

int main() {
    vector<vector<int>> graph = {
        {1, 2},
        {0, 2, 3},
        {0, 1, 3},
        {1, 2, 4},
        {3}
    };

    vector<int> articulationPoints = articulationsPoints(graph);
    cout << "Articulation Points in the graph: ";
    for (int point : articulationPoints) {
        cout << point << " ";
    }
    cout << endl;

    return 0;
}