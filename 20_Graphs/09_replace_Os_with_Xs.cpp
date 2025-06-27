#include <bits/stdc++.h>
using namespace std;

void dfs(int row, int column, vector<vector<char>>& board, vector<vector<int>>& visited) {
    visited[row][column] = 1;

    int drow[4] = {-1, 0, 1, 0};
    int dcol[4] = {0, 1, 0, -1};

    for (int i=0 ; i<4 ; i++) {
        int nrow = row + drow[i];
        int ncol = column + dcol[i];

        if (nrow < 0 || nrow >= board.size() || ncol < 0 || ncol >= board[0].size()) continue;

        if (!visited[nrow][ncol] && board[nrow][ncol] == 'O') {
                dfs(nrow,ncol,board,visited);
            }
        }
}

void solve(vector<vector<char>>& board) {
    int m = board.size();
    int n = board[0].size();

    vector<vector<int>> visited(m, vector<int> (n,0));

    for (int j=0 ; j<n ; j++) {
        if (board[0][j] == 'O') {
            dfs(0,j,board,visited);
        }
        if (board[m-1][j] == 'O') {
            dfs(m-1,j,board,visited);
        }
    }
    for (int i=1 ; i<m-1 ; i++) {
        if (board[i][0] == 'O') {
            dfs(i,0,board,visited);
        }
        if (board[i][n-1] == 'O') {
            dfs(i,n-1,board,visited);
        }
    }

    for (int i=0 ; i<m ; i++) {
        for (int j=0 ; j<n ; j++) {
            if (!visited[i][j]) board[i][j] = 'X';
        }
    }
}

int main() {
    vector<vector<char>> board = {
        {'X', 'X', 'X', 'X'},
        {'X', 'O', 'O', 'X'},
        {'X', 'X', 'O', 'X'},
        {'X', 'O', 'X', 'X'}
    };

    solve(board);

    for (const auto& row : board) {
        for (char cell : row) {
            cout << cell << " ";
        }
        cout << endl;
    }

    return 0;
}