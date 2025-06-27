#include <bits/stdc++.h>
using namespace std;

int findFloor(vector<int>& arr, int x)
{
    int low = 0;
    int high = arr.size()-1;
    // int ans = -1;

    while (low<=high)
    {
        int mid = (low+high)/2;
        if (arr[mid] <= x)
        {
            // ans = arr[mid];
            low = mid+1;
        }
        else
        {
            high = mid-1;
        }
    }
    // return ans;
    if (high == -1) return -1;
    return arr[high];
}

int main()
{
    vector<int> v = {1,2,3,3,5,8,8,10,10,11};

    cout << findFloor(v,4) << endl;

    return 0;
}