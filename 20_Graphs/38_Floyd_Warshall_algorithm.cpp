#include <bits/stdc++.h>
using namespace std;

void printMatrix(const vector<vector<int>>& matrix) {
    for (auto row : matrix) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
}

void floydWarshall(vector<vector<int>>& dist) {
    int n = dist.size();
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i == j) {
                dist[i][j] = 0; // Distance to self is zero
            } else if (dist[i][j] == -1) {
                dist[i][j] = 1e9; // No edge means infinite distance
            }
        }
    }

    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    // Check for negative cycles
    for (int i = 0; i < n; ++i) {
        if (dist[i][i] < 0) {
            cout << "Negative cycle detected!" << endl;
            return;
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (dist[i][j] == 1e9) {
                dist[i][j] = -1; // Convert infinite distance back to -1 for output
            }
        }
    }
}

int main() {
    vector<vector<int>> dist = {
        {0, 3, -1, -1},
        {-1, 0, 1, -1},
        {-1, -1, 0, 2},
        {-1, -1, -1, 0}
    };

    cout << "Initial distance matrix:" << endl;
    printMatrix(dist);

    floydWarshall(dist);

    cout << "Distance matrix after Floyd-Warshall algorithm:" << endl;
    printMatrix(dist);

    return 0;
}