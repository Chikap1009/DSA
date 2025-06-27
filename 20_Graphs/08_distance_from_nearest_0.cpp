#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
    int m = mat.size();
    int n = mat[0].size();
    vector<vector<int>> ans = mat;
    queue<pair<pair<int,int>,int>> q;
    for (int i=0 ; i<m ; i++) {
        for (int j=0 ; j<n ; j++) {
            if (mat[i][j] == 0) q.push({{i,j},0});
            else ans[i][j] = -1;
        }
    }
    
    int drow[4] = {-1, 0, 1, 0};
    int dcol[4] = {0, 1, 0, -1};

    while(!q.empty()) {
            int row = q.front().first.first;
            int col = q.front().first.second;
            int dist = q.front().second;
            q.pop();

            for (int i=0 ; i<4 ; i++) {
                int nrow = row + drow[i];
                int ncol = col + dcol[i];

                if (nrow >= 0 && nrow < m &&
                    ncol >= 0 && ncol < n &&
                    ans[nrow][ncol] == -1) {
                        ans[nrow][ncol] = dist+1;
                        q.push({{nrow,ncol},dist+1});
                    }
        }
    }

    return ans;
}

int main() {
    vector<vector<int>> mat = {{0,0,0},{0,1,0},{1,1,1}};
    vector<vector<int>> result = updateMatrix(mat);
    for (const auto& row : result) {
        for (const auto& val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
    return 0;
}