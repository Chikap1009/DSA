#include <bits/stdc++.h>
using namespace std;

bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int n = matrix.size();
    int m = matrix[0].size();

    int row = 0;
    int column = m-1;

    while (row < n && column >= 0)
    {
        if (matrix[row][column] == target) return true;

        if (matrix[row][column] < target) row++;
        else column--;
    }

    return false;
}

int main()
{
    vector<vector<int>> v = {{1,4,7,11,15},{2,5,8,12,19},{3,6,9,16,22},{10,13,14,17,24},{18,21,23,26,30}};

    cout << searchMatrix(v, 26) << endl;

    return 0;
}