#include <bits/stdc++.h>
using namespace std;

vector<int> optimal_spiralOrder(vector<vector<int>>& matrix) {
    int m = matrix.size();
    int n = matrix[0].size();
    int top = 0;
    int bottom = m-1;
    int left = 0;
    int right = n-1;
    vector<int> ans;
    while (left <= right && top <= bottom)
    {
        for (int i=left ; i<=right ; i++)
        {
            ans.push_back(matrix[top][i]);
        }
        top++;

        for (int i=top ; i<=bottom ; i++)
        {
            ans.push_back(matrix[i][right]);
        }
        right--;

        if (top <= bottom)
        {
            for (int i=right ; i>=left ; i--)
            {
                ans.push_back(matrix[bottom][i]);
            }
            bottom--;
        }

        if (left <= right)
        {
            for (int i=bottom ; i>=top ; i--)
            {
                ans.push_back(matrix[i][left]);
            }
            left++;
        }
    }
    return ans;
}

int main()
{
    vector<vector<int>> matrix = {{1,2,3,4},{5,6,7,8},{9,10,11,12}};

    vector<int> v = optimal_spiralOrder(matrix);

    for (auto x : v)
    {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}