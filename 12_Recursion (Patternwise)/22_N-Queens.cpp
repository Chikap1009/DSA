#include <bits/stdc++.h>
using namespace std;

// bool canPlace(int row, int column, vector<string> board, int n)
// {
//     int dupRow = row;
//     int dupCol = column;

//     while(dupRow >= 0 && dupCol >= 0)
//     {
//         if (board[dupRow][dupCol] == 'Q') return false;
//         dupRow--;
//         dupCol--;
//     }

//     dupRow = row;
//     dupCol = column;

//     while(dupRow >= 0)
//     {
//         if (board[dupRow][dupCol] == 'Q') return false;
//         dupRow--;
//     }

//     dupRow = row;

//     while(dupRow >= 0 && dupCol < n)
//     {
//         if (board[dupRow][dupCol] == 'Q') return false;
//         dupRow--;
//         dupCol++;
//     }

//     return true;
// }

// void solve(int n, vector<vector<string>> &ans, vector<string> &board, int row = 0)
// {
//     if (row == n)
//     {
//         ans.push_back(board);
//         return;
//     }

//     for (int column = 0 ; column < n ; column++)
//     {
//         if (canPlace(row, column, board, n))
//         {
//             board[row][column] = 'Q';
//             solve(n,ans,board,row+1);
//             board[row][column] = '.';
//         }
//     }
// }

// vector<vector<string>> solveNQueens(int n) {
//     vector<vector<string>> ans;
//     vector<string> board;
//     string s(n,'.');
//     for (int i=0 ; i<n ; i++)
//     {
//         board.push_back(s);
//     }
//     solve(n,ans,board);
//     return ans;
// }

void solve(int n, vector<vector<string>> &ans, vector<string> &board, vector<int>& upperColumn, vector<int>&leftDiagonal, vector<int>&rightDiagonal, int row = 0)
{
    if (row == n)
    {
        ans.push_back(board);
        return;
    }

    for (int column = 0 ; column < n ; column++)
    {
        if (upperColumn[column] == 0 && leftDiagonal[n-1 + row-column] == 0 && rightDiagonal[row+column] == 0)
        {
            board[row][column] = 'Q';
            upperColumn[column] = 1;
            leftDiagonal[n-1 + row-column] = 1;
            rightDiagonal[row+column] = 1;
            solve(n,ans,board,upperColumn,leftDiagonal,rightDiagonal,row+1);
            board[row][column] = '.';
            upperColumn[column] = 0;
            leftDiagonal[n-1 + row-column] = 0;
            rightDiagonal[row+column] = 0;
        }
    }
}

vector<vector<string>> solveNQueens(int n) {
    vector<vector<string>> ans;
    vector<string> board;
    string s(n,'.');
    for (int i=0 ; i<n ; i++)
    {
        board.push_back(s);
    }
    vector<int> upperColumn(n,0);
    vector<int> leftDiagonal(2*n-1,0);
    vector<int> rightDiagonal(2*n-1,0);
    solve(n,ans,board,upperColumn,leftDiagonal,rightDiagonal);
    return ans;
}


int main()
{
    vector<vector<string>> ans = solveNQueens(4);

    for (auto x : ans)
    {
        for (auto y : x)
        {
            cout << y << endl;
        }
        cout << endl;
    }

    return 0;
}