#include <bits/stdc++.h>
using namespace std;

void dfs(int r, int c, vector<vector<int>>& grid, vector<vector<bool>>& visited, vector<pair<int, int>>& shape, int baseR, int baseC) {
    int m = grid.size(), n = grid[0].size();
    visited[r][c] = true;
    shape.push_back({r - baseR, c - baseC});

    int dr[4] = {-1, 0, 1, 0};
    int dc[4] = {0, 1, 0, -1};

    for (int i = 0; i < 4; i++) {
        int nr = r + dr[i], nc = c + dc[i];
        if (nr >= 0 && nr < m && nc >= 0 && nc < n &&
            grid[nr][nc] == 1 && !visited[nr][nc]) {
            dfs(nr, nc, grid, visited, shape, baseR, baseC);
        }
    }
}

vector<pair<int, int>> normalize(vector<pair<int, int>>& shape) {
    vector<vector<pair<int, int>>> transforms(8);

    for (auto [x, y] : shape) {
        transforms[0].push_back({ x,  y});
        transforms[1].push_back({ x, -y});
        transforms[2].push_back({-x,  y});
        transforms[3].push_back({-x, -y});
        transforms[4].push_back({ y,  x});
        transforms[5].push_back({ y, -x});
        transforms[6].push_back({-y,  x});
        transforms[7].push_back({-y, -x});
    }

    for (auto& t : transforms) {
        sort(t.begin(), t.end());
        int baseX = t[0].first, baseY = t[0].second;
        for (auto& p : t) {
            p.first -= baseX;
            p.second -= baseY;
        }
    }

    return *min_element(transforms.begin(), transforms.end());
}

int numDistinctIslands2(vector<vector<int>>& grid) {
    int m = grid.size(), n = grid[0].size();
    vector<vector<bool>> visited(m, vector<bool>(n, false));
    set<vector<pair<int, int>>> uniqueShapes;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 1 && !visited[i][j]) {
                vector<pair<int, int>> shape;
                dfs(i, j, grid, visited, shape, i, j);
                uniqueShapes.insert(normalize(shape));
            }
        }
    }

    return uniqueShapes.size();
}

int main() {
    vector<vector<int>> grid = {
        {1, 1, 0, 0, 0},
        {1, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 1},
        {0, 0, 0, 1, 1}
    };

    cout << "Number of distinct islands: " << numDistinctIslands2(grid) << endl;

    return 0;
}