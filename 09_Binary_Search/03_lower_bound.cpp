#include <bits/stdc++.h>
using namespace std;

int implementLowerBound(vector<int>& arr, int x)
{
    int low = 0;
    int high = arr.size() - 1;
    // int ans = arr.size();

    while (low <= high)
    {
        int mid = (low+high)/2;
        if (arr[mid] >= x)
        {
            // ans = mid;
            high = mid-1;
        }
        else
        {
            low = mid+1;
        }
    }
    // return ans;
    return low;
}

int main()
{
    vector<int> v = {1,2,3,3,5,8,8,10,10,11};

    cout << implementLowerBound(v,12) << endl;
    cout << lower_bound(v.begin(),v.end(),12) - v.begin() << endl;

    return 0;
}