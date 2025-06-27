#include <bits/stdc++.h>
using namespace std;

int findCeil(vector<int>& arr, int x)
{
    int low = 0;
    int high = arr.size()-1;
    // int ans = -1;

    while (low<=high)
    {
        int mid = (low+high)/2;
        if (arr[mid] >= x)
        {
            // ans = arr[mid];
            high = mid-1;
        }
        else
        {
            low = mid+1;
        }
    }
    // return ans;
    if (low == -1) return -1;
    return arr[low];
}

int main()
{
    vector<int> v = {1,2,3,3,5,8,8,10,10,11};

    cout << findCeil(v,4) << endl;

    return 0;
}