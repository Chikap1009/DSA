#include <bits/stdc++.h>
using namespace std;

void dfs(int i, vector<vector<int>> isConnected, vector<int>& visited) {
    visited[i] = 1;
    for (int j=0 ; j<isConnected.size() ; j++) {
        if (isConnected[i][j] == 1 && visited[j] == 0) {
            dfs(j, isConnected, visited);
        }
    }
}

int findCircleNum(vector<vector<int>>& isConnected) {
    int provinces = 0;
    int n = isConnected.size();
    vector<int> visited(n,0);
    for (int i=0 ; i<n ; i++) {
        if (visited[i] == 0) {
            provinces++;
            dfs(i, isConnected, visited);
        }
    }
    return provinces;
}

int main() {
    vector<vector<int>> isConnected = {
        {1, 1, 0},
        {1, 1, 0},
        {0, 0, 1}
    };
    cout << "Number of provinces: " << findCircleNum(isConnected) << endl;
    return 0;
}