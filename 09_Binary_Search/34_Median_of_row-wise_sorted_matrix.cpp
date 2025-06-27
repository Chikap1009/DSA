#include <bits/stdc++.h>
using namespace std;

int upper_bound(vector<int> row, int val)
{
    int low = 0;
    int high = row.size()-1;

    while (low <= high)
    {
        int mid = (low + high)/2;

        if (row[mid] > val) high = mid-1;
        else low = mid+1;
    }

    return low;
}

int calculateSmallerEquals(vector<vector<int>> matrix, int n, int m, int val)
{
    int count = 0;

    for (int i=0 ; i<n ; i++)
    {
        count += upper_bound(matrix[i],val);
    }

    return count;
}

int median(vector<vector<int>> matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();

    int low = INT_MAX;
    int high = INT_MIN;

    for (int i=0 ; i<n ; i++)
    {
        low = min(low, matrix[i][0]);
        high = max(high, matrix[i][m-1]);
    }

    int check = (n*m)/2;

    while (low <= high)
    {
        int mid = (low + high)/2;

        int smallerEquals = calculateSmallerEquals(matrix, n, m, mid);

        if (smallerEquals > check) high = mid - 1;
        else low = mid + 1;
    }

    return low;
}

int main()
{
    vector<vector<int>> v =  {{1,5,7,9,11},{2,3,4,5,10},{9,10,12,14,16}};

    cout << median(v) << endl;

    return 0;
}