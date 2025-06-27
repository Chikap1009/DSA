#include <bits/stdc++.h>
using namespace std;

// void validPaths(vector<vector<int>>& mat, vector<string>& ans, vector<vector<int>>&seen, string path = "", int row = 0, int column = 0)
// {
//     if (row==mat.size()-1 && column==mat.size()-1)
//     {
//         ans.push_back(path);
//         return;
//     }
    
//     if (row >= 0 && row < mat.size() && column >= 0 && column < mat.size())
//     {
//         if (mat[row][column] == 1 && seen[row][column] == 0)
//         {
//             seen[row][column] = 1;
//             path.push_back('R');
//             validPaths(mat,ans,seen,path,row,column+1);
//             path.pop_back();
//             path.push_back('D');
//             validPaths(mat,ans,seen,path,row+1,column);
//             path.pop_back();
//             path.push_back('L');
//             validPaths(mat,ans,seen,path,row,column-1);
//             path.pop_back();
//             path.push_back('U');
//             validPaths(mat,ans,seen,path,row-1,column);
//             path.pop_back();
//             seen[row][column] = 0;
//         }
//     }
// }

// vector<string> findPath(vector<vector<int>> &mat) {
//     vector<string> ans;
//     int n = mat.size();
//     vector<vector<int>> seen;
//     vector<int> line (n,0);
//     for (int i=0 ; i<n ; i++)
//     {
//         seen.push_back(line);
//     }
//     validPaths(mat, ans, seen);
//     return ans;
// }

// void validPaths(vector<vector<int>>& mat, vector<string>& ans, vector<vector<int>>&seen, string path = "", int row = 0, int column = 0)
// {
//     int n = mat.size();
//     if (row==n-1 && column==n-1)
//     {
//         ans.push_back(path);
//         return;
//     }
    
//     if (row+1 < n && mat[row+1][column] == 1 && seen[row+1][column] == 0)
//     {
//         seen[row+1][column] = 1;
//         validPaths(mat,ans,seen,path+"D",row+1,column);
//         seen[row+1][column] = 0;
//     }
//     if (column-1 >= 0 && mat[row][column-1] == 1 && seen[row][column-1] == 0)
//     {
//         seen[row][column-1] = 1;
//         validPaths(mat,ans,seen,path+"L",row,column-1);
//         seen[row][column-1] = 0;
//     }
//     if (column+1 < n && mat[row][column+1] == 1 && seen[row][column+1] == 0)
//     {
//         seen[row][column+1] = 1;
//         validPaths(mat,ans,seen,path+"R",row,column+1);
//         seen[row][column+1] = 0;
//     }
//     if (row-1 >= 0 && mat[row-1][column] == 1 && seen[row-1][column] == 0)
//     {
//         seen[row-1][column] = 1;
//         validPaths(mat,ans,seen,path+"U",row-1,column);
//         seen[row-1][column] = 0;
//     }
// }

// vector<string> findPath(vector<vector<int>> &mat) {
//     vector<string> ans;
//     int n = mat.size();
//     vector<vector<int>> seen;
//     vector<int> line (n,0);
//     for (int i=0 ; i<n ; i++)
//     {
//         seen.push_back(line);
//     }
//     seen[0][0] = 1;
//     validPaths(mat, ans, seen);
//     return ans;
// }

void validPaths(vector<vector<int>>& mat, vector<string>& ans, vector<vector<int>>&seen, vector<int> dirRow, vector<int> dirCol, string path = "", int row = 0, int column = 0)
{
    int n = mat.size();
    if (row==n-1 && column==n-1)
    {
        ans.push_back(path);
        return;
    }
    
    string dir = "DLRU";
    for (int i=0 ; i<4 ; i++)
    {
        int newRow = row + dirRow[i];
        int newCol = column + dirCol[i];
        if (newRow >= 0 && newCol >= 0 && newRow < n && newCol < n && mat[newRow][newCol] == 1 && seen[newRow][newCol] == 0)
        {
            seen[newRow][newCol] = 1;
            validPaths(mat,ans,seen,dirRow,dirCol,path+dir[i],newRow,newCol);
            seen[newRow][newCol] = 0;
        }
    }
}

vector<string> findPath(vector<vector<int>> &mat) {
    vector<string> ans;
    int n = mat.size();
    vector<vector<int>> seen (n, vector<int>(n,0));
    seen[0][0] = 1;
    vector<int> dirRow = {1,0,0,-1}, dirCol = {0,-1,1,0};
    validPaths(mat, ans, seen, dirRow, dirCol);
    return ans;
}

int main()
{
    vector<vector<int>> v = {{1, 0, 0, 0}, {1, 1, 0, 1}, {1, 1, 0, 0}, {0, 1, 1, 1}};

    vector<string> ans = findPath(v);

    for (auto x : ans)
    {
        cout << x << endl;
    }

    return 0;
}