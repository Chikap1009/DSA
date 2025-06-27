#include <bits/stdc++.h>
using namespace std;

// vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
//     if (image[sr][sc] == color) return image;
//     int m = image.size();
//     int n = image[0].size();
//     vector<vector<int>> modified = image;
//     modified[sr][sc] = color;
//     int og = image[sr][sc];
//     int drow[4] = {-1, 0, 1, 0};
//     int dcol[4] = {0, 1, 0, -1};
//     queue<pair<int,int>> q;
//     q.push({sr,sc});
//     while(!q.empty()) {
//         int row = q.front().first;
//         int col = q.front().second;
//         q.pop();
//         for (int i=0 ; i<4 ; i++) {
//             int nrow = row + drow[i];
//             int ncol = col + dcol[i];
//             if (nrow >= 0 && nrow < m &&
//                 ncol >= 0 && ncol < n &&
//                 modified[nrow][ncol] == og) {
//                     modified[nrow][ncol] = color;
//                     q.push({nrow,ncol});
//                 }
//         }
//     }
//     return modified;
// }

void dfs(vector<vector<int>>& result, vector<vector<int>>& image, int sr, int sc, int initialColor, int color) {
    if (sr < 0 || sr >= image.size() || sc < 0 || sc >= image[0].size() || result[sr][sc] != initialColor) {
        return; // Out of bounds or not the initial color
    }
    result[sr][sc] = color; // Fill the color
    // Explore all four directions
    dfs(result, image, sr - 1, sc, initialColor, color); // Up
    dfs(result, image, sr + 1, sc, initialColor, color); // Down
    dfs(result, image, sr, sc - 1, initialColor, color); // Left
    dfs(result, image, sr, sc + 1, initialColor, color); // Right
}

vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
    int initialColor = image[sr][sc];
    if (initialColor == color) return image; // No need to fill if the color is the same
    vector<vector<int>> result = image;
    dfs(result, image, sr, sc, initialColor, color);
    return result;
}

int main() {
    vector<vector<int>> image = {{1,1,1},{1,1,0},{1,0,1}};
    int sr = 1, sc = 1, color = 2;
    vector<vector<int>> result = floodFill(image, sr, sc, color);
    for (const auto& row : result) {
        for (const auto& val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
    return 0;
}