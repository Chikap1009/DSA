#include <bits/stdc++.h>
using namespace std;

int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
    vector<vector<int>> cost(n, vector<int> (n,1e9));

    for (int i=0 ; i<n ; i++) {
        cost[i][i] = 0;
    }

    for (auto it : edges) {
        int u = it[0];
        int v = it[1];
        int wt = it[2];

        cost[u][v] = wt;
        cost[v][u] = wt;
    }

    for (int k=0 ; k<n ; k++) {
        for (int i=0 ; i<n ; i++) {
            for (int j=0 ; j<n ; j++) {
                cost[i][j] = min(cost[i][j], cost[i][k] + cost[k][j]);
            }
        }
    }

    int minCities = n+1;
    int city = -1;

    for (int i=0 ; i<n ; i++) {
        int count = 0;
        for (int j=0 ; j<n ; j++) {
            if (cost[j][i] <= distanceThreshold) count++;
        }
        if (count <= minCities) {
            minCities = count;
            city = i;
        }
    }

    return city;
}

int main() {
    int n = 4;
    vector<vector<int>> edges = {{0,1,3},{1,2,1},{1,3,4},{2,3,1}};
    int distanceThreshold = 4;

    cout << findTheCity(n, edges, distanceThreshold) << endl; // Output: 3

    return 0;
}