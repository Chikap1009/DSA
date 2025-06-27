#include <bits/stdc++.h>    
using namespace std;

int rowWithMax1s(vector<vector<int>> &arr) {
    int n = arr.size();
    int m = arr[0].size();
    
    int maxRow = -1;
    int rowNo = -1;
    
    for (int i=0 ; i<n ; i++)
    {
        vector<int> v = arr[i];
        int low = 0;
        int high = m-1;
        while (low <= high)
        {
            int mid = (low + high)/2;
            
            if (v[mid] == 1)
            {
                high = mid-1;
            }
            else
            {
                low = mid+1;
            }
        }
        int noOf1 = m-low;
        if (noOf1 > maxRow)
        {
            maxRow = noOf1;
            rowNo = i;
        }
    }
    
    return rowNo;
}

int main()
{
    vector<vector<int>> v = {{0,1,1,1}, {0,0,1,1}, {1,1,1,1}, {0,0,0,0}};

    cout << rowWithMax1s(v) << endl;

    return 0;
}