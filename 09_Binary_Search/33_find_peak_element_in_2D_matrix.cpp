#include <bits/stdc++.h>
using namespace std;

vector<int> findPeakGrid(vector<vector<int>>& mat) {
    int m = mat.size();
    int n = mat[0].size();

    int low = 0;
    int high = m-1;

    while (low <= high)
    {
        int mid = (low + high)/2;

        int maxInRow = -1;
        int maxIndex = -1;

        for (int i=0 ; i<n ; i++)
        {
            if (mat[mid][i] > maxInRow)
            {
                maxInRow = mat[mid][i];
                maxIndex = i;
            }
        }

        int check = mat[mid][maxIndex];

        int up = -1;
        int down = -1;

        if (mid-1 >= 0)
        {
            up = mat[mid-1][maxIndex];
        }
        if (mid+1 < m)
        {
            down = mat[mid+1][maxIndex];
        }

        if (check > up && check > down) return {mid, maxIndex};
        else if (check < up) high = mid-1;
        else low = mid+1;
    }

    return {-1, -1};
}

int main()
{
    vector<vector<int>> v = {{10,20,15},{21,30,14},{7,16,32}};

    vector<int> ans = findPeakGrid(v);

    cout << ans[0] << " " << ans[1] << endl;

    return 0; 
}