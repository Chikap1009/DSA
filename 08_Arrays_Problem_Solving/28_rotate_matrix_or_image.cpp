#include <bits/stdc++.h>
using namespace std;

void brute_rotateImage(vector<vector<int>>& matrix)
{
    int n = matrix.size();
    int ans[n][n];
    for (int i=0 ; i<n ; i++)
    {
        for (int j=0 ; j<n ; j++)
        {
            ans[j][n-1-i] = matrix[i][j];
        }
    }

    for (int i=0 ; i<n ; i++)
    {
        for (int j=0 ; j<n ; j++)
        {
            matrix[i][j] = ans[i][j];
        }
    }
}

void optimal_rotateImage(vector<vector<int>>& matrix)
{
    int n = matrix.size();
    for (int i=0 ; i<=n-2 ; i++)
    {
        for (int j=i+1 ; j<n ; j++)
        {
            swap(matrix[i][j],matrix[j][i]);
        }
    }

    for (int i=0 ; i<n ; i++)
    {
        reverse(matrix[i].begin(),matrix[i].end());
    }
}

int main()
{
    vector<vector<int>> matrix = {{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
    brute_rotateImage(matrix);
    for (auto i : matrix)
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }

    cout << endl;

    matrix = {{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
    optimal_rotateImage(matrix);
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