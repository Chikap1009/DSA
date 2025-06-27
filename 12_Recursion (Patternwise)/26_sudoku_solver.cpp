#include <bits/stdc++.h>
using namespace std;

// int getBoxNumber(int i, int j)
// {
//     if (i<=2 && j<=2) return 0;
//     else if (i<=2 && j<=5) return 1;
//     else if (i<=2) return 2;
//     else if (i<=5 && j<=2) return 3;
//     else if (i<=5 && j<=5) return 4;
//     else if (i<=5) return 5;
//     else if (i<=8 && j<=2) return 6;
//     else if (i<=8 && j<=5) return 7;
//     else if (i<=8) return 8;
//     return -1;
// }

// bool sudoku(vector<vector<char>>& board, vector<vector<int>>& rows, vector<vector<int>>& columns, vector<vector<int>>& boxes, vector<vector<char>> &ans, int row = 0, int column = 0)
// {
//     if (row == 9)
//     {
//         ans = board;
//         return true;
//     }

//     if (board[row][column] != '.')
//     {
//         if (column+1 < 9) 
//         {
//             if (sudoku(board,rows,columns,boxes,ans,row,column+1)) return true;
//         }
//         else
//         {
//             if (sudoku(board,rows,columns,boxes,ans,row+1,0)) return true;
//         }
//     }
//     else
//     {
//         for (int i=1 ; i<=9 ; i++)
//         {
//             if (find(rows[row].begin(),rows[row].end(),i) != rows[row].end()) continue;
//             if (find(columns[column].begin(),columns[column].end(),i) != columns[column].end()) continue;          
//             int box = getBoxNumber(row,column);
//             if (find(boxes[box].begin(),boxes[box].end(),i) != boxes[box].end()) continue;
//             char c = (char)(i + '0');
//             board[row][column] = c;
//             rows[row].push_back(i);
//             columns[column].push_back(i);
//             boxes[box].push_back(i);
//             if (column+1 < 9) 
//             {
//                 if (sudoku(board,rows,columns,boxes,ans,row,column+1)) return true;
//             }
//             else
//             {
//                 if (sudoku(board,rows,columns,boxes,ans,row+1,0)) return true;
//             }
//             board[row][column] = '.';
//             rows[row].pop_back();
//             columns[column].pop_back();
//             boxes[box].pop_back();
//         }
//         return false;
//     }
//     return false;
// }

// void solveSudoku(vector<vector<char>>& board) {
//     vector<vector<int>> rows(9);
//     vector<vector<int>> columns(9);
//     vector<vector<int>> boxes(9);
//     vector<vector<char>> ans;
//     for (int i=0 ; i<9 ; i++)
//     {
//         for (int j=0 ; j<9 ; j++)
//         {
//             if (board[i][j] != '.')
//             {
//                 int num = board[i][j] - '0';
//                 rows[i].push_back(num);
//                 columns[j].push_back(num);
//                 boxes[getBoxNumber(i,j)].push_back(num);
//             }
//         }
//     }
//     sudoku(board, rows, columns, boxes, ans);
//     board = ans;
// }

bool isValid(vector<vector<char>>& board, int row, int column, char c)
{
    for (int i=0 ; i<9 ; i++)
    {
        if (board[i][column] == c) return false;
        if (board[row][i] == c) return false;
        if (board[3*(row/3) + i/3][3*(column/3) + i%3] == c) return false; 
    }
    return true;
}

bool solve(vector<vector<char>>& board)
{
    for (int i=0 ; i<9 ; i++)
    {
        for (int j=0 ; j<9 ; j++)
        {
            if (board[i][j] == '.')
            {
                for (char c='1' ; c<='9' ; c++)
                {
                    if (isValid(board, i, j, c))
                    {
                        board[i][j] = c;
                        if (solve(board)) return true;
                        else board[i][j] = '.';
                    }
                }
                return false;
            }
        }
    }
    return true;
}

void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }

int main()
{
    vector<vector<char>> board = {{'5','3','.','.','7','.','.','.','.'},
 {'6','.','.','1','9','5','.','.','.'},
 {'.','9','8','.','.','.','.','6','.'},
 {'8','.','.','.','6','.','.','.','3'},
 {'4','.','.','8','.','3','.','.','1'},
 {'7','.','.','.','2','.','.','.','6'},
 {'.','6','.','.','.','.','2','8','.'},
 {'.','.','.','4','1','9','.','.','5'},
 {'.','.','.','.','8','.','.','7','9'}};

 solveSudoku(board);

 for (auto x : board)
 {
    for (auto y : x)
    {
        cout << y << " ";
    }
    cout << endl;
 }

 return 0;
}