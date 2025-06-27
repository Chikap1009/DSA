#include <bits/stdc++.h>
using namespace std;

int minimumEffortPath(vector<vector<int>>& heights) {
    int m = heights.size();
    int n = heights[0].size();

    priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;
    vector<vector<int>> efforts(m, vector<int> (n, 1e9));

    pq.push({0,{0,0}});
    efforts[0][0] = 0;

    while(!pq.empty()) {
        int effort = pq.top().first;
        int row = pq.top().second.first;
        int col = pq.top().second.second;

        if (row == m-1 && col == n-1) return effort;
        
        pq.pop();

        int drow[4] = {-1,0,1,0};
        int dcol[4] = {0,1,0,-1};

        for (int i=0 ; i<4 ; i++) {
            int nrow = row + drow[i];
            int ncol = col + dcol[i];

            if (nrow >= 0 && nrow < m && ncol >= 0 && ncol < n &&
                max(abs(heights[nrow][ncol] - heights[row][col]), effort) <
                efforts [nrow][ncol]) {
                    efforts[nrow][ncol] = max(abs(heights[nrow][ncol] - heights[row][col]), effort);
                    pq.push({efforts[nrow][ncol], {nrow,ncol}});
                }
        }
    }

    return -1;
}

int main() {
    vector<vector<int>> heights = {{1,2,3},{3,8,4},{5,3,5}};
    cout << minimumEffortPath(heights) << endl; // Output: 1
    return 0;
}