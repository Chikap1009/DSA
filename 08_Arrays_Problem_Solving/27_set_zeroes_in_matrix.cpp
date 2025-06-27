#include <bits/stdc++.h>
using namespace std;

void makeRow(int row, vector<vector<int>>& matrix)
{
    int n = matrix[0].size();
    for (int j=0 ; j<n ; j++)
    {
        if (matrix[row][j] != 0)
        {
            matrix[row][j] = -1;
        }
    }
}

void makeCol(int col, vector<vector<int>>& matrix)
{
    int m = matrix.size();
    for (int i=0 ; i<m ; i++)
    {
        if (matrix[i][col] != 0)
        {
            matrix[i][col] = -1;
        }
    }
}

void brute_setZeroes(vector<vector<int>>& matrix)
{
    int m = matrix.size();
    int n = matrix[0].size();
    for (int i=0 ; i<m ; i++)
    {
        for (int j=0 ; j<n ; j++)
        {
            if (matrix[i][j] == 0)
            {
                makeRow(i, matrix);
                makeCol(j, matrix);
            }
        }
    }

    for (int i=0 ; i<m ; i++)
    {
        for (int j=0 ; j<n ; j++)
        {
            if (matrix[i][j] == -1)
            {
                matrix[i][j] = 0;
            }
        }
    }
}

void better_setZeroes(vector<vector<int>>& matrix)
{
    int m = matrix.size();
    int n = matrix[0].size();
    vector<int> row(m,1);
    vector<int> col(n,1);

    for (int i=0 ; i<m ; i++)
    {
        for (int j=0 ; j<n ; j++)
        {
            if (matrix[i][j] == 0)
            {
                row[i] = 0;
                col[j] = 0;
            }
        }
    }

    for (int i=0 ; i<m ; i++)
    {
        for (int j=0 ; j<n ; j++)
        {
            if (matrix[i][j] != 0)
            {
                if (row[i] == 0 || col[j] == 0)
                {
                    matrix[i][j] = 0;
                }
            }
        }
    }
}

void optimal_setZeroes(vector<vector<int>>& matrix)
{
    int m = matrix.size();
    int n = matrix[0].size();

    int col0 = matrix[0][0];

    for (int i=0 ; i<m ; i++)
    {
        for (int j=0 ; j<n ; j++)
        {
            if (matrix[i][j] == 0)
            {
                matrix[i][0] = 0;
                if (j==0) col0 = 0;
                else matrix[0][j] = 0;
            }
        }
    }

    for (int i=1 ; i<m ; i++)
    {
        for (int j=1 ; j<n ; j++)
        {
            if (matrix[i][j] != 0)
            {
                if (matrix[0][j] == 0 || matrix[i][0] == 0)
                {
                    matrix[i][j] = 0;
                }
            }
        }
    }

    if (matrix[0][0] == 0)
    {
        for (int j=0 ; j<n ; j++)
        {
            matrix[0][j] = 0;
        }
    }

    if (col0 == 0)
    {
        for (int i=0 ; i<m ; i++)
        {
            matrix[i][0] = 0;
        }
    }
}

int main()
{
    vector<vector<int>> matrix = {{1,1,1,1},{1,0,1,1},{1,1,0,1},{0,1,1,1}};
    brute_setZeroes(matrix);
    for (auto i : matrix)
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }

    cout << endl;

    matrix = {{1,1,1,1},{1,0,1,1},{1,1,0,1},{0,1,1,1}};
    better_setZeroes(matrix);
    for (auto i : matrix)
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }

    cout << endl;

    matrix = {{1,1,1,1},{1,0,1,1},{1,1,0,1},{0,1,1,1}};
    optimal_setZeroes(matrix);
    for (auto i : matrix)
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }

    return 0;
}