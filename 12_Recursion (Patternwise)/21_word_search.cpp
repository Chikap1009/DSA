#include <bits/stdc++.h>
using namespace std;

bool check(vector<vector<char>>& board, string word, int row, int column, vector<vector<int>>& seen, int wordIndex = 1)
{
    if (wordIndex == word.length()) return true;

    if (row-1>=0 && board[row-1][column] == word[wordIndex] && seen[row-1][column] == 0)
    {
        seen[row-1][column] = 1;
        if (check(board,word,row-1,column,seen,wordIndex+1)) return true; //up
        seen[row-1][column] = 0;
    }
    if (row+1<board.size() && board[row+1][column] == word[wordIndex] && seen[row+1][column] == 0)
    {
        seen[row+1][column] = 1;
        if (check(board,word,row+1,column,seen,wordIndex+1)) return true; //down
        seen[row+1][column] = 0;
    }
    if (column-1>=0 && board[row][column-1] == word[wordIndex] && seen[row][column-1] == 0)
    {
        seen[row][column-1] = 1;
        if (check(board,word,row,column-1,seen,wordIndex+1)) return true; //left
        seen[row][column-1] = 0;
    }
    if (column+1<board[0].size() && board[row][column+1] == word[wordIndex] && seen[row][column+1] == 0)
    {
        seen[row][column+1] = 1;
        if (check(board,word,row,column+1,seen,wordIndex+1)) return true; //right
        seen[row][column+1] = 0;
    }
    return false;
}

bool exist(vector<vector<char>>& board, string word) {
    int n = board.size();
    int m = board[0].size();

    // if (n*m < word.length()) return false;

    vector<vector<int>> seen;
    for (int i=0 ; i<n ; i++)
    {
        vector<int> temp(m,0);
        seen.push_back(temp);
    }
    for (int i=0 ; i<n ; i++)
    {
        for (int j=0 ; j<m ; j++)
        {
            if (board[i][j] == word[0])
            {
                seen[i][j] = 1;
                if (check(board,word,i,j,seen)) return true;
                seen[i][j] = 0;
            }
        }
    }
    return false;
}

int main()
{
    vector<vector<char>> board = {{'a','a','b','a','a','b'},{'a','a','b','b','b','a'},{'a','a','a','a','b','a'},{'b','a','b','b','a','b'},{'a','b','b','a','b','a'},{'b','a','a','a','a','b'}};

    string word = "bbbaabbbbbab";

    cout << exist(board,word) << endl;

    return 0;
}